// 3 ≤ N ≤ 10000

// !! 서로 선행 관계가 없는 작업들은 동시에 수행 가능하다. !!

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int workTime[10001];
int inDegree[10001];
int cache[10001];

vector<int> graph[10001];

// (Weight, Vertex) 
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void topological_sort(){
	
	for(int i = 1 ; i <= N ; ++i){
		if(inDegree[i] == 0){
			pq.push(make_pair(workTime[i], i));
			cache[i] = workTime[i];
		}
	}
	
	while(!pq.empty()){
		
		int sofar = pq.top().first;		int curV = pq.top().second;
		pq.pop();
		
		for(int i = 0 ; i < graph[curV].size() ; ++i){
			int nextV = graph[curV][i];
			int nextWeight = workTime[nextV] + sofar;
			
//			if(cache[nextV] != -1 && cache[nextV] <= nextWeight)	continue;
			
			inDegree[nextV]--;
			if(inDegree[nextV] == 0){
				pq.push(make_pair(nextWeight, nextV));	// <Weight, next_Vertex>
				cache[nextV] = nextWeight;
			}
			
		}	
	}
	
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	scanf("%d", &N);
	
	for(int i = 1 ; i <= N ; ++i){
		int num;
		scanf("%d %d", &workTime[i], &num);
		for(int j = 0 ; j < num ; ++j){
			int tmp;
			scanf("%d", &tmp);
			graph[tmp].push_back(i);
			inDegree[i]++;
		}
	}
	
	topological_sort();
	
	// OUTPUT : 모든 작업을 완료하기 위한 최소 시간을 출력한다.
	int answer = -1 * 0x7fffffff;
	for(int i = 1 ; i <= N ; ++i){
		answer = max(answer, cache[i]);
	}
	printf("%d", answer);
	
	return 0;
}
