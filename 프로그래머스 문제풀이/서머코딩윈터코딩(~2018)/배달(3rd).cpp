#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 1 <= N <= 50
// (a b c)	1 <= c <= 10,000

int cache[51];

vector<pair<int ,int> > graph[51];	// (dstIdx, cost)

priority_queue<pair<int ,int>, vector<pair<int ,int>>, greater<pair<int ,int> > > pq;

void graphBuild(vector<vector<int> >& input){
	for(int i = 0 ; i < input.size() ; ++i){
		int a = input[i][0];
		int b = input[i][1];
		int cost = input[i][2];
		
		graph[a].push_back(make_pair(b, cost));
		graph[b].push_back(make_pair(a, cost));
	}
}

void dijkstra(){
	
	cache[1] = 0;
	pq.push(make_pair(0, 1));
	
	while(!pq.empty()){
		int sofar = pq.top().first;
		int curIdx = pq.top().second;
		pq.pop();
		
		for(int i = 0 ; i < graph[curIdx].size() ; ++i){
			int nextIdx = graph[curIdx][i].first;
			int nextSofar = graph[curIdx][i].second + sofar;
			
			if(cache[nextIdx] != -1 && cache[nextIdx] <= nextSofar)	continue;
			
			cache[nextIdx] = nextSofar;
			pq.push(make_pair(nextSofar, nextIdx));
		}
	}
	
}

int solution(int N, vector<vector<int> > road, int K) {
    memset(cache, -1, sizeof(cache));
	
	graphBuild(road);
	
	dijkstra();
	
	// OUTPUT
	// 자기도 포함해서 배달 가능한 곳의 개수 return
	int answer = 0;
	for(int i = 1 ; i <= N ; ++i){
		if(cache[i] <= K && cache[i] != -1)	++answer;
	}

    return answer;
}
