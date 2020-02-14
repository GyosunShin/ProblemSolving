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
vector<pair<int, int> > adj[MAX_V];

int kruskal(vector<pair<int, int> >& selected){
	int ret = 0;
	selected.clear();
	
	vector<pair<int, pair<int, int> > > edges;
	for(int u = 0 ; u < V ; ++u){
		for(int i = 0 ; i < adj[u].size() ; ++i){
			int v = adj[u][i].first, cost = adj[u][i].second;
			edges.push_back(make_pair(cost, make_pair<u, v>));
		}
	}
	
	sort(edges.begin(), edges.end());
	
	DisjointSet sets(V);
	
	for(int i = 0 ; i < edges.size() ; ++i){
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		
		if(sets.find(u) == sets.find(v))	continue;
		
		sets.merge(u, v);
		selected.push_back(make_pair(u, v));
		ret += cost;
	}
	return ret;
}


int main(){
	 
	
	
	return 0;
}







