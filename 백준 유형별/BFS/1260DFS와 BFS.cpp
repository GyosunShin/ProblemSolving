// ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), Ž���� ������ ������ ��ȣ V
// M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ / ������ ����� 
// 

// INPUT
//4 5 1
//1 2
//1 3
//1 4
//2 4
//3 4

// OUTPUT
// 1 2 4 3 // DFS ������ 
// 1 2 3 4 // BFS ������

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

vector<int> v[1001];
int visited[1001];

queue<int> q;

int N, M, V;

void bfs(){
	while(!q.empty()){
		
		int cur = q.front();	q.pop();
		printf("%d ", cur);
		
		for(int i = 0 ; i < v[cur].size() ; ++i){
			if(visited[v[cur][i]] != 1){
				visited[v[cur][i]] = 1;
				q.push(v[cur][i]);
			}
		}	
		
	}
}

void dfs(int idx){
	printf("%d ", idx);	
	
	for(int i = 0 ; i < v[idx].size() ; ++i){
		if(visited[v[idx][i]] != 1){
			visited[v[idx][i]] = 1;
			dfs(v[idx][i]);
		}
	}
}

int main(){
	scanf("%d %d %d", &N, &M, &V);  // ����, ����, Ž�� ���� ���� ��ȣ 
	for(int i = 0 ; i < M ; ++i){
		int src, dst;
		scanf("%d %d",&src, &dst);
		v[src].push_back(dst);
		v[dst].push_back(src);
	}
	
	for(int i = 1 ; i <= N ; ++i){
		sort(v[i].begin(), v[i].end());   // �̷��� �ϸ� �����ź��� ���� ���´� 
	}
	
	// dfs ������
	visited[V] = 1;
	dfs(V);
	printf("\n");
	
	// ���� BFS ����!
	q.push(V);
	memset(visited, 0, sizeof(visited));
	visited[V] = 1;
	bfs();
	
	return 0;	
}



