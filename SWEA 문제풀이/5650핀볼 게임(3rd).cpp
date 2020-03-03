// OUTPUT : 게임에서 얻을 수 있는 점수의 최댓값을 구하여라!
// 빈칸에서만 출발 가능

// (5 ≤ N ≤ 100)

#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int T, N;
int pan[102][102];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};
const int change_dir[6][4] = {
	{0,0,0,0},
	{1,3,0,2},
	{3,0,1,2},
	{2,0,3,1},
	{1,2,3,0},
	{1,0,3,2}
};
const int opposite[4] = {1, 0, 3, 2};
vector<pair<int, int> > wholes[5];

int global_r, global_c;

int point;

void solve(int start_r, int start_c, int start_dir){
	
	while(true){
		int next_r = start_r + dr[start_dir];	int next_c = start_c + dc[start_dir];
		// 블록
		if(1 <= pan[next_r][next_c] && pan[next_r][next_c] <= 5){
			++point;
			start_dir = change_dir[pan[next_r][next_c]][start_dir];
		}
		// 웜홀 
		if(6 <= pan[next_r][next_c] && pan[next_r][next_c] <= 10){
			for(int i = 0 ; i < wholes[pan[next_r][next_c]-6].size() ; ++i){
				if(wholes[pan[next_r][next_c]-6][i].first != next_r || wholes[pan[next_r][next_c]-6][i].second != next_c){
					start_r = wholes[pan[next_r][next_c]-6][i].first;
					start_c = wholes[pan[next_r][next_c]-6][i].second;
					break;
				}
			}
			continue;
		}
		// 범위 밖
		if(1 > next_r || next_r > N || 1 > next_c || next_c > N){
			++point;
			start_dir = opposite[start_dir];
		}
		start_r = next_r;	start_c = next_c;
		if(start_r == global_r && start_c == global_c)	return;
		if(pan[start_r][start_c] == -1)	return;
	}
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		
		for(int i = 0 ; i < 102 ; ++i){
			for(int j = 0 ; j < 102 ; ++j){
				pan[i][j] = -2;
			}
		}
		
		for(int i = 0 ; i < 5 ; ++i)	wholes[i].clear();
		int ans = -1 * 0x7fffffff;
		scanf("%d", &N);
		
		for(int i = 1 ; i <= N ; ++i){
			for(int j = 1 ; j <= N ; ++j){
				scanf("%d", &pan[i][j]);
				if(6 <= pan[i][j] && pan[i][j] <= 10){
					wholes[pan[i][j] - 6].push_back(make_pair(i, j));
				}
			}
		}
				
		for(int i = 1 ; i <= N ; ++i){
			for(int j = 1 ; j <= N ; ++j){
				if(pan[i][j] == 0){
					global_r = i;	global_c = j;
					for(int k = 0 ; k < 4 ; ++k){
						// 게임은 핀볼이 (출발 위치)로 돌아오거나, (블랙홀)에 빠질 때 끝나게 되며,
						point = 0;
						
						solve(i, j, k);
						ans = max(ans, point);	
					}
				}
			}
		}
		
		printf("#%d %d\n", z, ans);
	}
	return 0;
}
