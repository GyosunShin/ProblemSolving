// (5 ≤ N ≤ 100)
// 6 <= 웜홀 <= 10
// 블랙홀 -1

// OUTPUT : 게임에서 얻을 수 있는 점수의 최댓값을 구하여라!

#include <cstdio> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

int T, N;
int pan[100][100];
int ans = -1 * 0x7fffffff;

int dir_change[4][5] = {
	{1,3,2,1,1},
	{3,0,0,2,0},
	{0,1,3,3,3},
	{2,2,1,0,2}
};

// 상 하 좌 우 
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

vector<pair<int, int> > whole[5];
map<pair<int ,int>, pair<int ,int> > m;

int start_r, start_c;

int reverse(int input){
	switch (input){
		case 0:
			return 1;
		case 1:
			return 0;
		case 2:
			return 3;
		case 3:
			return 2;									
	}
}

// 출발 위치로 돌아오거나, 블랙홀(-1)에 빠질 때 끝나게 되며
int solve(int r, int c, int dir){
	int ret = 0;
	while(true){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];	int next_dir = dir;	
		if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N){
			next_dir = reverse(dir);
			ret++;
		}
		else{
			if((next_r == start_r && next_c == start_c) || pan[next_r][next_c] == -1)	break;
			if(1 <= pan[next_r][next_c] && pan[next_r][next_c] <= 5){        // 블록 	 
				next_dir = dir_change[dir][pan[next_r][next_c] - 1];
				ret++;
			}
			else if(6 <= pan[next_r][next_c] && pan[next_r][next_c] <= 10){  // 웜홀 
				int tmp_r = m[{next_r, next_c}].first;	int tmp_c = m[{next_r, next_c}].second;
				next_r = tmp_r;	next_c = tmp_c;
			}
		}
		r = next_r;	c = next_c;	dir = next_dir;
	}
	return ret;
}

int main(){
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		for(int i = 0 ; i < 5 ; ++i)	whole[i].clear();
		m.clear();
		ans = -1 * 0x7fffffff;
		scanf("%d", &N);
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &pan[i][j]);		
				if(6 <= pan[i][j] && pan[i][j] <= 10){
					whole[pan[i][j] - 6].push_back(make_pair(i,j));
				}
			}
		}
		 
		
		for(int i = 0 ; i < 5 ; ++i){
			if(whole[i].size() == 2){
				m[make_pair(whole[i][0].first, whole[i][0].second)] = make_pair(whole[i][1].first, whole[i][1].second);
				m[make_pair(whole[i][1].first, whole[i][1].second)] = make_pair(whole[i][0].first, whole[i][0].second);
			}
		}	
		
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				for(int k = 0 ; k < 4 ; ++k){
					if(pan[i][j] == 0){
						start_r = i;	start_c = j;
						ans = max(ans, solve(i, j, k));
					}
				}
			}
		}		
		
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}
