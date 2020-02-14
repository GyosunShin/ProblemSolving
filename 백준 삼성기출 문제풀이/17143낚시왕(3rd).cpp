// (2 ≤ R, C ≤ 100, 0 ≤ M ≤ R×C)
// r, c, s, d, z (1 ≤ r ≤ R, 1 ≤ c ≤ C, 0 ≤ s(속력) ≤ 1000, 1 ≤ d(이동방향) ≤ 4, 1 ≤ z(크기) ≤ 10000)
// d: 1위 / 2아래 / 3오른쪽 / 4왼쪽 
// 
// OUTPUT : 낚시왕이 잡은 상어 크기의 합을 출력한다. 

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

struct INFO{
	int s, d, z;   // 속도, 방향, 크기 
};

int R, C, M;

INFO map[2][100][100];

const int dr[] = {-1, 1, 0, 0};  // 상 하 우 좌 
const int dc[] = {0, 0, 1, -1};

int seq = 0; 

int ans; 

queue<pair<int, int> > loc[2];

int main(){
	scanf("%d %d %d", &R, &C, &M);
	for(int m = 0 ; m < M ; ++m){
		int r, c, s, d, z;
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		INFO tmp;	tmp.s = s;	tmp.d = d-1;	tmp.z = z;
		map[seq][r-1][c-1] = tmp;
		loc[seq].push(pair<int, int>(r-1, c-1));
	}
	
	//#################################################
	
	for(int i = 0 ; i < C ; ++i){
		// 일단 먼저 먹는다.
		for(int j = 0 ; j < R ; ++j) {
			if(map[seq][j][i].z > 0){  // 상어가 존재할 경우  먹고 상어 지워준다. 
				ans += map[seq][j][i].z;
				map[seq][j][i].s = 0;	map[seq][j][i].d = 0;	map[seq][j][i].z = 0;   // 비우기! 
				break;	
			}	
		}
		
		if(i == C-1)	break;
		
		// 이젠  상어 움직여준다.
		int next_seq;
		if(seq == 0)	next_seq = 1;
		else if(seq == 1)	next_seq = 0;
		
		memset(map[next_seq], 0, sizeof(map[next_seq]));
		
		// 다음 위치 찾자...
		while(!loc[seq].empty()){
			int cur_r = loc[seq].front().first;	int cur_c = loc[seq].front().second;	loc[seq].pop();
			int cur_dir = map[seq][cur_r][cur_c].d;   // 0 : 상  | 1 : 하 | 2 : 우 | 3 : 좌 
			int cur_speed = map[seq][cur_r][cur_c].s;
			int cur_size = map[seq][cur_r][cur_c].z;
			
			
			for(int z = 0 ; z < cur_speed ; ++z){
				cur_r += dr[cur_dir];	cur_c += dc[cur_dir];
				if(0 > cur_r || cur_r >= R || 0 > cur_c || cur_c >= C){
					cur_r -= dr[cur_dir];	cur_c -= dc[cur_dir];	
					if(cur_dir == 0)	cur_dir = 1;
					else if(cur_dir == 1)	cur_dir = 0;
					else if(cur_dir == 2)	cur_dir = 3;
					else if(cur_dir == 3)	cur_dir = 2;
					cur_r += dr[cur_dir];	cur_c += dc[cur_dir];	
				}
			}
			
			if(map[next_seq][cur_r][cur_c].z > 0){  // 이미 누가 있으면 크기 비교해서 
				if(cur_size > map[next_seq][cur_r][cur_c].z){  // 새로운게 더 클경우 
					map[next_seq][cur_r][cur_c].z = cur_size;
					map[next_seq][cur_r][cur_c].s = cur_speed;
					map[next_seq][cur_r][cur_c].d = cur_dir;	
				}
			}
			else{
				loc[next_seq].push(pair<int,int>(cur_r, cur_c));
				map[next_seq][cur_r][cur_c].z = cur_size;
				map[next_seq][cur_r][cur_c].s = cur_speed;
				map[next_seq][cur_r][cur_c].d = cur_dir;					
			}
			
			
		}
		
		
		seq = next_seq;	 
	}
	
	printf("%d", ans);
	return 0;
}





