// FD x: 거북이를 x만큼 앞으로 전진
// LT a: 거북이를 반시계 방향으로 a도 만큼 회전
// RT a: 거북이를 시계 방향으로 a도 만큼 회전
// PU: 연필을 올린다
// PD: 연필을 내린다.

// OUTPUT : 직사각형을 그리는데 필요한 PU 명령의 최솟값

// 직사각형의 개수 N이 주어진다. (1 ≤ N ≤ 1000)
// (-500 ≤ x1 < x2 ≤ 500), (-500 ≤ y1 < y2 ≤ 500) 

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

//const int garo_dx[] = {-2, 2, -1, 1, -1, 1};
//const int garo_dy[] = {0, 0, -1, -1, 1, 1};
//const int sero_dx[] = {0, 0, -1, -1, 1, 1};
//const int sero_dy[] = {-2, 2, -1, 1, -1, 1};

bool pan[1000*2 + 1][1000*2 + 1];
bool visited[1000*2 + 1][1000*2 + 1];

int ans;

queue<pair<int, int>> q;

void bfs(int start_x, int start_y){
	
	visited[start_x][start_y] = true;
	q.push({start_x, start_y});
	
	while(!q.empty()){
		int cur_x = q.front().first;	int cur_y = q.front().second;
		q.pop();
		pan[cur_x][cur_y] = false;
		
		for(int dir = 0 ; dir < 4; ++dir){
			int next_x = cur_x + dr[dir];	int next_y = cur_y + dc[dir];
			
			if(0 > next_x || next_x >= 2001 || 0 > next_y || next_y >= 2001 || visited[next_x][next_y]
			|| !pan[next_x][next_y])	continue;
			visited[next_x][next_y] = true;
			q.push({next_x, next_y});
		}	
	}
	
}

void solve(){
	
	if(pan[500*2][500*2]){
		bfs(1000,1000);
//		++ans;
	}
		
	for(int i = 0 ; i < 2001 ; ++i){
		for(int j = 0 ; j < 2001 ; ++j){
			if(pan[i][j]){
				bfs(i,j);
				++ans;
			}
		}
	}
	
}

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);	
		x1 += 500;
		y1 += 500;
		x2 += 500;
		y2 += 500;
		x1 = x1*2;
		y1 = y1*2;
		x2 = x2*2;
		y2 = y2*2;
		
		if(x1 < x2){
			if(y1 < y2){	// 1인경우 
				for(int i = x1 ; i <= x2 ; ++i){
					pan[i][y1] = true;
					pan[i][y2] = true;
				}
				for(int i = y1 ; i <= y2 ; ++i){
					pan[x1][i] = true;
					pan[x2][i] = true;
				}
			}
			else{		// 2인 경우 
				for(int i = x1 ; i <= x2 ; ++i){
					pan[i][y1] = true;
					pan[i][y2] = true;
				}
				for(int i = y2 ; i <= y1 ; ++i){
					pan[x1][i] = true;
					pan[x2][i] = true;
				}
			}
		}
		else{
			if(y2 < y1){	// 1인경우 
				for(int i = x2 ; i <= x1 ; ++i){
					pan[i][y1] = true;
					pan[i][y2] = true;
				}
				for(int i = y2 ; i <= y1 ; ++i){
					pan[x1][i] = true;
					pan[x2][i] = true;
				}
			}
			else{	// 2인경우 
				for(int i = x2 ; i <= x1 ; ++i){
					pan[i][y1] = true;
					pan[i][y2] = true;
				}
				for(int i = y1 ; i <= y2 ; ++i){
					pan[x1][i] = true;
					pan[x2][i] = true;
				}
			}			
		}
		
	}
	
	solve();
	
	printf("%d", ans);
		
	return 0;
}
