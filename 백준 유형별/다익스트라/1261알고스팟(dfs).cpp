// 현재 (1, 1)에 있는 알고스팟 운영진이 (N, M)으로 이동하려면 벽을 최소 몇 개 부수어야 하는지 구하는 프로그램을 작성하시오.

// 가로 크기 M, 세로 크기 N (1 ≤ N, M ≤ 100)
// (0 : 빈방) (1 : 벽)

#include <stdio.h> 
#include <string.h>
using namespace std;

int R,C;
int map[100][100];
int visited[100][100];
int block[100][100];   // 여태까지 여기에 오기까지 몇개의 블록을 쳐 부셨니? 

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int cnt;

void dfs(int cur_r, int cur_c){
//	printf("CUR_R : %d / CUR_C : %d / CNT : %d\n", cur_r, cur_c, cnt);
	
	int& ret = block[cur_r][cur_c];
	if(ret <= cnt)	return;
	else	ret = cnt;
	
	if(cur_r == R-1 && cur_c == C-1)	return;
	
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
		if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || visited[next_r][next_c])	continue;
		visited[next_r][next_c] = 1;
		if(map[next_r][next_c] == 1){
			++cnt;
			dfs(next_r, next_c);
		}
		else{
			dfs(next_r, next_c);
		}
		visited[next_r][next_c] = 0;
		if(map[next_r][next_c] == 1)	--cnt;	
	}
}


int main(){
	
	scanf("%d %d", &C, &R);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%1d", &map[i][j]);
			block[i][j] = 0x7fffffff;		
		}
	}
	visited[0][0] = 1;
	dfs(0, 0);	
	
	printf("%d", block[R-1][C-1]);
	
	return 0;
}
