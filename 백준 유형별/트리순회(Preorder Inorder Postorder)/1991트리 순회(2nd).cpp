//  노드의 개수 N(1≤N≤26)
//  각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드
// 자식 노드가 없는 경우에는 .으로 표현된다

// OUTPUT : 첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한

#include <stdio.h>

int N;
int map[26][2];  // <cur, <left, right>>     0 ~ 25

void pre(int start){  // (루트) (왼쪽 자식) (오른쪽 자식)
	printf("%c", 'A' + start);
	
	for(int i = 0 ; i < 2 ; ++i){
		if((0 <= map[start][i] && map[start][i] <= 25)){
			pre(map[start][i]);
		}
	}	
}

void in(int start){  // (왼쪽 자식) (루트) (오른쪽 자식)

	if((0 <= map[start][0] && map[start][0] <= 25)){
		in(map[start][0]);
	}
	printf("%c", 'A' + start);
	if((0 <= map[start][1] && map[start][1] <= 25)){
		in(map[start][1]);
	}
}

void post(int start){  // (왼쪽 자식) (오른쪽 자식) (루트)
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
	
	// 전위
	pre(0);
	printf("\n");
	
	// 중위
	in(0);
	printf("\n");
	
	// 후위 
	post(0);
	printf("\n");
	
	return 0;
}
