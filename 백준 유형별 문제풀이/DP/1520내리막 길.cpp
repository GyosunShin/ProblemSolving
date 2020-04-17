// 1 <= R, C <= 500
// 1 <= 각 지점의 높이 <= 10000


#include <cstdio> 
#include <cstring>

int R, C;

int pan[500][500];
int cache[500][500];

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

int dfs(int r, int c){
	
	if(r == R-1 && c == C-1)	return 1;
	
	int& ret = cache[r][c];
	if(ret != -1)	return ret;
	
	int tmp_sum = 0;
	
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C
		|| pan[r][c] <= pan[next_r][next_c])	continue;
		
		tmp_sum += dfs(next_r, next_c);
	}
	
	return ret = tmp_sum;
	
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	scanf("%d %d", &R, &C);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	
	// OUTPUT
	// 첫째 줄에 이동 가능한 경로의 수 H를 출력한다. 모든 입력에 대하여 H는 10억 이하의 음이 아닌 정수이다.
	printf("%d", dfs(0,0));
	
	return 0;
}
