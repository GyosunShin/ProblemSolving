// 1 : 집 | 0: 집 없음
//  5≤N≤25

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct INFO{
	int r, c;	
};

int N;
int map[25][25];
int visited[25][25];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

queue<INFO> q;
vector<int> nums;

int cnt;

int bfs(int r, int c){
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();	
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
			
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N || map[next_r][next_c] == 0 || visited[next_r][next_c] != 0){
				continue;
			}
			INFO next;	next.r = next_r;	next.c = next_c;
			visited[next_r][next_c] = 1;
			cnt++;
			q.push(next);
		}
	}
	
	return cnt;
}

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%1d", &map[i][j]);
		}
	}
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(visited[i][j] == 0 && map[i][j] != 0){
				cnt = 1;
				visited[i][j] = 1;
				INFO start;
				start.r = i;	start.c = j;
				printf("START_R : %d / START_C : %d\n", i, j);
				q.push(start);
				nums.push_back(bfs(i, j));
			}
		}
	}	
	
	printf("%d\n", nums.size());
	sort(nums.begin(), nums.end());
	for(int i = 0 ; i < nums.size() ; ++i){
		printf("%d\n", nums[i]);
	}
	
	return 0;
}
 
