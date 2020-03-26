
// 2 <= �ܾ��  <= 100,000

// OUTPUT : �н��� �ܾ���� ������� ã�� �� �� ���� ���ڸ� �Է��ϸ� �Ǵ��� ��� 

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int ALPHABETS = 26;

int ans;

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
		
		if(this->cnt == 1 || *str == 0){
			return 0;
		}
		
		int next = numTrans(*str);
		return (children[next]->find(str+1)) + 1;
	}
	
};

SPELL root;

int solution(vector<string> words) {
    
    for(int i = 0 ; i < words.size() ; ++i){
    	root.insert(words[i].c_str());
    }
    
    for(int i = 0 ; i < words.size() ; ++i){
    	int tmp = root.find(words[i].c_str());
    	ans += (tmp);
    }
    
    return ans;
}




