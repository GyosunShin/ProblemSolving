// 5 <= N <= 100
// build_frame = [x, y, a, b] = [가로좌표, 세로좌표, 설치or삭제할 구조물 종류(0 : 기둥, 1 : 보), 설치(1) or 삭제(0)]

// 구조물은 교차점 좌표를 기준으로 보는 오른쪽, 기둥은 위쪽 방향으로 설치 또는 삭제합니다

// OUTPUT : 모든 명령어를 수행한 후 구조물의 상태를 return 
// [x,y,a] = [가로 좌표, 세로 좌표, (0 : 기둥, 1 : 보)]
// x좌표 오름차순 , y좌표 오름차순, 기둥이 먼저 

#include <string>
#include <vector>
#include <algorithm> 
#include <cstdio>

using namespace std;

const int SIZEMAX = 100;

vector<vector<int>> answer;

bool pan[SIZEMAX*2 + 1][SIZEMAX*2 + 1]; 

int N, real_N;

void install(int x, int y, int what){
	
	int tx, ty;
	
	// 기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
	if(what == 0){ // 기둥 
		tx = x*2;
		ty = y*2 + 1;
		
		if(ty == 1){	// 바닥위에 설치할 경우 
			pan[tx][ty] = true;
		}
		else{
			// 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
			if((ty-2) >= 0 && pan[tx][ty - 2]){
				pan[tx][ty] = true;
			}
			
			if((tx-1) >= 0 && (ty-1) >= 0 && pan[tx-1][ty-1]){
				pan[tx][ty] = true;
			}
			
			if((tx+1) <= real_N && (ty-1) >= 0 && pan[tx+1][ty-1]){
				pan[tx][ty] = true;
			}
			
		}
		
	}
	else if(what == 1){ // 보 
		// 보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
		tx = x*2 + 1;
		ty = y*2;
		
		if(ty == 0)	return;
		
		if((tx-2) >= 0 && (tx+2) <= real_N && pan[tx-2][ty] && pan[tx+2][ty]){
			pan[tx][ty] = true;
		}		
		
		if((tx-1) >= 0 && (ty-1) >= 0 && pan[tx-1][ty-1]){
			pan[tx][ty] = true;
		}		
		
		if((tx+1) <= real_N && (ty-1) >= 0 && pan[tx+1][ty-1]){
			pan[tx][ty] = true;
		}		
	}
	
}

void del(int x, int y, int what){
	
	if(what == 0){ // 기둥 
		int tx = x*2;
		int ty = y*2 + 1;		
		
		bool flag = true;
		
		if((tx+1) <= real_N && (ty+1) <= real_N && pan[tx+1][ty+1]){
			
			bool tmp_flag = false;
			
			if((tx+1) <= real_N && pan[tx+2][ty]){
				tmp_flag = true;
			}
			if((tx-1) >= 0 && (tx+3) <= real_N && (ty+1) <= real_N && (pan[tx-1][ty+1] && pan[tx+3][ty+1])){
				tmp_flag = true;
			}
			
			if(!tmp_flag){
				flag = false;
			}
			
		}
		if(pan[tx-1][ty+1]){
			
			bool tmp_flag = false;
			
			if((tx-2) >= 0 && pan[tx-2][ty]){
				tmp_flag = true;
			}
			if((tx-3) >= 0 && (tx+1) <= real_N && (ty+1) <= real_N && (pan[tx-3][ty+1] && pan[tx+1][ty+1])){
				tmp_flag = true;
			}
			
			if(!tmp_flag){
				flag = false;
			}
			
		}
		if(pan[tx][ty+2]){
			
			if(!pan[tx+1][ty+1] && !pan[tx-1][ty+1]){
				
			}
			
		}
		
		if(flag){
			pan[tx][ty] = false;
		}
		
	}
	else if(what == 1){ // 보 
		int tx = x*2 + 1;
		int ty = y*2;
		
		bool tmp_flag = true;
		
		// 자신의 왼쪽, 오른쪽에 위치한 보	CHECK
		// 자신의 양쪽끝네 걸쳐서 기대고 있는 기둥 CHECK 
		if(pan[tx+2][ty]){
			if( !( (pan[tx+1][ty-1]) || (pan[tx+3][ty-1]) ) ){
				tmp_flag = false;
			}
		}
		if(pan[tx-2][ty]){
			if( !( (pan[tx-1][ty-1]) || (pan[tx-3][ty-1]) ) ){
				tmp_flag = false;
			}
		}
		if(pan[tx-1][ty+1]){
			if( ! ( pan[tx-2][ty] || pan[tx-1][ty-1] )){
				tmp_flag = false;
			}
		}
		if(pan[tx+1][ty+1]){
			if( ! ( pan[tx+1][ty-1] || pan[tx+2][ty] )){
				tmp_flag = false;
			}
		}
		
		if(tmp_flag){
			pan[tx][ty] = false;
		}				
		
	}	
	
}

void check(){
	// [가로 좌표, 세로 좌표, (0 : 기둥, 1 : 보)]
	
	for(int x = 0 ; x <= real_N ; ++x){
		for(int y = 0 ; y <= real_N ; ++y){
			if(pan[x][y]){
				vector<int> tmp;
				if(x % 2 == 0){	// 기둥 0 
					tmp.push_back(x / 2);
					tmp.push_back(y / 2);
					tmp.push_back(0);
				}
				else{	// 보 1 
					tmp.push_back(x / 2);
					tmp.push_back(y / 2);
					tmp.push_back(1);
				}
				answer.push_back(tmp);
			}
		}
	}
	
}

void solve(vector<vector<int>>& input){
	// [가로좌표, 세로좌표, 설치or삭제할 구조물 종류(0 : 기둥, 1 : 보), 설치(1) or 삭제(0)]
	
	for(int i = 0 ; i < input.size() ; ++i){
		if(input[i][3] == 1){	// 설치 
			install(input[i][0], input[i][1], input[i][2]);
		}
		else if(input[i][3] == 0){	// 삭제 
			del(input[i][0], input[i][1], input[i][2]);
		}
	}
	
	check();
	
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	N = n;
	real_N = N*2;
	
	solve(build_frame);
	
	sort(answer.begin(), answer.end());
    return answer;
}
