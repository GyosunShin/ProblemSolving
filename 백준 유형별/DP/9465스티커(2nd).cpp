// 1 ¡Â n ¡Â 100,000

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int T, N;
int map[2][100000];
int cache[2][100000];

int solve(int r, int c){
	if(c >= N)	return;	
	
	int& ret = cache[r][c];
	if(ret != -1)	return ret;
	if(r == 0){
		ret = max(map[r][c] + solve(r+1, c+1), map[][] + solve());	
		ret = max();
	}
	else if(r == 1)P{
		ret = max(map[r][c] + solve(r-1, c+1), map[][] + solve());	
	}
	
	return ret;
}

int main(){
	scanf("%d", &T);
	
	for(int z = 0 ; z < T ; ++z){
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);	
		for(int i = 0 ; i < 2 ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &map[i][j]);			
			}
		}
		cache[]
		int ans = max(solve(0,0), solve(1,0));
		printf("%d\n", ans);	
		
	}
	
	return 0;
}
