// (1 ≤ N ≤ 15)
// (1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1,000)

// OUTPUT : 첫째 줄에 백준이가 얻을 수 있는 최대 이익을 출력한다.

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
int T[15], P[15];

int cache[15];

int solve(int n){
	if(n == N)	return 0;
	if(n > N)	return (-1 * 0x7fffffff);
	
	int& ret = cache[n];
	if(ret != -1)	return ret;
	
	ret = max(P[n] + solve(n+T[n]), solve(n+1));
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d %d", &T[i], &P[i]);
	}
	//##################################
	
	int ans = solve(0);
	printf("%d", ans);
	return 0;
}
