//n(1 ≤ n ≤ 500)
//
//OUTPUT : 첫째 줄에 합이 최대가 되는 경로에 있는 수의 합을 출력한다.

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N;

int cache[500][500];
int map[500][500];

int solve(int r, int c){
	if(r == N-1)	return map[r][c];
	int& ret = cache[r][c];
	if(ret != -1)	return cache[r][c];
	
	ret = max(solve(r+1,c), solve(r+1,c+1)) + map[r][c];
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j <= i ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	//#################################
	
	int ans = solve(0,0);
	printf("%d", ans);
	return 0;
}




