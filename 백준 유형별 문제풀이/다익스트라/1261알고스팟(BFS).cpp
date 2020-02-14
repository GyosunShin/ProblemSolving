// 현재 (1, 1)에 있는 알고스팟 운영진이 (N, M)으로 이동하려면 벽을 최소 몇 개 부수어야 하는지 구하는 프로그램을 작성하시오.

// 가로 크기 M, 세로 크기 N (1 ≤ N, M ≤ 100)
// (0 : 빈방) (1 : 벽)

#include <stdio.h> 
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int R,C;
int map[100][100];
bool visited[100][100];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int bfs(){
	
	visited[0][0] = true;
	pq.push(make_pair(0, make_pair(0,0)));
	
	while(!pq.empty()){
		int cur_r = pq.top().second.first;
		int cur_c = pq.top().second.second;
		int cnt = pq.top().first;
		pq.pop();
		printf("%d %d // %d\n", cur_r, cur_c, cnt);
		
		if(cur_r == (R-1) && cur_c == (C-1)){
			return cnt;
		}
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];	int next_cnt = cnt;
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || visited[next_r][next_c])	continue;
			visited[next_r][next_c] = true;
			if(map[next_r][next_c] == 1){
				next_cnt++;
			}
			pq.push(make_pair(next_cnt, make_pair(next_r, next_c)));
		}	
	}
}

int main(){
	
	scanf("%d %d", &C, &R);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%1d", &map[i][j]);		
		}
	}
	
	int ans = bfs();
	
	printf("%d", ans);
	return 0;
}
