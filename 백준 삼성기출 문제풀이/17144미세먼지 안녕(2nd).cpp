// OUTPUT : T초가 지난 후 구사과의 방에 남아있는 미세먼지의 양을 구해보자.

// INPUT :  R, C, T (6 ≤ R, C ≤ 50, 1 ≤ T ≤ 1,000) 
// Ar,c (-1 ≤ Ar,c ≤ 1,000)

#include <stdio.h>
#include <queue> 
#include <string.h>

using namespace std;

struct DUST{
	int r, c;
};

queue<DUST> q;

int R, C, T;

int map[50][50];
int new_dust[50][50];

int clean1_r, clean1_c;
int clean2_r, clean2_c;
int flag = 0;


const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int main(){
	scanf("%d %d %d", &R, &C, &T);
	for(int i = 0 ; i < R ; ++i){
		for(int j  = 0 ; j < C ; ++j){
			scanf("%d", &map[i][j]);
			if(map[i][j] == -1){
				if(flag == 0)	{
					flag = 1;
					clean1_r = i;	clean1_c = j;
				}
				else if(flag == 1){
					clean2_r = i;	clean2_c = j;
				}
			}
			else if(map[i][j] > 0){
				DUST tmp;	tmp.r = i;	tmp.c = j;
				q.push(tmp);
			}
		}
	}
	//#################################
	
	for(int z = 0 ; z < T ; ++z){  // T초 동안 수행 
		// 일단 미세먼지 확산
		while(!q.empty()){
			int cnt = 0;
			DUST cur = q.front();	q.pop();
			
			for(int dir = 0 ; dir < 4 ; ++dir){
				int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
				if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || map[next_r][next_c] == -1)	continue;
				++cnt;
				DUST next;	next.r = next_r;	next.c = next_c;
				new_dust[next_r][next_c] += (int)(map[cur.r][cur.c] / 5);
			}
			
			int new_dust_v = map[cur.r][cur.c];
			new_dust_v = new_dust_v - (((int)(new_dust_v/5)) * cnt);
			map[cur.r][cur.c] = new_dust_v;
		}
		
		for(int i = 0 ; i < R ; ++i){
			for(int j  = 0 ; j < C ; ++j){
				map[i][j] += new_dust[i][j];
				new_dust[i][j] = 0;
			}
		}
		// 미세먼지 확산 완료
		
		// 이젠 공기청정 ㄱㄱ
		//int clean1_r, clean1_c;
		//int clean2_r, clean2_c;
		
		for(int i = clean1_r - 2 ; i >= 0 ; --i){
			map[i+1][0] = map[i][0];
		}
		for(int i = 1 ; i < C ; ++i){
			map[0][i-1] = map[0][i];
		}
		for(int i = 1 ; i <= clean1_r ; ++i){
			map[i-1][C-1] = map[i][C-1];
		}
		for(int i = C-2 ; i >= 1 ; --i){
			map[clean1_r][i+1] = map[clean1_r][i];
		}
		map[clean1_r][clean1_c+1] = 0;
		
		for(int i = clean2_r + 2 ; i <= R-1 ; ++i){
			map[i-1][0] = map[i][0];
		}
		for(int i = 1 ; i < C ; ++i){
			map[R-1][i-1] = map[R-1][i];
		}
		for(int i = R-2 ; i >= clean2_r ; --i){
			map[i+1][C-1] = map[i][C-1];
		}
		for(int i = C-2 ; i >= 1 ; --i){
			map[clean2_r][i+1] = map[clean2_r][i];
		}
		map[clean2_r][clean2_c+1] = 0;	 
		
		for(int i = 0 ; i < R ; ++i){
			for(int j= 0 ; j < C ; ++j){
				if(0 < map[i][j]){
					DUST tmp;
					tmp.r = i;	tmp.c = j;
					if(map[i][j] > 0)	q.push(tmp);
				}
			}
		}	
	}
	
	int ans = 0;
	
	for(int i = 0 ; i < R ; ++i){
		for(int j  = 0 ; j < C ; ++j){
			if(map[i][j] > 0)	ans += map[i][j];
		}
	}
	
	printf("%d", ans);	
	
	return 0;
}





