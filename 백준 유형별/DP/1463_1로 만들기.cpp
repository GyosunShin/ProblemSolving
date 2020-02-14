// 1 <= INPUT <= 10^6

// OUTPUT : 첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
int dp[1000001];  // For) 1 <= INPUT <= 1000000

int solve(int n){
	if(n == 1)	return 0;
	int& ret = dp[n];
	if(ret != -1)	return ret;
	ret = 0x7fffffff;
	if(n % 3 == 0)	ret = min(ret, solve(n / 3) + 1);
	if(n % 2 == 0)	ret = min(ret, solve(n / 2) + 1);
	ret = min(ret, solve(n - 1) + 1);
	return ret;
}

int main(){
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	int ret = solve(n);
	printf("%d\n", ret);
	return 0;
}







