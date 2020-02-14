// (0 : 빈칸 ) (1 : 벽)
// board의 한 변의 길이는 5 이상 100 이하입니다.

// OUTPUT : 로봇이 (N, N) 위치까지 이동하는데 필요한 최소 시간 Return

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int visited[100][100][100][100];

vector<vector<int>> map;

struct INFO{
	int r1, c1, r2, c2, time;
};

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};
int N, ans;

queue<INFO> q;

void bfs(){
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
        
//        cout << "( CUR_R1 : " << cur.r1 << " CUR_C1 : " << cur.c1 << ")  CUR_R2 : " << cur.r2 << "  CUR_C2 : " << cur.c2 << "    || TIME : " << cur.time << endl;
		
		if((cur.r1 == (N-1) && cur.c1 == (N-1)) || (cur.r2 == (N-1) && cur.c2 == (N-1))){
			ans = cur.time;
			break;
		}
		int next_time = cur.time + 1;
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r1 = cur.r1 + dr[dir];
			int next_c1 = cur.c1 + dc[dir];
			int next_r2 = cur.r2 + dr[dir];
			int next_c2 = cur.c2 + dc[dir];
			
			if(0 > next_r1 || next_r1 >= N || 0 > next_c1 || next_c1 >= N || 0 > next_r2 || next_r2 >= N || 0 > next_c2 || next_c2 >= N 
			|| visited[next_r1][next_c1][next_r2][next_c2] != 0 || map[next_r1][next_c1] == 1 || map[next_r2][next_c2] == 1){
				continue;
			}
			visited[next_r1][next_c1][next_r2][next_c2] = 1;
			INFO next;
			next.r1 = next_r1;	next.c1 = next_c1;	next.r2 = next_r2;	next.c2 = next_c2;	next.time = next_time;
			q.push(next);
		}
		
		if(cur.r1 == cur.r2){  // 가로방향일 경우 
			int min = cur.c1 < cur.c2 ? cur.c1 : cur.c2;
			int max = cur.c1 < cur.c2 ? cur.c2 : cur.c1;
			
			int next_r1 = cur.r1 - 1;
			int next_c1 = max;
			int next_r2 = cur.r1;
			int next_c2 = max;
			if(!(0 > next_r1 || next_r1 >= N || 0 > next_c1 || next_c1 >= N || 0 > next_r2 || next_r2 >= N || 0 > next_c2 || next_c2 >= N 
			|| map[cur.r1 - 1][min] == 1 || visited[next_r1][next_c1][next_r2][next_c2] != 0 || map[next_r1][next_c1] == 1 || map[next_r2][next_c2] == 1)){
				visited[next_r1][next_c1][next_r2][next_c2] = 1;
				INFO next;
				next.r1 = next_r1;	next.c1 = next_c1;	next.r2 = next_r2;	next.c2 = next_c2;	next.time = next_time;
				q.push(next);
			}
			
			next_r1 = cur.r1 + 1;
			next_c1 = max;
			next_r2 = cur.r1;
			next_c2 = max;
			
			if(!(0 > next_r1 || next_r1 >= N || 0 > next_c1 || next_c1 >= N || 0 > next_r2 || next_r2 >= N || 0 > next_c2 || next_c2 >= N 
			|| map[cur.r1 + 1][min] == 1 || visited[next_r2][next_c2][next_r1][next_c1] != 0 || map[next_r1][next_c1] == 1 || map[next_r2][next_c2] == 1)){
				visited[next_r2][next_c2][next_r1][next_c1] = 1;
				INFO next;
				next.r1 = next_r2;	next.c1 = next_c2;	next.r2 = next_r1;	next.c2 = next_c1;	next.time = next_time;
				q.push(next);
			}
			
			next_r1 = cur.r1;
			next_c1 = min;
			next_r2 = cur.r1 - 1;
			next_c2 = min;
			
			if(!(0 > next_r1 || next_r1 >= N || 0 > next_c1 || next_c1 >= N || 0 > next_r2 || next_r2 >= N || 0 > next_c2 || next_c2 >= N 
			|| map[cur.r1 - 1][max] == 1 || visited[next_r2][next_c2][next_r1][next_c1] != 0 || map[next_r1][next_c1] == 1 || map[next_r2][next_c2] == 1)){
				visited[next_r2][next_c2][next_r1][next_c1] = 1;
				INFO next;
				next.r1 = next_r2;	next.c1 = next_c2;	next.r2 = next_r1;	next.c2 = next_c1;	next.time = next_time;
				q.push(next);
			}
			
			next_r1 = cur.r1;
			next_c1 = min;
			next_r2 = cur.r1 + 1;
			next_c2 = min;
			
			if(!(0 > next_r1 || next_r1 >= N || 0 > next_c1 || next_c1 >= N || 0 > next_r2 || next_r2 >= N || 0 > next_c2 || next_c2 >= N 
			|| map[cur.r1 + 1][max] == 1 || visited[next_r1][next_c1][next_r2][next_c2] != 0 || map[next_r1][next_c1] == 1 || map[next_r2][next_c2] == 1)){
				visited[next_r1][next_c1][next_r2][next_c2] = 1;
				INFO next;
				next.r1 = next_r1;	next.c1 = next_c1;	next.r2 = next_r2;	next.c2 = next_c2;	next.time = next_time;
				q.push(next);
			}
			
		}
		else{	// 세로방향일 경우 
			int min = cur.r1 < cur.r2 ? cur.r1 : cur.r2;
			int max = cur.r1 < cur.r2 ? cur.r2 : cur.r1;
			
			int next_r1 = max;
			int next_c1 = cur.c1 - 1;
			int next_r2 = max;
			int next_c2 = cur.c1;
			
			if(!(0 > next_r1 || next_r1 >= N || 0 > next_c1 || next_c1 >= N || 0 > next_r2 || next_r2 >= N || 0 > next_c2 || next_c2 >= N 
			|| map[min][cur.c1 - 1] == 1 || visited[next_r1][next_c1][next_r2][next_c2] != 0 || map[next_r1][next_c1] == 1 || map[next_r2][next_c2] == 1)){
				visited[next_r1][next_c1][next_r2][next_c2] = 1;
				INFO next;
				next.r1 = next_r1;	next.c1 = next_c1;	next.r2 = next_r2;	next.c2 = next_c2;	next.time = next_time;
				q.push(next);
			}
			
			next_r1 = max;
			next_c1 = cur.c1 + 1;
			next_r2 = max;
			next_c2 = cur.c1;
			
			if(!(0 > next_r1 || next_r1 >= N || 0 > next_c1 || next_c1 >= N || 0 > next_r2 || next_r2 >= N || 0 > next_c2 || next_c2 >= N 
			|| map[min][cur.c1 + 1] == 1 || visited[next_r2][next_c2][next_r1][next_c1] != 0 || map[next_r1][next_c1] == 1 || map[next_r2][next_c2] == 1)){
				visited[next_r2][next_c2][next_r1][next_c1] = 1;
				INFO next;
				next.r1 = next_r2;	next.c1 = next_c2;	next.r2 = next_r1;	next.c2 = next_c1;	next.time = next_time;
				q.push(next);
			}
			
			next_r1 = min;
			next_c1 = cur.c1 - 1;
			next_r2 = min;
			next_c2 = cur.c1;
			
			if(!(0 > next_r1 || next_r1 >= N || 0 > next_c1 || next_c1 >= N || 0 > next_r2 || next_r2 >= N || 0 > next_c2 || next_c2 >= N 
			|| map[max][cur.c1 - 1] == 1 || visited[next_r1][next_c1][next_r2][next_c2] != 0 || map[next_r1][next_c1] == 1 || map[next_r2][next_c2] == 1)){
				visited[next_r1][next_c1][next_r2][next_c2] = 1;
				INFO next;
				next.r1 = next_r1;	next.c1 = next_c1;	next.r2 = next_r2;	next.c2 = next_c2;	next.time = next_time;
				q.push(next);			
			}
			
			next_r1 = min;
			next_c1 = cur.c1 + 1;
			next_r2 = min;
			next_c2 = cur.c1;
			
			if(!(0 > next_r1 || next_r1 >= N || 0 > next_c1 || next_c1 >= N || 0 > next_r2 || next_r2 >= N || 0 > next_c2 || next_c2 >= N 
			|| map[max][cur.c1 + 1] == 1 || visited[next_r2][next_c2][next_r1][next_c1] != 0 || map[next_r1][next_c1] == 1 || map[next_r2][next_c2] == 1)){
				visited[next_r2][next_c2][next_r1][next_c1] = 1;
				INFO next;
				next.r1 = next_r2;	next.c1 = next_c2;	next.r2 = next_r1;	next.c2 = next_c1;	next.time = next_time;
				q.push(next);		
			}
							
		}
	}
}

int solution(vector<vector<int>> board) {
    map = board;
    N = board.size();
    
    INFO start;
    start.r1 = 0;	start.c1 = 0;start.r2 = 0;	start.c2 = 1;	start.time = 0;
    visited[start.r1][start.c1][start.r2][start.c2] = 1;
    q.push(start);
    bfs();
    
    return ans;
}
