#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

vector<int> answer;

const int ALPHABETS = 26;

int toNumber(char ch) {
	return ch - 'a';
}

// Trie�� �� ��带 ��Ÿ���� ��ü
struct TrieNode{
	
	TrieNode* children[ALPHABETS];
	bool terminal;
	
	TrieNode() : terminal(false){
		memset(children, 0, sizeof(children));
	}
	~TrieNode(){  // �Ҹ��ڴ� ��ü�� ������ ������ �����Ϸ��� ���� �ڵ����� ȣ��Ǹ�, ����� ���� ��ü�� ������ �ݴϴ�.
		for(int i = 0 ; i < ALPHABETS ; ++i){
			if(children[i])	delete children[i];
		}
	}
	
	// �� Node�� Root�� �ϴ� Trie�� ���ڿ� key�� �߰��Ѵ�. 
	void insert(const char* key){
		if(*key == 0){
			terminal = true;
		}
		else{
			int next = toNumber(*key);
			
			if(children[next] == NULL){	// �ش� �ڽ� ��尡 ���ٸ� �����Ѵ�. 
				children[next] = new TrieNode();
			}
			children[next]->insert(key + 1);
		}
	}
		
	int find(const char* key){
		int sum = 0;
		
		if(*key == 0){
			if(terminal)	return 1;
			return 0;
		}
		
		if(*key == '?'){
			for(int i = 0 ; i < 26 ; ++i){
				if(children[i] == NULL)	continue;
				sum += children[i]->howmany(key+1);
			}
		}
		else{
			int next = toNumber(*key);
			if(children[next] == NULL)	return 0;
			sum += children[next]->howmany(key+1);
		}
		return sum;	
	}
	
};

vector<int> solution(vector<string> words, vector<string> queries){    
    TrieNode root;
    
    for(int i = 0 ; i < words.size() ; ++i){
    	root.insert(words[i].c_str());
    }
    
    for(int i = 0 ; i < queries.size() ; ++i){
    	answer.push_back(root.howmany(queries[i].c_str()));
    }
    
    return answer;
}
