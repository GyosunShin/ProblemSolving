// 2 ¡Â N, M ¡Â 100

#include <cstdio> 
#include <queue>
#include <algorithm>

using namespace std;

int R, C;
int pan[100][100];
bool visited[100][100];

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

queue<pair<int, pair<int, int>>> q;

int solve(){
	
	visited[0][0] = true;
	q.push(make_pair(1, make_pair(0,0)));
	
	while(!q.empty()){
		int cur_r = q.front().second.first;
		int cur_c = q.front().second.second;
		int sofar = q.front().first;
		q.pop();
		
		if(cur_r == R-1 && cur_c == C-1){
			return sofar;
		}
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];
			int next_c = cur_c + dc[dir];
			
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C
			|| visited[next_r][next_c] || pan[next_r][next_c] != 1)	continue;
			
			visited[next_r][next_c] = true;
			q.push(make_pair(sofar + 1, make_pair(next_r, next_c)));
		}		
	}
	
}

int main(){
	
	scanf("%d %d", &R, &C);
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%1d", &pan[i][j]);
		}
	}
	
	int ret = solve();
	
	printf("%d", ret);
	
	return 0;
}
