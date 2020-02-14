// 수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.

//  (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

#include <stdio.h>

int N;
int map[1000];
int up[1000];
int down[1000];

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &map[i]);
	
	up[0] = 1;
	for(int i = 1 ; i < N ; ++i){
		int max = 0;
		for(int j = 0 ; j < i ; ++j){
			if(map[i] > map[j]){
				if(max < up[j])	max = up[j];
			}
		}
		up[i] = max + 1;
	}
	
	down[N-1] = 1;
	for(int i = (N-2) ; i >= 0 ; --i){
		int max = 0;
		for(int j = (N-1) ; j > i ; --j){
			if(map[i] > map[j]){
				if(max < down[j])	max = down[j];
			}
		}
		down[i] = max + 1;
	}
	
//	for(int i = 0 ; i < N ; ++i)	printf("%d  ", up[i]);
//	printf("\n");
//	for(int i = 0 ; i < N ; ++i)	printf("%d  ", down[i]);
//	printf("\n");
	
	int ans = 0;
	for(int i = 0 ; i < N ; ++i){
		int tmp = up[i] + down[i] - 1;
		if(ans < tmp)	ans = tmp;
	}
	printf("%d", ans);
		
	return 0;
}

