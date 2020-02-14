#include <cstdio>
#include <string>
#include <set>
#include <cmath>
#include <functional>
#include <iostream>

using namespace std;

int T, N, K;
string str;

set<int, greater<int>> s;

int trans(string input){
	int ret = 0;
	int size = input.size();
	for(int i = 0 ; i < input.size() ; ++i){
		int now = pow(16, (size-1-i));
		int next;
		char tmp = input[i];
		if('0' <= tmp && tmp <= '9'){
			next = tmp - '0';
		}
		else if('A' <= tmp && tmp <= 'F'){
			next = tmp - 'A' + 10;
		}
		ret += now * next;
	}
	return ret;
}


int solve(string input){
	
	int div = input.size() / 4;
	// (div)(div)(div)(div)
	 
	for(int i = 0 ; i <= div ; ++i){
		int ret = 0;
		string tmp = input.substr(0, input.size() - i);
		string ttmp = input.substr(input.size() - i);
		string tttmp = ttmp + tmp;
		
		for(int j = 0 ; j < tttmp.size() ; j += div){
			string yo = tttmp.substr(j, div);
			int p = trans(yo);
//			cout << "PEACe : " << p << endl;
			s.insert(p);
		}
	}
	
	set<int>::iterator it;
//	
//	for(it = s.begin() ; it != s.end() ; ++it){
//		cout << *it << endl;
//	}	
	
	it = s.begin();
	for(int i = 0 ; i < K-1 ; ++i)	++it;
	return *it;
}

int main(){
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		s.clear();
		scanf("%d %d", &N, &K);
		cin >> str;
		int ans = solve(str);
		printf("#%d %d\n", z, ans);
	}
	return 0;
}

