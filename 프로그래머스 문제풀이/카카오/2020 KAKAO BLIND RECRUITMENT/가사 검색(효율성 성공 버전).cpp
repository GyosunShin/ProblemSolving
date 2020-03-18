#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int ALPHABETS = 26;

int numTrans(char input){
	return input - 'a';
}

struct SPELL{
	
	SPELL* children[ALPHABETS];
	int cnt;
	bool terminal;
	
	SPELL() : cnt(0), terminal(false) {
		memset(children, 0, sizeof(children));
	}
	~SPELL(){
		for(int i = 0 ; i < ALPHABETS ; ++i)	delete children[i];
	}
	
	void insert(const char* str){
		(this->cnt)++;
		if(*str == 0){
			terminal = true;
			return;
		}
		int next = numTrans(*str);
		if(children[next] == NULL){
			children[next] = new SPELL();
		}
		children[next]->insert(str+1);
	}
	
	int find(const char* str){
		int ret = 0;
		if(*str == '?'){
			ret = this->cnt;
		}
		else{				
			int next = numTrans(*str);
			if(children[next] == NULL)	ret = 0;
			else	ret = children[next]->find(str+1);
		}				
		return ret;
	}
	
};

vector<int> answer;

SPELL root[10001];
SPELL rroot[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    
    for(int i = 0 ; i < words.size() ; ++i){
    	
//    	if(root[words[i].size()] == NULL)	root[words[i].size()] = new SPELL();
    	root[words[i].size()].insert(words[i].c_str());
    	
    	string rev = words[i];
    	reverse(rev.begin(), rev.end());
//    	if(rroot[words[i].size()] == NULL)	rroot[words[i].size()] = new SPELL();
    	rroot[words[i].size()].insert(rev.c_str());
    	
    }
	    
	for(int i = 0 ; i < queries.size() ; ++i){
		
		int ret = 0;
		if(queries[i].back() == '?'){
			ret = root[queries[i].size()].find(queries[i].c_str());
		}
		else{
			string rev = queries[i];
			reverse(rev.begin(), rev.end());
			ret = rroot[queries[i].size()].find(rev.c_str());
		}
		
		answer.push_back(ret);
	}
    
    return answer;
    
}
