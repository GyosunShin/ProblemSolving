// N(4 �� N �� 50), ���̷����� ���� M(1 �� M �� 10)

// OUTPUT : �������� ���°� �־����� ��, ��� �� ĭ�� ���̷����� �۶߸��� �ּ� �ð��� ���غ���.
// * ��� �� ĭ�� ���̷����� �۶߸� �� ���� ��쿡�� -1�� ����Ѵ�. *

#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

struct INFO{
	int r, c, time;
};

int N, M;
int map[50][50];
int visited[50][50];

int blanks;

int ans = 0x7fffffff;

vector<INFO> v;
vector<int> picked;

queue<INFO> q;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

bool flag = false;

void bfs(){
	int tmp_max = 0;
	int cnt = 0;
	
	// (0 : �� ĭ), (1 : ��), (2  : ���̷���)
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N || map[next_r][next_c] == 1 || visited[next_r][next_c] != 0){
				continue;
			}
			INFO next;	next.r = next_r;	next.c = next_c;	next.time = cur.time + 1;
			q.push(next);
			++cnt;
			if(map[next_r][next_c] == 2)	--cnt;
			visited[next_r][next_c] = 1;
//			printf("next_r : %d / next_c : %d / next_time : %d\n", next_r, next_c, next.time);
			if(tmp_max < next.time)	tmp_max = next.time;
		}
	}
	
	
//	printf("BLANKS : %d / CNT : %d / tmp_max : %d\n", blanks, cnt, tmp_max);
	if(cnt == blanks){
		flag = true;
		if(ans > tmp_max)	ans = tmp_max;
	}
	
}

void dfs(int start){
	if(picked.size() == M){
		memset(visited, 0, sizeof(visited));
		// 2nd) BFS�̿��ؼ� picked�� �̾��� index�� �̿��ؼ� ���̷��� �۶߷� ���� 
		for(int i = 0 ; i < picked.size() ; ++i){
			q.push(v[picked[i]]);
			visited[v[picked[i]].r][v[picked[i]].c] = 1;
		}	
		
		bfs();
	}
	
	for(int i = start ; i < v.size() ; ++i){
		picked.push_back(i);
		dfs(i+1);
		picked.pop_back();
	}
}

int main(){
	memset(visited, 0, sizeof(visited));
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);	// (0 : �� ĭ), (1 : ��), (2 : ���̷���)
			if(map[i][j] == 0)	++blanks;
			else if(map[i][j] == 2){
				INFO tmp;	tmp.r = i;	tmp.c = j;	tmp.time = 0;
				v.push_back(tmp);
			}
		}
	}
	//###################################
	
	// 1st) DFS�̿��ؼ� ���̷��� �߿� m�� �����϶�!
	dfs(0);
	
	if(!flag){
		printf("-1");
		return 0;
	}
	else{
		printf("%d", ans);
		return 0;		
	}
	
			
}
 
