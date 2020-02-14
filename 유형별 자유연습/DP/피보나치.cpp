#include <stdio.h>
#include <string.h>

long long cache[100];

long long solve(int idx){
	if(idx == 1)	return 1;
	else if(idx == 2)	return 1;
	long long& ret = cache[idx];
	if(ret != -1)	return ret;
	ret = solve(idx-1) + solve(idx-2);
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	int idx;
	scanf("%d", &idx);
	long long ret = solve(idx);
	
	printf("%lld", ret);
	
	return 0;
}
