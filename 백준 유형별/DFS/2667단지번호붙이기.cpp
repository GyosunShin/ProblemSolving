// 5≤N≤25
// INPUT
//7
//0110100     3
//0110101	  7
//1110101     8
//0000111     9
//0100000     그니깐 오름차순으로 
//0111110
//0111000

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct INFO{
	int r, c;
};

int N;
int map[25][25];
int visited[25][25];

int flag = 0; 

queue<INFO> q;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

vector<int> ans_v;

int tmp_cnt = 0;

void dfs(int r, int c){
//	printf("DFS) R : %d / C : %d\n", r, c);
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N)	continue;
		if(visited[next_r][next_c] == 0 && map[next_r][next_c] == 1){
			visited[next_r][next_c] = 1;
			++tmp_cnt;
			dfs(next_r, next_c);
		}
	}
	
}

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%1d", &map[i][j]);
			if(map[i][j] == 1){
				INFO tmp;
				tmp.r = i;	tmp.c = j;
				q.push(tmp);
			}
		}
	}
	//##################################
	
	int	ans_cnt = 0;
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		if(visited[cur.r][cur.c] == 1){
			continue;
		}
		visited[cur.r][cur.c] = 1;
		tmp_cnt = 1;
		++ans_cnt;
		dfs(cur.r, cur.c);
		ans_v.push_back(tmp_cnt);
	}
	printf("%d\n", ans_cnt);
	sort(ans_v.begin(), ans_v.end());
	for(int i = 0 ; i < ans_v.size() ; ++i)	printf("%d\n", ans_v[i]);
	
	return 0;
}
