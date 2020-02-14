#include <stdio.h> 
#include <string.h> 
#include <vector>

using namespace std;

int T, N, M;
vector<int> v[20001];
int visited[20001];
bool escape = false;

void dfs(int start, int color){
	if(escape)	return;
	visited[start] = color;
	
	for(int i = 0 ; i < v[start].size() ; ++i){
		if(visited[v[start][i]] == (color)) {
			escape = true;
			return;
		}
		
		if(visited[v[start][i]] == 0) {
			dfs(v[start][i], color * -1);
		}
	}
	
}

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		
		for(int i = 1 ; i <= N ; ++i){
			v[i].clear();
		}
		
		escape = false;
		memset(visited, 0, sizeof(visited));
		scanf("%d %d", &N, &M);	
		for(int i = 0 ; i < M ; ++i){
			int src, dst;
			scanf("%d %d", &src, &dst);		
			v[src].push_back(dst);
			v[dst].push_back(src);
		}
		
		for(int i = 1 ; i <= N ; ++i){
			if(visited[i] == 0){
				dfs(i, -1);
			}
			if(escape)	break;
		}	
		
		if(escape)	printf("NO\n");
		else	printf("YES\n");
	}
	
	return 0;
}
