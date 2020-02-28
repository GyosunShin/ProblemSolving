// 1글자 <= 각 단어 <= 10글자 
// (1 <= N <= 10)
// 테스트 케이스의 수 C(C <= 50)

#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstring> 

using namespace std;

char pan[5][5];
int cache[5][5][10];
int T, N;
string strs[10];


const int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

string global_str;

bool solve(int r, int c, int idx){
//	printf("<%d / %d> [%c]\n",r, c, global_str[idx]);
	
	int& ret = cache[r][c][idx];
	if(ret != -1)	return ret;
	
	if(idx == global_str.size() - 1)	return true;
	
	bool tmp_flag = false;
		
	for(int dir = 0 ; dir < 8 ; ++dir){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		if(0 > next_r || next_r >= 5 || 0 > next_c || next_c >= 5 
		|| pan[next_r][next_c] != global_str[idx+1])	continue;
		tmp_flag = tmp_flag || solve(next_r, next_c, idx+1);
	}
	
	return ret = tmp_flag;
}

void sol(){
	
	for(int z = 0 ; z < N ; ++z){
		bool tmp_flag = false;
		for(int i = 0 ; i < 5 ; ++i){
			if(tmp_flag)	break;
			for(int j = 0 ; j < 5 ; ++j){
				if(pan[i][j] == strs[z][0]){
					memset(cache, -1, sizeof(cache));
					global_str = strs[z];
					if(solve(i, j, 0)){
						tmp_flag = true;
						break;
					}
				}
			}
		}
		if(tmp_flag)	cout << strs[z] << " YES" << endl;
		else	cout << strs[z] << " NO" << endl;
	}
	
}

int main(){
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		getchar();
		for(int i = 0 ; i < 5 ; ++i){
			for(int j = 0 ; j < 5 ; ++j){
				scanf("%1c", &pan[i][j]);
			}
			getchar();
		}		
		
		scanf("%d", &N);	
		for(int i = 0 ; i < N ; ++i){
			cin >> strs[i];
		}
		
		sol();
	}
	return 0;
}
