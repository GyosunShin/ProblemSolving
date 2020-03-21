// Enter [���� ���̵�] [�г���] (ex. Enter uid1234 Muzi)
// Leave [���� ���̵�] (ex. Leave uid1234)
// Change [���� ���̵�] [�г���] (ex. Change uid1234 Muzi)

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<pair<string, string>> answer;

map<string, string> m;

vector<string> solution(vector<string> record) {
    
    for(int i = 0 ; i < record.size() ; ++i){
    	
    	if(record[i][0] == 'E'){	// (ex. Enter uid1234 Muzi)
    		
    		int id_idx = record[i].find(" ");
    		int name_idx = record[i].find(" ", id_idx + 1);
    		
    		string id = record[i].substr(id_idx + 1, name_idx - id_idx - 1);
    		string name = record[i].substr(name_idx + 1);
    		
    		m[id] = name;
    	
    		answer.push_back(make_pair(id, "���� ���Խ��ϴ�."));
    		
    	}
    	else if(record[i][0] == 'L'){	// (ex. Leave uid1234)
    	
    		int id_idx = record[i].find(" ");
    		string id = record[i].substr(id_idx + 1);
    		
    		answer.push_back(make_pair(id, "���� �������ϴ�."));
    		
    	}
    	else if(record[i][0] == 'C'){	// (ex. Change uid1234 Muzi)
    		
    		int id_idx = record[i].find(" ");
    		int name_idx = record[i].find(" ", id_idx + 1);
    		
    		string id = record[i].substr(id_idx + 1, name_idx - id_idx - 1);
    		string name = record[i].substr(name_idx + 1);  
			
			m[id] = name;
    		
    	}
    	
    }
    
    vector<string> ans;
    
    for(int i = 0 ; i < answer.size() ; ++i){
    	ans.push_back(m[answer[i].first] + answer[i].second);
    }
    
    return ans;
}






