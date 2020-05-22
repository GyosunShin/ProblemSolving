// N(1 ≤ N(R) ≤ 1,000), M(1 ≤ M(C) ≤ 1,000)

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO{
	int r, c, dist, sofar;
};

int R, C;
int pan[1000][1000];
bool visited[1000][1000][2];

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

queue<INFO> q;

int solve(){
	
	visited[0][0][0] = true;
	INFO start = {0,0,1,0};
	q.push(start);
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();	
		
		if(cur.r == R-1 && cur.c == C-1)	return cur.dist;
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
			int next_dist = cur.dist + 1;	int next_sofar = cur.sofar;
			
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C)	continue;
			
			if(cur.sofar == 1 && pan[next_r][next_c] == 1)	continue;
			if(cur.sofar == 0 && pan[next_r][next_c] == 1)	next_sofar++;
			
			if(visited[next_r][next_c][next_sofar])	continue;
			
			visited[next_r][next_c][next_sofar] = true;
			INFO next = {next_r, next_c, next_dist, next_sofar};
			q.push(next);
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
	
	// OUTPUT
	// 첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.
	printf("%d", ret);
	
	return 0;
}
