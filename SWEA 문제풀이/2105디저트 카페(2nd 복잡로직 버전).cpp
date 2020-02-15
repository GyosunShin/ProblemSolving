// 디저트를 가장 많이 먹을 수 있는 경로를 찾고, 그 때의 디저트 수를 정답으로 출력하는 프로그램을 작성하라.
// 만약, 디저트를 먹을 수 없는 경우 -1을 출력한다.

//  (4 ≤ N ≤ 20)
//  1 <= 디저트 종류 <= 100

#include <cstdio>
#include <cstring>

int T, N;
int pan[20][20];

bool cache[101];

const int dr[] = {1, 1, -1, -1};
const int dc[] = {1, -1, -1, 1};

int right, left;

int ans = -1;

void dfs(int start_r, int start_c, int dir, int cnt, int sum){
//	printf("RIGHT : %d / LEFT : %d / START_R : %d / START_C : %d / DIR : %d / CNT : %d / SUM : %d\n",right, left, start_r, start_c, dir, cnt, sum);
	
	if(dir == 0){
		int next_r = start_r + dr[dir];	int next_c = start_c + dc[dir];
		int tmp_r = start_r + dr[dir+1];	int tmp_c = start_c + dc[dir+1];
		if(0 > next_r || next_r >= N-1 || 0 > next_c || next_c >= N){
			if(!cache[pan[tmp_r][tmp_c]]){
				cache[pan[tmp_r][tmp_c]] = true;
				++left;
				dfs(tmp_r, tmp_c, dir+1, cnt+1, sum+pan[tmp_r][tmp_c]);
				left--;
				cache[pan[tmp_r][tmp_c]] = false;
			}
		}
		else{
			if(!cache[pan[tmp_r][tmp_c]] && right > 0){  // 최소한 오른쪽 아래방향으로 1번은 전진해야 방향 바꾸기 가능 
				cache[pan[tmp_r][tmp_c]] = true;
				++left;
				dfs(tmp_r, tmp_c, dir+1, cnt+1, sum+pan[tmp_r][tmp_c]);
				left--;
				cache[pan[tmp_r][tmp_c]] = false;
			}
			if(!cache[pan[next_r][next_c]]){
				cache[pan[next_r][next_c]] = true;
				++right; 
				dfs(next_r, next_c, dir, cnt+1, sum+pan[next_r][next_c]);
				right--;
				cache[pan[next_r][next_c]] = false;
			}
		}	
	}
	
	else if(dir == 1){
		int next_r = start_r + dr[dir];	int next_c = start_c + dc[dir];
		int tmp_r = start_r + dr[dir+1];	int tmp_c = start_c + dc[dir+1];
		if(0 > next_r || next_r >= N || 1 > next_c || next_c >= N){
			if(!cache[pan[tmp_r][tmp_c]]){
				cache[pan[tmp_r][tmp_c]] = true;
				--right;
				dfs(tmp_r, tmp_c, dir+1, cnt+1, sum+pan[tmp_r][tmp_c]);
				right++;
				cache[pan[tmp_r][tmp_c]] = false;
			}
		}
		else{
			if(!cache[pan[tmp_r][tmp_c]]){
				cache[pan[tmp_r][tmp_c]] = true;
				--right;
				dfs(tmp_r, tmp_c, dir+1, cnt+1, sum+pan[tmp_r][tmp_c]);
				right++;
				cache[pan[tmp_r][tmp_c]] = false;
			}
			if(!cache[pan[next_r][next_c]]){
				cache[pan[next_r][next_c]] = true;
				++left; 
				dfs(next_r, next_c, dir, cnt+1, sum+pan[next_r][next_c]);
				left--;
				cache[pan[next_r][next_c]] = false;
			}
		}			
		
	}
	
	else if(dir == 2){
		int next_r = start_r + dr[dir];	int next_c = start_c + dc[dir];
		
		if(right == 0){
			int tmp_r = start_r + dr[dir+1];	int tmp_c = start_c + dc[dir+1];
			if(left == 1){
				--left;
				dfs(tmp_r, tmp_c, dir + 1, cnt+1, sum+pan[tmp_r][tmp_c]);
				left++;
			}
			else{
				if(!cache[pan[tmp_r][tmp_c]]){
					cache[pan[tmp_r][tmp_c]] = true;
					--left; 
					dfs(tmp_r, tmp_c, dir + 1, cnt+1, sum+pan[tmp_r][tmp_c]);
					left++;
					cache[pan[tmp_r][tmp_c]] = false;
				}
			}
		}
		else{
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N){
				return;
			}
			if(!cache[pan[next_r][next_c]]){
				cache[pan[next_r][next_c]] = true;
				--right; 
				dfs(next_r, next_c, dir, cnt+1, sum+pan[next_r][next_c]);
				right++;
				cache[pan[next_r][next_c]] = false;
			}
		}
	}
	
	else if(dir == 3){
		int next_r = start_r + dr[dir];	int next_c = start_c + dc[dir];
		
		if(left == 0){
			int tmp_cnt = cnt - 1;
//			printf("<도달!>MMAX : %d / SUM : %d / CNT : %d\n", mmax, tmp_sum , tmp_cnt);
			if(tmp_cnt > ans){
				ans = tmp_cnt;
//				printf("<정답> TMP_SUM : %d  / TMP_CNT : %d\n", tmp_sum, tmp_cnt);
				return;
			}
		}
		else{
			if(left == 1){
				--left; 
				dfs(next_r, next_c, dir, cnt+1, sum+pan[next_r][next_c]);		
				left++;
			}
			else{
				if(!cache[pan[next_r][next_c]]){
					cache[pan[next_r][next_c]] = true;
					--left; 
					dfs(next_r, next_c, dir, cnt+1, sum+pan[next_r][next_c]);
					left++;
					cache[pan[next_r][next_c]] = false;
				}
			}
		}
		
	}
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		ans = -1;
		scanf("%d", &N);	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &pan[i][j]);		
			}
		}
		
		for(int i = 0 ; i < N-2 ; ++i){
			for(int j = 1 ; j < N-1 ; ++j){
				right = 0;	left = 0;
				cache[pan[i][j]] = true;
				dfs(i, j, 0, 1, pan[i][j]);
				cache[pan[i][j]] = false;
			}
		}
		
		printf("#%d %d\n", z, ans);
	}
	return 0;
}



