
// 1 <= N <= 2,000

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

vector<pair<int, pair<int, int> > >	v;	// (누구인지 IDX (start:0(or)end:1, 시간) )
set<int> s;

bool comp(pair<int, pair<int, int> >& a, pair<int, pair<int, int> >& b){
	
	if(a.second.second == b.second.second)	return a.second.first < b.second.first;
	return a.second.second < b.second.second;
	
}

void divide(vector<string>& input){
	
	for(int i = 0 ; i < input.size() ; ++i){
		
		string s = input[i].substr(11, 12);
		string t = input[i].substr(24);
		t.pop_back();
		int h = stoi(s.substr(0,2));
		int m = stoi(s.substr(3,2));
		int se = stoi(s.substr(6,2));
		int ss = stoi(s.substr(9));
		
		int end = (h * 3600 * 1000) + (m * 60 * 1000) + (se * 1000) + (ss);
		
		// 종료시간
		v.push_back(make_pair(i, make_pair(1, end)));
		
		int target = t.find('.');
		int tss = 0;
		if(target == -1){
			tss += 1000 * stoi(t);
		}
		else{
			int ts = stoi(t.substr(0, target));
			string tmp = t.substr(target + 1);
			for(int j = 0 ; j < tmp.size() ; ++j){
				tss += (tmp[j] - '0') * pow(10, 2-j);
			}
			tss += 1000 * ts;
		}
		int start = end - tss + 1;
		
		if(start <= 0)	start = 0;
			
		// 시작시간
		v.push_back(make_pair(i, make_pair(0, start)));
	}
	
}

int solve(){
	
	int mmax = 0;
	
	for(int i = 0 ; i < v.size() ; ++i){
		int now = v[i].second.second;
				
		if(v[i].second.first == 0){
			s.insert(v[i].first);
			int cur = (int)s.size();
			for(int j = i + 1 ; j < v.size() ; ++j){
				if(v[j].second.second >= now + 1000)	break;
				if(v[j].second.first == 0)	cur++;
			}
			mmax = max(mmax, cur);					
		}
		else{
			
			int cur = (int)s.size();
			for(int j = i + 1 ; j < v.size() ; ++j){
				if(v[j].second.second >= now + 1000)	break;
				if(v[j].second.first == 0)	cur++;
			}
			
			mmax = max(mmax, cur);
			s.erase(v[i].first);
		}				

	}	

	return mmax;
}

int solution(vector<string> lines) {
    
    // EX) 2016-09-15 20:59:57.421 0.351s,
    // 응답완료시간 S ==> 2016-09-15 hh:mm:ss.sss
    // 처리시간 T ==> 0.1s, 0.312s, 2s   (0.001 <=  <= 3.000)
    // 응답완료시간 S를 기준으로 오름차순 정렬
    
    divide(lines);
    	
    sort(v.begin(), v.end(), comp);
    
    int ret = solve();
    
    // OUTPUT
    // 초당 최대 처리량을 리턴한다.
    
    return ret;
}
