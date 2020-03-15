// (6 < k < 13)

#include <cstdio>
#include <vector>

using namespace std;

vector<int> picked;

int K;
int pan[12];

void dfs(int start){
	
	if(picked.size() == 6){
		for(int i =0 ; i < picked.size() ; ++i)	printf("%d ", picked[i]);
		printf("\n");
		return;
	}
	
	for(int i = start ; i < K ; ++i){
		picked.push_back(pan[i]);
		dfs(i+1);
		picked.pop_back();
	}
	
}

int main(){
	while(true){
		scanf("%d", &K);
		if(K == 0)	return 0;
		for(int i = 0 ; i < K ; ++i)	scanf("%d", &pan[i]);
		
		dfs(0);
		
		printf("\n");
	}
	return 0;
}
