// 한 다리의 방향이 중간에 바뀌면 안된다. (그래서 다리는 가로방향 아니면 세로방향만 가능) 
//  또, 다리의 길이는 2 이상이어야 한다.

// LIMIT
// 1 ≤ N, M ≤ 10
// 3 ≤ N×M ≤ 100
// 2 ≤ 섬의 개수 ≤ 6

// 사용했던 반례 
//4 10
//0 0 1 0 0 0 0 1 0 1
//0 0 0 0 0 0 1 0 0 1
//0 0 0 0 0 0 0 0 0 0
//0 1 1 0 0 1 0 0 0 0 

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int R, C;
int pan[10][10];
int island[10][10];
bool visited[10][10];
int idx = 1;

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

queue<pair<int, int>> q;

vector<pair<int, int>> adj[7];	// <가중치, 연결된 섬>

vector<pair<int, pair<int, int>>> edges;	// <가중치, <src, dst>>

struct DisjointSet{
	
	vector<int> parent, rank;
	
	DisjointSet(int n) : parent(n), rank(n, 1){
		for(int i = 0 ; i < parent.size() ; ++i)	parent[i] = i;
	}
	
	int find(int u){
		if(parent[u] == u)	return u;
		return parent[u] = find(parent[u]);
	}
	
	void merge(int u, int v){
		u = find(u);	v = find(v);
		
		if(u == v)	return;
		
		if(rank[u] > rank[v]){
			parent[v] = u;
		}
		else{
			parent[u] = v;
			if(rank[u] == rank[v])	rank[v]++;
		}
	}
	
};

void pt(){
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			printf("%d ", island[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void bfs(int start_r, int start_c, int flag){
	
	while(!q.empty())	q.pop();
	visited[start_r][start_c] = true;
	island[start_r][start_c] = flag;
	q.push(make_pair(start_r, start_c));
	
	while(!q.empty()){
		int cur_r = q.front().first;	int cur_c = q.front().second;	q.pop();
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C
			|| visited[next_r][next_c] || pan[next_r][next_c] != 1)	continue;
			q.push(make_pair(next_r, next_c));
			visited[next_r][next_c] = true;
			island[next_r][next_c] = flag;
		}
	}
	
}

void divide(){
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			if(pan[i][j] != 0 && !visited[i][j]){
				bfs(i, j, idx);
				idx++;
			}
		}
	}
}

pair<int, int> check(int start_r, int start_c, int dir){
	int start_value = island[start_r][start_c];
	
	pair<int, int> ret;
	ret.first = -1;	ret.second = -1;
	int len = 0;
	int dst = -1;
	
	while(true){
		start_r += dr[dir];		start_c += dc[dir];
		if(0 > start_r || start_r >= R || 0 > start_c || start_c >= C)	break;
		if(island[start_r][start_c] == start_value)	break;
		if(island[start_r][start_c] > 0){
			dst = island[start_r][start_c];
			break;
		}
		len++;
	}
	
	ret.first = len;	ret.second = dst;
	return ret;
}

void lineBuild(){
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			if(island[i][j] >= 1){
				for(int dir = 0 ; dir < 4 ; ++dir){
					pair<int, int> ret = check(i, j, dir);
					if(ret.first >= 2 && ret.second > 0){
						adj[island[i][j]].push_back(make_pair(ret.first, ret.second));
					}
				}
			}
		}
	}
}

int kruskal(){	
	// 1 ~ (idx-1) 섬의 IDX
	
	// adj -> edges
	for(int i = 1 ; i < 7 ; ++i){
		for(int j = 0 ; j < adj[i].size() ; ++j){
			edges.push_back(make_pair(adj[i][j].first, make_pair(i, adj[i][j].second)));
		}
	}
	
	sort(edges.begin(), edges.end());
	
	DisjointSet ds(idx);
	int ret = 0;
	vector<pair<int, int>> tmp;
	for(int i = 0 ; i < edges.size() ; ++i){
		int cost = edges[i].first;
		int src = edges[i].second.first;	int dst = edges[i].second.second;
		
		if(ds.find(src) == ds.find(dst))	continue;
		
		ds.merge(src, dst);	
		tmp.push_back(make_pair(src, dst));
		ret += cost;
	}

	// 부모 통일 시키기
	for(int i = 0 ; i < tmp.size() ; ++i){
		ds.merge(tmp[i].first, tmp[i].second);
	}
	
	for(int i = 1 ; i < idx-1 ; ++i){
		if(ds.parent[i] != ds.parent[i+1]){
			ret = -1;
			break;
		}
	}
	
	return ret;
}

int main(){
	scanf("%d %d", &R, &C);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%d", &pan[i][j]);	// (0 : 바다) (1 : 땅)
		}
	}
	
	divide();
//	pt();
	// 섬의 개수 : (idx-1)
	
	lineBuild();
//	for(int i = 0 ; i < 7 ; ++i)
//		for(int j = 0 ; j < adj[i].size() ; ++j)
//			printf("%d -> %d [%d]\n", i, adj[i][j].second, adj[i][j].first);

	printf("%d", kruskal());
	
	return 0;
}
