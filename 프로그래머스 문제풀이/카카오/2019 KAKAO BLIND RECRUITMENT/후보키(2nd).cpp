
#include <string>
#include <vector>
#include <set>
#include <cstdio>

using namespace std;

int R, C, ans;

vector<int> picked;

set<vector<string>> s;

vector<pair<int, int>> already;

bool check(vector<vector<string>>& relation){
	s.clear();
	
	for(int i = 0 ; i < R ; ++i){
		
		vector<string> tmp;
		
		for(int j = 0 ; j < picked.size() ; ++j){
			tmp.push_back(relation[i][picked[j]]);		
		}
		
		set<vector<string>>::iterator it;
		it = s.find(tmp);
		if(it == s.end()){
			s.insert(tmp);
		}
		else{
			return false;
		}
		
	}
	
	int now = 0;
	for(int i = 0 ; i < picked.size() ; ++i){
		now |= (1 << picked[i]);
	}
	already.push_back({now, picked.size()});
	
	return true;
}

void dfs(int start, int cnt, vector<vector<string>>& relation){
		
	if(picked.size() == cnt){
		
//		for(int i = 0 ; i < picked.size() ; ++i){
//			printf("%d ", picked[i]);
//		}
//		printf("\n");		
		
		int now = 0;
		for(int i = 0 ; i < picked.size() ; ++i){
			now |= (1 << picked[i]);
		}
		for(int i = 0 ; i < already.size() ; ++i){
			if((already[i].first & now) == already[i].first && already[i].second < picked.size()){
				return;
			}
		}
		
		if(check(relation)){
			++ans;
		}
		
		return;
		
	}
	
	for(int i = start ; i < C ; ++i){
		picked.push_back(i);
		dfs(i+1, cnt, relation);
		picked.pop_back();
	}
	
}

void solve(vector<vector<string>>& relation){
	
	for(int i = 1 ; i <= C ; ++i){
		dfs(0, i, relation);
	}
	
}

int solution(vector<vector<string>> relation){
    R = relation.size();
    C = relation[0].size();
    
    solve(relation);
    
    // 이 릴레이션에서 후보 키의 개수를 return 
 	return ans;
}
