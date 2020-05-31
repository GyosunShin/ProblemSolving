// 정점의 개수 N (1 ≤ N ≤ 100)

#include <cstdio>
#include <cstring>

int N, src;

int pan[101][101];
bool visited[101];
int cache[101][101];


void dfs(int idx){
	
	for(int i = 1 ; i <= N ; ++i){
		if(i == src && pan[idx][i]){
			cache[src][i] = 1;
			continue;
		}
		if(!visited[i] && pan[idx][i]){
			visited[i] = true;
			cache[src][i] = 1;
			dfs(i);
		}
	}
	
}

void solve(){
	
	for(int i = 1 ; i <= N ; ++i){
		memset(visited, false, sizeof(visited));
		src = i;	
		visited[i] = true;
		dfs(i);
	}
	
}

int main(){
	memset(cache, 0, sizeof(cache));
	scanf("%d", &N);
	
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j <= N ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	
	solve();
	
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j <= N ; ++j){
			printf("%d ", cache[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
