// 5 <= N <= 100
// (0 : 빈칸) (1 : 벽)

// 로봇이 차지하는 두 칸 중 어느 한 칸이라도 (N, N) 위치에 도착하면 됩니다.

// (1, 1) --> (N, N)

// OUTPUT : 로봇이 (N, N) 위치까지 이동하는데 필요한 최소 시간을 return

#include <string>
#include <vector>
#include <queue>

using namespace std;

struct INFO{
	int r1, c1, r2, c2, time;
};

int N;

bool visited[100][100][100][100];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

queue<INFO> q;

int solution(vector<vector<int>> board) {
	
    N = board.size();
    
    INFO start = {0,0,0,1,0};
    visited[0][0][0][1] = true;	
	visited[0][1][0][0] = true;
    q.push(start);
    
    int ans;
    
    while(!q.empty()){
    	
    	INFO cur = q.front();	q.pop();
    	
    	if((cur.r1 == (N-1) && cur.c1 == (N-1)) || (cur.r2 == (N-1) && cur.c2 == (N-1))){
    		ans = cur.time;
    		break;
    	}
    	
    	for(int dir = 0 ; dir < 4 ; ++dir){
    		int next_r1 = cur.r1 + dr[dir];	int next_c1 = cur.c1 + dc[dir];
    		int next_r2 = cur.r2 + dr[dir];	int next_c2 = cur.c2 + dc[dir];
    		
    		if(0 > next_r1 || next_r1 >= N || 0 > next_c1 || next_c1 >= N ||
			0 > next_r2 || next_r2 >= N || 0 > next_c2 || next_c2 >= N)	continue;
			if(board[next_r1][next_c1] == 1 || board[next_r2][next_c2] == 1)	continue;
			if(visited[next_r1][next_c1][next_r2][next_c2] || visited[next_r2][next_c2][next_r1][next_c1])	continue;
			
			visited[next_r1][next_c1][next_r2][next_c2] = true;	
			visited[next_r2][next_c2][next_r1][next_c1] = true;
			INFO next = {next_r1, next_c1, next_r2, next_c2, cur.time+1};
			q.push(next);
    	}
    	
    	
    	if(cur.r1 == cur.r2){	// 가로 모양인 경우 
    	
    		if(cur.r2 - 1 >= 0){
    			if(board[cur.r2-1][cur.c1] == 0 && board[cur.r2-1][cur.c2] == 0){
    				int next_r1 = cur.r2-1;	int next_c1 = cur.c2;
    				if(!visited[cur.r2][cur.c2][next_r1][next_c1] && !visited[next_r1][next_c1][cur.r2][cur.c2]){
    					visited[cur.r2][cur.c2][next_r1][next_c1] = true;
    					visited[next_r1][next_c1][cur.r2][cur.c2] = true;
    					INFO next = {next_r1, next_c1, cur.r2, cur.c2, cur.time+1};
    					q.push(next);
    				}
    				
    				int next_r2 = cur.r2-1;	int next_c2 = cur.c1;
    				if(!visited[cur.r1][cur.c1][next_r2][next_c2] && !visited[next_r2][next_c2][cur.r1][cur.c1]){
    					visited[cur.r1][cur.c1][next_r2][next_c2] = true;
    					visited[next_r2][next_c2][cur.r1][cur.c1] = true;
    					INFO next = {cur.r1, cur.c1, next_r2, next_c2, cur.time+1};
    					q.push(next);
    				}
    			}
    			
    		}
    		if(cur.r2 + 1 < N){
    			
    			if(board[cur.r2+1][cur.c1] == 0 && board[cur.r2+1][cur.c2] == 0){
    				int next_r1 = cur.r2+1;	int next_c1 = cur.c2;
    				if(!visited[cur.r2][cur.c2][next_r1][next_c1] && !visited[next_r1][next_c1][cur.r2][cur.c2]){
    					visited[cur.r2][cur.c2][next_r1][next_c1] = true;
    					visited[next_r1][next_c1][cur.r2][cur.c2] = true;
    					INFO next = {next_r1, next_c1, cur.r2, cur.c2, cur.time+1};
    					q.push(next);
    				}
    				
    				int next_r2 = cur.r2+1;	int next_c2 = cur.c1;
    				if(!visited[cur.r1][cur.c1][next_r2][next_c2] && !visited[next_r2][next_c2][cur.r1][cur.c1]){
    					visited[cur.r1][cur.c1][next_r2][next_c2] = true;
    					visited[next_r2][next_c2][cur.r1][cur.c1] = true;
    					INFO next = {cur.r1, cur.c1, next_r2, next_c2, cur.time+1};
    					q.push(next);
    				}
    			}
    			
    		}
    		
    		
    	}
    	else{	// 세로 모양인 경우
    	
    		if(cur.c2 - 1 >= 0){
    			
    			if(board[cur.r2][cur.c1-1] == 0 && board[cur.r1][cur.c2-1] == 0){
    				int next_r1 = cur.r2;	int next_c1 = cur.c2-1;
    				if(!visited[cur.r2][cur.c2][next_r1][next_c1] && !visited[next_r1][next_c1][cur.r2][cur.c2]){
    					visited[cur.r2][cur.c2][next_r1][next_c1] = true;
    					visited[next_r1][next_c1][cur.r2][cur.c2] = true;
    					INFO next = {next_r1, next_c1, cur.r2, cur.c2, cur.time+1};
    					q.push(next);
    				}
    				
    				int next_r2 = cur.r1;	int next_c2 = cur.c2-1;
    				if(!visited[cur.r1][cur.c1][next_r2][next_c2] && !visited[next_r2][next_c2][cur.r1][cur.c1]){
    					visited[cur.r1][cur.c1][next_r2][next_c2] = true;
    					visited[next_r2][next_c2][cur.r1][cur.c1] = true;
    					INFO next = {cur.r1, cur.c1, next_r2, next_c2, cur.time+1};
    					q.push(next);
    				}    				
    			}
    			
    		}
    		if(cur.c2 + 1 < N){
    			if(board[cur.r2][cur.c1+1] == 0 && board[cur.r1][cur.c2+1] == 0){
	    			int next_r1 = cur.r2;	int next_c1 = cur.c2+1;
					if(!visited[cur.r2][cur.c2][next_r1][next_c1] && !visited[next_r1][next_c1][cur.r2][cur.c2]){
						visited[cur.r2][cur.c2][next_r1][next_c1] = true;
						visited[next_r1][next_c1][cur.r2][cur.c2] = true;
						INFO next = {next_r1, next_c1, cur.r2, cur.c2, cur.time+1};
						q.push(next);
					}    			
					
					int next_r2 = cur.r1;	int next_c2 = cur.c2+1;
					if(!visited[cur.r1][cur.c1][next_r2][next_c2] && !visited[next_r2][next_c2][cur.r1][cur.c1]){
						visited[cur.r1][cur.c1][next_r2][next_c2] = true;
						visited[next_r2][next_c2][cur.r1][cur.c1] = true;
						INFO next = {cur.r1, cur.c1, next_r2, next_c2, cur.time+1};
						q.push(next);
					}    
				}
    		}
    		
    	}
    	
    }
    
    return ans;
}




