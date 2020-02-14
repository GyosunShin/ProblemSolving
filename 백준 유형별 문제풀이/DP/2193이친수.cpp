#include <stdio.h> 
#include <string.h>

int N;  //1<= N <=90

long cache[91];

long solve(int n){
	if(n == 0)	return 0;
	if(n == 1)	return 1;
	long& ret = cache[n];
	if(ret != -1)	return ret;
	ret = solve(n-1) + solve(n-2);
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));	
	cache[0] = 0;	cache[1] = 1;
	scanf("%d", &N);
	long ans = solve(N);
	printf("%ld", ans);
	return 0;
}
