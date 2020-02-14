#include <stdio.h>
#include <vector>

using namespace std;

int T;

int ans;
int n;  // 1 <=   <= 10

vector<int> picked;

void dfs(int cnt){
	if(picked.size() == cnt){

		
		int tmp_sum = 0;
		for(int i = 0 ; i < picked.size() ; ++i){
			tmp_sum += picked[i];
		}
		if(tmp_sum == n){
			++ans;
//			printf("[");
//			for(int i = 0 ; i < picked.size() ; ++i){
//				printf("%d ", picked[i]);
//			}
//			printf("]\n");
		}
		return;
	}
	
	for(int i = 1 ; i <= 3 ; ++i){
		picked.push_back(i);
		dfs(cnt);
		picked.pop_back();
	}
	
	
}

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		ans = 0;
		scanf("%d", &n);
		
		for(int i = 1 ; i <= n ; ++i){
			dfs(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}
