#include <stdio.h>
#include <vector>

using namespace std;

vector<int> picked;

void dfs(int start){
	if(picked.size() == 3){
		for(int i= 0 ; i < picked.size() ; ++i){
			printf("%d  ", picked[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i = start ; i < 5 ; ++i){
		picked.push_back(i);
		dfs(i+1);
		picked.pop_back();
	}
	
}

int main(){
	
	dfs(0);
	
	
	return 0;
}
