// 1 ≤ N ≤ 4
// 2 ≤ W ≤ 12
// 2 ≤ H ≤ 15

// OUTPUT : 남은 벽돌의 개수를 구하라!(최대한 많은 벽돌을 깨뜨렸을 때 남은 것을 구하라)

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N, W, H;
int map[15][12];
int backup[15][12];
bool visited[15][12];

bool flag = false;

vector<int> picked;
queue<pair<int, int> > q;

const int dr[] = {-1, 1, 0 ,0 };
const int dc[] = {0, 0, -1, 1};

int ans = 0x7fffffff;

void bfs(){
	
	while(!q.empty()){
		int cur_r = q.front().first;	int cur_c = q.front().second;	q.pop();
		int howfar = backup[cur_r][cur_c];
		backup[cur_r][cur_c] = 0;
		
		for(int dis = 1 ; dis < howfar ; ++dis){
			for(int dir = 0 ; dir < 4 ; ++dir){
				int next_r = cur_r + (dr[dir] * dis);	int next_c = cur_c + (dc[dir] * dis);
				if(0 > next_r || next_r >= H || 0 > next_c || next_c >= W || visited[next_r][next_c])	continue;
				visited[next_r][next_c] = true;
				q.push(make_pair(next_r, next_c));
			}
		}
	}
	
}

void smash(int start){
	int top = -1;
	for(int i = 0 ; i < H ; ++i){
		if(backup[i][start] > 0){
			top = i;
			break;
		}
	}
	if(top == -1){
		return;
	}
	
	memset(visited, false, sizeof(visited));
	q.push(make_pair(top, start));
	visited[top][start] = true;
	bfs();
	
	// 주석 처리한 부분은 잘못된 로직 
//	// backup 보고 0 로 표시된거 있는거 보고 가라앉혀라!
//	for(int i = 0 ; i < W ; ++i){
//		for(int j = H-1 ; j >= 0 ; --j){
//			if(backup[j][i] == 0){
//				int tmp = -1;
//				for(int k = j ; k >= 0 ; --k){
//					if(backup[k][i] > 0){
//						tmp = k;
//						break;
//					}
//				}
//				if(tmp == -1)	break;
//				
//				for(int k = j-1 ; k >= 0 ; --k){
//					backup[k+1][i] = backup[k][i];
//				}
//				backup[0][i] = 0;
//				j = H-1;
//			}
//		}
//	}

	// 벽돌 무너뜨리기
	for(int i = 0 ; i < W ; ++i){
		vector<int> tmp;
		for(int j = H-1 ; j >= 0 ; --j){
			if(backup[j][i] > 0)	tmp.push_back(backup[j][i]);
		}
		for(int j = 0 ; j < H ; ++j){
			backup[j][i] = 0;
		}
		for(int j = 0 ; j < tmp.size() ; ++j){
			backup[H-1-j][i] = tmp[j];
		}
	}
	
}

void dfs(){
	if(flag)	return;
	
	if(picked.size() == N){
		
		copy(&map[0][0], &map[0][0] + (15*12), &backup[0][0]);
		
		for(int i = 0 ; i < picked.size() ; ++i){
			smash(picked[i]);
		}
		
		int tmp = 0;
		for(int i = 0 ; i < H ; ++i){
			for(int j = 0 ; j < W ; ++j){
				if(backup[i][j] > 0){
					++tmp;
				}
			}
		}
		
		ans = min(ans, tmp);
		
		if(ans == 0)	flag = true;
				
		return;
	}
	
	for(int i = 0 ; i < W ; ++i){
		picked.push_back(i);
		dfs();
		picked.pop_back();
	}
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		ans = 0x7fffffff;
		flag = false;
		scanf("%d %d %d", &N, &W, &H);	
		for(int i = 0 ; i < H ; ++i){
			for(int j = 0 ; j < W ; ++j){
				scanf("%d", &map[i][j]);
			}
		}
		
		dfs();
		
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}
