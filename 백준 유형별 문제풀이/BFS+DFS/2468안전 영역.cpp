// 2 <= N <= 100 
// 1 <= 높이 <= 100
// 
// OUTPUT : 첫째 줄에 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 출력한다. 

#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int N;
int map[100][100];
int visited[100][100];

int highest = (-1 * 0x7fffffff);
int ans = (-1 * 0x7fffffff);
int tmp_ans;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

void dfs(int r, int c, int height){
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		if(0> next_r || next_r >= N || 0> next_c || next_c >= N || visited[next_r][next_c] != 0 || map[next_r][next_c] <= height){
			continue;
		}
		visited[next_r][next_c] = 1;
		dfs(next_r, next_c, height);		
	}
}

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);
			if(highest < map[i][j])	highest = map[i][j];
		}
	}
	//#################################
	
	for(int i = 0 ; i < highest ; ++i){
		tmp_ans = 0;
		memset(visited, 0, sizeof(visited));
		for(int j = 0 ; j < N ; ++j){
			for(int l = 0 ; l < N ; ++l){
				if(visited[j][l] == 1 || map[j][l] <= i)	continue;
				dfs(j, l, i);
				++tmp_ans;
			}
		}
		
		if(ans < tmp_ans){
			ans = tmp_ans;
		}
	}
	
	printf("%d", ans);
	return 0;
}
