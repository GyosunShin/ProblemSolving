// ���� ũ�� N�� ���� ũ�� M�� �־�����. (3 �� N, M �� 8)
// 0�� �� ĭ, 1�� ��, 2�� ���̷���(2 <= Virus <= 10)

// INPUT
// 7 7
// 2 0 0 0 1 1 0
// 0 0 1 0 1 2 0
// 0 1 1 0 1 0 0
// 0 1 0 0 0 0 0
// 0 0 0 0 0 1 1
// 0 1 0 0 0 0 0
// 0 1 0 0 0 0 0

// OUTPUT : ù° �ٿ� ���� �� �ִ� ���� ������ �ִ� ũ�⸦ ����Ѵ�.

#include <stdio.h>
#include <queue>

using namespace std;

int N, M;
int map[8][8];

int ans = -1 * 0x7fffffff;

int dr[] = {-1, 1, 0, 0};  // �� �� �� �� 
int dc[] = {0, 0, -1, 1};



void bfs(){  
	int copy[8][8];
	int visited[8][8] = { 0, };
	queue<pair<int, int> > q;
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			copy[i][j] = map[i][j];
			if(map[i][j] == 2){
				q.push(pair<int, int>(i, j));
				visited[i][j] = 1;
			}	
		}
	}
	
	while(!q.empty()){
		int cur_r = q.front().first;	int cur_c = q.front().second;
		q.pop();
//		copy[cur_r][cur_c] = 2;
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir]; 
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= M)	continue;
			if(copy[next_r][next_c] == 0 && visited[next_r][next_c] == 0){
				copy[next_r][next_c] = 2;
				visited[next_r][next_c] = 1;
				q.push(pair<int, int>(next_r, next_c));
			}
		}
	}
	// ������� ���� �Ϸ�
	
	 
	int tmp_cnt = 0;
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){	
			if(copy[i][j] == 0)	++tmp_cnt;
		}
	}
	
	if(tmp_cnt > ans)	ans = tmp_cnt;		
}

void dfs(int count, int r, int c){
	if(count == 3){
		// TODO : Virus �۶߸���(BFS) --> 0 ���� count! 
		bfs();
		return; 
	}
	
	for(int i = r ; i < N ; ++i){
		for(int j = c ; j < M ; ++j){
			if(map[i][j] == 0){
				map[i][j] = 1;		
				dfs(count + 1, i, j);
				map[i][j] = 0;
			}
		}
		c = 0;
	}
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	//#################################
	
	// Ǯ�̹�� : DFS!
	 
	dfs(0, 0, 0);  // param : count, r, c
	printf("%d", ans);
	return 0;
}
