// 집의 수 : N <= 1000
// R, G, B <= 1000 
// 
// OUTPUT : 첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.

#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int R[1000];
int G[1000];
int B[1000];

int cache_r[1000];
int cache_g[1000];
int cache_b[1000];

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ;++i){
		scanf("%d %d %d", &R[i], &G[i], &B[i]);
	}
	//############################################
	
	cache_r[0] = R[0];	cache_g[0] = G[0];	cache_b[0] = B[0];
	for(int i = 1; i < N ; ++i){
		cache_r[i] = min(cache_g[i-1], cache_b[i-1]) + R[i];
		cache_g[i] = min(cache_r[i-1], cache_b[i-1]) + G[i];
		cache_b[i] = min(cache_r[i-1], cache_g[i-1]) + B[i];
	}
	
	int ans = min(cache_r[N-1], cache_g[N-1]);
	ans = min(ans, cache_b[N-1]);
	
	printf("%d", ans);
	
	return 0;
}


