#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;

int map[16][16];

vector<int> picked;
vector<int> unpicked;
bool used[16];

int ans = 0x7fffffff;

int solve(){
	int sumA = 0;
	int sumB = 0;
	
	// 순열 이용  
	for(int i = 0 ; i < picked.size() ; ++i){
		for(int j = i+1 ; j < picked.size() ; ++j) {
			sumA += (map[picked[i]][picked[j]] + map[picked[j]][picked[i]]);
		}
	}
	
	for(int i = 0 ; i < unpicked.size() ; ++i){
		for(int j = i+1 ; j < unpicked.size() ; ++j) {
			sumB += (map[unpicked[i]][unpicked[j]] + map[unpicked[j]][unpicked[i]]);
		}
	}
	return abs(sumA - sumB);
}

void dfs(int start){
	
	if(picked.size() == (N/2)){
		for(int i = 0 ; i < N ; ++i){
			if(!used[i])	unpicked.push_back(i);
		}
		
		ans = min(ans, solve());
		unpicked.clear();
		return;
	}
	
	for(int i = start ; i < N ; ++i){
		picked.push_back(i);
		used[i] = true;
		dfs(i+1);
		picked.pop_back();
		used[i] = false;
	}
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		ans = 0x7fffffff;
		scanf("%d", &N);
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &map[i][j]);		
			}
		}
		
		// 조합 이용
		dfs(0); 		
		
		printf("#%d %d\n", z, ans);
	}
	return 0;
}


