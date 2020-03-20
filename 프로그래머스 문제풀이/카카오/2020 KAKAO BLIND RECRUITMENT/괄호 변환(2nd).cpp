//1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
//2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
//3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
//  3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
//4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
//  4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
//  4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
//  4-3. ')'를 다시 붙입니다. 
//  4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
//  4-5. 생성된 문자열을 반환합니다.

// OUTPUT
// 균형잡힌 괄호 문자열 p가 매개변수로 주어질 때, 주어진 알고리즘을 수행해 올바른 괄호 문자열로 변환한 결과를 return

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check(string& input){
	
	vector<char> tmp;
	
	for(int i = 0 ; i < input.size() ; ++i){
		char cur = input[i];
		
		if(cur == ')'){
			if(tmp.size() > 0 && tmp.back() == '('){
				tmp.pop_back();
			}
			else{
				tmp.push_back(cur);
			}
		}
		else{
			tmp.push_back(cur);
		}
		
	}
	
	if(tmp.size() == 0)	return true;
	return false;
}


string solve(string& str){
		
	if(str.size() == 0)	return str;
	
	if(check(str))	return str;
	
	int cnt1 = 0;	int cnt2 = 0;
	int idx = -1;
	for(int i = 0 ; i < str.size() ; ++i){
		if(cnt1 == cnt2 && cnt1 > 0 && cnt2 > 0){
			idx = i;
			break;
		}
		if(str[i] =='(')	++cnt1;	
		if(str[i] ==')')	++cnt2;
	}
	// idx는 문자열 v의 시작 인덱스
	string u;
	string v;
	if(idx == -1){
		u = str;
		v = "";	
	}
	else{
		u = str.substr(0, idx);
		v = str.substr(idx);
	}
	
//	cout << "U : " << u << endl << "V : " << v << endl;
		
	if(check(u)){	// u가 올바른 문자열이라면 
		// 문자열 v에 대해 1단계부터 다시 수행합니다. 
  		// 3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
  		u += solve(v);
		return u;
	}
	else{	// u가 올바른 문자열이 아니라면 
		string tmp = "(";
		tmp += solve(v);
		tmp += ")";
		//  u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
		u.pop_back();
		u = u.substr(1);
		for(int i = 0 ; i < u.size() ; ++i){
			if(u[i] == '(')	u[i] = ')';
			else if(u[i] == ')')	u[i] = '(';
		}
		tmp += u;
		return tmp;
	}
	
}

string solution(string p) {
    
    return solve(p);
}

