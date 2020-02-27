// 4X4 <= land 크기 <= 300X300
// 1 <= 각 격자의 값 <= 10000
// 1 <= height <= 10000

// OUTPUT :  모든 칸을 방문하기 위해 필요한 사다리 설치 비용의 최솟값을 return 하도록 solution 함수를 완성해주세요.

#include <string>
#include <vector>
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

struct DisjointSet{
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n+1), rank(n+1, 1){
		for(int i = 1 ; i <= n ; ++i){
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

struct INFO{
	int r, c;
};
int map[300][300];

int divide;

int H, N;
vector<vector<int>> global_land;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

void bfs(int r, int c){
	queue<INFO> q;	
	INFO start;
	start.r = r;	start.c = c;
	
	int flag = ++divide;
	
	map[r][c] = flag;
	q.push(start);
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N || map[next_r][next_c] != 0
			|| H < abs(global_land[cur.r][cur.c] - global_land[next_r][next_c]))	continue;
			INFO next;	next.r = next_r;	next.c = next_c;
			q.push(next);
			map[next_r][next_c] = flag;		
		}
	}
	
}

int solution(vector<vector<int>> land, int height) {
	global_land = land;
	N = land.size();
	H = height;
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(map[i][j] == 0){
				bfs(i, j);
			}
		}
	}
	
	vector<pair<int, int>> vs[divide + 1];
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < (N-1) ; ++j){
			if(map[i][j] != map[i][j+1]){
				vs[map[i][j]].push_back(pair<int, int>(map[i][j+1], abs(global_land[i][j] - global_land[i][j+1])));
				vs[map[i][j+1]].push_back(pair<int, int>(map[i][j], abs(global_land[i][j] - global_land[i][j+1])));
			}
		}
	}
	
	for(int j = 0 ; j < N ; ++j){
		for(int i = 0 ; i < (N-1) ; ++i){
			if(map[i][j] != map[i + 1][j]){
				vs[map[i][j]].push_back(pair<int, int>(map[i+1][j], abs(global_land[i][j] - global_land[i+1][j])));
				vs[map[i+1][j]].push_back(pair<int, int>(map[i][j], abs(global_land[i][j] - global_land[i+1][j])));
			}
		}
	}	
	
	for(int i = 1 ; i <= divide ; ++i){
		vs[i].erase(unique(vs[i].begin(),vs[i].end()),vs[i].end());
	}	
	
	vector<pair<int, pair<int, int>>> edges; // <cost, <src, dst>>
	for(int i = 1 ; i <= divide ; ++i){
		for(int j = 0 ; j < vs[i].size() ; ++j){
			int cost = vs[i][j].second;
			int src =  i;	int dst = vs[i][j].first;
			edges.push_back(make_pair(cost, make_pair(src, dst)));
		}
	}
	
	sort(edges.begin(), edges.end());

	DisjointSet sets(divide);
	int ans = 0;
	
	for(int i = 0 ; i < edges.size() ; ++i){
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		
		if(sets.find(u) == sets.find(v))	continue;
		
		sets.merge(u, v);
		ans += cost;
	}
	
	return ans;
}
