//  (1≤V≤20,000, 1≤E≤300,000)
// (u, v, w)

// OUTPUT : 경로가 존재하지 않는 경우에는 INF를 출력하면 된다

#include <stdio.h> 
#include <string.h> 
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int V, E, K;

vector<pair<int, int> > vs[20001];
int ans[20001];

void dijk(int start){
	
	priority_queue<pair<int ,int> > pq;   // <cost, dst>
	
	pq.push(make_pair(0, start));
	ans[start] = 0;
	
	while(!pq.empty()){
		int cost = -pq.top().first;	int cur_node = pq.top().second;
		pq.pop();
		for(int i = 0 ; i < vs[cur_node].size() ; ++i){
			int next_node = vs[cur_node][i].first;
			int next_cost = vs[cur_node][i].second + cost;
			if(ans[next_node] == -1){
				ans[next_node] = next_cost;
			}
			if(ans[next_node] < next_cost)	continue;
			ans[next_node] = next_cost;
			pq.push(make_pair(-next_cost, next_node));
		}
	}
	
}

int main(){
	memset(ans, -1, sizeof(ans));
	scanf("%d %d %d", &V, &E, &K);
	for(int i = 0 ; i < E ; ++i){
		int u,v, w;
		scanf("%d %d %d", &u, &v, &w);
		vs[u].push_back(make_pair(v, w));
	}
	
	dijk(K);
	
	for(int i = 1 ; i <= V ; ++i){
		if(ans[i] == -1)	printf("INF\n");
		else	printf("%d\n", ans[i]);
	}
	
	return 0;
}
