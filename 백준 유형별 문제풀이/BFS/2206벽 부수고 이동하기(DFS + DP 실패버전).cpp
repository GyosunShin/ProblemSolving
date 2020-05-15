// (0 : 이동 가능) (1 : 벽)
// 벽을 한 개 까지 부수고 이동하여도 된다.
//  N(1 ≤ N(R) ≤ 1,000), M(1 ≤ M(C) ≤ 1,000)

// OUTPUT
// 첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int R, C;
int pan[1000][1000];
bool visited[1000][1000];
int cache[1000][1000][2];

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

int dfs(int r, int c, int sofar){
	
	if(r == R-1 && c == C-1){
		return 1;
	}

	int& ret = cache[r][c][sofar];
	if(ret != -1)	return ret;
	
	int mmin = 2000000;
	
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		
		if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C 
		|| visited[next_r][next_c])	continue;
		if(sofar == 1 && pan[next_r][next_c] == 1)	continue;
		if(sofar == 0 && pan[next_r][next_c] == 1){
			visited[next_r][next_c] = true;
			mmin = min(mmin, dfs(next_r, next_c, sofar + 1) + 1);
			visited[next_r][next_c] = false;
			continue;
		}
		visited[next_r][next_c] = true;
		mmin = min(mmin, dfs(next_r, next_c, sofar) + 1);
		visited[next_r][next_c] = false;
	}
	
	return ret = mmin;
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	scanf("%d %d", &R, &C);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%1d", &pan[i][j]);
		}
	}
	
	// OUTPUT
	// 첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.
	visited[0][0] = true;
	int ret = dfs(0,0,0);
	visited[0][0] = false;
	if(ret >= 2000000)	ret = -1;
	
	printf("%d", ret);
	
	return 0;
}
