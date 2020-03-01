#include <cstdio>
#include <string>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

int T, N, K;
string input;

set<int, greater<int>> ans;

int divv;

void solve(string& todiv){
	
	for(int i = 0 ; i < todiv.size() ; i += divv){
		string tmp = todiv.substr(i, divv);
//		cout << "YO : " << tmp << endl;
		int tmp_sum = 0;
		for(int j = 0 ; j < tmp.size() ; ++j){
			int tttmp = pow(16, divv - j - 1);
			if('A' <= tmp[j] && tmp[j] <= 'F')	tmp_sum += ((tmp[j] - 'A') + 10) * tttmp;
			else	tmp_sum += (tmp[j] - '0') * tttmp;
		}
//		cout << "TMP_SUM : " << tmp_sum << endl;
		ans.insert(tmp_sum);
	}
//	cout << "SIZE : " << ans.size() << endl;
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		ans.clear();
		scanf("%d %d", &N, &K);
		cin >> input;
		
		divv = input.size() / 4;
		solve(input);
		
		string ttmp;
		for(int i = 1 ; i < divv ; ++i){
			ttmp.clear();
			ttmp += input.substr(input.size() - i);
			ttmp += input.substr(0, input.size() - i);
//			cout << "TTMP22 : " << ttmp << endl;
			solve(ttmp);
		}
		
		set<int>::iterator it;
		it = ans.begin();
		
//		for(it = ans.begin() ; it != ans.end() ; ++it){
//			cout << *it << endl;
//		}			
		
		for(int i = 0 ; i < K-1 ; ++i)	++it;
		int tmp_ans = *it;
		printf("#%d %d\n", z, tmp_ans);
	}
	
	return 0;
}
