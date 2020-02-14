// N (1 ¡Â N ¡Â 15)
// (1 ¡Â Ti ¡Â 5, 1 ¡Â Pi ¡Â 1,000)

#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int tmap[15], pmap[15];
int cache[15];

int solve(int start){
	if(start > N)	return (-1 * 0x7fffffff);
	if(start == N)	return 0;
	
	int& ret = cache[start];
	if(ret != 0)	return ret;
	ret = max(solve(start + tmap[start]) + pmap[start], solve(start+1));
	return ret;
}

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		int ti, pi;
		scanf("%d %d", &ti, &pi);
		tmap[i] = ti;
		pmap[i] = pi;
	}
	
	int ans = solve(0);
	
	printf("%d", ans);
	return 0;
}
