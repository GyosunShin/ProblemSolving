// INPUT
// (4 ≤ N ≤ 20)
// 1 <= 디저트 나타내는 수 <= 100 
 
// OUTPUT
// 디저트를 가장 많이 먹을 수 있는 경로를 찾고, 그 때의 디저트 수를 정답으로 출력
// 만약, 디저트를 먹을 수 없는 경우 -1을 출력한다.

#include <cstdio> 
#include <algorithm>

using namespace std;

int T, N;
int pan[20][20];
bool visited[101];
int global_r, global_c;

const int dr[] = {1,1,-1,-1};
const int dc[] = {1,-1,-1,1};

int dfs(int r, int c, int dir){
//	printf("[%d / %d] %d\n", r, c, dir);
	
	if(r == global_r && c == global_c && dir != 0){
		return 0;
	}
	
	int mmax = -1 * 0x7fffffff;
	visited[pan[r][c]] = true;
	
	if(r == global_r && c == global_c && dir == 0){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		if(visited[pan[next_r][next_c]]){
			visited[pan[r][c]] = false;
			return -1 * 0x7fffffff;	
		}
		mmax = max(mmax, dfs(next_r, next_c, dir)+1);
	}
	else{
		for(int d = 0 ; d < 2 ; ++d){
			if(d == 0){	
				int next_r = r + dr[dir];	int next_c = c + dc[dir];
				
				if(dir == 3 && next_r == global_r && next_c == global_c){
					visited[pan[r][c]] = false;
					return 1;
				}
				
				if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N
				|| visited[pan[next_r][next_c]])	continue;
				mmax = max(mmax, dfs(next_r, next_c, dir)+1);
			}
			else if(d == 1 && dir < 3){
				int next_r = r + dr[dir+1];	int next_c = c + dc[dir+1];
				
				if(dir == 2 && next_r == global_r && next_c == global_c){
					visited[pan[r][c]] = false;
					return 1;
				}
				
				if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N
				|| visited[pan[next_r][next_c]])	continue;
				mmax = max(mmax, dfs(next_r, next_c, dir+1)+1);
			}
		}
	}
	visited[pan[r][c]] = false;
	return mmax;
}

int check(int start_r, int start_c){
	global_r = start_r;	global_c = start_c;
	return dfs(start_r, start_c, 0);
}

int solve(){
	int ret = -1;
	
	for(int i = 0 ; i < N-2 ; ++i){
		for(int j = 1 ; j < N-1 ; ++j){
			int tmp = check(i,j);
//			printf("(%d / %d) %d\n", i,j,tmp);
			ret = max(ret, tmp);
		}
	}
	
	return ret;
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		scanf("%d", &N);	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &pan[i][j]);			
			}
		}
		
		int ans = solve();
		if(ans <= 0)	ans = -1;
		
		printf("#%d %d\n", z, ans);
	}
	
	
	return 0;
}
