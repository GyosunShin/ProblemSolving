//(3 ≤ N, M ≤ 8)  N : 세로 / M : 가로
//0 : 빈칸(3이상) / 1 : 벽(2이상 10이하) / 2 : 바이러스
//
//출력 : 얻을 수 있는 안전 영역의 최대 크기 
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int map[8][8];

int ans; // 가장 큰 안전영역의 최대 크기 

// 상 하 좌 우 
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs(){
	queue<int> q;
	int backup[8][8]; // 필요한 이유 : BFS를 통해 바이러스를 늘려갈 것이므로! 
	int visited[8][8] = { 0, };
	
	// 일단 바이러스들을 퍼뜨려야 한다.  BY) BFS!!!
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			backup[i][j] = map[i][j];
			if(backup[i][j] == 2){  // 이미 'Virus'이 있다면 visited에 표시해두자! 
				visited[i][j] = 1;
				q.push(i*10 + j);
			}
		}
	}
	// 그래서 여기까지는 원래 map에 존재하였던 Virus을 queue에 집어넣은 셈이다.
	// 벽의 순서는 어차피 필요없고 가능한한 바이러스를 늘려가기만 하면 되는 것이므로 미리 채워 넣어도 No상관
	
	while(!q.empty()){
		int cur = q.front(); q.pop();
		int cur_r = cur / 10;
		int cur_c = cur % 10;
		backup[cur_r][cur_c] = 2;
		for(int i = 0 ; i < 4 ; ++i){
			int next_r = cur_r + dr[i];		
			int next_c = cur_c + dc[i];
			// 범위에서 벗어날 경우 고려
			if(next_r < 0 || next_r >= N || next_c < 0 || next_c >= M)	continue;
			
			if(backup[next_r][next_c] == 0 && visited[next_r][next_c] != 1){  // 비어있다면 바이러스 증식! 
				visited[next_r][next_c] = 1;
				int next = next_r * 10 + next_c;
				q.push(next);	 
			}
		}
	}
	// 자! 그래서 여기까지 이제  Virus 증식 완료! 
	
	// 이제... 안전지역 크기 계산 ㄱㄱ!
	int tmp = 0;
	for(int i = 0 ; i < N ; ++i) {
		for(int j = 0 ; j < M ; ++j){
			if(backup[i][j] == 0) tmp++;
		}
	}
	
	if(tmp > ans){
		ans = tmp;
	}
	
	 
	
}

void dfs(int count, int r, int c){  // 일단 map의 모든 공간을 훑으면서 빈칸이라면, 즉 값이 '0'인 지점을 3곳을 무작위로 선정한다. 
	if(count == 3){
		bfs();
		return; 
	}
	
	for(int i = r ; i < N ; ++i){
		for(int j = c ; j < M ; ++j){
			if(map[i][j] == 0){  // 빈칸이라면!!
				map[i][j] = 1;
				dfs(count + 1, i, j);
				map[i][j] = 0;
			}
		}
		// !!!!!!!!!!!
		c = 0;
		// !!!!!!!!!!!		
	}
}


int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0, 0, 0);
	printf("%d", ans);
}
 
