//  (1≤V≤20,000, 1≤E≤300,000) 

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int V, E, K;

vector<pair<int, int>> adjs[20000];	// <dst, weight>
int cache[20000];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void solve(){
	
	cache[K] = 0;
	pq.push({0, K});
	
	while(!pq.empty()){
		int src = pq.top().second;	int sofar = pq.top().first;
		pq.pop();
		
		for(int i = 0 ; i < adjs[src].size() ; ++i){
			int dst = adjs[src][i].first;
			int howlong = adjs[src][i].second;
			
			if((cache[dst] == -1) || cache[dst] > (sofar + howlong)){
				cache[dst] = (sofar + howlong);
				pq.push({(sofar + howlong), dst});
			}
		}
	}
	
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	K--;
	
	for(int i = 0 ; i < E ; ++i){
		int src, dst, weight;
		scanf("%d %d %d", &src, &dst, &weight);	
		--src;	--dst;
		adjs[src].push_back({dst, weight});
	}
	
	solve();
	
	// OUTPUT : 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.
	for(int i = 0 ; i < V ; ++i){
		if(cache[i] == -1)	printf("INF\n");
		else	printf("%d\n", cache[i]);
	}

	return 0;
}
