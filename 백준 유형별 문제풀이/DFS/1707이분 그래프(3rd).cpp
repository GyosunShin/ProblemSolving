// 케이스의 개수 K(2≤K≤5)
// V(1≤V≤20,000)   E(1≤E≤200,000)

// OUTPUT
// K개의 줄에 걸쳐 입력으로 주어진 그래프가 이분 그래프이면 YES, 아니면 NO를 순서대로 출력한다.

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, V, E;

vector<int> graph[20001];
int cache[20001];
queue<pair<int, int>> q;	// <정점번호, 색갈(1 or -1)>

bool bfs(int start){
	
	while(!q.empty())	q.pop();
	
	cache[start] = 1;
	q.push({start, 1});
	
	while(!q.empty()){
		int cur = q.front().first;	
		int color =  q.front().second;
		q.pop();
		
		for(int i = 0 ; i < graph[cur].size() ; ++i){
			int next = graph[cur][i];
			int next_color = -1 * color;
//			printf("NEXT : %d / nextcolor : %d / color : %d\n", next, cache[next], color);
			if(cache[next] == color)	return false;
			if(cache[next] != 0)	continue;
			q.push({next, next_color});
			cache[next] = next_color;
		}
	}
	
	return true;
}


bool solve(){
	
	for(int i = 1 ; i <= V ; ++i){
		if(cache[i] == 0){
//			printf("start : %d\n", i);
			if(!bfs(i)){
//				printf("FALSE\n");
				return false;
			}
		}
	}
	
	return true;
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		memset(cache, 0, sizeof(cache));
		for(int i = 0 ; i < 20001 ; ++i)	graph[i].clear();
		
		scanf("%d %d", &V, &E);	
		
		for(int i = 0 ; i < E ; ++i){
			int src, dst;
			scanf("%d %d", &src, &dst);
			
			graph[src].push_back(dst);
			graph[dst].push_back(src);
		}
		
		if(solve())	printf("YES\n");
		else	printf("NO\n");
	}
	
	return 0;
}
