//정점의 개수 N(1 ≤ N ≤ 1,000)
//간선(양방향)의 개수 M(1 ≤ M ≤ 10,000)
//시작할 정점의 번호 V

#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> map[1001];
queue<int> qmap;
int N, M, V;
int visited[1001];

void bfs(){
	
	while(!qmap.empty()){
		int cur = qmap.front();
		printf("%d ", cur);
		qmap.pop();
		
		for(int i = 0 ; i < map[cur].size() ; ++i){
			int next = map[cur][i];
			if(visited[next] == -1){
				qmap.push(next);	
				visited[next] = 1;
			}
		}	
	}
	
}

void dfs(int start){
	printf("%d ", start);
	for(int i = 0 ; i < map[start].size() ; ++i){
		if(visited[map[start][i]] == -1){
			visited[map[start][i]] = 1;
			dfs(map[start][i]);
		}
	}
}

int main(){
	scanf("%d %d %d", &N, &M, &V);
	for(int i = 0 ; i < M ; ++i){
		int src, dst;
		scanf("%d %d", &src, &dst);
		map[src].push_back(dst);
		map[dst].push_back(src);
	}
	
	for(int i = 1 ; i <= M ; ++i){
		sort(map[i].begin(), map[i].end());
	}
	
	memset(visited, -1, sizeof(visited));
	visited[V] = 1;
	dfs(V);
	printf("\n");
	memset(visited, -1, sizeof(visited));
	visited[V] = 1;
	qmap.push(V);
	bfs();
	
	return 0;
}
