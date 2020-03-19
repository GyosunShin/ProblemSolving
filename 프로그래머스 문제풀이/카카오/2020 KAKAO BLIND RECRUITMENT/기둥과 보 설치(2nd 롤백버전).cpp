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
bool pan[SIZEMAX*2 + 1][SIZEMAX*2 + 1]; 

vector<vector<int>> answer;

int N, real_N;

bool install(int x, int y, int what, bool test){
	
	bool ret = false;
	
	int tx, ty;
	
	// ����� �ٴ� ���� �ְų� ���� ���� �� �κ� ���� �ְų�, �Ǵ� �ٸ� ��� ���� �־�� �մϴ�.
	if(what == 0){ // ��� 
		tx = x*2;
		ty = y*2 + 1;
		if(test){
			tx = x;
			ty = y;
		}
		
		if(ty == 1){	// �ٴ����� ��ġ�� ��� 
			pan[tx][ty] = true;
			ret = true;
		}
		else{
			// ���� ���� �� �κ� ���� �ְų�, �Ǵ� �ٸ� ��� ���� �־�� �մϴ�.
			
			if((ty-2) >= 0 && pan[tx][ty - 2]){
				pan[tx][ty] = true;
				ret = true;
			}
			
			if((tx-1) >= 0 && (ty-1) >= 0 && pan[tx-1][ty-1]){
				pan[tx][ty] = true;
				ret = true;
			}
			
			if((tx+1) <= real_N && (ty-1) >= 0 && pan[tx+1][ty-1]){
				pan[tx][ty] = true;
				ret = true;
			}
			
		}
		
	}
	else if(what == 1){ // �� 
		// ���� ���� �� �κ��� ��� ���� �ְų�, �Ǵ� ���� �� �κ��� �ٸ� ���� ���ÿ� ����Ǿ� �־�� �մϴ�.
		tx = x*2 + 1;
		ty = y*2;
		if(test){
			tx = x;
			ty = y;
		}		
		
		if(ty == 0)	return false;
		
		if((tx-2) >= 0 && (tx+2) <= real_N && pan[tx-2][ty] && pan[tx+2][ty]){
			pan[tx][ty] = true;
			ret = true;
		}		
		
		if((tx-1) >= 0 && (ty-1) >= 0 && pan[tx-1][ty-1]){
			pan[tx][ty] = true;
			ret = true;
		}		
		
		if((tx+1) <= real_N && (ty-1) >= 0 && pan[tx+1][ty-1]){
			pan[tx][ty] = true;
			ret = true;
		}		
	} 
		
	return ret;
	
}

void del(int x, int y, int what){
	
	int tx, ty;
	
	if(what == 0){ // ��� 
		tx = x*2;
		ty = y*2 + 1;	
	}
	else if(what == 1){ // �� 
		tx = x*2 + 1;
		ty = y*2;
	}
	
	pan[tx][ty] = false;
	
	bool flag = true;
	
	for(int i = 0 ; i <= real_N ; ++i){
		if(!flag)	break;
		for(int j = 0 ; j <= real_N ; ++j){
			if(pan[i][j]){
				bool tmp_flag;
				if(i%2 == 0)	tmp_flag = install(i, j, 0, true);
				else	tmp_flag = install(i, j, 1, true);
				if(!tmp_flag){
					flag = false;
					break;
				}
				
			}
		}
	}
	
	if(!flag){
		pan[tx][ty] = true;	
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
			install(input[i][0], input[i][1], input[i][2], false);
		}
		else if(input[i][3] == 0){	// ���� 
			del(input[i][0], input[i][1], input[i][2]);
		}
	}
	
	check();
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame){
	N = n;
	real_N = N*2;
	solve(build_frame);
	
	sort(answer.begin(), answer.end());
    return answer;
}
