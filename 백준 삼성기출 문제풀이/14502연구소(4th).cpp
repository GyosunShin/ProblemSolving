// 0은 빈 칸 /  1은 벽  /  2는 바이러스

// OUTPUT : 안전 영역 크기의 최댓값

// (3 ≤ N(R), M(C) ≤ 8)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int R, C;
int pan[8][8];
int backup[8][8];
bool visited[8][8];

int ans = -1 * 0x7fffffff;

queue<pair<int, int> > q;
vector<pair<int, int> > vs;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

void bfs(){
	
	for(int i = 0 ; i < vs.size() ; ++i){
		q.push(vs[i]);
		visited[vs[i].first][vs[i].second] = true;
	}
	
	
	while(!q.empty()){
		
		int cur_r = q.front().first;	int cur_c = q.front().second;	q.pop();
		backup[cur_r][cur_c] = 2;
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || visited[next_r][next_c]
			|| backup[next_r][next_c] != 0)	continue;
			visited[next_r][next_c] = true;
			
			q.push(make_pair(next_r, next_c));
		}
	}
	
}

void dfs(int start_r, int start_c, int cnt){
	
	if(cnt == 3){
		
		copy(&pan[0][0], &pan[0][0] + (8 * 8), &backup[0][0]);
		memset(visited, false, sizeof(visited));
		bfs();
		
		int tmp_sum = 0;
		
		for(int i = 0 ; i < R ; ++i){
			for(int j =0 ; j < C ; ++j){
				if(backup[i][j] == 0)	++tmp_sum;
			}
		}
		
		ans = max(ans, tmp_sum);
		
		return;
	}
	
	
	for(int i = start_r ; i < R ; ++i){
		for(int j = start_c ; j < C ; ++j){
			
			if(pan[i][j] == 0){
				pan[i][j] = 1;
				dfs(i, j, cnt+1);
				pan[i][j] = 0;
			}
			
		}
		start_c = 0;
	}
	
}

int main(){
	scanf("%d %d", &R, &C);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j =0 ; j < C ; ++j){
			scanf("%d", &pan[i][j]);
			if(pan[i][j] == 2)		vs.push_back(make_pair(i, j));
		}
	}
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			if(pan[i][j] == 0){
				pan[i][j] = 1;
				dfs(i, j, 1);
				pan[i][j] = 0;
			}
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
