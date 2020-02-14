// 노드의 개수 
// 부모노드  자식노드  가중치

// 노드의 개수 n(1 ≤ n ≤ 10,000)
// 1 <= 가중치 <= 100

#include <stdio.h> 
#include <vector>
#include <string.h>

using namespace std;

int N;
vector<pair<int, int>> map[10000+1];
int visited[10000+1];

int ans = -1 * 0x7fffffff;

void dfs(int start, int len){
	if(ans < len){
		ans = len;
	}
	
	for(int i = 0 ; i < map[start].size() ; ++i){
		if(visited[map[start][i].first] != -1){
			continue;
		}
		visited[map[start][i].first] = 1;
		dfs(map[start][i].first, len + map[start][i].second);
		visited[map[start][i].first] = -1;
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
	
	for(int i = 1 ; i <= N ; ++i){
		memset(visited, -1, sizeof(visited));
		visited[i] = 1;
		dfs(i, 0);
	}
	
	printf("%d", ans);
	return 0;
}
 
