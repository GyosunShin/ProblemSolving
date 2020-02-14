// ù° �ٿ� �������� ���� N(1 �� N �� 1,000,000)�� �־�����.
// ��° �ٿ��� �� �����忡 �ִ� �������� �� Ai (1 �� Ai �� 1,000,000)�� �־�����.
// ��° �ٿ��� B�� C�� �־�����. (1 �� B, C �� 1,000,000)
// 
// INPUT
// 3
// 3 4 5
// 2 2
// 
// OUTPUT
// �ʿ��� �������� �ּ� ���� ����Ѵ�.
#include <stdio.h>

int N;
int map[1000000]; // �����帶�� ����ִ� ������ �� �����
int B, C;
long long ans;

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
	}
	scanf("%d %d", &B, &C);
	//###############################
	
	ans += N;
	for(int i = 0 ; i < N ; ++i){
		map[i] -= B;
		if(map[i] <= 0)	continue;
		int tmp = map[i] / C;
		if((map[i] % C != 0)){
			++tmp;
//			printf("test : %d \n", tmp);
		}	
		ans += tmp;
	}	
	
	printf("%ld", ans);
	return 0;
}


		




 
