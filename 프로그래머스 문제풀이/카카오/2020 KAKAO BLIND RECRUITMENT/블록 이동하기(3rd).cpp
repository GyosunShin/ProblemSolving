
// (0 : 빈칸) (1 : 벽)
 
// OUTPUT
// 로봇이 (N, N) 위치까지 이동하는데 필요한 최소 시간을 return

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO{
	int r1, c1, r2, c2;
	int time;
};

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

bool visited[100][100][100][100];

queue<INFO> q;

int N;

bool outcheck(int r1, int c1, int r2, int c2){
	if(0 > r1 || r1 >= N || 0 > r2 || r2 >= N || 0 > c1 || c1 >= N || 0 > c2 || c2 >= N)	return true;
	return false;
}

bool hitcheck(int r1, int c1, int r2, int c2, vector<vector<int>>& pan){
	if(pan[r1][c1] == 1)	return true;
	if(pan[r2][c2] == 1)	return true;
	return false;
}

pair<pair<int, int>, pair<int, int>> garo(int r1, int c1, int r2, int c2, int dir, vector<vector<int>>& pan){
	// (r1, c1) (r2, c2)
	pair<pair<int, int>, pair<int, int>> ret;
	int next_r1 = -1, next_c1 = -1, next_r2 = -1, next_c2 = -1;
	ret.first.first = -1;	ret.first.second = -1;	ret.second.first = -1;	ret.second.second = -1;
	
	if(dir == 0){
		if(0 > r1 - 1)	return ret;
		if(pan[r1-1][c1] == 1 || pan[r1-1][c2] == 1)	return ret;
		next_r1 = r1-1;	next_c1 = c2;	next_r2 = r2;	next_c2 = c2;
		if(visited[next_r1][next_c1][next_r2][next_c2])	return ret;
	}
	else if(dir == 1){
		if(0 > r1 - 1)	return ret;
		if(pan[r1-1][c1] == 1 || pan[r1-1][c2] == 1)	return ret;
		next_r1 = r1-1;	next_c1 = c1;	next_r2 = r1;	next_c2 = c1;
		if(visited[next_r1][next_c1][next_r2][next_c2])	return ret;
	}
	else if(dir == 2){
		if(r1 + 1 >= N)	return ret;
		if(pan[r1+1][c1] == 1 || pan[r1+1][c2] == 1)	return ret;
		next_r1 = r2;	next_c1 = c2;	next_r2 = r2+1;	next_c2 = c2;
		if(visited[next_r1][next_c1][next_r2][next_c2])	return ret;
	}
	else if(dir == 3){
		if(r1 + 1 >= N)	return ret;
		if(pan[r1+1][c1] == 1 || pan[r1+1][c2] == 1)	return ret;
		next_r1 = r1;	next_c1 = c1;	next_r2 = r1+1;	next_c2 = c1;
		if(visited[next_r1][next_c1][next_r2][next_c2])	return ret;
	}
	
	ret.first.first = next_r1;	ret.first.second = next_c1;	ret.second.first = next_r2;	ret.second.second = next_c2;
	return ret;	
}

pair<pair<int, int>, pair<int, int>> sero(int r1, int c1, int r2, int c2, int dir, vector<vector<int>>& pan){
	// (r1, c1)
	// (r2, c2)
	pair<pair<int, int>, pair<int, int>> ret;
	int next_r1 = -1, next_c1 = -1, next_r2 = -1, next_c2 = -1;
	ret.first.first = -1;	ret.first.second = -1;	ret.second.first = -1;	ret.second.second = -1;
	
	if(dir == 0){
		if(0 > c1 - 1)	return ret;
		if(pan[r1][c1-1] == 1 || pan[r2][c2-1] == 1)	return ret;
		next_r1 = r2;	next_c1 = c2-1;	next_r2 = r2;	next_c2 = c2;
		if(visited[next_r1][next_c1][next_r2][next_c2])	return ret;
	}
	else if(dir == 1){
		if(0 > c1 - 1)	return ret;
		if(pan[r1][c1-1] == 1 || pan[r2][c2-1] == 1)	return ret;
		next_r1 = r1;	next_c1 = c1-1;	next_r2 = r1;	next_c2 = c1;
		if(visited[next_r1][next_c1][next_r2][next_c2])	return ret;
	}
	else if(dir == 2){
		if(c1 + 1 >= N)	return ret;
		if(pan[r1][c1+1] == 1 || pan[r2][c2+1] == 1)	return ret;
		next_r1 = r2;	next_c1 = c2;	next_r2 = r2;	next_c2 = c2+1;
		if(visited[next_r1][next_c1][next_r2][next_c2])	return ret;
	}
	else if(dir == 3){
		if(c1 + 1 >= N)	return ret;
		if(pan[r1][c1+1] == 1 || pan[r2][c2+1] == 1)	return ret;
		next_r1 = r1;	next_c1 = c1;	next_r2 = r1;	next_c2 = c1+1;
		if(visited[next_r1][next_c1][next_r2][next_c2])	return ret;
	}
	
	ret.first.first = next_r1;	ret.first.second = next_c1;	ret.second.first = next_r2;	ret.second.second = next_c2;
	return ret;	
}

