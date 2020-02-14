// 직사각형 개수 (1 ≤ N ≤ 1000) 
// 직사각형의 좌표 x1, y1, x2, y2가 주어진다. (-500 ≤ x1 < x2 ≤ 500), (-500 ≤ y1 < y2 ≤ 500)

#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int N;

bool map[2001][2001];
bool visited[2001][2001];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

queue<pair<int, int> > q;

int max_idx = -1 * 0x7fffffff;

void mark(int x1, int y1, int x2, int y2){
	x1 += 500;
	x1 *= 2;
	x2 += 500;
	x2 *= 2;
	y1 += 500;
	y1 *= 2;
	y2 += 500;
	y2 *= 2;
	
	for(int i = x1 ; i <= x2 ; ++i)	map[i][y1] = true;
	for(int i = x1 ; i <= x2 ; ++i)	map[i][y2] = true;
	for(int i = y1 ; i <= y2 ; ++i)	map[x1][i] = true;
	for(int i = y1 ; i <= y2 ; ++i)	map[x2][i] = true;
}

void bfs(int start_x, int start_y){
	visited[start_x][start_y] = true;
	q.push(make_pair(start_x, start_y));
	
	while(!q.empty()){
		
		int cur_r = q.front().first;	int cur_c = q.front().second;	
		q.pop();
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			if(0 > next_r || next_r > max_idx || 0 > next_c || next_c > max_idx || visited[next_r][next_c] || !map[next_r][next_c])	continue;
			visited[next_r][next_c] = true;
			q.push(make_pair(next_r, next_c));
		}
		
	}
	
}

int main(){
	
	int ans = 0;
	
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		max_idx = max(max_idx, x1);
		max_idx = max(max_idx, x2);
		max_idx = max(max_idx, y1);
		max_idx = max(max_idx, y2);
		mark(x1,y1,x2,y2);
	}
	max_idx += 500;
	max_idx *= 2;
	
	if(map[1000][1000] && !visited[1000][1000]){
		bfs(1000,1000);
	}
	
	
	for(int i = 0 ; i <= max_idx ; ++i){
		for(int j = 0 ; j <= max_idx ; ++j){
			if(map[i][j] && !visited[i][j]){
				if(i == 1000 && j == 1000){
					continue;	
				}
				bfs(i,j);
				++ans;
			}
		}
	}
	
	printf("%d", ans);
	
	return 0;
}

