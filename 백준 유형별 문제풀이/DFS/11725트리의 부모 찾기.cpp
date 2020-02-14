// N (2 ≤ N ≤ 100,000)

// OUTPUT : 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.

#include <stdio.h>
#include <vector>

using namespace std;

int N; 

vector<int> v[100001];
int ans[100001];
bool visited[100001];

void dfs(int start){
	
	for(int i = 0 ; i < v[start].size() ; ++i){
		int target = v[start][i];
		if(visited[target])	continue;
		ans[target] = start;
		visited[target] = true;
		dfs(target);
	}
	
}

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N-1 ; ++i){
		int src, dst;
		scanf("%d %d", &src, &dst);	
		v[src].push_back(dst);
		v[dst].push_back(src);
	}
	
	visited[1] = true;
	dfs(1);
	
	for(int i = 2 ; i <= N ; ++i)	printf("%d\n", ans[i]);
	
	return 0;
}

