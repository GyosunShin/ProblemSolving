// T
// P
// 1 <=  T, P <= 1,000,000 

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

string T, P;

// N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해 pi[] rPtks
// pi[i] = N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
vector<int>  getPartialMatch(const string& N){
	
	int m = N.size();
	vector<int> pi(m, 0);
	
	// KMP로 자신을 찾는다.
	// N을 N에서 찾는다. begin = 0이면 자기 자신을 찾아버리니까 안됨!
	int begin = 1;
	int matched = 0;
	
	// 비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록
	while(begin + matched < m) {
		
		if(N[begin + matched] == N[matched]){
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else{
			if(matched == 0)	++begin;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return pi;
}


// '짚더미'  H의 모든 부분 문자열로 '바늘' N이 출현하는 시작 위치들을 모두 반환
vector<int> kmpSearch(const string& H, const string& N){
	
	int n = H.size();
	int m = N.size();
	
	vector<int> ret;
	
	// pi[i] = N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이 
	vector<int> pi = getPartialMatch(N);
	
	// begin = matched = 0에서부터 시작
	int begin = 0;
	int matched = 0;
	
	while(begin <= n - m) {
		// 만약 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
		if(matched < m && H[begin + matched] == N[matched]) {
			++matched;
			if(matched == m)	ret.push_back(begin);
		}
		else{
			// 예외 : matched가 0인 경우에는 다음 칸에서부터 계속
			if(matched == 0) 	++begin;
			else{
				begin += matched - pi[matched-1];
				
				// begin을 옮겼다고 해도 처음부터 다시 시작할 필요 없다.
				// 옮긴 후에도 pi[matched-1]만큼은 항상 일치하기 때문
				matched = pi[matched-1] ;
			}
		}
	}
	
	return ret;
}

int main(){
	
	getline(cin, T);
	getline(cin, P);
	
	vector<int> ret = kmpSearch(T, P);
	
	cout << ret.size() << endl;
	
	for(int i = 0 ; i < ret.size() ; ++i){
		cout << ret[i] + 1 << " ";
	}
	
	return 0;
}
