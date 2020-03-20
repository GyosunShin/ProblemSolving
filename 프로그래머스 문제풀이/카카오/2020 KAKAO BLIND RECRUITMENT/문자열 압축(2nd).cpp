//  1�� �̻� ������ ���ڿ��� �߶� �����Ͽ� ǥ���� ���ڿ� �� ���� ª�� ���� ���̸� return

// 1 <= S�� ���� <= 1000
// ��� �ҹ��� 

#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int solve(int unit, string& str){
	
	string ret;
	
	string start = str.substr(0, unit);
	int cnt = 1;
	for(int i = unit ; i < str.size() ; i = i+unit){
		
		if(start == str.substr(i, unit)){
			++cnt;
		}
		else{
			if(cnt == 1){
				ret += start;	
			}
			else{
				ret += to_string(cnt);
				ret += start;	
			}
			cnt = 1;
			start = str.substr(i, unit);
		}
		
	}
	
	if(cnt >= 1){
		if(cnt == 1){
			ret += start;	
		}
		else{
			ret += to_string(cnt);
			ret += start;	
		}
	}
	
//	cout << ret << endl;
	return ret.size();
	
}

int solution(string s) {
    int answer = 0x7fffffff;
    
    for(int i = 1 ; i <= s.size() ; ++i){
    	answer = min(answer, solve(i, s));
    }
    
    return answer;
}
