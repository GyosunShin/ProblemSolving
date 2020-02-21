// 어떤 암호가 주어졌을 때, 그 암호의 해석이 몇 가지가 나올 수 있는지 구하는 프로그램을 작성하시오.

// OUTPUT : 1,000,000으로 나눈 나머지를 출력한다. / 암호가 잘못되어 암호를 해석할 수 없는 경우에는 0을 출력한다.

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
string input;

//  5000자리 이하의 암호
int cache[5000];

int str_len;

int solve(int idx){
	if(idx >= str_len)	return 1;
	
	if(input[idx] == '0')	return 0;
	
	int &ret = cache[idx];
	if(ret != -1)	return ret;
	
	int tmp_ret = 0;
	if(idx + 1 < str_len){
		if( (input[idx] == '1') || (input[idx] == '2' && ( '0' <= input[idx+1] && input[idx+1] <= '6')) )	{
			tmp_ret += solve(idx+2);	tmp_ret %= 1000000;
			tmp_ret += solve(idx+1);	tmp_ret %= 1000000;
		}
		else{
			tmp_ret += solve(idx+1);	tmp_ret %= 1000000;
		}
	}
	else{
		tmp_ret += solve(idx+1);	tmp_ret %= 1000000;
	}
	
	return ret = tmp_ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	cin >> input;
	str_len = input.size();	
	
	printf("%d", solve(0));
	
	return 0;
}
