// 운영 비용 = K * K + (K - 1) * (K - 1)

// (5 ≤ N ≤ 20)
// (1 ≤ M ≤ 10)
// (1 : 집) (0 : 빈칸)

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO{
	int r, c, dis;
};

int T, N, M;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int map[20][20];
bool visited[20][20];
int exps[40];

int ans = -1;

int bfs(int start_r, int start_c){
	int cnt = 0;
	
	INFO start;
	start.r = start_r;	start.c = start_c;	start.dis = 1;
	
	queue<INFO> q;
	visited[start_r][start_c] = true;
	q.push(start);
	
	int flag_cnt = 1;
	
	int last_dis;
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		int cur_r = cur.r;	int cur_c = cur.c;	int cur_dis = cur.dis;
		last_dis = cur_dis;
		
		if(cur_dis > 1 && flag_cnt != cur_dis){
			
			int diff = exps[cur_dis-1] - (cnt * M);	
			
			if(diff <= 0){	// 손해 안보는 경우 
				ans = max(ans, cnt);
			}			
			
			flag_cnt = cur_dis;
			
		}
		
		if(map[cur_r][cur_c] == 1)	++cnt;
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];	int next_dis = cur_dis + 1;
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N || visited[next_r][next_c])	continue;
			visited[next_r][next_c] = true;
			INFO next;	next.r = next_r;	next.c = next_c;	next.dis = next_dis;
			q.push(next);
		}
	}
	
	
	int diff = exps[last_dis] - (cnt * M);	

	if(diff <= 0){	// 손해 안보는 경우 
		ans = max(ans, cnt);
	}			

	
}

int main(){
	for(int i = 1 ; i < sizeof(exps) / sizeof(int) ; ++i){
		exps[i] = (i * i) + ((i - 1) * (i - 1));
	}
	
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		ans = -1;
		scanf("%d %d", &N, &M);	
		
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &map[i][j]);			
			}
		}
		
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				memset(visited, false, sizeof(visited));
				bfs(i, j);
			}
		}
		
		// 출력해야 할 정답은 손해를 보지 않으면서 홈방범 서비스를 가장 많은 집들에 제공하는 
		// 서비스 영역을 찾았을 때, 그 때의 서비스를 제공 받는 집들의 수이다
		printf("#%d %d\n", z, ans);
	}

}
