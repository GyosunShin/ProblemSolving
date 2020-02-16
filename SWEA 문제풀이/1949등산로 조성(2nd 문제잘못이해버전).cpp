// (3 ≤ N ≤ 8)
// (1 ≤ K ≤ 5)
// 1 <= 지형의 높이는 <= 20 

// OUTPUT : 만들 수 있는 가장 긴 등산로를 찾아 그 길이를 출력

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, K;
int map[20][20];
bool visited[20][20];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int ans = -1 * 0x7fffffff;

vector<pair<int, int> > maxs;

void dfs(int r, int c, int cnt){
	
	bool tmp_flag = true;
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N || visited[next_r][next_c] || map[r][c] <= map[next_r][next_c])	continue;
		visited[next_r][next_c] = true;
		tmp_flag = false;
		dfs(next_r, next_c, cnt + 1);
		visited[next_r][next_c] = false;;
	}
	if(tmp_flag){  // 더이상 전진 불가능 의미 
		if(ans < cnt)	ans = cnt;
		return;
	}
	
}

int main(){
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		maxs.clear();
		ans = -1 * 0x7fffffff;
		int tmp_max = -1 * 0x7fffffff;
		scanf("%d %d", &N, &K);	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &map[i][j]);			
				tmp_max = max(tmp_max, map[i][j]);
			}
		}
		
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				if(map[i][j] == tmp_max)	maxs.push_back(make_pair(i, j));
			}
		}
		for(int i = 0 ; i < maxs.size() ; ++i){
			dfs(maxs[i].first, maxs[i].second, 1);
		}
				
		for(int k = 1 ; k <= K ; ++k){
			for(int i = 0 ; i < N ; ++i){
				for(int j = 0 ; j < N ; ++j){
					map[i][j] -= k;
					
					maxs.clear();
					tmp_max = -1 * 0x7fffffff;
					for(int m = 0 ; m < N ; ++m){
						for(int n = 0 ; n < N ; ++n){
							tmp_max = max(tmp_max, map[m][n]);
						}
					}
					for(int m = 0 ; m < N ; ++m){
						for(int n = 0 ; n < N ; ++n){
							if(map[m][n] == tmp_max)	maxs.push_back(make_pair(m, n));
						}
					}
					
					for(int m = 0 ; m < maxs.size() ; ++m){
						dfs(maxs[m].first, maxs[m].second, 1);
					}
					
					map[i][j] += k;
				}
			}
		}
		
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}

