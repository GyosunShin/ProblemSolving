// (3 ≤ N ≤ 8)
// (1 ≤ K ≤ 5)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, K;

int pan[8][8];
bool visited[8][8];

int ans = 0;
int max_start = -1 * 0x7fffffff;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int dfs(int r, int c, bool flag){
	int tmp_ret = 0;
	
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N || visited[next_r][next_c])	continue;

		for(int i = 0 ; i <= K ; ++i){
			int cutted = pan[next_r][next_c] - i;
			if(cutted >= pan[r][c])	continue;
			else{
				
				if(i == 0){
					pan[next_r][next_c] = pan[next_r][next_c] - i;
					visited[next_r][next_c] = true;
					tmp_ret = max(tmp_ret, dfs(next_r, next_c, flag) + 1);
					visited[next_r][next_c] = false;
					pan[next_r][next_c] = pan[next_r][next_c] + i;
				}
				else{
					if(flag)	continue;
					pan[next_r][next_c] = pan[next_r][next_c] - i;
					visited[next_r][next_c] = true;
					tmp_ret = max(tmp_ret, dfs(next_r, next_c, true) + 1);
					visited[next_r][next_c] = false;
					pan[next_r][next_c] = pan[next_r][next_c] + i;
				}	
			}
		}
		
	}
	
	return tmp_ret;
	
}

void solve(){
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(pan[i][j] == max_start){
//				printf("START_R : %d / START_C : %d\n", i, j);
				visited[i][j] = true;
				ans = max(ans, dfs(i, j, false) + 1);
				visited[i][j] = false;
//				printf("ANS : %d\n", ans);
			}
		}
	}
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		ans = 0;
		max_start = -1 * 0x7fffffff;
		scanf("%d %d", &N, &K);
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &pan[i][j]);
				max_start = max(max_start, pan[i][j]);
			}
		}
		
		solve();			
		
		// OUTPUT : 가장 긴 등산로의 길이
		printf("#%d %d\n", z, ans);
	}
	return 0;
}
