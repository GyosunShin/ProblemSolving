// (1 ≤ N, M ≤ 100)

// OUTPUT
// (N, M)으로 이동하기 위해 벽을 최소 몇 개 부숴야 하는지 

#include <cstdio> 
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int R, C;
int pan[100][100];
int cache[100][100];

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

// (sofarWeight, vertexIndex)
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

void dijkstra(){
	
	cache[0][0] = 0;
	pq.push(make_pair(0, make_pair(0, 0)));
	
	while(!pq.empty()){
		int sofar = pq.top().first;
		int cur_r = pq.top().second.first;
		int cur_c = pq.top().second.second;
		pq.pop();
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];
			int next_c = cur_c + dc[dir];
			
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C)	continue;
			
			int next_sofar = sofar;
			if(pan[next_r][next_c] == 1)	next_sofar++;
			
			if(cache[next_r][next_c] != -1 && cache[next_r][next_c] <= next_sofar)	continue;
			
			cache[next_r][next_c] = next_sofar;
			pq.push(make_pair(next_sofar, make_pair(next_r, next_c)));
		}
	}	
	
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	scanf("%d %d", &C, &R);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%1d", &pan[i][j]);
		}
	}
	
	dijkstra();
	
	printf("%d", cache[R-1][C-1]);
	
	return 0;
}
