// 1 <= n <= 10

#include <cstdio>
#include <cstring>

int T, N, sum;
int cache[11][11];

int dfs(int deep){
	
	if(deep > 10)	return 0;
	if(sum > N)	return 0;
	
	int& ret = cache[sum][deep];
	if(ret != -1)	return ret;
	
	if(sum == N){
		return 1;
	}
	
	int s = 0;
	
	for(int i = 1 ; i <= 3; ++i){
		sum += i;
		s += dfs(deep + 1);
		sum -= i;
	}
	
	return ret = s;
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		memset(cache, -1, sizeof(cache));
		sum = 0;
		scanf("%d", &N);
		
		printf("%d\n", dfs(0));
	}
	
	return 0;
}
