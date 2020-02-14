// S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN  [바이토닉 수열] 
// 수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.

// (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

#include <stdio.h>

int cache[1000];
int cachetwo[1000];
int map[1000];
int N;

int ans = -1 * 0x7fffffff;

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);	
	}
	
	cache[0] = 1;
	
	for(int i = 1 ; i < N ; ++i){
		int max = 0;
		for(int j = 0 ; j < i ; ++j){
			if(map[i] > map[j]){
				if(max < cache[j])	max = cache[j];
			}
		}
		cache[i] = max + 1;
	}
	
	
	cachetwo[N-1] = 1;
	
	for(int i = (N-2) ; i >= 0 ; --i){
		int max = 0;
		for(int j = (N-1) ; j > i ; --j){
			if(map[i] > map[j]){
				if(max < cachetwo[j])	max = cachetwo[j];
			}
		}
		cachetwo[i] = max + 1;
	}	
	
	for(int i = 0 ; i < N ; ++i){
		if(ans < (cache[i] + cachetwo[i]) - 1)	ans = (cache[i] + cachetwo[i]) - 1;
	}
	
	printf("%d", ans);
	return 0;
}
