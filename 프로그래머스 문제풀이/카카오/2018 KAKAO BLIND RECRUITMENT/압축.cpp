
// (1) ���̰� 1�� ��� �ܾ �����ϵ��� ������ �ʱ�ȭ�Ѵ�.
// (2) �������� ���� �Է°� ��ġ�ϴ� ���� �� ���ڿ� w�� ã�´�.
// (3) w�� �ش��ϴ� ������ ���� ��ȣ�� ����ϰ�, �Է¿��� w�� �����Ѵ�.
// (4) �Է¿��� ó������ ���� ���� ���ڰ� �����ִٸ�(c), w+c�� �ش��ϴ� �ܾ ������ ����Ѵ�.
// (5) �ܰ� 2�� ���ư���.

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



