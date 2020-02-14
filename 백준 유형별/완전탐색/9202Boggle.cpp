#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <cstring>
#include <vector>


using namespace std;

const int ALPHABETS = 26;
int toNumber(char ch){return ch - 'A';}
int dr[] = {-1,-1,-1,1,1,1,0,0};
int dc[] = {-1,0,1.-1,0,1,-1,1};
int score[] = {0,0,0,1,1,2,3,5,11};
string boggle[4];
bool visited[4][4];

vector<string> res;
//set<string> res;

struct TrieNode{
	TrieNode* children[ALPHABETS];
	bool terminal;
	
	TrieNode() : terminal(false){
		memset(children, 0, sizeof(children));
	}
	
	~TrieNode(){
		for(int i = 0 ; i<ALPHABETS ; i++){
			if(children[i])
				delete children[i];
		}
	}
	
	// �� ��带 root�� �ϴ� Trie�� ���ڿ� key�� �߰��Ѵ�.
	void insert(const char* key) {
		// ���ڿ��� ������ terminal�� ������ �ٲٰ� ����
		if(*key == 0) 
			terminal = true;
		else{
			int next = toNumber(*key);
			//�ش� �ڽĳ�尡 ������ �����Ѵ�.
			if(children[next] == NULL) 
				children[next] = new TrieNode();
			// �ش� �ڽ� ���� ��� ȣ�� 
			children[next]->insert(key + 1);
		}
	}
	
	void find(int r, int c, string cur){
		if( (!(0 <= r && r <= 3)) || (!(0 <= c && c <= 3)) ) return;
		if(visited[r][c]) return;  // �̹� �湮�� ���̸� return�ؼ� ��͸� �����
		 
		
		visited[r][c] = true;  // �̹� �湮�� ���� �ƴϾ��ٸ�, ���� �湮������ ǥ�����ش�. 
		cur = cur + boggle[r][c];
		
		if(children[boggle[r][c] - 'A'] == '\0'){
			visited[r][c] = false;
			return;
		}
		
		// ���ڿ��� �������� �ش��ϴ� TrieNode�� �����Ͽ��� ��� �׸��д� 
		if(children[boggle[r][c] - 'A']->terminal)
			res.push_back(cur);
//			res.insert(cur);


		// �ڽ��� �ѷ��δ� ������ 8���� boggle�� ���Ͽ� �罬������ ȣ�� 
		for(int m = 0 ; m < 8 ; m++)
			children[boggle[r][c] - 'A']->find(r + dr[m], c + dc[m], cur);
		visited[r][c] = false;
	}
};

int main(){
	int n;
	cin >> n;
	
	TrieNode* root = new TrieNode();
	
	// ���� ���ڿ��� Trie�ڷᱸ���� �����س��´� 
	for(int i = 0 ; i < n ; i++){
		char t[10];
		scanf("%s", &t);
		root->insert(t);
	}
	getchar();

	int boggles;
	scanf("%s", &boggles);
	
	for(int i = 0 ; i < boggles ; i++){
		for(int j = 0 ; j < 4 ; j ++){
			cin >> boggle[j];
		}
		res.clear();
		for(int j = 0 ; j < 4 ; j ++){
			for(int k = 0 ; k < 4 ; k++){
				// "" : Trie�� root���� �׻� ""�̹Ƿ� 
				root->find(j,k,"");
			}
		}
				
		string longstr = res.front();
		int tscore = 0;
		for(auto it : res){
			if(longstr.size() < it.size())
				longstr = it;
			tscore += score[it.size()];
		}
		
		cout << tscore << " " << longstr << " " << res.size() << endl;
	}
	
}




