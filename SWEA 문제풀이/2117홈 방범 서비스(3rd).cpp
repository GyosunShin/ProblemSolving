// 운영 비용 = K * K + (K - 1) * (K - 1)

// (5 ≤ N ≤ 20)  (1 ≤ M ≤ 10)

// OUTPUT 
//   이때, 손해를 보지 않으면서 홈방범 서비스를 가장 많은 집들에 제공하는 서비스 영역을 찾고,
//   그 때의 홈방범 서비스를 제공 받는 집들의 수를 출력하는 프로그램을 작성하라.

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int T, N, M;
int pan[20][20];
bool visited[20][20];

int ans = -1 * 0x7fffffff;

queue<pair<int, pair<int, int> > > q;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

void check(int start_r, int start_c){
	memset(visited, false, sizeof(visited));
	while(!q.empty())	q.pop();
	
	int div = 0;
	int cnt = 0;
	int last_dis;
	
	q.push(make_pair(0, make_pair(start_r, start_c)));
	visited[start_r][start_c] = true;
	
	while(!q.empty()){
		int cur_r = q.front().second.first;	int cur_c = q.front().second.second;	int cur_dis = q.front().first;
		last_dis = cur_dis;
		q.pop();
		
		if(cur_dis == 2*N)	break;
		
		if(cur_dis != div){
			int pay = cur_dis * cur_dis + (cur_dis - 1) * (cur_dis - 1);
			if((cnt * M) - pay >= 0){
				ans = max(ans, cnt);
			}
			div = cur_dis;
		}
		
		if(pan[cur_r][cur_c] == 1)	cnt++;
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N || visited[next_r][next_c])	continue;
			visited[next_r][next_c] = true;
			q.push(make_pair(cur_dis + 1, make_pair(next_r, next_c)));
		}
	}
	
	
	int pay = last_dis * last_dis + (last_dis - 1) * (last_dis - 1);
	if((cnt * M) - pay >= 0){
		ans = max(ans, cnt);
	}
	
}


void solve(){
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			check(i, j);
		}
	}
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T; ++z){
		while(!q.empty())	q.pop();
		memset(visited, false, sizeof(visited));;
		ans = -1 * 0x7fffffff;
		scanf("%d %d", &N, &M);	
		
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){	
				// (1 : 집) (0 : 빈칸)
				scanf("%d", &pan[i][j]);		
			}
		}
		
		solve();
		
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}


