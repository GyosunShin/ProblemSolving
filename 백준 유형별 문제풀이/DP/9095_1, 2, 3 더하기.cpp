#include <stdio.h>
#include <string.h>

int dp[12];

int solve(int n){
	if(n == 1)	return 1;
	if(n == 2)	return 2;
	if(n == 3)	return 4;
	
	int& ret = dp[n];
	if(ret != -1)	return ret;
	
	ret = solve(n-1) + solve(n-2) + solve(n-3);
	return ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int n;
		scanf("%d", &n);
		int ret = solve(n);
		printf("%d\n", ret);
	}
	return 0;
}
