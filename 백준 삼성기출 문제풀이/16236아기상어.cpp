// 공간의 크기 N(2 ≤ N ≤ 20)
// 0: 빈 칸
// 1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
// 9: 아기 상어의 위치

#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int map[20][20];

int size = 2; // 초기 아기상어의 크기 
int eat_cnt = 0;   // 상어가 자리 옮겼으면 물고기 먹은 횟수 처음부터 다시시작! 	

int ans;

// 상 좌 우 하
int dr[] = {-1, 0, 0, 1}; 
int dc[] = {0, -1, 1, 0};

struct INFO{
	int r;
	int c;	
	int len;	 
};

INFO start; 

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 9){  // 새끼 상어의 위치 기억 
				start.r = i;
				start.c = j;
				start.len = 0;
				map[i][j] = 0;
			}
		}
	}
	// ##############################
	

	
	while(1){  // 더이상 먹을 물고기 없을때까지면 
		queue<INFO> q;
		q.push(start);
		int flag = 0; 
		int visited[20][20] = { 0, };
		
		INFO tmp;
		tmp.len = -1;
		// 최상단 최좌측에 있는거 선별해 내려고 초기값 이렇게 잡았음! 
		tmp.r = 20;
		tmp.c = 20;
		
		while(!q.empty()) {
			INFO cur = q.front();
			q.pop();
			visited[cur.r][cur.c] = 1;
			
			if(tmp.len != -1 && cur.len > tmp.len){  // 이미 뽑아낸 경우다. 				
				break;
			}
			
			if(map[cur.r][cur.c] < size && map[cur.r][cur.c] != 0){  // 먹을 수 있는경우 
				// 이전에 선택된 값이랑 거리는 동일하지만 위치상 더 위쪽, 왼쪽에 위치할 경우 tmp변경! 
				flag = 1 ;
				if(tmp.r > cur.r || (tmp.r == cur.r && tmp.c > cur.c)) {
					tmp = cur;
				}
			}
			
			for(int i = 0 ; i < 4 ; ++i){
				INFO next;
				next.r =  cur.r + dr[i];
				next.c =  cur.c + dc[i];
				next.len = cur.len + 1;
				// 이미 다른 노드로부터의 BFS탐색에 의해 거친지점이라면... (or) 범위에서 벗어난다면... 
				if(visited[next.r][next.c] != 0 || 0 > next.r || next.r >= N || 0 > next.c || next.c >= N){  
					continue; 
				}
				if(map[next.r][next.c] <= size){
					visited[next.r][next.c] = 1;
					q.push(next);
				}
				
			}
		} // queue empty되는 지점
		
		if(!flag){
			break;
		}
		else{
			start = tmp;
			ans += tmp.len; 
			++eat_cnt;
			if(eat_cnt == size){  // 상어의 크기 ++! 
				++size;
				eat_cnt = 0;
			}
			map[tmp.r][tmp.c] = 0;  // 먹었으니까 빈칸으로 바꿔준다.				
		}
	}
	
	printf("%d", start.len);
}





