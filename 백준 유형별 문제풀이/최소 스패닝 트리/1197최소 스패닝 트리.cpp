// INPUT : V(1 �� V �� 10,000)  E(1 �� E �� 100,000)
// A B C(-1000000 ~ 1000000)

// OUTPUT : ù° �ٿ� �ּ� ���д� Ʈ���� ����ġ�� ����Ѵ�.
#include <stdio.h> 
#include <vector>
#include <algorithm>

using namespace std;

int V, E; 

struct Disjoint{   // Union-find
	vector<int> parent, rank;
	
	Disjoint(int n) : parent(n+1), rank(n+1, 1){
		for(int i = 1; i < parent.size() ; ++i){
			parent[i] = i;
		}
	}
	
	int find(int v){  // �θ� ��带 ã�Ƽ� ��ȯ 
		if(parent[v] == v)	return v;
		return parent[v] = find(parent[v]);
	}
	
	void merge(int u, int v){  // 
		u = find(u);	v = find(v);
		if(u == v)	return;
		
		if(rank[u] > rank[v])	swap(u, v);
		
		parent[u] = v;
		if(rank[u] == rank[v])	++rank[v];
	}	
};

int main(){
	scanf("%d %d", &V, &E);
	
	vector<pair<int, pair<int, int> > > edges;
	
	for(int z = 0 ; z < E ; ++z){
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		edges.push_back(make_pair(C, make_pair(A, B)));
	}
	
	sort(edges.begin(), edges.end());
	
	// ũ�罺Į MST ����!
	
	Disjoint sets(V);
	int ans = 0;
	
	for(int i = 0 ; i < edges.size() ; ++i){
		int cost = edges[i].first;
		int src = edges[i].second.first;	int dst = edges[i].second.second;
		
		if(sets.find(src) == sets.find(dst))	continue;
		
		sets.merge(src, dst);
		ans += cost;
	}
	printf("%d", ans);
	return 0;
}
