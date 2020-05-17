// 1 <= R, C, K <= 100

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, K;

int pan[100][100];
bool visited[100][100];

queue<pair<int, int>> q;

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

void pt(){
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			printf("%d", pan[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
}

void mark(int lx, int ly, int rx, int ry){
	// (R-ry, lx) ~~ (R-ry, rx-1)
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// (R-1-ly, lx) ~~ (R-1-ly, rx-1)
	
	for(int i = R-ry ; i <= R-1-ly ; ++i){
		for(int j = lx ; j <= rx - 1 ; ++j){
			pan[i][j] = 1;
		}
	}
}

int solve(int start_r, int start_c){
	
	int ret = 0;
	
	visited[start_r][start_c] = true;
	q.push(make_pair(start_r, start_c));
	
	while(!q.empty()){
		int cur_r = q.front().first;	int cur_c = q.front().second;
		q.pop();
		ret++;
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C 
			|| visited[next_r][next_c] || pan[next_r][next_c] == 1)	continue;
			q.push(make_pair(next_r, next_c));
			visited[next_r][next_c] = true;
		}
		
	}
	
	return ret;
}

int main(){
	scanf("%d %d %d", &R, &C, &K);
	
	for(int i = 0 ; i < K ; ++i){
		int lc, lr, rc, rr;
		scanf("%d %d %d %d", &lc, &lr, &rc, &rr);
		mark(lc, lr, rc, rr);
	}
	
	pt();
	
	vector<int> answer;

	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			if(!visited[i][j] && pan[i][j] != 1){
				int ret = solve(i, j);
//				printf("[%d / %d] : %d\n", i, j , ret);
				answer.push_back(ret);
			}
		}
	}
	
	sort(answer.begin(), answer.end());
	printf("%d\n", answer.size());
	for(int i = 0 ; i < answer.size() ; ++i){
		printf("%d ", answer[i]);	
	}
	
	return 0;
}
