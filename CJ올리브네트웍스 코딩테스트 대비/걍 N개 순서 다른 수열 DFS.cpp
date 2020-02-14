#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector<int> picked;
int cache[5];

void dfs(){
	if(picked.size() == 4){
		printf("[");
		for(int i = 0 ; i < picked.size() ; ++i){
			printf("%d ", picked[i]);
		}
		printf("]\n");
		
		return;
	}
	
	for(int i = 0 ; i < 4 ; ++i){
		if(cache[i] != -1)	continue;
		picked.push_back(i);
		cache[i] = 1;
		dfs();
		picked.pop_back();
		cache[i] = -1;
	}
	
}

int main(){
	memset(cache, -1, sizeof(cache));
	dfs();
	
	return 0;
}
