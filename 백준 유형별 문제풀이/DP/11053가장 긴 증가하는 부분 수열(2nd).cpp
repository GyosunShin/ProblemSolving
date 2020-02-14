// (1 ¡Â N ¡Â 1,000)
#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int map[1001];
int cache[1001];

int main(){
	scanf("%d", &N);
	for(int i = 1 ; i <= N ; ++I){
		scanf("%d", &map[i]);	
	}
	
	cache[1] = 1;
	
	for(int i = 2 ; i <= N ; ++i){
		cache[i] = ;
	}
	
	printf("%d", cache[N]);
	
	return 0;
}
