
//������ ����� ���̵���� ���� �ߺ����� �ʽ��ϴ�.
//������ ����� ���̵�� (���ĺ� �ҹ���)�� (����)�θ����� �����Ǿ� �ֽ��ϴ�.

// OUTPUT
// ��÷���� ���ܵǾ�� �� ���� ���̵� ����� ��� ����� ���� ������ �� return 

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> m;
vector<int> v;

bool check(string& id, string& tem){
	
	bool ret = true;
	
	for(int i = 0 ; i < id.size() ; ++i){
		if(tem[i] == '*')	continue;
		
		if(tem[i] != id[i]){
			ret = false;
			break;
		}
	}
	
	return ret;
}

int solve(string str, int cnt, vector<string>& user){
	
	int ret = 0;
	
	if(cnt > 1){
		
		
		
	}
	else if(cnt == 1){
		
		for(int i = 0 ; i < user.size() ; ++i){
			if(user[i].size() == str.size()){
				bool ret = check(user[i], str);
				if(ret){
					ret++;
				}
			}
		}
		
	}
	
	return ret;
}

int solution(vector<string> user_id, vector<string> banned_id) {
	
	for(int i = 0 ; i < banned_id.size() ; ++i){
		m[banned_id[i]]++;
	}
	
	map<string, int>::iterator it;
	for(it = m.begin() ; it != m.end() ; ++it){
		int ret = solve(it->first, it->second, user_id);
		v.push_back(ret);
	}
	
	
	
    int answer = 1;
//    for(int i = 0 ; i < v.size() ; ++i){
//    	answer *= v[i];
//    }
    return answer;
}




