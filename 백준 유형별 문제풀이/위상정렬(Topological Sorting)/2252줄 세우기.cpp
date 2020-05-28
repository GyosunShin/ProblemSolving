// 1¡ÂN¡Â32,000		1¡ÂM¡Â100,000

#include <cstdio> 
#include <queue>
#include <vector>

using namespace std;

int N, M;
int inDegree[32001];
vector<int> v[32001];

queue<int> q;

void Topological_Sort(){
	
	for(int i = 1 ; i <= N ; ++i){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int cur = q.front();	q.pop();
		
		printf("%d ", cur);
		
		for(int i = 0 ; i < v[cur].size() ; ++i){
			int target = v[cur][i];
			inDegree[target]--;
			
			if(inDegree[target] == 0){
				q.push(target);
			}		
		}
	}
	
}

int main(){
	scanf("%d %d", &N, &M);
	
	for(int i = 0 ; i < M ; ++i){
		int fr, re;
		scanf("%d %d", &fr, &re);		
		// fr --> re
		inDegree[re]++;
		v[fr].push_back(re);
	}
	
	Topological_Sort();
	
	return 0;
}
