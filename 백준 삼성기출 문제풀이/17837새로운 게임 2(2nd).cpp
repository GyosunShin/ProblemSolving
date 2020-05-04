
// 턴이 진행되던 중에 말이 4개 이상 쌓이는 순간 게임이 종료된다.

// 한 말이 이동할 때 위에 올려져 있는 말도 함께 이동한다

// 다음 Target 칸의 색
// 흰색(0) : 그냥 평범하게 이동하여 위에 쌓는다.
// 빨간색(1) : 흰색과 동일하게 이동하여 위에 쌓지만 순서 뒤집는다.
// 파란색(2) (or) 경계 벗어난 경우 : 이동방향 역전시키고 한칸 이동하기

//4 ≤ N(체스판 크기) ≤ 12
//4 ≤ K(말 개수) ≤ 10 

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct INFO{
	int r, c, dir;
};

// 우, 좌, 상, 하 
const int dr[] = {0,0,-1,1};
const int dc[] = {1,-1,0,0};
const int dd[] = {1,0,3,2};

int N, K;
int pan[12][12];	// For) 색깔 
vector<int> track[12][12];

vector<INFO> horses;

bool check(){
		
	for(int i = 0 ; i < horses.size() ; ++i){
		
		int cur_r = horses[i].r;	int cur_c = horses[i].c;	int cur_dir = horses[i].dir;
		int next_r = cur_r + dr[cur_dir];	int next_c = cur_c + dc[cur_dir];	int next_dir = cur_dir;
		
		if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N 
		|| pan[next_r][next_c] == 2){	// 파란색 (or) 범위 벗어난 경우 
			next_dir = dd[next_dir];
			next_r = cur_r + dr[next_dir];	next_c = cur_c + dc[next_dir];
			horses[i].dir = next_dir;
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N || pan[next_r][next_c] == 2){
				continue;
			}
		}
		
		if(pan[next_r][next_c] == 0){	// 흰색
			int idx = 0;
			for(int j = 0 ; j < (int)track[cur_r][cur_c].size() ; ++j){
				if(track[cur_r][cur_c][j] == i){
					idx = j;
					break;
				}
			}
			for(int j = idx ; j < (int)track[cur_r][cur_c].size() ; ++j){
				track[next_r][next_c].push_back(track[cur_r][cur_c][j]);
				horses[track[cur_r][cur_c][j]].r = next_r;	horses[track[cur_r][cur_c][j]].c = next_c;
			}
			int tmp = (int)track[cur_r][cur_c].size() - idx;
			for(int j = 0 ; j < tmp ; ++j){
				track[cur_r][cur_c].pop_back();
			}
		}
		else if(pan[next_r][next_c] == 1){	// 빨간색
			int idx = 0;
			for(int j = 0 ; j < (int)track[cur_r][cur_c].size() ; ++j){
				if(track[cur_r][cur_c][j] == i){
					idx = j;
					break;
				}
			}			
			for(int j = (int)track[cur_r][cur_c].size()-1 ; j >= idx ; --j){
				track[next_r][next_c].push_back(track[cur_r][cur_c][j]);
				horses[track[cur_r][cur_c][j]].r = next_r;	horses[track[cur_r][cur_c][j]].c = next_c;
			}
			int tmp = (int)track[cur_r][cur_c].size() - idx;
			for(int j = 0 ; j < tmp ; ++j){
				track[cur_r][cur_c].pop_back();
			}
		}	
		
		if(track[next_r][next_c].size() >= 4)	return true;	
	}
	
	return false;
}

int solve(){
	int turn = 1;
	
	while(true){
		if(turn > 1000){
			turn = -1;
			break;
		}
		
		if(check()){
			break;
		}
		turn++;
	}
	
	// 게임이 종료되는 턴의 번호를 출력한다. 
	// 그 값이 1,000보다 크거나 절대로 게임이 종료되지 않는 경우에는 -1을 출력한다.
	return turn;
}

int main(){
	scanf("%d %d", &N, &K);
	
	//  (0 : 흰색)  (1 : 빨간색)  (2 : 파란색) 
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	
	int r, c, dir;
	for(int i = 0 ; i < K ; ++i){
		scanf("%d %d %d", &r, &c, &dir);
		r--;	c--;	dir--;
		INFO tmp = {r, c, dir};
		horses.push_back(tmp);
		track[r][c].push_back(i);
	}
	
	printf("%d", solve());
	
	return 0;
}
