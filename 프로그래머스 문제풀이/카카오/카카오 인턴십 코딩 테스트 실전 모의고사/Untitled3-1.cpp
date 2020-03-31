
//응모한 사용자 아이디들은 서로 중복되지 않습니다.
//응모한 사용자 아이디는 (알파벳 소문자)와 (숫자)로만으로 구성되어 있습니다.

// OUTPUT
// 당첨에서 제외되어야 할 제재 아이디 목록은 몇가지 경우의 수가 가능한 지 return 

// user_id 배열의 크기는 1 이상 8 이하입니다.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> idxes;
vector<int> picked;

bool cache[8];

int answer;

int N;

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

vector<int> solve(string tem, vector<string>& user){
	
	vector<int> tmp;
	
	for(int i = 0 ; i < user.size() ; ++i){
		if(user[i].size() == tem.size()){
			
			bool ret = check(user[i], tem);
			if(ret){
				tmp.push_back(i);
			}
			
		}
	}
	return tmp;
}

void dfs(int start){
	
	if(picked.size() == N){
		
		for(int i = 0 ; i < picked.size() ; ++i){
			cout << picked[i] << ", ";
		}
		cout << endl;
		
		++answer;
		return;
	}
	
	for(int i = 0 ; i < idxes[start].size() ; ++i){
		if(!cache[idxes[start][i]]){
			cache[idxes[start][i]] = true;		
			picked.push_back(idxes[start][i]);
			dfs(start + 1);
			picked.pop_back();
			cache[idxes[start][i]] = false;
		}
	}
	
}

int solution(vector<string> user_id, vector<string> banned_id) {
	
	N = banned_id.size();
	
	for(int i = 0 ; i < banned_id.size() ; ++i){
		string cur = banned_id[i];
		vector<int> ret = solve(cur, user_id);
		idxes.push_back(ret);
	}
	
	
	for(int i = 0 ; i < idxes.size() ; ++i){
		for(int j = 0 ; j < idxes[i].size() ; ++j){
			cout << idxes[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl;

	dfs(0);
	
	return answer;
}




