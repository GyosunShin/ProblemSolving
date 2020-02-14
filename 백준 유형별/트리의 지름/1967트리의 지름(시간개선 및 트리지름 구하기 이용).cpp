// 노드의 개수 
// 부모노드  자식노드  가중치

// 노드의 개수 n(1 ≤ n ≤ 10,000)
// 1 <= 가중치 <= 100

#include <stdio.h> 
#include <vector>
#include <string.h>

using namespace std;

int N;
vector<pair<int, int>> map[10001];

int far;
int ans = -1 * 0x7fffffff;
bool visited[10001];

void dfs(int start, int cnt){
	
	if(ans < cnt){
		far = start;
		ans = cnt;
	}
	
	for(int i = 0 ; i < map[start].size() ; ++i){
		int next = map[start][i].first;
		if(visited[next])	continue;
		visited[next] = true;
		int w = map[start][i].second;
		dfs(next, cnt + w);
		visited[next] = false;
	}
	
}


int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < (N-1) ; ++i){
		int paren, child, weight;
		scanf("%d %d %d", &paren, &child, &weight);	
		map[paren].push_back(pair<int, int>(child, weight));
		map[child].push_back(pair<int, int>(paren, weight));
	}
	
	visited[1] = true;
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	visited[far] = true;
	dfs(far, 0);
	
	printf("%d", ans);
	
	return 0;
}
