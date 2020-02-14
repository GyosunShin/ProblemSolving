// N (1 ¡Â N ¡Â 15)

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
int t[15];
int p[15];

int cache[15];

int solve(int index){
	if(index == N)	return 0;
	if(index > N)	return (-1 * 0x7fffffff);
	int& ret = cache[index];
	if(ret != -1)	return ret;
	ret = max(solve(index+1), solve(index + t[index]) + p[index]);
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d %d", &t[i], &p[i]);	
	}
	
	int ans = solve(0);
	
	printf("%d", ans);
	
	return 0;
}
