// 최소 한 개의 모음과 최소 두 개의 자음으로 구성
// (3 ≤ L ≤ C ≤ 15)

#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int L, C;

vector<char> pan;

void dfs(int start, string& str){
	
	if(str.size() == L){
		int cntm = 0;
		int cntz = 0;
		for(int i = 0 ; i < str.size() ; ++i){
			if(str[i] == 'a' || str[i] == 'e' ||str[i] == 'i' ||str[i] == 'o' ||str[i] == 'u')	cntm++;
			else cntz++;
		}
		if(cntm >= 1 && cntz >= 2)	cout << str << endl;
		return;
	}
	
	for(int i = start ; i < pan.size() ; ++i){
		str.push_back(pan[i]);
		dfs(i+1, str);
		str.pop_back();
	}
	
}


int main(){
	scanf("%d %d", &L, &C);
	getchar();
	for(int i = 0 ; i < C ; ++i){
		int tmp;
		scanf("%c", &tmp);
		getchar();
		pan.push_back(tmp);
	}
	
	sort(pan.begin(), pan.end());
	string tmp = "";
	dfs(0, tmp);
	
	return 0;
}
