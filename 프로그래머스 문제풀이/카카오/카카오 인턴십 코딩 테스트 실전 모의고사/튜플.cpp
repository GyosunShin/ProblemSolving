// 순서고려

// s가 표현하는 튜플을 배열에 담아 return

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

vector<int> answer;
vector<vector<int>> pan;

// 1 이상 100,000 이하인 자연수
map<int, int> m;

bool comp(vector<int>& a, vector<int>& b){
	return a.size() < b.size();
}

bool cmp(pair<int, int>& a, pair<int, int>& b){
	return a.second > b.second;
}

void solve(){
	
	// pan이용해서 풀이
	for(int i = 0 ; i < pan.size() ; ++i){
		for(int j = 0 ; j < pan[i].size() ; ++j){
			m[pan[i][j]]++;
		}	
	}
	
	vector<pair<int, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	
	for(int i = 0 ; i < v.size() ; ++i){
		answer.push_back(v[i].first);
	}
	
	
}

vector<int> solution(string s) {
    
    s.erase(s.begin());	
	s.erase(--s.end());
	
	while(true){
		
		int start, end;
		start = s.find('{');
		end = s.find('}');
		
		string subset = s.substr(start+1, end-start-1);
		
		vector<int> sub;
		
		stringstream ss(subset);
		string token;
		
		while(getline(ss, token, ',')){
			sub.push_back(stoi(token));
		}
		
		pan.push_back(sub);
		
		s.erase(0, end+1);
		if(s.size() <= 0)	break;
		
	}
	
	sort(pan.begin(), pan.end(), comp);
	
	
	solve();
	
	
//	for(int i = 0 ; i < pan.size() ; ++i){
//		for(int j = 0 ; j < pan[i].size() ; ++j){
//			cout << pan[i][j] << ", ";	
//		}
//		cout << endl;	
//	}
//	cout << endl;
	
    
    return answer;
}
