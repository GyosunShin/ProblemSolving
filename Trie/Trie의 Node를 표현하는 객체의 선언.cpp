const int ALPHABETS = 26;

int toNumber(char ch) {
	return ch - 'A';
}

// Trie�� �� ��带 ��Ÿ���� ��ü
struct TrieNode{
	
	TrieNode* children[ALPHABETS];
	bool terminal;
	
	TrieNode() : terminal(false){
		memset(children, 0, sizeof(children));	// �� �������� �ʱⰪ�� NULL�� 
	}
	~TrieNode(){  // �Ҹ��ڴ� ��ü�� ������ ������ �����Ϸ��� ���� �ڵ����� ȣ��Ǹ�, ����� ���� ��ü�� ������ �ݴϴ�.
		for(int i = 0 ; i < ALPHABETS ; ++i){
			if(children[i])	delete children[i];
		}
	}
	
	// �� Node�� Root�� �ϴ� Trie�� ���ڿ� key�� �߰��Ѵ�. 
	void insert(const char* key){
		if(*key == 0){	// char[]�� ������ �ι��� �Ǵ� 
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
	
	// �� Node�� Root�� �ϴ� Trie�� ���ڿ� key�� �����Ǵ� ��带 ã�´�. 
	TrieNode* find(const char* key){
		if(*key == 0)	return this;
		int next = toNumber(*key);
		if(children[next] == NULL)	return NULL;
		return children[next]->find(key+1);
	}
	
};




