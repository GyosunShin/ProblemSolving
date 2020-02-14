// ��ô��� �̿� 

// ���� ª�� �ٸ� �ϳ��� ���� �� ����� �����ϴ� ����� ã���ÿ�.
// (0 : �ٴ�) (1 : ����)
// N(100������ �ڿ���)

#include <stdio.h> 
#include <queue>

using namespace std;

struct INFO{
	int r, c;	
};

struct SPAN{
	int r, c, len;	
};

queue<INFO>	q;
queue<SPAN> spanning;

int N;
int map[100][100];
int visited[100][100];
int bridge_visited[100][100];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int cnt = 1;
int ans = 0x7fffffff;
int flag = 0x7fffffff;

void bfs(int r, int c){
	
	INFO start;
	start.r = r;	start.c = c;
	q.push(start);
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		map[cur.r][cur.c] = cnt;
		
		SPAN tmp;
		tmp.r = cur.r;	tmp.c = cur.c;	tmp.len = 0;
		spanning.push(tmp);
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
			
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N || visited[next_r][next_c] != 0 || map[next_r][next_c] == 0)	continue;
			visited[next_r][next_c] = 1;
			
			INFO next;
			next.r = next_r;	next.c = next_c;
			q.push(next);
		}	
	}
}

void spaned(){
	
	while(!spanning.empty()){
		
//		for(int i = 0 ; i < N ; ++i){
//			for(int j = 0 ; j < N ; ++j){
//				printf("%d ", map[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
		
		SPAN cur = spanning.front();	spanning.pop();
		if(flag < cur.len)	return;
		int cur_flag = map[cur.r][cur.c];
//		printf("%d\n", cur.len);
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N || map[next_r][next_c] == cur_flag)	continue;
			
			if(map[next_r][next_c] != cur_flag && map[next_r][next_c] != 0){
				int ret = bridge_visited[next_r][next_c] + bridge_visited[cur.r][cur.c];
				if(ret < ans)	ans = ret;
				if(cur.len < flag)	flag = cur.len;
			}
			
			SPAN next;
			next.r = next_r;	next.c = next_c;	next.len = cur.len + 1;
			map[next_r][next_c] = cur_flag;
			bridge_visited[next_r][next_c] = next.len;
			spanning.push(next);
		}
	}
	
}

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);		
		}
	}
	
	// ���� ������ By BFS
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(map[i][j]  == 1 && visited[i][j] == 0){
				bfs(i, j);
				cnt++;
			}
		}
	}
	
//	for(int i = 0 ; i < N ; ++i){
//		for(int j = 0 ; j < N ; ++j){
//			printf("%d ", map[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
	
	// ��ô ��� ���� 
	spaned();
	
	printf("%d", ans);
	
	return 0;
}
