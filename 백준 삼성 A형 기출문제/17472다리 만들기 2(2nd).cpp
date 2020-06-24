// 다리의 방향은 곧아야 함
// 2 <= 다리의 길이 

// INPUT
// 1 ≤ N, M ≤ 10
// 2 ≤ 섬의 개수 ≤ 6

#include <cstdio> 
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct DisjointSet{
	vector<int> rank, parent;
	
	DisjointSet(int input) : parent(input), rank(input, 1){
		for(int i = 0 ; i < input ; ++i){
			parent[i] = i;
		}
	}
	
	// 합치기 
	void merge(int u, int v){
		u = find(u);	v = find(v);
		
		if(u == v)	return;
		
		if(rank[u] > rank[v]){
			parent[v] = u;
		}
		else{
			if(rank[u] == rank[v]){
				rank[v]++;
			}
			parent[u] = v;
		}	
	}
	
	// 루트 부모 찾기 
	int find(int u){
		if(u == parent[u])	return u;
		return parent[u] = find(parent[u]);
	}
	
};

int R, C;
int pan[10][10];
int realMap[10][10];

bool visited[10][10];

int islandCnt = 1;

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

queue<pair<int ,int>> q;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
greater<pair<int, pair<int, int>>>> edges;	// <weight, <src, dst>>

vector<pair<int, int>> eachIsland[7];

void pt(){
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			printf("%d ", realMap[i][j]);
		}
		printf("\n");
	}
	
}

bool rangeCheck(int r, int c){
	if(0 > r || r >= R || 0 > c || c >= C)	return false;
	return true;
}

void bfs(int r, int c){
	
	// islandCnt 값으로 realMap에 칠해놓기
	visited[r][c] = true;
	q.push(make_pair(r, c));
	 
	while(!q.empty()){
		int cur_r = q.front().first;	int cur_c = q.front().second;
		q.pop();
		realMap[cur_r][cur_c] = islandCnt;
		eachIsland[islandCnt].push_back(make_pair(cur_r, cur_c));
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			if(!rangeCheck(next_r, next_c))	continue;
			if(pan[next_r][next_c] != 1 || visited[next_r][next_c])	continue;
			
			visited[next_r][next_c] = true;
			q.push(make_pair(next_r, next_c));
		}
	}
	
}

void buildIsland(){
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			if(pan[i][j] == 1 && !visited[i][j]){
				bfs(i, j);
				islandCnt++;
			}
		}
	}
	
	islandCnt--;
	
//	pt();
//	printf("ISLAND_CNT : %d\n", islandCnt);
	
}

void findEdges(){
	
	// 1 <= 섬 번호 <= islandCnt
	for(int src = 1 ; src <= islandCnt ; ++src){
		// eachIsland[src]에 담긴 것들을 각각 4방향에 대해 뻗어나가면서 
		// 가능한 모든 edge 확인하기
		for(int i = 0 ; i < eachIsland[src].size() ; ++i){
			int cur_r = eachIsland[src][i].first;	int cur_c = eachIsland[src][i].second;
			
			for(int dir = 0 ; dir < 4 ; ++dir){
				int dis = 1;
				int dst = -1;
				bool flag = true;
				while(true){
					int next_r = cur_r + (dr[dir] * dis);	int next_c = cur_c + (dc[dir] * dis);
					if(!rangeCheck(next_r, next_c)){
						flag = false;
						break;
					}
					if(realMap[next_r][next_c] == src){
						flag = false;
						break;
					}
					if(realMap[next_r][next_c] != 0 &&
					realMap[next_r][next_c] != src){
						dst = realMap[next_r][next_c];
						break;
					}
					dis++;
				}
				
				if(flag && (dis-1) >= 2){
					// edges : <dis <src, dst>>
					edges.push(make_pair(dis-1, make_pair(src, dst)));
//					printf("%d -> %d : %d\n", src, dst, dis-1);
				}
			}
			
		}
		
	}
	
}

int mst(){
	
	int sum = 0;
	
	DisjointSet ds(islandCnt+1);
	
	// priority_queue타입인 edges<weight, <src, dst>> 사용
	while(!edges.empty()){
		int weight = edges.top().first;
		int src = edges.top().second.first;	int dst = edges.top().second.second;
		edges.pop();
		
//		printf("%d --> %d : %d\n", src, dst, weight);
		
		if(ds.find(src) == ds.find(dst))	continue;
		
		ds.merge(src, dst);
		sum += weight;
	}
	
	int root = ds.find(1);
	bool flag = true;
	for(int i = 2 ; i <= islandCnt ; ++i){
		if(ds.find(i) != root){
			flag = false;
			break;
		}
	}
	
	if(!flag)	return -1;
	return sum;
}

int solve(){
	
	// 섬 확인하기
	buildIsland(); 
	
	// 섬들 간 가능한 모든 Edge확인해서 priority_queue안에 집어넣기
	findEdges();
	
	// Kruskal's MST 알고리즘 수행
	return mst(); 
	
}

int main(){
	
	scanf("%d %d", &R, &C);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			// (0 : 바다)	(1 : 땅) 
			scanf("%d", &pan[i][j]);
		}
	}
	
	int answer = solve();
	
	// OUTPUT
	// 모든 섬을 연결하는 다리 길이의 최솟값을 출력한다. 
	// 모든 섬을 연결하는 것이 불가능하면 -1을 출력한다.
	printf("%d", answer);
	
	return 0;
}
