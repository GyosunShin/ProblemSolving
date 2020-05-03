// (0 : 빈칸) (1: 벽) (2: 바이러스)

// N(4 ≤ N ≤ 50)
// M(1 ≤ M ≤ 10)

#include <cstdio> 
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

int pan[50][50];
int backup[50][50];
bool visited[50][50];

vector<pair<int, int>> vs;
vector<int> picked;

int ans = 0x7fffffff;

queue<pair<int, pair<int, int>>> q;

int bfs(){
	
	int max_time = 0;
	
	memset(visited, false, sizeof(visited));
	while(!q.empty())	q.pop();
	
	for(int i = 0 ; i < picked.size() ; ++i){
		int r = vs[picked[i]].first;	int c = vs[picked[i]].second;
		q.push(make_pair(0, make_pair(r, c)));
		visited[r][c] = true;
	}
	
	while(!q.empty()){
		
		int cur_r = q.front().second.first;	int cur_c = q.front().second.second;
		int cur_time = q.front().first;
		q.pop();
		
		if(pan[cur_r][cur_c] != 2)	max_time = max(max_time, cur_time);
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			int next_time = cur_time + 1;
			
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N
			|| visited[next_r][next_c] || backup[next_r][next_c] == -1)	continue;
			
			visited[next_r][next_c] = true;
			backup[next_r][next_c] = -1;
			q.push(make_pair(next_time, make_pair(next_r, next_c)));
		}
		
	}
		
	return max_time;
}

int check(){
	
	for(int i = 0 ; i < 50 ; ++i){
		for(int j = 0 ; j < 50 ; ++j){
			backup[i][j] = pan[i][j];
		}
	}
	
	int ret = bfs();
//	printf("RET : %d\n", ret);
//	for(int i = 0 ; i < N ; ++i){
//		for(int j = 0 ; j < N ; ++j){
//			printf("%d ", backup[i][j]);
//		}
//		printf("\n");
//	}	
//	printf("\n");
	
	int cnt = 0;
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(backup[i][j] == 0)	cnt++;
		}
	}	
	
	if(cnt > 0)	return 0x7fffffff;
	return ret;
	
}

void dfs(int start){
	
	if((int)picked.size() == M){
		
//		for(int i = 0 ; i < picked.size() ; ++i)	printf("%d ", picked[i]);
//		printf("\n");
		
		int ret = check();
		ans = min(ans, ret);
		
		return;
	}
	
	for(int i = start ; i < (int)vs.size() ; ++i){
		picked.push_back(i);
		dfs(i+1);
		picked.pop_back();
	}
	
}

int main(){
	scanf("%d %d", &N, &M);

	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &pan[i][j]);
			if(pan[i][j] == 2)	vs.push_back(make_pair(i, j));
			if(pan[i][j] == 1)	pan[i][j] = -1;
		}
	}
	
	dfs(0);

	// OUTPUT 
	// 연구소의 모든 빈 칸에 바이러스가 있게 되는 최소 시간을 출력한다. 
	// 바이러스를 어떻게 놓아도 모든 빈 칸에 바이러스를 퍼뜨릴 수 없는 경우에는 -1을 출력한다.
	if(ans == 0x7fffffff)	ans = -1;
	printf("%d", ans);

	return 0;
}

