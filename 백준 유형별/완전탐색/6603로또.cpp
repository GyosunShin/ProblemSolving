//  49가지 수 중 k(k>6)개의 수를 골라 집합 S

#include <stdio.h>
#include <vector>

using namespace std;

int K;
int map[12];

vector<int> picked;

void dfs(int start){
	
	if(picked.size() == 6){
		for(int i = 0 ; i < picked.size() ; ++i){
			printf("%d ", map[picked[i]]);
		}
		printf("\n");
	}
	
	
	for(int i = start ; i < K ; ++i){
		picked.push_back(i);
		dfs(i+1);
		picked.pop_back();
	}
	
}

int main(){
	
	while(true){
		scanf("%d", &K);  // 첫 번째 수는 k (6 < k < 13)
		if(K == 0)	return 0;
		for(int i = 0 ; i < K ; ++i){
			scanf("%d", &map[i]);		
		}
		dfs(0);
		printf("\n");
	}
	
	return 0;
}
