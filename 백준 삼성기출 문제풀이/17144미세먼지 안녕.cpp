#include <stdio.h> 
#include <queue>

using namespace std;

struct INFO{
	int r, c, size;
};

struct PURY{
	int up_r, up_c, down_r, down_c;
};

queue<INFO> q;
 
int R, C, T;
int map[50][50];

PURY pury;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int ans;

void bfs(int year){
	for(int z = 0 ; z < T ; ++z){
		int add[50][50] = { 0, };
		while(!q.empty()){
			INFO cur = q.front();	q.pop();
			
			int cnt = 0;
			for(int dir = 0 ; dir < 4 ; ++dir){
				INFO next;
				next.r = cur.r + dr[dir];	next.c = cur.c + dc[dir];	
				if(0 > next.r || next.r >= R || 0 > next.c || next.c >= C || map[next.r][next.c] == -1){
					continue;
				}
				add[next.r][next.c] += cur.size / 5;
				++cnt;
			}
			map[cur.r][cur.c] -= ((cur.size / 5) * cnt);
		}
		
		// 이제는 map + add
		for(int i = 0 ; i < R ; ++i){
			for(int j = 0 ; j < C ; ++j){
				if(map[i][j] == -1)	continue;
				map[i][j] += add[i][j];
			}
		}
		// 이제 여기까지 미세먼지 확산 완료!
		
		// 이제부터는 공기청정기 가동!
		for(int i = pury.up_r-2 ; i >= 0 ; --i)	map[i+1][0] = map[i][0];
		for(int i = 1 ; i < C ; ++i)	map[0][i-1] = map[0][i];		
		for(int i = 1 ; i <= pury.up_r ; ++i)	map[i-1][C-1] = map[i][C-1];		
		for(int i = C-2 ; i >= 1 ; --i)	map[pury.up_r][i+1] = map[pury.up_r][i];
		map[pury.up_r][1] = 0;
	
		for(int i = pury.down_r+2 ; i <= R-1 ; ++i)	map[i-1][0] = map[i][0];		
		for(int i = 1 ; i <= C-1 ; ++i)	map[R-1][i-1] = map[R-1][i];		
		for(int i = R-2 ; i >= pury.down_r ; --i)	map[i+1][C-1] = map[i][C-1];		
		for(int i = C-2 ; i >= 1 ; --i)	map[pury.down_r][i+1] = map[pury.down_r][i];
		map[pury.down_r][1] = 0;	
		// FAN 순환 완료!
		
		for(int i = 0 ; i < R ; ++i){
			for(int j= 0 ; j < C ; ++j){
				if(0 < map[i][j]){
					INFO tmp;
					tmp.r = i;	tmp.c = j;	tmp.size = map[i][j];
					if(map[i][j] > 0)	q.push(tmp);
				}
			}
		}		
		
	}
	// T년 다 흐름... 
		
	for(int i = 0 ; i < R ; ++i){
		for(int j= 0 ; j < C ; ++j){
			if(map[i][j] > 0)	ans += map[i][j];
		}
	}
	
}

int main(){
	scanf("%d %d %d", &R, &C, &T);
	int flag = 0;
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%d", &map[i][j]);  // -1이면 공기청정기 자리 
			if(map[i][j] == -1 && flag == 0){
				pury.up_r = i;	pury.up_c = j;
				++flag;
			}
			if(map[i][j] == -1 && flag != 0){			
				pury.down_r = i;	pury.down_c = j;
			}
			if(0 < map[i][j]){
				INFO tmp;
				tmp.r = i;	tmp.c = j;	tmp.size = map[i][j];
				q.push(tmp);
			}
		}
	}
	//#############################################################
	
	// 1st) BFS를 통한 미세먼지 확산! 
	bfs(T);
	printf("%d\n", ans);
	return 0;
}
