#include <stdio.h>
#include <vector>

// 각 노드들을 객체로 표현하는 대신, 자신의 부모의 번호를 저장하는 1차원 배열만으로 표현 

struct NaiveDisjointSet{
	vector<int> parent;
	NaiveDisjointSet(int n): parent(n){
		for(int i = 0 ; i < n ; ++i){
			parent[i] = i;
		}
	}
	
	// u가 속한 트리의 root의 번호를 반환한다. 
	int find(int u) const{
		if(u == parent[u]) return u;
		return find(parent[u]);
	}
	
	// u가 속한 트리와 v가 속한 트리를 합친다. 
	void merge(int u, int v){
		u = find(u);	v = find(v);
		// u와 v가 이미 같은 트리에 속하는 경우를 걸러낸다. 
		if(u == v) return;
		parent[u] = v;
	}
};

int main(){
	
}
