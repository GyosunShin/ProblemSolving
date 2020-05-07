// n(2≤n≤100)
// 0 <= pan[i][j] <= 200

// OUTPUT
// 첫째 줄에 (최대 - 최소)가 가장 작아질 때의 그 값을 출력한다.

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int pan[100][100];
bool visited[100][100];

int mmax = -1;
int mmin = 0x7fffffff;

queue<pair<int, int>> q;

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

bool bfs(int mid){
	
	for(int z = mmin ; z <= mmax ; ++z){
		memset(visited, false, sizeof(visited));
		if(!(z <= pan[0][0] && pan[0][0] <= (z + mid)))	continue;
	
		while(!q.empty())	q.pop();
		visited[0][0] = true;
		q.push(make_pair(0,0));
		
		while(!q.empty()){
			int cur_r = q.front().first;	int cur_c = q.front().second;
			q.pop();
			
			if(cur_r == (N-1) && cur_c == (N-1))	return true;
			
			for(int dir = 0 ; dir < 4 ; ++dir){
				int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
				
				if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N
				|| visited[next_r][next_c]
				|| !(z <= pan[next_r][next_c] && pan[next_r][next_c] <= z + mid))	continue;
				visited[next_r][next_c] = true;
				q.push(make_pair(next_r, next_c));
			}
		}
	
	}
	
	return false;
}

int solve(){
	int left = 0;
	int right = mmax;
	
	while(left <= right){
		int mid = (left + right) / 2;
		
		if(bfs(mid)){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}	
	}
	
	return left;
}

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &pan[i][j]);
			mmax = max(mmax, pan[i][j]);
			mmin = min(mmin, pan[i][j]);
		}
	}
	
	printf("%d", solve());
	
	return 0;
}


