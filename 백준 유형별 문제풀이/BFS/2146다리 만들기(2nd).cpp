// 1 <= N < = 100
// (0 : 바다)  (1 : 육지)

// OUTPUT : 첫째 줄에 가장 짧은 다리의 길이를 출력한다.

#include <cstdio> 
#include <queue>
#include <algorithm>

using namespace std;

int N;
int pan[100][100];
int island[100][100];
bool visited[100][100];
int howfar[100][100];

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

int global_cnt = 1;

queue<pair<int, int>> q;
queue<pair<int, int>> qq;

bool flag;
int flag_cnt = 0x7fffffff;
int ans = 0x7fffffff;

void record(int start_r, int start_c){
	island[start_r][start_c] = global_cnt;
	visited[start_r][start_c] = true;
	q.push({start_r, start_c});
	qq.push(make_pair(start_r, start_c));
	
	while(!q.empty()){
		int cur_r = q.front().first;	int cur_c = q.front().second;
		q.pop();
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N || visited[next_r][next_c]
			|| pan[next_r][next_c] != 1)	continue;
			visited[next_r][next_c] = true;
			island[next_r][next_c] = global_cnt;
			q.push({next_r, next_c});
			qq.push(make_pair(next_r, next_c));
		}
	}
}

void span(){
	
	while(!qq.empty()){
		int cur_r = qq.front().first;	int cur_c = qq.front().second;
//		printf("CUR : %d / %d\n", cur_r, cur_c);
		if(flag && howfar[cur_r][cur_c] > flag_cnt)	return;
		qq.pop();
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N
			|| island[next_r][next_c] == island[cur_r][cur_c])	continue;
			
			if(island[next_r][next_c] != island[cur_r][cur_c] && island[next_r][next_c] != 0
			&& island[cur_r][cur_c] != 0){
//				printf("<%d / %d> / <%d / %d>\n", next_r, next_c, cur_r, cur_c);
				if(!flag){
					flag = true;
					flag_cnt = howfar[cur_r][cur_c];
				}
				ans = min(ans, howfar[next_r][next_c] + howfar[cur_r][cur_c]);
			}
//			printf("NEXT : %d / %d\n", next_r, next_c);
			island[next_r][next_c] = island[cur_r][cur_c];
			howfar[next_r][next_c] = howfar[cur_r][cur_c] + 1;
			qq.push(make_pair(next_r, next_c));
		}
		
		
	}
	
	
	
}

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i)
		for(int j = 0 ; j < N ; ++j)	scanf("%d", &pan[i][j]);
		
		
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ;j < N ; ++j){
			if(!visited[i][j] && pan[i][j] == 1){
				record(i,j);
				global_cnt++;
			}
		}
	}
	
	span();
	printf("%d", ans);
	
	return 0;
}
