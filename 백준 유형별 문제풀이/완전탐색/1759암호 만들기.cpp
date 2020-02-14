// 서로 다른 L개 알파베 소문자 
// 최소 한 개의 모음과 최소 두 개의 자음으로 구성

// INPUT : (3 ≤ L ≤ C ≤ 15)

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


int L, C;

char map[15];

vector<string> ans;

vector<int> picked;

void dfs(int start){
	
	if(picked.size() == L){
		string tmp;
		for(int i = 0 ; i < picked.size() ; ++i){
			tmp += map[picked[i]];
		}
		ans.push_back(tmp);
	}
	
	for(int i = start ; i < C ; ++i){
		picked.push_back(i);
		dfs(i+1);
		picked.pop_back();
	}
	
}

int main(){
	
	scanf("%d %d", &L, &C);
	getchar();
	
	for(int i = 0 ; i < C ; ++i){
		scanf("%c", &map[i]);
		getchar();
	}
	
	sort(map, map+C);
	sort(ans.begin(), ans.end());
	
	// 조합이용 
	dfs(0);
	
	for(int i = 0 ; i < ans.size() ; ++i){
		int cnt = 0;
		for(int j = 0 ; j < ans[i].size() ; ++j){
			if(ans[i][j] == 'a' || ans[i][j] == 'e' ||ans[i][j] == 'i' ||ans[i][j] == 'o' ||ans[i][j] == 'u')	++cnt;
		}
		int za = L - cnt;
		if(cnt >= 1 && za >= 2)	cout << ans[i] << endl;
	}
	
	return 0;
}

