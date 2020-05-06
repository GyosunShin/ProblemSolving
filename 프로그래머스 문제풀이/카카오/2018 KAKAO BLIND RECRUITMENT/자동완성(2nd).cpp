
// 2 <= N <= 100,000 --> 중복 없음
// 2 <= L(모든 단어 길이의 총합) <= 1,000,000
// 알파벳 소문자만

#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

struct TrieNode{
	
	int cnt;
	TrieNode* children[26];
	
	TrieNode() : cnt(0){
		memset(children, 0, sizeof(children));
	}
	
	~TrieNode(){
		for(int i = 0 ; i < 26 ; ++i)	delete children[i];
	}
	
	void insert(const char* str){
		cnt++;
		
		if(*str == 0)	return;
		
		int next = *str - 'a';
		
		if(children[next] == NULL){
			children[next] = new TrieNode();
		}
		children[next]->insert(str+1);
	}
	
	int find(const char* str){
		if(*str == 0 || cnt == 1)	return 0;
		
		int next = *str - 'a';
		
		return (children[next]->find(str + 1)) + 1;
	}
	
};

TrieNode root;

void buildTree(vector<string>& input){
	
	for(int i = 0 ; i < input.size() ; ++i){
		root.insert(input[i].c_str());
	}
	
}

int solve(vector<string>& input){
	
	int sum = 0;
	
	for(int i = 0 ; i < input.size() ; ++i){
		int tmp = root.find(input[i].c_str());
		sum += tmp;
	}
	
	return sum;
	
}

int solution(vector<string> words) {
	
	buildTree(words);
    
    return solve(words);
    
}
