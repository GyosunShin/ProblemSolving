#include <stdio.h> 
#include <algorithm>

using namespace std;

int N;
int stair[300];
int cache[300];

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &stair[i]);
	}
	
	cache[0] = stair[0];
	cache[1] = max(stair[0] + stair[1], stair[1]);
	cache[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
	
	for(int i = 3 ; i < N ; ++i){
		cache[i] = max(cache[i-2] + stair[i], stair[i-1] + stair[i] + cache[i-3]);
	}
	printf("%d", cache[N-1]);
	return 0;
}
