// 트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다. 트리의 지름을 구하는 프로그램을 작성하시오.

// 트리의 정점의 개수 V가 주어지고 (2≤V ≤100,000)

// 1 <= 가중치 <= 10000

#include <stdio.h> 
#include <string.h> 
#include <vector>
#include <algorithm>

using namespace std;

int V, far; 

vector<pair<int, int> > map[100001];		// <weight, dst>

bool visited[100001];
long long ans = -1 * 0x7fffffff;

void dfs(int start, long long cnt){
	
	if(ans < cnt){
		far = start;
		ans = cnt;
	}
	
	for(int i = 0 ; i < map[start].size() ; ++i){
		int next = map[start][i].second;
		if(visited[next])	continue;
		visited[next] = true;
		int w = map[start][i].first;
		dfs(next, cnt + w);
		visited[next] = false;
	}
	
}

int main(){	
	scanf("%d", &V);
	
	for(int i = 1 ; i <= V ; ++i){
		int src;
		scanf("%d", &src);
		int cnt = 1;
		int dst, w;
		while(1){
			int tmp;
			scanf("%d", &tmp);	
			if(tmp == -1)	break;
			if(cnt % 2 == 1){
				dst = tmp;
			}
			else{
				w = tmp;
				map[src].push_back(make_pair(w, dst));
			}
			++cnt;
		}
	}
	
	visited[1] = true;
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	visited[far] = true;
	dfs(far, 0);
	
	printf("%lld", ans);
	
	return 0;
}
