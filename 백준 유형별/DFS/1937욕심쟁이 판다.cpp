// 대나무 숲의 크기 n(1 ≤ n ≤ 500)
// 대나무의 양 <= 1,000,000

// OUTPUT : 첫째 줄에는 판다가 최대한 살 수 있는 일수(K)를 출력한다.

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
int map[500][500];
int cache[500][500];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int dfs(int r, int c){
	int& ret = cache[r][c];
	if(ret != -1)	return ret;
	
	int tmp = 0;
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = r + dr[dir];
		int next_c = c + dc[dir];
		if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N || map[r][c] >= map[next_r][next_c])	continue;
		tmp = max(tmp, dfs(next_r, next_c) + 1);
	} 
	if(tmp == 0)	return ret = 1;
	return ret = tmp;
}

int main(){
	int ans = -1 * 0x7fffffff;
	
	memset(cache, -1, sizeof(cache));
	
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(cache[i][j] == -1){
				int tmp = dfs(i,j);
				if(ans < tmp)	ans = tmp;
			}
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
