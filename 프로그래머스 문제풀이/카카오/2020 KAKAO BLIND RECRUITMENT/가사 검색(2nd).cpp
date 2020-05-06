#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

struct NODE{
	
	NODE* children[26];
	int cnt;
	
	NODE() : cnt(0){
		for(int i = 0 ; i < 26 ; ++i){
			memset(children, 0, sizeof(children));
		}
	}
	
	void insert(const char* str){
		cnt++;
		if(*str == 0)	return;
		
		int next = *str - 'a';
		if(children[next] == NULL){
			children[next] = new NODE();
		}
		children[next]->insert(str + 1);
	}
	
	int find(const char* str){
		
		if(*str == '?'){
			return	cnt;
		}
		else{
			int next = *str - 'a';
			if(children[next] == NULL)	return 0;
			return children[next]->find(str+1);
		}
		
	}
	
};

NODE spell[10001];
NODE rspell[10001];

vector<int> answer;

void buildTree(vector<string>& input){
	
	for(int i = 0 ; i < input.size() ; ++i){
		string cur = input[i];
		spell[(int)cur.size()].insert(cur.c_str());
		
		reverse(cur.begin(), cur.end());
		rspell[(int)cur.size()].insert(cur.c_str());
	}
	
}

void solve(vector<string>& qs){
	
	for(int i = 0 ; i < qs.size() ; ++i){
		string cur = qs[i];
		
		int ret = 0;
		
		if(qs[i][0] == '?'){
			reverse(cur.begin(), cur.end());
			ret = rspell[(int)cur.size()].find(cur.c_str());
		}
		else{
			ret = spell[(int)cur.size()].find(cur.c_str());
		}
		
		answer.push_back(ret);
	}
	
}


// 2 <= words <= 100,000
// 1 <= words[i] <= 10,000
// 소문자만 
vector<int> solution(vector<string> words, vector<string> queries) {
	
	buildTree(words);
	
	solve(queries);
    
    return answer;
}
