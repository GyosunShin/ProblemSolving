// 게임이 종료되는 턴의 번호를 구해보자.

// 4 ≤ N ≤ 12  /  4 ≤ K ≤ 10
// (0 흰색) (1 빨간색) (2 파란색)
// 행, 열의 번호(1 <=)  , 이동 방향   (1 →) (2 ←) (3 ↑) (4  ↓)

// OUTPUT : 게임이 종료되는 턴의 번호를 출력한다. 그 값이 1,000보다 크거나 절대로 게임이 종료되지 않는 경우에는 -1을 출력한다.

#include <stdio.h> 
#include <queue>
#include <vector>

using namespace std;

int map[12][12];
vector<int> v[12][12];

// 우 좌 상 하 
const int dr[] = {0, 0, -1, 1};
const int dc[] = {1, -1, 0, 0};
// 좌 우 하 상 
const int rev_dr[] = {0, 0, 1, -1};
const int rev_dc[] = {-1, 1, 0, 0};

int N, K;
int loc[11][3];

int dir_change(int input){
	if(input == 0)	return 1;
	if(input == 1)	return 0;
	if(input == 2)	return 3;
	if(input == 3)	return 2;
}

int solve(){
	
	int ret = 1;
	
	while(true){
		if(ret > 1000)	return -1;
		
		for(int i = 1 ; i <= K ; ++i){
			int cur_r = loc[i][0];
			int cur_c = loc[i][1];
			int cur_dir = loc[i][2];
			
//			printf("HORSE : %d / CUR_R : %d / CUR_C : %d / CUR_DIR : %d / RET : %d\n",i , cur_r, cur_c, cur_dir, ret);						
			
			// map : (0 흰색) (1 빨간색) (2 파란색)
			int stack_size = v[cur_r][cur_c].size();
			int where;
			for(int j = 0 ; j < stack_size ; ++j){
				if(v[cur_r][cur_c][j] == i){
					where = j;
					break;
				}
			}
			
			int next_r = cur_r + dr[cur_dir];	int next_c = cur_c + dc[cur_dir];
			
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N){   // 다음 방향이 원판에서 벗어날 경우 
				int rev_r = cur_r + rev_dr[cur_dir];	int rev_c = cur_c + rev_dc[cur_dir];
				if(map[rev_r][rev_c] == 2){
					loc[i][2] = dir_change(cur_dir);
					continue;
				}
				else{
					next_r = rev_r;	next_c = rev_c; cur_dir = dir_change(cur_dir);
					loc[i][2] = cur_dir;
				}
			}
			
			if(map[next_r][next_c] == 2) {  // 갈 자리가 파란 색인 경우 
				int rev_r = cur_r + rev_dr[cur_dir];	int rev_c = cur_c + rev_dc[cur_dir];
				if(0 > rev_r || rev_r >= N || 0 > rev_c || rev_c >= N){
					loc[i][2] = dir_change(cur_dir);								
					continue;
				}
				if(map[rev_r][rev_c] == 2){
					loc[i][2] = dir_change(cur_dir);							
					continue;
				}
				else{
					next_r = rev_r;	next_c = rev_c; cur_dir = dir_change(cur_dir);
					loc[i][2] = cur_dir;
				}				
			}			
			
			if(map[next_r][next_c] == 0) {  // 갈 자리가 흰 색인 경우 
				loc[i][0] = next_r;
				loc[i][1] = next_c;
				for(int k = where ; k < stack_size ; ++k){  // 새로운 곳으로 옮겨주고 
					v[next_r][next_c].push_back(v[cur_r][cur_c][k]);
					loc[v[cur_r][cur_c][k]][0] = next_r;	loc[v[cur_r][cur_c][k]][1] = next_c;
				}
				for(int k = where ; k < stack_size ; ++k){  // 기존의 자리에서 빼준다. 
					v[cur_r][cur_c].pop_back();
				}	
			}
			
			if(map[next_r][next_c] == 1) {  // 갈 자리가 빨간 색인 경우 
				loc[i][0] = next_r;
				loc[i][1] = next_c;
				for(int k = stack_size-1 ; k >= where ; --k){  // 새로운 곳으로 옮겨주고 
					v[next_r][next_c].push_back(v[cur_r][cur_c][k]);
					loc[v[cur_r][cur_c][k]][0] = next_r;	loc[v[cur_r][cur_c][k]][1] = next_c;
				}
				for(int k = where ; k < stack_size ; ++k){  // 기존의 자리에서 빼준다. 
					v[cur_r][cur_c].pop_back();
				}					
			}
			
			
			for(int q = 0 ; q < N ; ++q){
				for(int j = 0 ; j < N ; ++j){
					if(v[q][j].size() >= 4)	return ret;
				}
			}
			
			
		}  // 턴 종료시점 
		ret++;
	}
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);		
		}
	}
	for(int i = 1 ; i <= K ; ++i){
		// 행, 열의 번호(1 <=)  , 이동 방향   (1 →) (2 ←) (3 ↑) (4  ↓)
		int r, c, dir;
		scanf("%d %d %d", &r, &c, &dir);
		r--;
		c--;
		dir--;
		loc[i][0] = r;
		loc[i][1] = c;
		loc[i][2] = dir;
		v[r][c].push_back(i);
	}
	
	printf("%d", solve());
	
	return 0;
}

