// 배추밭의 가로길이 M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50), 그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)

// OUTPUT : 각 테스트 케이스에 대해 필요한 최소의 배추흰지렁이 마리 수를 출력한다.

#include <stdio.h> 
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct INFO{
	int r, c;
};

int T;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int M, N, K;
int map[50][50];
int visited[50][50];

void dfs(int r, int c){
	
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		if(0> next_r || next_r >= N || 0> next_c || next_c >= M || visited[next_r][next_c] != 0 || map[next_r][next_c] != 1){
			continue;
		}
		visited[next_r][next_c] = 1;
		dfs(next_r, next_c);
	}
	
}

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		scanf("%d %d %d", &M, &N, &K);  // 가로(column), 세로(row), 배추 개수  
		
		vector<INFO> v;
		for(int i = 0 ; i < K ; ++i){
			int tmp_r, tmp_c;
			scanf("%d %d", &tmp_c, &tmp_r);  // 가로(column), 세로(row)
			map[tmp_r][tmp_c] = 1;
			INFO tmp;
			tmp.r = tmp_r;	tmp.c = tmp_c;
			v.push_back(tmp);
		}
		
		int ans = 0;
		
		for(int i = 0 ; i < v.size() ; ++i){
			INFO cur = v[i];
//			printf("CUR_R : %d / CUR_C : %d\n", cur.r, cur.c);
			
			if(visited[cur.r][cur.c] == 1){
//				printf("VISITED!\n");
				continue;
			}
			
			dfs(cur.r, cur.c);
//			printf("++ANS!! : %d\n", ans);
			++ans;
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}
