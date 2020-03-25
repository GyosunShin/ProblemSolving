
// 1 <= N <= 2,000
// 응답완료시간 S "공백" 처리시간 T 
// S : 2016-09-15 hh:mm:ss.sss
// T : 최대 소수점 셋째 자리까지 기록하며 뒤에는 초 단위를 의미하는 s로 끝난다.	 
// 0.001 <= T <= 3.000
// !! (처리시간은 시작시간과 끝시간을 포함) !!

// OUTPUT 
// solution 함수에서는 로그 데이터 lines 배열에 대해 초당 최대 처리량을 리턴한다.

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cmath>

using namespace std;

vector<string> ss;
vector<string> ts;

vector<pair<pair<double, int>, int>> times;	// < <시간, flag(0:시작)(1:끝)> , idx >
vector<pair<double, set<int>>> stamp;

void div(vector<string>& input){
	
	// 2016-09-15 20:59:57.421 0.351s,
	for(int i = 0 ; i < input.size() ; ++i){
		// substr(11, 12)
		ss.push_back(input[i].substr(11,12));
		string tmp = input[i].substr(24);
		tmp.pop_back();
		ts.push_back(tmp);
	}
	
}

void write(){
	
	for(int i = 0 ; i < ss.size() ; ++i){
		int h, m, s;
		double rem;
		
		double start, end;
		
		h = stoi(ss[i].substr(0,2));
		m = stoi(ss[i].substr(3,2));
		s = stoi(ss[i].substr(6,2));
		rem = stod(ss[i].substr(8));
		
		end = (h*3600) + (m*60) + (s) + (rem);
		
		times.push_back({{end, 1}, i});
		
		start = end - stod(ts[i]) + 0.001;
				
		times.push_back({{start, 0}, i});
		
	}
	
}


int solve(){
	
	int ret = -1;
	
	for(int i = 0 ; i < stamp.size() ; ++i){
		double cur_time = stamp[i].first;
		
//		printf("%lf\n", cur_time);
		
		for(int j = i ; j < stamp.size() ; ++j){
//			printf("{{ %lf }}\n", fabs(stamp[j].first - cur_time + (double)0.001));
			if(stamp[j].first - cur_time + (double)0.001 > (double)1.00000001){
//				cout << "BREAK" << endl;
				break;
			}
			
			set<int> tmp;
			
			for(int k = i ; k <= j ; ++k){
				set<int>::iterator it;
				for(it = stamp[k].second.begin() ; it != stamp[k].second.end() ; ++it){
					tmp.insert(*it);
				}
			}
			
			ret = max(ret, (int)tmp.size());
			
		}
		
	}
	
	return ret;
}


int solution(vector<string> lines) {	// 응답완료시간 기준 오름차순 정렬되어 있음 
    
    div(lines);
    
    write();
    
    sort(times.begin(), times.end());
    
    int ans = 0;
    int answer = 0;
    
    set<int> s;
    
    for(int i = 0 ; i < times.size() ; ++i){
    	
    	if(times[i].first.second == 0){	// start
    		s.insert(times[i].second);
    	}
    	
    	stamp.push_back({times[i].first.first, s});
    	
    	if(times[i].first.second == 1){	// end
    		s.erase(times[i].second);
    	}
    	
    	
    }
    
    return solve();
}
