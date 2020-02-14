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
	
	// 이 노드를 root로 하는 Trie에 문자열 key를 추가한다.
	void insert(const char* key) {
		// 문자열이 끝나면 terminal만 참으로 바꾸고 종료
		if(*key == 0) 
			terminal = true;
		else{
			int next = toNumber(*key);
			//해당 자식노드가 없으면 생성한다.
			if(children[next] == NULL) 
				children[next] = new TrieNode();
			// 해당 자식 노드로 재귀 호출 
			children[next]->insert(key + 1);
		}
	}
	
	void find(int r, int c, string cur){
		if( (!(0 <= r && r <= 3)) || (!(0 <= c && c <= 3)) ) return;
		if(visited[r][c]) return;  // 이미 방문한 곳이면 return해서 재귀를 멈춘다
		 
		
		visited[r][c] = true;  // 이미 방문한 곳이 아니었다면, 이제 방문했음을 표시해준다. 
		cur = cur + boggle[r][c];
		
		if(children[boggle[r][c] - 'A'] == '\0'){
			visited[r][c] = false;
			return;
		}
		
		// 문자열의 마지막에 해당하는 TrieNode에 도착하였을 경우 그만둔다 
		if(children[boggle[r][c] - 'A']->terminal)
			res.push_back(cur);
//			res.insert(cur);


		// 자신을 둘러싸는 인접한 8개의 boggle에 대하여 재쉬적으로 호출 
		for(int m = 0 ; m < 8 ; m++)
			children[boggle[r][c] - 'A']->find(r + dr[m], c + dc[m], cur);
		visited[r][c] = false;
	}
};

int main(){
	int n;
	cin >> n;
	
	TrieNode* root = new TrieNode();
	
	// 정답 문자열을 Trie자료구조에 저장해놓는다 
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
				// "" : Trie의 root노드는 항상 ""이므로 
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




