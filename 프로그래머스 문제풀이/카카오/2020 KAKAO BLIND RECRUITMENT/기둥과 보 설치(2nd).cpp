// 5 <= N <= 100
// build_frame = [x, y, a, b] = [������ǥ, ������ǥ, ��ġor������ ������ ����(0 : ���, 1 : ��), ��ġ(1) or ����(0)]

// �������� ������ ��ǥ�� �������� ���� ������, ����� ���� �������� ��ġ �Ǵ� �����մϴ�

// OUTPUT : ��� ��ɾ ������ �� �������� ���¸� return 
// [x,y,a] = [���� ��ǥ, ���� ��ǥ, (0 : ���, 1 : ��)]
// x��ǥ �������� , y��ǥ ��������, ����� ���� 

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
	
	// ����� �ٴ� ���� �ְų� ���� ���� �� �κ� ���� �ְų�, �Ǵ� �ٸ� ��� ���� �־�� �մϴ�.
	if(what == 0){ // ��� 
		tx = x*2;
		ty = y*2 + 1;
		
		if(ty == 1){	// �ٴ����� ��ġ�� ��� 
			pan[tx][ty] = true;
		}
		else{
			// ���� ���� �� �κ� ���� �ְų�, �Ǵ� �ٸ� ��� ���� �־�� �մϴ�.
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
	else if(what == 1){ // �� 
		// ���� ���� �� �κ��� ��� ���� �ְų�, �Ǵ� ���� �� �κ��� �ٸ� ���� ���ÿ� ����Ǿ� �־�� �մϴ�.
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
	
	if(what == 0){ // ��� 
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
	else if(what == 1){ // �� 
		int tx = x*2 + 1;
		int ty = y*2;
		
		bool tmp_flag = true;
		
		// �ڽ��� ����, �����ʿ� ��ġ�� ��	CHECK
		// �ڽ��� ���ʳ��� ���ļ� ���� �ִ� ��� CHECK 
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
	// [���� ��ǥ, ���� ��ǥ, (0 : ���, 1 : ��)]
	
	for(int x = 0 ; x <= real_N ; ++x){
		for(int y = 0 ; y <= real_N ; ++y){
			if(pan[x][y]){
				vector<int> tmp;
				if(x % 2 == 0){	// ��� 0 
					tmp.push_back(x / 2);
					tmp.push_back(y / 2);
					tmp.push_back(0);
				}
				else{	// �� 1 
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
	// [������ǥ, ������ǥ, ��ġor������ ������ ����(0 : ���, 1 : ��), ��ġ(1) or ����(0)]
	
	for(int i = 0 ; i < input.size() ; ++i){
		if(input[i][3] == 1){	// ��ġ 
			install(input[i][0], input[i][1], input[i][2]);
		}
		else if(input[i][3] == 0){	// ���� 
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
