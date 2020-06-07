#include <cstdio>
#include <cstring>

int cache[5][5] = {
	{5,5,5,5,5},
	{5,5,5,5,5},
	{5,5,5,5,5},
	{5,5,5,5,5},
	{5,5,5,5,5}
};

int main(){
	
	memset(cache[2], 0, sizeof(cache[2]));
	
	for(int i = 0 ; i < 5 ; ++i){
		for(int j = 0 ; j < 5 ; ++j){
			printf("%d ", cache[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
