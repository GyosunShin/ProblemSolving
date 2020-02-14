// 순열의 크기 N (2 ≤ N ≤ 1,000)

#include <stdio.h>
#include <string.h>

int T, N;
int map[1001];
int visited[1001];

void dfs(int start){
	if(visited[start] != -1){
		return;
	}
	
	visited[start] = 1;
	dfs(map[start]);
}


int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		memset(map, -1, sizeof(map));
		memset(visited, -1, sizeof(visited));
		scanf("%d", &N);
		for(int i = 1 ; i <= N ; ++i){
			scanf("%d", &map[i]);		
		}
		int ans = 0;
		for(int i = 1 ; i <= N ; ++i){
			if(visited[i] == -1){
				dfs(i);
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
