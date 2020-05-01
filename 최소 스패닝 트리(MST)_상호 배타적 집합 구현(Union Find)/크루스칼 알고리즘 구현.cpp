
// MST(Minimum Spanning Tree) = 최소 신장 트리 
// 가중치 그래프의 스패닝 트리 중 가중치의 합이 가장 작은 트리
// = 그래프의 연결성을 그대로 유지하는 가장 '저렴한' 그래프를 찾는 문제 

// 크루스칼 알고리즘
// 그래프의 모든 간선을 가중치의 오름차순으로 정렬한 뒤,
// 스패닝 트리에 하나씩 추가해 갑니다.
// 물론 가중치가 작다고 해서 무조건 간선을 트리에 더하는 것은 아니다.
// 자칫하다가는 선택한 간선들이 Cycle을 이룰 수 있기 때문이다.	 

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct DisjointSet{
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1){
		for(int i = 0 ; i < n ; ++i){
			parent[i] = i;
		}	
	}
	
	int find(int u){
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	
	void merge(int u, int v){
		u = find(u);	v = find(v);
		
		if(u == v)	return;
		if(rank[u] > rank[v]) swap(u, v);
		
		parent[u] = v;
		if(rank[u] == rank[v]) ++rank[v];
	}
};

const int MAX_V = 100;
int V;
vector<pair<int, int> > adj[MAX_V];	//	<연결된 정점 번호, 간선 가중치>

int kruskal(vector<pair<int, int> >& selected){
	int ret = 0;
	selected.clear();
	
	// <가중치, <정점1, 정점2>>의 목록을 얻는다.
	vector<pair<int, pair<int, int> > > edges;
	for(int u = 0 ; u < V ; ++u){
		for(int i = 0 ; i < adj[u].size() ; ++i){
			int v = adj[u][i].first, cost = adj[u][i].second;
			edges.push_back(make_pair(cost, make_pair(u, v)));
		}
	}
	
	sort(edges.begin(), edges.end());
	
	DisjointSet sets(V);
	
	for(int i = 0 ; i < edges.size() ; ++i){
		int cost = edges[i].first;	// 가중치 
		int u = edges[i].second.first, v = edges[i].second.second;	// 양쪽 끝 정점번호들 
		 
		if(sets.find(u) == sets.find(v))	continue;	// 두개가 이미 연결되어 있는지 확인 
		
		sets.merge(u, v);
		selected.push_back(make_pair(u, v));	// MST를 이루는 간선을 축적해서 반환해주는 용도 
		ret += cost;
	}
	return ret;
}


int main(){
	 
	
	
	return 0;
}







