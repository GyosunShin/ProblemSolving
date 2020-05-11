
//  (3 ≤ K ≤ 500)	
// 각 장의 파일 크기 <= 10000

#include <cstdio> 
#include <cstring>
#include <algorithm>

using namespace std;

int T, N;
int pan[501];
int sum[501];
int cache[501][501];

int dfs(int start, int end){
	
	if(start >= end)	return 0;	
	
	if(start + 1 == end){
		return pan[start] + pan[end];
	}
	
	int& ret = cache[start][end];
	if(ret != -1)	return ret;
	
	int mmax = 0x7fffffff;
	
	for(int i = start ; i < end ; ++i){
		mmax = min(mmax, 
		dfs(start, i) + dfs(i+1, end) + sum[end] - sum[start] + pan[start]);
	}
	
	return ret = mmax;
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);	
		for(int i = 1 ; i <= N ; ++i){
			scanf("%d", &pan[i]);	
			sum[i] = sum[i-1] + pan[i];
		}
		printf("%d\n", dfs(1, N));
	}
	
	return 0;
}
