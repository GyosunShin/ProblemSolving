// 식재료 수 (4 ≤ N ≤ 16)
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int T, N;
int map[16][16];
int cache[16];

vector<int> unpicked;
vector<int> picked;

int ans = 0x7fffffff;

int check(){
	int tmp1 = 0;
	for(int i = 0 ; i < picked.size() ; ++i){
		for(int j = 0 ; j < picked.size() ; ++j){	
			tmp1 += map[picked[i]][picked[j]];
		}
	}
	
	int tmp2 = 0;
	for(int i = 0 ; i < unpicked.size() ; ++i){
		for(int j = 0 ; j < unpicked.size() ; ++j){	
			tmp2 += map[unpicked[i]][unpicked[j]];
		}
	}	
	
	return abs(tmp1 - tmp2);
}

void dfs(int start){
	if(picked.size() == (N / 2)){
		int tmp_ans;
		
		unpicked.clear();
		for(int i = 0 ; i < N ; ++i){
			if(cache[i] == -1){
				unpicked.push_back(i);
			}
		}
		
//		for(int i = 0 ; i < picked.size() ; ++i)	printf("%d ", picked[i]);
//		printf("\n");
//		for(int i = 0 ; i < unpicked.size() ; ++i)	printf("%d ", unpicked[i]);
//		printf("\n\n");		
		
		tmp_ans = check();
		if(ans > tmp_ans)	ans = tmp_ans;
		
		return;
	}
	
	for(int i = start ; i < N ; ++i){
		if(cache[i] == -1){
			picked.push_back(i);
			cache[i] = 1;
			dfs(i + 1);
			picked.pop_back();
			cache[i] = -1;
		}
	}
}

int main(){
	scanf("%d", &T);
	for(int z = 1 ; z <= T; ++z){
		ans = 0x7fffffff;
		picked.clear();	unpicked.clear();
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &map[i][j]);
			}
		}
		//################################
		
		dfs(0);		
				
		printf("#%d %d\n", z, ans);
	}
	return 0;
}
