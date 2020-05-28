// 문제의 수 N(1 ≤ N ≤ 32,000)	M(1 ≤ M ≤ 100,000)

#include <cstdio> 
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> graph[32001];

priority_queue<int, vector<int>, greater<int>> pq;
int inDegree[32001];

void topological_sort(){
	
	for(int i = 1 ; i <= N ; ++i){
		if(inDegree[i] == 0)	pq.push(i);
	}
	
	while(!pq.empty()){
		int cur = pq.top();	pq.pop();
		
		printf("%d ", cur);
		
		for(int i = 0 ; i < graph[cur].size() ; ++i){
			int target = graph[cur][i];
			inDegree[target]--;
			
			if(inDegree[target] == 0){
				pq.push(target);
			}	
		}
	}
	
}

int main(){
	scanf("%d %d", &N, &M);
	
	for(int i = 0 ; i < M ; ++i){
		int fr, re;
		scanf("%d %d", &fr, &re);
		inDegree[re]++;
		graph[fr].push_back(re);
	}
	
	topological_sort();
	
	return 0;
}
