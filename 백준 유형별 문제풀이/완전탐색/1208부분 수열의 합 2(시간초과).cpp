// (1 ¡Â N ¡Â 40, |S| ¡Â 1,000,000)

#include <stdio.h> 
#include <vector>

using namespace std;

int N, S, ans;
int map[40];

vector<int> picked;

void dfs(int start){
	if(picked.size() > 0){
		int tmp_sum = 0;
		for(int i = 0 ; i < picked.size() ; ++i){
			tmp_sum += map[picked[i]];
		}
		if(tmp_sum == S)	++ans;
	}
	
	if(picked.size() == N){
		return;
	}
	
	for(int i = start ; i < N ; ++i){
		picked.push_back(i);
		dfs(i + 1);
		picked.pop_back();
	}
	
}

int main(){
	scanf("%d %d", &N, &S);
	
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
	}
		
	// nCr
	dfs(0);
	
	printf("%d", ans);
	
	return 0;
}
