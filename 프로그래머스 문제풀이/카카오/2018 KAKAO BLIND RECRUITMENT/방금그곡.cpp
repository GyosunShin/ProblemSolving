
// C, C#, D, D#, E, F, F#, G, G#, A, A#, B

// 조건이 일치하는 음악이 여러 개일 때에는 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환한다. 
// 재생된 시간도 같을 경우 먼저 입력된 음악 제목을 반환한다.
// 조건이 일치하는 음악이 없을 때에는 `(None)`을 반환한다.

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct INFO{
	
	// 재생시간
	int last;
	
	// 시작시간 
	int start;
	
	// 전체악보
//	string acbo; 
	vector<string> acbo;
	
	// 제목
	string title; 
	
};

vector<INFO> lst;

bool comp(INFO& a, INFO& b){
	
	if(a.last == b.last)	return a.start < b.start;
	return a.last > b.last;
	
}

vector<string> tokens;

string solution(string m, vector<string> musicinfos) {	//시작한 시각, 끝난 시각, 음악 제목, 악보 정보
//12:00,12:14,HELLO,CDEFGAB
	for(int j = 0 ; j < m.size() ; ++j){
		string tmp;
		
		if(j == m.size() - 1){
			tokens.push_back(m.substr(j,1));
			break;
		}
			
		if(m[j+1] == '#'){
			tmp += m[j];
			tmp += m[j+1];
			j++;
		}
		else{
			tmp += m[j];
		}
		
		tokens.push_back(tmp);
	}
	
//	for(int i = 0 ; i < tokens.size() ; ++i)	cout << "( "<< tokens[i] << " )" << endl;
	
	for(int i = 0 ; i < musicinfos.size() ; ++i) {
		string infos[4];
		
		stringstream ss(musicinfos[i]);
		string token;
		int j = 0;
		
		while(getline(ss, token, ',')){
			infos[j] = token;
			j++;
		}
		
		int start = (stoi(infos[0].substr(0,2))*60) + (stoi(infos[0].substr(3)));
		int end = (stoi(infos[1].substr(0,2))*60) + (stoi(infos[1].substr(3)));
		
		INFO tmp;
		tmp.start = start;
		tmp.last = end - start + 1;
		tmp.title = infos[2];
		
		vector<string> v;
		for(int j = 0 ; j < infos[3].size() ; ++j){
			string tmp;
			
			if(j == infos[3].size() - 1){
				v.push_back(infos[3].substr(j,1));
				break;
			}			
			
			if(infos[3][j+1] == '#'){
				tmp += infos[3][j];
				tmp += infos[3][j+1];
				j++;
			}
			else{
				tmp += infos[3][j];
			}
			
			v.push_back(tmp);
		}
		
				
		vector<string> acbo;
		int idx = 0;
		for(int j = 0 ; j < tmp.last ; ++j){
			acbo.push_back(v[idx]);
			idx = (idx + 1) % v.size();
		}
		
		tmp.acbo = acbo;
		
		lst.push_back(tmp);
	}
	
	sort(lst.begin(), lst.end(), comp);
	
	string answer;

	for(int i = 0 ; i < lst.size() ; ++i){
		
		if(lst[i].acbo.size() < tokens.size())	continue;
		
		// m : tokens
		// lst.acbo
		
		bool f = false;
		
		for(int j = 0 ; j < lst[i].acbo.size() - tokens.size() ; ++j){
			bool flag = true;
			for(int k = 0 ; k < tokens.size() ; ++k){
				if(tokens[k] != lst[i].acbo[j+k]){
					flag = false;
					break;
				}
			}
			if(flag){
				f = true;
				break;
			}
			
		}
		if(f){
			answer = lst[i].title;
			break;
		}
		
	}
	
	if(answer == "")	answer = "(None)";

    return answer;
}
