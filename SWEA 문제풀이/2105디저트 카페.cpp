// 디저트를 가장 많이 먹을 수 있는 경로를 찾고, 그 때의 디저트 수를 정답으로 출력하는 프로그램을 작성하라.
// 만약, 디저트를 먹을 수 없는 경우 -1을 출력한다.

// (4 ≤ N ≤ 20)
// 0 <= 디저트 종류 <= 99

#include <stdio.h>	
#include <string.h>
#include <vector>

using namespace std;

struct INFO{
	int r, c;
};

int T, N;
int map[20][20];
int visited[20][20];
int desert[100];

const int dr[] = {-1, -1, 1, 1};
const int dc[] = {-1, 1, -1, 1};

int ans = -1 * 0x7fffffff;

void dfs(int start_r, int start_c, int cur_r, int cur_c, bool flag, int len){
//	printf("START_R : %d / START_C : %d\nCUR_R : %d / CUR_C : %d\n LEN : %d\n\n", start_r, start_c, cur_r, cur_c, len);
	if(!flag){
		desert[map[start_r][start_c]] = 1;
		visited[start_r][start_c] = 1;
	}
	if(start_r == cur_r && start_c == cur_c && flag){
//		printf("PANBYILING! : %d\n", len);
		if(ans < len)	ans = len;
		return;
	}
	flag = true; 
	
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
////		printf("NEXT_R : %d \ NEXT_C : %d\n", next_r, next_c);
		if(next_r == start_r && next_c == start_c && len >= 3){
			visited[next_r][next_c] = 1;
			desert[map[next_r][next_c]] = 1;
			dfs(start_r, start_c, next_r, next_c, flag, len + 1);
			desert[map[next_r][next_c]] = -1;
			visited[next_r][next_c] = -1;			
		}
		else{
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N || visited[next_r][next_c] != -1 || desert[map[next_r][next_c]] != -1){
				continue;
			}	
			visited[next_r][next_c] = 1;
			desert[map[next_r][next_c]] = 1;
			dfs(start_r, start_c, next_r, next_c, flag, len + 1);
			desert[map[next_r][next_c]] = -1;
			visited[next_r][next_c] = -1;
		}
	}
	
}

int main(){
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		ans = -1 * 0x7fffffff;
		memset(desert, -1, sizeof(desert));
		memset(visited, -1, sizeof(visited));
		scanf("%d", &N);	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				int tmp;
				scanf("%d", &tmp);
				map[i][j] = (tmp-1);
			}
		}
		//################################
		
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
//				printf("I : %d / J : %d\n", i, j);
				if((i == 0 && j == 0) || (i == 0 && j == N-1) || (i == N-1 && j == 0) || (i == N-1 && j == N-1))	continue;
				dfs(i, j, i, j, false, 0);
			}
		}
		
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}
