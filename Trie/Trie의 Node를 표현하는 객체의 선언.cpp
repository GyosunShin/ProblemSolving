const int ALPHABETS = 26;

int toNumber(char ch) {
	return ch - 'A';
}

// Trie의 한 노드를 나타내는 객체
struct TrieNode{
	
	TrieNode* children[ALPHABETS];
	bool terminal;
	
	TrieNode() : terminal(false){
		memset(children, 0, sizeof(children));	// 각 포인터의 초기값을 NULL로 
	}
	~TrieNode(){  // 소멸자는 객체의 수명이 끝나면 컴파일러에 의해 자동으로 호출되며, 사용이 끝난 객체를 정리해 줍니다.
		for(int i = 0 ; i < ALPHABETS ; ++i){
			if(children[i])	delete children[i];
		}
	}
	
	// 이 Node를 Root로 하는 Trie에 문자열 key를 추가한다. 
	void insert(const char* key){
		if(*key == 0){	// char[]의 마지막 널문자 판단 
			terminal = true;
		}
		else{
			int next = toNumber(*key);
			
			if(children[next] == NULL){	// 해당 자식 노드가 없다면 생성한다. 
				children[next] = new TrieNode();
			}
			children[next]->insert(key + 1);
		}
	}
	
	// 이 Node를 Root로 하는 Trie에 문자열 key와 대응되는 노드를 찾는다. 
	TrieNode* find(const char* key){
		if(*key == 0)	return this;
		int next = toNumber(*key);
		if(children[next] == NULL)	return NULL;
		return children[next]->find(key+1);
	}
	
};




