// 1 <=  n <= 500
// 1 <= pan[i][j] <= 1,000,000

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int pan[500][500];
int cache[500][500];

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

int mmax = -1;

int dfs(int start_r, int start_c){
	
	int& ret = cache[start_r][start_c];
	if(ret != -1)	return ret;
	
	int cur_value = pan[start_r][start_c];
	
	int tmp_max = 0;
	
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = start_r + dr[dir];	int next_c = start_c + dc[dir];
		int next_value = pan[next_r][next_c];
		
		if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N
		|| !(cur_value < next_value))	continue;
		
		tmp_max = max(tmp_max, dfs(next_r, next_c) + 1);
	}
	
	return ret = tmp_max;
}

void solve(){
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			mmax = max(mmax, dfs(i, j));
		}
	}
	
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	
	solve();
	
//	for(int i = 0 ; i < N ; ++i){
//		for(int j = 0 ; j < N ; ++j){
//			printf("%d ", cache[i][j]);
//		}
//		printf("\n");
//	}	
//	printf("\n");
	
	// OUTPUT
	// 판다가 최대한 살 수 있는 일수(K)를 출력
	printf("%d", mmax+1);
	
	return 0;
}
