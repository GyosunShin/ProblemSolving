// 밀 수 있는 방향 :  →, ↘, ↓

// OUTPUT
// 파이프의 한쪽 끝을 (N, N)로 이동시키는 방법의 개수

// 3 ≤ N ≤ 16
// (0 : 빈칸)  (1 : 벽)

#include <cstdio> 
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int pan[16][16];
int cache[16][16][16][16][3];	// (0 : 가로)	(1 : 세로)	(0 : 대각)

const int garoDrA[] = {0, 0};
const int garoDcA[] = {1, 1};
const int garoDrB[] = {0, 1};
const int garoDcB[] = {1, 1};

const int seroDrA[] = {1, 1};
const int seroDcA[] = {0, 0};
const int seroDrB[] = {1, 1};
const int seroDcB[] = {0, 1};

const int diagonalDrA[] = {1, 1, 1};
const int diagonalDcA[] = {1, 1, 1};
const int diagonalDrB[] = {0, 1, 1};
const int diagonalDcB[] = {1, 0, 1};

const int posChangeGaro[] = {0, 2};
const int posChangeSero[] = {1, 2};
const int posChangeDiagonal[] = {0, 1, 2};

bool scopeCheck(int r1, int c1, int r2, int c2){
	if(0 > r1 || r1 >= N || 0 > c1 || c1 >= N
	|| 0 > r2 || r2 >= N || 0 > c2 || c2 >= N)	return false;
	return true;
}

int dfs(int r1, int c1, int r2, int c2, int pos){
	
	if((r1 == N-1 && c1 == N-1) || (r2 == N-1 && c2 == N-1))	return 1;
	
	int& ret = cache[r1][c1][r2][c2][pos];
	if(ret != -1)	return ret;
	
	int sum = 0; 
	// 가능 경우의 수
	// (가로 : 2) (세로 : 2) (대각서 : 3)
	if(pos == 0){		// (가로 : 2)
		for(int dir = 0 ; dir < 2 ; ++dir){
			int next_r1 = r1 + garoDrA[dir];	int next_c1 = c1 + garoDcA[dir];
			int next_r2 = r2 + garoDrB[dir];	int next_c2 = c2 + garoDcB[dir];
			if(!scopeCheck(next_r1, next_c1, next_r2, next_c2))	continue;
			if(dir == 0 && pan[next_r2][next_c2] == 1)	continue;
			else if(dir == 1){
				if(pan[r2][c2+1] == 1 || pan[r2+1][c2+1] == 1 || pan[r2+1][c2] == 1)	continue;
			}
			sum += dfs(next_r1, next_c1, next_r2, next_c2, posChangeGaro[dir]);
		}
	}
	else if(pos == 1){	// (세로 : 2)
		for(int dir = 0 ; dir < 2 ; ++dir){
			int next_r1 = r1 + seroDrA[dir];	int next_c1 = c1 + seroDcA[dir];
			int next_r2 = r2 + seroDrB[dir];	int next_c2 = c2 + seroDcB[dir];
			if(!scopeCheck(next_r1, next_c1, next_r2, next_c2))	continue;
			if(dir == 0 && pan[next_r2][next_c2] == 1)	continue;
			else if(dir == 1){
				if(pan[r2][c2+1] == 1 || pan[r2+1][c2+1] == 1 || pan[r2+1][c2] == 1)	continue;
			}
			sum += dfs(next_r1, next_c1, next_r2, next_c2, posChangeSero[dir]);
		}		
	}
	else if(pos == 2){	// (대각 : 3)
		for(int dir = 0 ; dir < 3 ; ++dir){
			int next_r1 = r1 + diagonalDrA[dir];	int next_c1 = c1 + diagonalDcA[dir];
			int next_r2 = r2 + diagonalDrB[dir];	int next_c2 = c2 + diagonalDcB[dir];
			if(!scopeCheck(next_r1, next_c1, next_r2, next_c2))	continue;
			if(dir == 0 || dir == 1){
				if(pan[next_r2][next_c2] == 1)	continue;
			}
			else if(dir == 2){
				if(pan[r2][c2+1] == 1 || pan[r2+1][c2+1] == 1 || pan[r2+1][c2] == 1)	continue;
			}
			sum += dfs(next_r1, next_c1, next_r2, next_c2, posChangeDiagonal[dir]);
		}				
	}
	
	return ret = sum;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	
	int ret = dfs(0, 0, 0, 1, 0);
	printf("%d", ret);
	
	return 0;
}
