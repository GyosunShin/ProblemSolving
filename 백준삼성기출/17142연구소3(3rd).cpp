// 첫째 줄에 연구소의 크기 N(4 ≤ N ≤ 50) / 놓을 수 있는 바이러스의 개수 M(1 ≤ M ≤ 10)이 주어진다.
// 0은 빈 칸 / 1은 벽 / 2는 바이러스(M <=   <= 10)

// OUTPUT : 연구소의 모든 빈 칸에 바이러스가 있게 되는 최소 시간을 출력한다. 
// 바이러스를 어떻게 놓아도 모든 빈 칸에 바이러스를 퍼뜨릴 수 없는 경우에는 -1을 출력한다.

#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

struct INFO{
	int r,c,time;
};

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int N, M;

int map[50][50];
//int visited[50][50];

int blanks;

vector<pair<int, int> > v;
vector<pair<int, int> > picked;

int ans = 0x7fffffff;

bool flag = false;

void bfs(){
	int max_time = -1 * 0x7fffffff;
	int tri = 0;
	int visited[50][50] = { 0, };
	queue<INFO> q;
	for(int i = 0 ; i < picked.size() ; ++i){
		INFO tmp;
		tmp.r = picked[i].first;	tmp.c = picked[i].second;	tmp.time = 0;
		q.push(tmp);
		visited[tmp.r][tmp.c] = 1;
		if(max_time < tmp.time)	max_time = tmp.time;
	}
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		if(max_time < cur.time)	max_time = cur.time;
		if(map[cur.r][cur.c] != 2)	++tri;
			
		if(tri == blanks){
			flag = true;
			if(ans > max_time)	ans = max_time;
			break;
		}				
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur.r + dr[dir];
			int next_c = cur.c + dc[dir];
			int next_time = cur.time + 1;
			
			if(visited[next_r][next_c] != 0 || map[next_r][next_c] == 1 || 0 > next_r || next_r >= N || 0 > next_c || next_c >= N)	continue;
			INFO next;	next.r = next_r;	next.c = next_c;	next.time = next_time;
			visited[next_r][next_c] = 1;
			q.push(next);
			
		}	
	}
	
	
}

void dfs(int start){
	if(picked.size() == M){
		bfs();
		return;
	}	
	
	for(int i = start ; i < v.size() ; ++i){
		picked.push_back(v[i]);
		dfs(i + 1);
		picked.pop_back();
	}
	
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 0)	++blanks;
			else if(map[i][j] == 2){
				v.push_back(pair<int, int>(i,j));
			}
		}
	}
	// #####################################
	
	dfs(0);
	if(!flag)	printf("-1");
	else	printf("%d", ans);
	
	return 0;
}
