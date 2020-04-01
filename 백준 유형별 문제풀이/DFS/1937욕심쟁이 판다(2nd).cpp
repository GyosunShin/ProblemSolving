// (1 ≤ n ≤ 500)
//  대나무의 양 <= 1,000,000

// OUTPUT : 첫째 줄에는 판다가 최대한 살 수 있는 일수(K)를 출력한다.

#include <cstdio> 
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int pan[500][500];
int cache[500][500];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int ans = -1;

int dfs(int start_r, int start_c){
	
	int& ret = cache[start_r][start_c];
	if(ret != -1)	return ret;
	
	int mmax = 0;
	
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = start_r + dr[dir];	int next_c = start_c + dc[dir];
		
		if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N || 
		pan[next_r][next_c] <= pan[start_r][start_c])	continue;
		
		mmax = max(mmax, dfs(next_r, next_c) + 1);
	}
	
	return ret = mmax;
	
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j)	scanf("%d", &pan[i][j]);
	}
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			ans = max(ans, dfs(i, j) + 1);
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
