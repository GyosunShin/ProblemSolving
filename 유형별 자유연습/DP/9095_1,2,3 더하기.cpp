#include <stdio.h>
#include <string.h>

int T;

// n은 양수이며 11보다 작다.  --> 1 <= n <= 10
int cache[11];

int solve(int idx){
	if(idx == 1)	return 1;
	else if(idx == 2)	return 2;
	else if(idx == 3)	return 4;
	int& ret = cache[idx];
	if(ret != -1)	return ret;
	ret = solve(idx-1) + solve(idx-2) + solve(idx-3);
	return ret;
}

int main(){
	scanf("%d", &T);
	
	for(int z = 0 ; z < T ; ++z){
		memset(cache, -1, sizeof(cache));
		int tmp;
		scanf("%d", &tmp);
		int ret = solve(tmp);
		printf("%d\n", ret);
	}
	return 0;	
}
