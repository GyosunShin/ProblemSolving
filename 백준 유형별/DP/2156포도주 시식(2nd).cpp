// 1¡Ân¡Â10,000

#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int map[10001];
int cache[10001];

int main(){
	scanf("%d", &N);
	for(int i = 1 ; i <= N ; ++i){
		scanf("%d", &map[i]);	
	}
	
	cache[1] = map[1];
	cache[2] = map[1] + map[2];
	
	if(N <= 2){
		printf("%d", cache[N]);
		return 0;	
	}
	
	for(int i = 3 ; i <= N ; ++i){
		cache[i] = max(cache[i-1], map[i] + map[i-1] + cache[i-3]);
		cache[i] = max(cache[i], map[i] + cache[i-2]);
	}
	printf("%d", cache[N]);
	return 0;
}
