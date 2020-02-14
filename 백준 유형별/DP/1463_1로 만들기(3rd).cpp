// INPUT : 1 <= N <= 1000000
// OUTPUT : 연산을 하는 횟수의 최솟값을 출력한다.

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int cache[1000001];

int solve(int n){
	if(n == 1)	return 0;
	int& ret = cache[n];
	if(ret != -1)	return ret;
	
	ret = 0x7fffffff;
	if(n % 3 == 0)	ret = min(ret, solve(n/3) + 1);
	if(n % 2 == 0)	ret = min(ret, solve(n/2) + 1);
	ret = min(ret, solve(n-1) + 1);
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	
	int ans = solve(N);
	printf("%d", ans);
	return 0;
}
