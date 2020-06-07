// 1 �� N(��ǻ�� ��) �� 1000
// ������ �� �ִ� ���� �� M (1 �� M �� 100,000)

// OUTPUT
// ��� ��ǻ�͸� �����ϴµ� �ʿ��� �ּҺ���� ù° �ٿ� ���

#include <cstdio> 
#include <vector>
#include <algorithm>

using namespace std;

int N, M, answer;

int rrank[1001];
int parent[1001];

vector<pair<int, pair<int, int>>> graph;

int find(int u){
	if(u == parent[u])	return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v){
	u = find(u);	v = find(v);
	
	if(u == v)	return;
	
	if(rrank[u] > rrank[v]){
		parent[v] = u;
	}
	else{
		if(rrank[u] == rrank[v])	rrank[v]++;
		parent[u] = v;
	}
}

int main(){
	scanf("%d", &N);
	
	for(int i = 1 ; i <= N ; ++i){
		parent[i] = i;
		rrank[i] = 1;
	}
	
	scanf("%d", &M);
	
	int src, dst, weight;
	
	for(int i = 0 ; i < M ; ++i){
		scanf("%d %d %d", &src, &dst, &weight);	
		graph.push_back(make_pair(weight, make_pair(src ,dst)));
	}
	
	sort(graph.begin(), graph.end());
	
	for(int i = 0 ; i < graph.size() ; ++i){
		int cost = graph[i].first;
		int src = graph[i].second.first;	int dst = graph[i].second.second;
		
		if(find(src) == find(dst))	continue;
		
		merge(src, dst);
		answer += cost;
	}
	
	printf("%d", answer);
	
	return 0;
}




