// �ٸ��� ������ ��ƾ� ��
// 2 <= �ٸ��� ���� 

// INPUT
// 1 �� N, M �� 10
// 2 �� ���� ���� �� 6

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
	
	// ��ġ�� 
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
	
	// ��Ʈ �θ� ã�� 
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
	
	// islandCnt ������ realMap�� ĥ�س���
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
	
	// 1 <= �� ��ȣ <= islandCnt
	for(int src = 1 ; src <= islandCnt ; ++src){
		// eachIsland[src]�� ��� �͵��� ���� 4���⿡ ���� ������鼭 
		// ������ ��� edge Ȯ���ϱ�
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
	
	// priority_queueŸ���� edges<weight, <src, dst>> ���
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
	
	// �� Ȯ���ϱ�
	buildIsland(); 
	
	// ���� �� ������ ��� EdgeȮ���ؼ� priority_queue�ȿ� ����ֱ�
	findEdges();
	
	// Kruskal's MST �˰��� ����
	return mst(); 
	
}

int main(){
	
	scanf("%d %d", &R, &C);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			// (0 : �ٴ�)	(1 : ��) 
			scanf("%d", &pan[i][j]);
		}
	}
	
	int answer = solve();
	
	// OUTPUT
	// ��� ���� �����ϴ� �ٸ� ������ �ּڰ��� ����Ѵ�. 
	// ��� ���� �����ϴ� ���� �Ұ����ϸ� -1�� ����Ѵ�.
	printf("%d", answer);
	
	return 0;
}
