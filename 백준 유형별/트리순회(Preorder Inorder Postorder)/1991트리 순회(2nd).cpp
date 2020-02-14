//  ����� ���� N(1��N��26)
//  �� ���� ���� ���� �ڽ� ���, ������ �ڽ� ���
// �ڽ� ��尡 ���� ��쿡�� .���� ǥ���ȴ�

// OUTPUT : ù° �ٿ� ���� ��ȸ, ��° �ٿ� ���� ��ȸ, ��° �ٿ� ���� ��ȸ��

#include <stdio.h>

int N;
int map[26][2];  // <cur, <left, right>>     0 ~ 25

void pre(int start){  // (��Ʈ) (���� �ڽ�) (������ �ڽ�)
	printf("%c", 'A' + start);
	
	for(int i = 0 ; i < 2 ; ++i){
		if((0 <= map[start][i] && map[start][i] <= 25)){
			pre(map[start][i]);
		}
	}	
}

void in(int start){  // (���� �ڽ�) (��Ʈ) (������ �ڽ�)

	if((0 <= map[start][0] && map[start][0] <= 25)){
		in(map[start][0]);
	}
	printf("%c", 'A' + start);
	if((0 <= map[start][1] && map[start][1] <= 25)){
		in(map[start][1]);
	}
}

void post(int start){  // (���� �ڽ�) (������ �ڽ�) (��Ʈ)
	if((0 <= map[start][0] && map[start][0] <= 25)){
		post(map[start][0]);
	}
	if((0 <= map[start][1] && map[start][1] <= 25)){
		post(map[start][1]);	
	}
	printf("%c", 'A' + start);
}

int main(){
	
	scanf("%d", &N);
	getchar();
	
	for(int i = 0 ; i < N ;++i){
		char cur, left, right;
		scanf("%c %c %c", &cur, &left, &right);
		getchar();
		map[cur - 'A'][0] = left - 'A';
		map[cur - 'A'][1] = right - 'A';
	}
	
	// ����
	pre(0);
	printf("\n");
	
	// ����
	in(0);
	printf("\n");
	
	// ���� 
	post(0);
	printf("\n");
	
	return 0;
}
