// N, M(2 ¡Â N, M ¡Â 100)

#include <stdio.h>
#include <queue>

using namespace std;

struct INFO{
	int r, c, time;
};

queue<INFO> q;

int R, C;
int map[100][100];
int visited[100][100];

int ans;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

void bfs(){
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
//		printf("%d / %d / %d\n", cur.r , cur.c, cur.time);
		if(cur.r == (R-1) && cur.c == (C-1)){
			ans = cur.time;
			break;
		}
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
			
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || visited[next_r][next_c] == 1 || map[next_r][next_c] == 0){
				continue;
			}
			visited[next_r][next_c] = 1;
			INFO next;
			next.r = next_r;	next.c = next_c;	next.time = cur.time + 1;
			q.push(next);
		}
		
	}
	
}

int main(){
	scanf("%d %d", &R, &C);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%1d", &map[i][j]);		
		}
	}
	
	
	INFO start;
	start.r = 0;	start.c = 0;	start.time = 1;
	q.push(start);
	
	bfs();
	
	printf("%d", ans);
	
	return 0;
}