int solution(vector<vector<int>> board) {
	
	N = board.size();
    
    visited[0][0][0][1] = true;
    INFO start = {0,0,0,1,0};
    q.push(start);
    
    int ans = 0;
    
    while(!q.empty()){
    	INFO cur = q.front();	q.pop();
    	
    	if((cur.r1 == (N-1) && (cur.c1 == (N-1)) || (cur.r2 == (N-1) && (cur.c2 == (N-1))))){
    		ans = cur.time;
    		break;
    	}
    	
    	for(int dir = 0 ; dir < 4 ; ++dir){
    		int next_r1 = cur.r1 + dr[dir];	int next_c1 = cur.c1 + dc[dir];
    		int next_r2 = cur.r2 + dr[dir];	int next_c2 = cur.c2 + dc[dir];
    		if(outcheck(next_r1, next_c1, next_r2, next_c2))	continue;
    		if(hitcheck(next_r1, next_c1, next_r2, next_c2, board))	continue;
    		if(visited[next_r1][next_c1][next_r2][next_c2])	continue;
    		visited[next_r1][next_c1][next_r2][next_c2] = true;
    		INFO next = {next_r1, next_c1, next_r2, next_c2, cur.time + 1};
    		q.push(next);
    	}
    	
    	for(int dir = 0 ; dir < 4 ; ++dir){
    		if(cur.r1 == cur.r2){		// -- 가로모양 
    			if(cur.c1 < cur.c2){
    				pair<pair<int, int>, pair<int, int>> ret = garo(cur.r1, cur.c1, cur.r2, cur.c2, dir, board);
    				if(ret.first.first != -1){
    					visited[ret.first.first][ret.first.second][ret.second.first][ret.second.second] = true;
				   		INFO next = {ret.first.first, ret.first.second, ret.second.first, ret.second.second, cur.time + 1};
    					q.push(next);    					
    				}
    			}
    			else{
    				pair<pair<int, int>, pair<int, int>> ret = garo(cur.r2, cur.c2, cur.r1, cur.c1, dir, board);
    				if(ret.first.first != -1){
    					visited[ret.first.first][ret.first.second][ret.second.first][ret.second.second] = true;
				   		INFO next = {ret.first.first, ret.first.second, ret.second.first, ret.second.second, cur.time + 1};
    					q.push(next);    					
    				}
    			}
    		}
    		else{						// || 세로모양 
    			if(cur.r1 < cur.r2){
    				pair<pair<int, int>, pair<int, int>> ret = sero(cur.r1, cur.c1, cur.r2, cur.c2, dir, board);
    				if(ret.first.first != -1){
    					visited[ret.first.first][ret.first.second][ret.second.first][ret.second.second] = true;
				   		INFO next = {ret.first.first, ret.first.second, ret.second.first, ret.second.second, cur.time + 1};
    					q.push(next);    					
    				}
    			}
    			else{
    				pair<pair<int, int>, pair<int, int>> ret = sero(cur.r2, cur.c2, cur.r1, cur.c1, dir, board);
    				if(ret.first.first != -1){
    					visited[ret.first.first][ret.first.second][ret.second.first][ret.second.second] = true;
				   		INFO next = {ret.first.first, ret.first.second, ret.second.first, ret.second.second, cur.time + 1};
    					q.push(next);    					
    				}
    			}    			
    		}
    	}		// 대각선 처리 
    	
    }	// The End of : while(!q.empty()) 
    
    return ans;
}
