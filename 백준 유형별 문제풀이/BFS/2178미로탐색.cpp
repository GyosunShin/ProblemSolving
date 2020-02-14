//N, M(2 ¡Â N, M ¡Â 100)
#include <stdio.h>
#include <queue>

using namespace std;

struct INFO{
	int r, c, len;
};

int N, M;
int map[100][100];
int visited[100][100];

int ans;

queue<INFO> q;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

void bfs(){
	
	while(!q.empty()){
		
		INFO cur = q.front();	q.pop();
//		printf("CUR_R : %d / CUR_C : %d\n", cur.r, cur.c);
		if(cur.r == N-1 && cur.c == M-1){
			ans = cur.len;
			break;
		}
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			INFO next;
			int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];	int next_len = cur.len + 1;
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= M)	continue;
			if(map[next_r][next_c] == 1 && visited[next_r][next_c] == 0){
				visited[next_r][next_c] = 1;
				next.r = next_r;	next.c = next_c;	next.len = next_len;
				q.push(next);
			}
		}
		
	}
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			scanf("%1d", &map[i][j]);
		}
	}
	//#################################
	
	if(map[0][0] == 1){
		INFO start;
		start.r = 0;	start.c = 0;	start.len = 1;
		q.push(start);
		visited[start.r][start.c] = 1;
	}
	else	printf("FUCK YOU\n");
	
	bfs();
	printf("%d", ans);
	return 0;
}
