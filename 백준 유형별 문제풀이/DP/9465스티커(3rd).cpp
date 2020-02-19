// (1 ≤ n ≤ 100,000)
// 0 <= 각 점수 <= 100 

// OUTPUT : 각 테스트 케이스 마다, 2n개의 스티커 중에서 두 변을 공유하지 않는 스티커 점수의 최댓값을 출력한다.

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, N;
int pan[2][100000];
int cache[2][100000];

int dfs(int r, int c){
	if(c >= N)	return 0;
	int &ret = cache[r][c];
	if(ret != -1)	return ret;
	int tmp_ret = -1 * 0x7fffffff;
	
	if(r == 0){
		tmp_ret = max(tmp_ret, dfs(1, c+1) + pan[r][c]);
		tmp_ret = max(tmp_ret, dfs(1, c+2) + pan[r][c]);	
	}
	else if(r == 1){
		tmp_ret = max(tmp_ret, dfs(0, c+1) + pan[r][c]);
		tmp_ret = max(tmp_ret, dfs(0, c+2) + pan[r][c]);	
	}
	return ret = tmp_ret;
}

int solve(){
	int tmp_ret = -1 * 0x7fffffff; 
	
	tmp_ret = max(tmp_ret, dfs(0,0));
	tmp_ret = max(tmp_ret, dfs(0,1));
	tmp_ret = max(tmp_ret, dfs(1,0));
	tmp_ret = max(tmp_ret, dfs(1,1));
	
	return tmp_ret;
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);
		for(int i = 0 ; i < 2 ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &pan[i][j]);
			}
		}	
		int ans = solve();
		printf("%d\n", ans);
	}
	
	return 0;
}
