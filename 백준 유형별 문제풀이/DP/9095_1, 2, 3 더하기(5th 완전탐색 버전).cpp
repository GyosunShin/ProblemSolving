// 1 <= n <= 10

#include <cstdio>

int T, N, ans, sum;

void dfs(){
	
	if(sum > N)	return;
	
	if(sum == N){
		++ans;
		return;
	}
	
	for(int i = 1 ; i <= 3; ++i){
		sum += i;
		dfs();
		sum -= i;
	}
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		ans = 0;
		sum = 0;
		scanf("%d", &N);
		
		dfs();
		printf("%d\n", ans);
	}
	
	return 0;
}
