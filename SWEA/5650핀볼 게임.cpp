// 게임에서 얻을 수 있는 점수의 최댓값을 구하여라!

// (5 ≤ N ≤ 100) == R == C
// 웜홀 최대 5쌍
// 블랙홀 최대 5개 

// 점수는 (벽)이나 (블록)에 부딪힌 횟수가 된다.

#include <stdio.h> 
#include <vector>
#include <algorithm>

using namespace std;

int map[100][100];

int T, N;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int ans = -1 * 0x7fffffff;

vector<pair<int, int> > six;
vector<pair<int, int> > seven;
vector<pair<int, int> > eight;
vector<pair<int, int> > nine;
vector<pair<int, int> > ten;

int dfs(int start_r, int start_c, int cur_r, int cur_c, int score, int dir, bool flag){
	// 원위치로 돌아왔을 때
	if(start_r == cur_r && start_c == cur_c && flag){
		return score;
	}
	flag = true;
	// 블랙홀에 들어와서 게임 종료 되었을때
	if(map[cur_r][cur_c] == -1){
		return score;
	}
	
	int next_r, next_c;
	next_r = cur_r + dr[dir];	next_c = cur_c + dc[dir];
	
	if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N){
		if(dir == 0){
			dir = 1;
		}	
		else if(dir == 1){
			dir = 0;
		}	
		else if(dir == 2){
			dir = 3;
		}	
		else if(dir == 3){
			dir = 2;		
		}	
		next_r = cur_r;	next_c = cur_c;
		++score;
	}
	
	if(map[next_r][next_c] == 1){
		if(dir == 0)	dir = 1;
		else if(dir == 1)	dir = 3;
		else if(dir == 2)	dir = 0;
		else if(dir == 3)	dir = 2;
		++score;
	}
	else if(map[next_r][next_c] == 2){
		if(dir == 0)	dir = 3;
		else if(dir == 1)	dir = 0;
		else if(dir == 2)	dir = 1;
		else if(dir == 3)	dir = 2;		
		++score;
	}
	else if(map[next_r][next_c] == 3){
		if(dir == 0)	dir = 2;
		else if(dir == 1)	dir = 0;
		else if(dir == 2)	dir = 3;
		else if(dir == 3)	dir = 1;		
		++score;
	}
	else if(map[next_r][next_c] == 4){
		if(dir == 0)	dir = 1;
		else if(dir == 1)	dir = 2;
		else if(dir == 2)	dir = 3;
		else if(dir == 3)	dir = 0;		
		++score;
	}
	else if(map[next_r][next_c] == 5){
		if(dir == 0)	dir = 1;
		else if(dir == 1)	dir = 0;
		else if(dir == 2)	dir = 3;
		else if(dir == 3)	dir = 2;		
		++score;
	}			
	else if(map[next_r][next_c] == 6){
		int target_index;
		if(six[0].first == next_r){
			target_index = 1;
		}
		else{
			target_index = 0;
		}
		next_r = six[target_index].first;	next_c = six[target_index].second;
	}
	else if(map[next_r][next_c] == 7){
		int target_index;
		if(seven[0].first == next_r){
			target_index = 1;
		}
		else{
			target_index = 0;
		}
		next_r = seven[target_index].first;	next_c = seven[target_index].second;
	}	
	else if(map[next_r][next_c] == 8){
		int target_index;
		if(eight[0].first == next_r){
			target_index = 1;
		}
		else{
			target_index = 0;
		}
		next_r = eight[target_index].first;	next_c = eight[target_index].second;
	}	
	else if(map[next_r][next_c] == 9){
		int target_index;
		if(nine[0].first == next_r){
			target_index = 1;
		}
		else{
			target_index = 0;
		}
		next_r = nine[target_index].first;	next_c = nine[target_index].second;
	}	
	else if(map[next_r][next_c] == 10){
		int target_index;
		if(ten[0].first == next_r){
			target_index = 1;
		}
		else{
			target_index = 0;
		}
		next_r = ten[target_index].first;	next_c = ten[target_index].second;
	}	
	
	return dfs(start_r, start_c, next_r, next_c, score, dir, flag);
}

int main(){
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		ans = -1 * 0x7fffffff;
		six.clear();	seven.clear();	eight.clear();	nine.clear();	ten.clear();
		scanf("%d", &N);
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N  ; ++j){
				scanf("%d", &map[i][j]);
				if(map[i][j] == 6){
					six.push_back(pair<int, int>(i, j));
				}
				else if(map[i][j] == 7){
					seven.push_back(pair<int, int>(i, j));
				}				
				else if(map[i][j] == 8){
					eight.push_back(pair<int, int>(i, j));
				}
				else if(map[i][j] == 9){
					nine.push_back(pair<int, int>(i, j));
				}				
				else if(map[i][j] == 10){
					ten.push_back(pair<int, int>(i, j));
				}				
			}
		}
		//################################
		
		// 시작위치는 map[][] == 0인 즉, 빈칸인 곳만 선정 가능! 
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N  ; ++j){
				if(map[i][j] == 0){
					// dfs(int start_r, int start_c, int cur_r, int cur_c, int score, int dir, bool flag)
					ans = max(ans, dfs(i, j, i, j, 0, 0, false));
					ans = max(ans, dfs(i, j, i, j, 0, 1, false));
					ans = max(ans, dfs(i, j, i, j, 0, 2, false));
					ans = max(ans, dfs(i, j, i, j, 0, 3, false));
				}
				else	continue;	
			}
		}
		printf("#%d %d\n", z, ans);
	}
	return 0;
}



