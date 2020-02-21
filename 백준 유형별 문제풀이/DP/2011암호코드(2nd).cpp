// � ��ȣ�� �־����� ��, �� ��ȣ�� �ؼ��� �� ������ ���� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

// OUTPUT : 1,000,000���� ���� �������� ����Ѵ�. / ��ȣ�� �߸��Ǿ� ��ȣ�� �ؼ��� �� ���� ��쿡�� 0�� ����Ѵ�.

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
string input;

//  5000�ڸ� ������ ��ȣ
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
