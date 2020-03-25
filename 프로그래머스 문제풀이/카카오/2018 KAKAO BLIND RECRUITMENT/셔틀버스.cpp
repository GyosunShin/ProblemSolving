

// 셔틀 운행 횟수 n,    		셔틀 운행 간격 t, 			한 셔틀에 탈 수 있는 최대 크루 수 m
//     0 < n <= 10				   0 < t <= 60							0 < m <= 45

//  콘은 게으르기 때문에 같은 시각에 도착한 크루 중 대기열에서 제일 뒤에 선다

// OUTPUT : 콘콘이 무사히 셔틀을 타고 사무실로 갈 수 있는 제일 늦은 도착 시각을 출력한다

#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct INFO{
	int ho, mi, no;
};

struct cmp{
    bool operator()(const INFO &a, const INFO &b){
    	// 이렇게 하면 작은거 부터 나온다 --> sort()함수와 반대다 
    	if(a.ho == b.ho && a.mi == b.mi)	return a.no > b.no;
    	if(a.ho == b.ho)	return a.mi > b.mi;
    	return a.ho > b.ho;
    }
};

int N, T, M;

int global_order;

// 인덱스 N-1까지만 유효한 셔틀버스 행 
priority_queue<INFO, vector<INFO>, cmp> q[10];	// <시, 분>
vector<pair<int, int>> bar;
vector<pair<int, int>> ps;

void putin(){
	
	// ps벡터 이용
	for(int i = 0 ; i < ps.size() ; ++i){
		int si = ps[i].first;	int bun = ps[i].second;
		
		int idx = -1;
		
		for(int j = 0 ; j < bar.size() ; ++j){
			int cur_h = bar[j].first;	int cur_m = bar[j].second;
			
			if(si < cur_h){
				idx = j;
				break;
			}
			else if(si == cur_h){
				if(bun < cur_m || bun == cur_m){
					idx = j;
					break;
				}
				else if(bun > cur_m){
					continue;
				}
			}
			else if(si > cur_h){
				continue;
			}				
			
		}
		
		int real_idx = -1;
		// 시간상 원래 들어가야 하는 곳 idx
		for(int j = idx ; j < N ; ++j){
			
			if(q[j].size() >= M){
				continue;
			}
			else{
				real_idx = j;
				break;
			}
			
		}
		
		if(real_idx == -1){
			continue;
		}
		else{
			
			INFO tmp = {si,bun,global_order};
			q[real_idx].push(tmp);
			global_order++;
			
		}
		
	}
	
}


vector<pair<int, int>> solve(){
	
	int idx = -1;
	int ans_h, ans_m;
	bool flag = false;
	
	for(int i = (N-1) ; i >= 0 ; --i){
		
		if(flag)	break;
		
		int start_h = bar[i].first;	int start_m = bar[i].second;
		int start = (start_h * 60) + start_m;
		int end = 0;
		
		
		for(int j = start ; j >= end ; --j){			
			priority_queue<INFO, vector<INFO>, cmp> backup = q[i];
			int h = j / 60;	int m = j % 60;
			
			INFO tmp = {h,m,global_order};
			backup.push(tmp);
			
			int ret_idx = 0;
			while(!backup.empty()){
				INFO cur = backup.top();	backup.pop();
				if(cur.no == global_order){
					break;
				}
				ret_idx++;
			}
			
			if(ret_idx < M){
				flag = true;
				ans_h = h;
				ans_m = m;
				break;
			}
			
		}
		
	}
	
	vector<pair<int, int>> tmp;
	tmp.push_back({ans_h, ans_m});
	return tmp;
}

string solution(int n, int t, int m, vector<string> timetable) {
    N = n;	T = t;	M = m;
    int start_h = 9;	int start_m = 0;
    for(int i = 0  ; i < N ; ++i){
    	bar.push_back({start_h, start_m});
    	
    	start_m += t;
    	if(start_m >= 60){
    		start_m %= 60;
    		start_h++;
    	}
    }
    
    for(int i = 0 ; i < timetable.size() ; ++i){
    	string cur = timetable[i];
    	int hour = stoi(cur.substr(0, 2));	int minu = stoi(cur.substr(3, 2));
    	ps.push_back({hour, minu});
    }
    
    sort(ps.begin(), ps.end());
    
    putin();
    
    vector<pair<int, int>> ans = solve();
    
    string answer;
    int hhh = ans[0].first;	int mmm = ans[0].second;
    string hh, mm;
    
    if(0 <= hhh && hhh < 10){
    	hh += "0";
    	hh += to_string(hhh);
    }
    else{
    	hh += to_string(hhh);
    }
    	
    if(0 <= mmm && mmm < 10){
    	mm += "0";
    	mm += to_string(mmm);
    }
    else{
    	mm += to_string(mmm);
    }    
    
    answer += (hh + ":" + mm);
    
    return answer;
}




