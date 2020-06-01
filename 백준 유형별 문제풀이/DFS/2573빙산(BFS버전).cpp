// (0 : 바다) (1~ : 빙산 높이)

// OUTPUT
// 한 덩어리의 빙산이 주어질 때, 
// 이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하는 프로그램을 작성

// !!!! 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력한다. !!!!

// 3 <= R, C <= 300

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int R, C;
int pan[300][300];
int backup[300][300];
bool visited[300][300];

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

queue<pair<int, int>> q;

void bfs(int start_r, int start_c){
	
	while(!q.empty())	q.pop();
	
	q.push(make_pair(start_r, start_c));
	visited[start_r][start_c] = true;
	
	while(q.empty() == 0){
		int cur_r = q.front().first;	int cur_c = q.front().second;
		q.pop();
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C
			|| visited[next_r][next_c] || pan[next_r][next_c] <= 0)	continue;
			
			q.push(make_pair(next_r, next_c));
			visited[next_r][next_c] = true;
		}
	}
	
}

int check(){
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	int flag = 0;
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			if(!visited[i][j] && pan[i][j] > 0){
				bfs(i, j);
				cnt++;
			}
			if(pan[i][j] > 0)	++flag;
		}
	}
	if(flag <= 0){
		return -1;
	}
	return cnt;
}

void melt(){
	
	for(int i = 0 ; i < R ; ++i)
		for(int j = 0 ; j < C ; ++j)
			backup[i][j] = pan[i][j];
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			if(backup[i][j] > 0){
				int tmp = 0;
				for(int dir = 0 ; dir < 4 ; ++dir){
					int next_r = i + dr[dir];	int next_c = j + dc[dir];
					if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C)	continue;
					if(backup[next_r][next_c] <= 0)	tmp++;
				}
				pan[i][j] -= tmp;
			}
		}
	}
	
}

int solve(){
	int ret = 0;
	
	while(true){
		int piece = check();
		if(piece == -1)	return 0;
		if(piece >= 2)	return ret;
		
		melt();
		
		ret++;
	}
	
	return ret;
}

int main(){
	scanf("%d %d", &R, &C);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	
	int ret = solve();
	printf("%d", ret);
	
	return 0;
}
