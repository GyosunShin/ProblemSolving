// 2 ≤ M(가로),N(세로) ≤ 1,000
// (1 익은)    (0 익지 않은)   (-1 빈칸)

#include <stdio.h> 
#include <queue>
#include <string.h>

using namespace std;

struct INFO{
	int r, c, time;
};

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int R, C;
int map[1000][1000];
int visited[1000][1000];

queue<INFO> q;
int ik, anik, added;

int ans;

void solve(){
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		if(map[cur.r][cur.c] == 0){
			map[cur.r][cur.c] = 1;
			++added;
			if(added == anik){
				ans = cur.time;
				break;
			}
		}
		
		for(int i = 0 ; i < 4 ; ++i){
			int next_r = cur.r + dr[i];	int next_c = cur.c + dc[i];
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || visited[next_r][next_c] != -1 || map[next_r][next_c] == -1){
				continue;
			}
			INFO next;	next.r = next_r;	next.c = next_c;	next.time = cur.time + 1;
			q.push(next);
			visited[next_r][next_c] = 1;
			
		}
		
	}
}

int main(){
	memset(visited, -1, sizeof(visited));
	scanf("%d %d", &C, &R);
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%d", &map[i][j]);	
			if(map[i][j] == 1){
				++ik;
				INFO tmp;
				tmp.r = i;	tmp.c = j;	tmp.time = 0;
				q.push(tmp);
			}
			else if(map[i][j] == 0)	++anik;
		}
	}
	//###############################
	if(anik == 0){
		printf("0");
		return 0;
	}
	
	solve();
		
	if(added == anik){
		printf("%d", ans);
		return 0;
	}
	else{
		printf("-1");
		return 0;
	}
	
	
	return 0;
}
