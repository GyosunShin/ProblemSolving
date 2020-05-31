// <R(빨강), G(초록)> , B(파랑)

// 1 ≤ N ≤ 100

#include <cstdio> 
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int N;
char pan[100][100];
bool visited[100][100];

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

queue<pair<int, int>> q;

bool check(char a, char b, int flag){
	// flag
	// 1 : 정상인
	// 2 : 장애인 
	
	if(flag == 1) {
		if(a == b)	return true;
		return false;
	}
	else if(flag == 2){
		if(a == 'R' && b == 'G')	return true;
		if(a == 'G' && b == 'R')	return true;
		if(a == b)	return true;
		return false;
	}
}

void bfs(int start_r, int start_c, int flag){
	
	char start = pan[start_r][start_c];
	visited[start_r][start_c] = true;
	q.push(make_pair(start_r, start_c));
	
	while(!q.empty()){
		int cur_r = q.front().first;	int cur_c = q.front().second;
		q.pop();
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N
			|| visited[next_r][next_c] || !(check(pan[cur_r][cur_c], pan[next_r][next_c], flag)))	continue;
			
			visited[next_r][next_c] = true;
			q.push(make_pair(next_r, next_c));
		}	
	}
	
}

int solve(int flag){
	memset(visited, false, sizeof(visited));
	
	int ret = 0;
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(!visited[i][j]){
				bfs(i, j, flag);
				ret++;
			}
		}
	}
	
	return ret;
}

int main(){
	
	scanf("%d", &N);
	
	getchar();
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%1c", &pan[i][j]);
		}
		getchar();
	}
	
	// OUTPUT : 일반인  장애인
	printf("%d %d", solve(1), solve(2));
	
	return 0;
}


