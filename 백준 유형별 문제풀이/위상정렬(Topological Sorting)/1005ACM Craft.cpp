// 2 ≤ N ≤ 1000
// 1 ≤ K ≤ 100000

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N, K, W;
int time[1001];
int cache[1001];
int inDegree[1001];

vector<int> graph[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

vector<int> ans;

void solve(){
	
	for(int i = 1 ; i <= N ; ++i){
		if(inDegree[i] == 0){
			pq.push(make_pair(time[i], i));
			cache[i] = time[i];
		}
	}
	
	while(!pq.empty()){
		int sofar = pq.top().first;	int curV = pq.top().second;	
		pq.pop();
		
		for(int i = 0 ; i < graph[curV].size() ; ++i){
			int nextV = graph[curV][i];
			int nextSofar = sofar + time[nextV];
			
			if(cache[nextV] != -1 && cache[nextV] <= nextSofar)	continue;
			
			inDegree[nextV]--;
			if(inDegree[nextV] == 0){
				pq.push(make_pair(nextSofar, nextV));
				cache[nextV] = nextSofar;
			}
		}
	}
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		memset(cache, -1, sizeof(cache));
		scanf("%d %d", &N, &K);
		
		while(!pq.empty())	pq.pop();
		for(int i = 1 ; i <= N ; ++i){
			graph[i].clear();
			inDegree[i] = 0;
		}
		
		for(int i = 1 ; i <= N ; ++i){
			scanf("%d", &time[i]);
		}
		int fr, re;
		for(int i = 1 ; i <= K ; ++i){
			scanf("%d %d", &fr, &re);
			graph[fr].push_back(re);
			inDegree[re]++;
		}
		scanf("%d", &W);
		
		solve();
		// OUTPUT : 건물 W를 건설완료 하는데 드는 최소 시간을 출력
		printf("%d\n", cache[W]);
	}
	
	return 0;
}
