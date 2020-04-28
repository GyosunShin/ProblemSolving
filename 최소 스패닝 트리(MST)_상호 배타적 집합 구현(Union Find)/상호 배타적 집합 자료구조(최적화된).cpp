#include <stdio.h>
#include <vector>

using namespace std;

struct OptimizedDisjointSet{
	vector<int> parent, rank;
	
	// rank[] : 해당 노드가 한 트리의 root 역할을 담당하는 경우에만 해당 트리의 높이를 저장 
	OptimizedDisjointSet(int n) : parent(n), rank(n, 1){	
		for(int i = 0 ; i < n ; ++i){
			parent[i] = i;
		}
	}
	
	// u가 속한 트리의 root의 번호를 반환한다. 
	int find(int u){
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);		// 경로 압축 최적화(Path Compression) 
	}
	
	// 항상 높이가 더 낮은 트리를 더 높은 트리 밑에 집어넣음으로써 트리의 높이가 높아지는 상황을 방지한다. 
	void merge(int u, int v){
		u = find(u);	v = find(v);
		
		// u와 v가 이미 같은 트리에 속하는 경우를 걸러낸다. 
		if(u == v)	return;
		
		if(rank[u] > rank[v]) swap(u, v);
		
		parent[u] = v;
		// 두 트리의 높이가 같을 경우에만 +1 해준다. 
		if(rank[u] == rank[v]) ++rank[v];
	}
};

int main(){
	
	return 0;
}
