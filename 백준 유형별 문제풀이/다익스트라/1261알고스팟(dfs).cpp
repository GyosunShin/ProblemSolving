// ���� (1, 1)�� �ִ� �˰��� ����� (N, M)���� �̵��Ϸ��� ���� �ּ� �� �� �μ���� �ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

// ���� ũ�� M, ���� ũ�� N (1 �� N, M �� 100)
// (0 : ���) (1 : ��)

#include <stdio.h> 
#include <string.h>
using namespace std;

int R,C;
int map[100][100];
int visited[100][100];
int block[100][100];   // ���±��� ���⿡ ������� ��� ����� �� �μ̴�? 

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
