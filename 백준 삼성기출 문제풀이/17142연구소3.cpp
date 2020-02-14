//  연구소의 크기 N(4 ≤ N ≤ 50), 놓을 수 있는 바이러스의 개수 M(1 ≤ M ≤ 10) 
//  0은 빈 칸, 1은 벽, 2(M<=  &&  <= 10)는 바이러스
//  
//  OUTPUT : 연구소의 모든 빈 칸에 바이러스가 있게 되는 최소 시간을 출력한다. 
//  바이러스를 어떻게 놓아도 모든 빈 칸에 바이러스를 퍼뜨릴 수 없는 경우에는 -1을 출력한다.

#include <stdio.h>
#include <vector>
#include <queue> 

using namespace std;

struct INFO{
	int r, c, len;
};

int N, M;
int map[50][50];

int ans = 0x7fffffff;

vector<pair<int, int> > virus;
vector<pair<int, int> > virus_picked;

int dr[] = {-1, 1, 0, 0};  // 상 하 좌 우 
int dc[] = {0, 0, -1, 1};
int blank;

int flag = 0;

void bfs(){
	int max_time = -1 * 0x7fffffff;
	int tmp_cnt = 0; 
	int visited[50][50] = { 0, };
	// 일단 큐 생성하고 큐에 virus_picked의 좌표들을 넣어준다.
	queue<INFO> q;
	for(int i = 0 ; i < virus_picked.size() ; ++i){
		INFO tmp;
		tmp.r = virus_picked[i].first;	tmp.c = virus_picked[i].second;	tmp.len = 0;
		q.push(tmp);
		visited[tmp.r][tmp.c] = 1;
		if(max_time < tmp.len)	max_time = tmp.len;
	}
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
//		printf("CUR_R : %d / CUR_C : %d\n", cur.r, cur.c);
		if(map[cur.r][cur.c] != 2)	++tmp_cnt;
		if(max_time < cur.len)	max_time = cur.len;
		if(tmp_cnt == blank){  // 다 채웠다면! 
//			printf("HIT! --> tmp_cnt : %d\n", tmp_cnt);
//			printf("FILL COMPLETE! : %d\n", max_time);
			flag = 1;
			if(ans > max_time){
				ans = max_time;
			}
			break; 
		}
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			INFO next;
			next.r = cur.r + dr[dir];	next.c = cur.c + dc[dir];	next.len = cur.len + 1;
//			printf("NEXT_R : %d / NEXT_C : %d\n", next.r, next.c);
			
			// 범위 벗어나거나 (or) 이미 다른 노드로부터 체크되었다던가 (or) 벽이라면 --> 넘어간다. 
			if(0 > next.r || next.r >= N || 0 > next.c || next.c >= N || visited[next.r][next.c] != 0 || map[next.r][next.c] == 1){
				continue;
			}
			
			// 빈칸인 경우! 
			visited[next.r][next.c] = 1;
			q.push(next);	
		}
		
	} // The End of 'while(!q.empty())'
//	printf("\n\n");
	
}

void dfs(int cnt){
	if(virus_picked.size() == M){
		// TODO : BFS돌려서 시간 측정하고 ans보다 작으면 ans값 갱신해준다.
//		for(int i = 0 ; i < virus_picked.size() ; ++i){
//			printf("(%d, %d) ", virus_picked[i].first, virus_picked[i].second);
//		}
//		printf("\n");
		bfs();
		
		return;
	}
	
	for(int i = cnt ; i < virus.size() ; ++i){
		virus_picked.push_back(virus[i]);
		dfs(i + 1);
		virus_picked.pop_back();
	}
	
}


int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 2)	virus.push_back(pair<int, int>(i, j));
			if(map[i][j] == 0)	++blank;
		}
	}
//	printf("BLANK : %d\n\n", blank);
	//#################################
	
	
	// 1st) DFS를 통해 virus vector에 존재하는 것중 m개를 뽑는당. 
	dfs(0);
	
	if(!flag)	ans = -1;
	printf("%d", ans);
	return 0;	
}
