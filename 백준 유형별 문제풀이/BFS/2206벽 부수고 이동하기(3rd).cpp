// N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)

// 벽을 한 개 까지 부수고 이동하여도 된다.

// 최단 거리를 출력한다. 불가능할 때는 -1을 출력
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int R, C;
int pan[1000][1000];
bool visited[1000][1000][2];

// ( (sofar, use?) (r, c) )
queue<pair<pair<int, int>, pair<int, int>>> q;

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

int solve(){
	
	visited[0][0][0] = true;
	q.push(make_pair(make_pair(1,0), make_pair(0,0)));
	
	while(!q.empty()){
		int sofar = q.front().first.first;
		int use = q.front().first.second;
		int cur_r = q.front().second.first;
		int cur_c = q.front().second.second;
		q.pop();
		
		if(cur_r == R-1 && cur_c == C-1){
			return sofar;
		}
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];
			int next_c = cur_c + dc[dir];
			int next_sofar = sofar + 1;
			int next_use = use;
			
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C)	continue;
			
			if(use == 0 && pan[next_r][next_c] == 1)	next_use++;
			else if(use == 1 && pan[next_r][next_c] == 1)	continue;
			
			if(visited[next_r][next_c][next_use])	continue;
			visited[next_r][next_c][next_use] = true;
			q.push(make_pair(make_pair(next_sofar, next_use), make_pair(next_r, next_c)));
		}	
	}
	
	return -1;
}

int main(){
	scanf("%d %d", &R, &C);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%1d", &pan[i][j]);
		}
	}
	
	int ret = solve();
	
	printf("%d", ret);
	
	return 0;
}
