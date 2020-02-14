//  (1 ≤ N(정점) ≤ 1,000, 0 ≤ M(간선) ≤ N×(N-1)/2)


#include <stdio.h> 
#include <string.h> 
#include <vector>

using namespace std;

int N, M;
vector<int> v[1001];
int visited[1001];

void dfs(int start){
	visited[start] = 1;
	
	for(int i = 0 ; i < v[start].size() ; ++i){
		if(visited[v[start][i]] == -1){
			dfs(v[start][i]);	
		}
	}
}

int main(){
	memset(visited, -1, sizeof(visited));
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < M ; ++i){
		int src, dst;
		scanf("%d %d", &src, &dst);	
		v[src].push_back(dst);	
		v[dst].push_back(src);
	}
	
	int ans = 0;
	
	for(int i = 1 ; i <= N ; ++i){
		if(visited[i] == -1){
			dfs(i);
			ans++;	
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
