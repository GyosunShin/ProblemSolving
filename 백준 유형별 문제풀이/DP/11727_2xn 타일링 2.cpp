#include <stdio.h>
#include <string.h>

int N;  //  (1 ¡Â n ¡Â 1,000)
int cache[1001];

int solve(int n){
	if(n == 1)	return 1;
	if(n == 2)	return 3;
	int& ret = cache[n];
	if(ret != -1)	return ret;
	ret = (solve(n-1) + (2 * solve(n-2))) % 10007;
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	int ans = solve(N);
	printf("%d", ans);
	return 0;
}
