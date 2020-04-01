//응모한 사용자 아이디들은 서로 중복되지 않습니다.
//응모한 사용자 아이디는 (알파벳 소문자)와 (숫자)로만으로 구성되어 있습니다.

// OUTPUT
// 당첨에서 제외되어야 할 제재 아이디 목록은 몇가지 경우의 수가 가능한 지 return 

// user_id 배열의 크기는 1 이상 8 이하입니다.

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int uSize, bSize, answer;
bool cache[8];
vector<int> picked;
set<int> s;

set<int>::iterator it;

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

void dfs(vector<string>& user_id, vector<string>& banned_id){
	
	if(picked.size() == bSize){
		bool flag = true;
		
		for(int i = 0 ; i < picked.size() ; ++i){
			if(!check(user_id[picked[i]], banned_id[i]) || user_id[picked[i]].size() != banned_id[i].size()){
				flag = false;
				break;
			}
		}
		
		if(flag){
			int tmp = 0;
			
			for(int i = 0 ; i < picked.size() ; ++i){
				int cur = picked[i];
				int ttmp = 1 << cur;
				tmp |= ttmp;
			}
			
			it = s.find(tmp);
			
			if(it == s.end()){
//				for(int i = 0 ; i < picked.size() ; ++i){
//					printf("%d  ", picked[i]);
//				}
//				printf("\n");
				
				++answer;
				s.insert(tmp);
			}
			
		}
		
		return;
	}
	
	
	for(int i = 0 ; i < uSize ; ++i){
		if(!cache[i]){
			cache[i] = true;
			picked.push_back(i);
			dfs(user_id, banned_id);
			picked.pop_back();
			cache[i] = false;
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	// uSize >= bSize
	uSize = user_id.size();
	bSize = banned_id.size();
	
	dfs(user_id, banned_id);

	return answer;
}

//int main(){
////	["frodo", "fradi", "crodo", "abc123", "frodoc"]
////	["*rodo", "*rodo", "******"]
//	vector<string> user_	id({"frodo", "fradi", "crodo", "abc123", "frodoc"});
//	vector<string> banned_id({"*rodo", "*rodo", "******"});
//	solution(user_id, banned_id);
//	
//	return 0;	
//}
