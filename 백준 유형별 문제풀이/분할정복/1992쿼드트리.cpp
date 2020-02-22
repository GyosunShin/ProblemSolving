// 1¡ÂN ¡Â64

#include <cstdio> 
#include <iostream>
#include <string>

using namespace std;

int N;
int pan[64][64];

string solve(int len, int start_r, int start_c){
		
	if(len == 1){
		if(pan[start_r][start_c] == 0)	return "0";
		else if(pan[start_r][start_c] == 1)	return "1";
	}
	
	bool zero_flag = true;	bool one_flag = true;
	for(int i = 0 ; i < len ; ++i){
		for(int j = 0 ; j < len ; ++j){
			if(pan[start_r + i][start_c + j] == 0){
				one_flag = false;
			}
			else if(pan[start_r + i][start_c + j] == 1){
				zero_flag = false;
			}
		}
	}	
	if(zero_flag){
		return "0";
	}
	else if(one_flag){
		return "1";
	}
	
	string tmp_ret = "(";
	int new_len = len / 2;
	tmp_ret += solve(new_len, start_r, start_c);
	tmp_ret += solve(new_len, start_r, start_c + new_len);
	tmp_ret += solve(new_len, start_r + new_len, start_c);
	tmp_ret += solve(new_len, start_r + new_len, start_c + new_len);
	tmp_ret += ")";
	
	return tmp_ret;
}

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%1d", &pan[i][j]);
		}
	}
	
	
//	string ans = "(" + solve(N, 0, 0) + ")";
//	cout << ans;
	
	cout << solve(N, 0, 0);
	
	return 0;
}
