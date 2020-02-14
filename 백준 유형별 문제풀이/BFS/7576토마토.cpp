// 2 ≤ M(가로),N(세로) ≤ 1,000 이다 
// 1 : 익은 토마토 / 0 : 안 익은 토마토 / -1 : 빈칸 
// 
// OUTPUT 
// 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 
// 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 
// 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.

#include <stdio.h>
#include <queue>

using namespace std;

struct INFO{
	int r, c, time;
};

int M, N;
int map[1000][1000];
int visited[1000][1000];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

queue<INFO> q;

int ans;

void bfs(){
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		ans = cur.time;
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= M || map[next_r][next_c] == -1 || visited[next_r][next_c] != 0)	continue;
			visited[next_r][next_c] = 1;
			map[next_r][next_c] = 1;
			INFO next;
			next.r = next_r;	next.c = next_c;	next.time = cur.time + 1;
			q.push(next);
		}
	}
	// 전염 완료!
}

int main(){
	int tmp_ans = 0;
	scanf("%d %d", &M, &N);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 0)	++tmp_ans;
			else if(map[i][j] == 1){  // 익은 토마토인 경우 
				INFO tmp;
				tmp.r = i;	tmp.c = j; tmp.time = 0;
				q.push(tmp);
				visited[i][j] = 1;
			}
		}
	}
	//#####################################
	
	if(tmp_ans == 0){ // 처음부터 다 익은 경우 
		printf("0");
		return 0;
	}
	
	
	bfs();
	
	int tmp_cnt = 0;
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			if(map[i][j] == 0)	++tmp_cnt;
		}
	}
	if(tmp_cnt != 0){
		printf("-1");	
		return 0;
	}
	
	printf("%d", ans);
	return 0;
	
}

