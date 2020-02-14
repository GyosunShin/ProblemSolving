// (1¡Ân¡Â10,000) 
#include <stdio.h> 
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int map[10000];
int cache[10000];

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
	}
	//###############################
	
	cache[0] = map[0];
	cache[1] = map[0] + map[1];
	
	for(int i = 2 ; i < N ; ++i){
		if(i == 2){
			int twomax = max(map[0] + map[2], map[1] + map[2]);
			twomax = max(twomax, map[0] + map[1]);
			cache[i] = twomax;
		}
		else{
			int tmp_max = max(map[i] + map[i-1] + cache[i-3], map[i] + cache[i-2]);
			tmp_max = max(tmp_max, cache[i-1]);
			cache[i] = tmp_max;			
		}

	}
	
	printf("%d", cache[N-1]);
	return 0;
}
