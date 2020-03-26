
// (1) 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
// (2) 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.
// (3) w에 해당하는 사전의 색인 번호를 출력하고, 입력에서 w를 제거한다.
// (4) 입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.
// (5) 단계 2로 돌아간다.

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> answer;
vector<pair<string, int>> dict[26];

int global_order = 1;

void solve(string& msg){
	
	while(true){
		
		if(msg.size() == 0)	break;
		
		char first_ch = msg[0];
		int start_id = first_ch - 'A';
		
		for(int i = dict[start_id].size() - 1 ; i >= 0 ; --i){
			if(msg.find(dict[start_id][i].first) == 0){
				answer.push_back(dict[start_id][i].second);
				msg.erase(0, dict[start_id][i].first.size());
				
				if(msg.size() > 0){
					char tmp = msg[0];
					string ttmp = dict[start_id][i].first;
					ttmp += tmp;
					int idx = (int)ttmp[0] - 'A';
					dict[idx].push_back({ttmp, global_order++});
				}
				
				break;
			}
			
		}
		
	}
	
	
}

vector<int> solution(string msg) {
	     
    char start = 'A';
    
    for(int i = 0 ; i < 26 ; ++i){
    	string tmp;
    	tmp += (start + i);
    	dict[i].push_back({tmp, global_order++});
    }
    
    solve(msg);
    
    return answer;
}


//int main(){
//	
//	
//	solution("KAKAO");
//	
//}
//



