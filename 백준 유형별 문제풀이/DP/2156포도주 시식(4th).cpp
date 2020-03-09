// (1¡Ân¡Â10,000)

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int pan[10000];
int cache[10000];

int main(){
	scanf("%d", &N);
	
	for(int i= 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	cache[0] = pan[0];
	cache[1] = cache[0] + pan[1];
	cache[2] = max(pan[0] + pan[2], pan[1] + pan[2]);
	cache[2] = max(cache[2], pan[0] + pan[1]);
	
	if(N <= 3){
		printf("%d", cache[N-1]);
		return 0;
	}
	
	for(int i = 3 ; i < N ; ++i){
		cache[i] = max(pan[i] + pan[i-1] + cache[i-3], pan[i] + cache[i-2]);
		cache[i] = max(cache[i], cache[i-1]);
	}
	
	printf("%d", cache[N-1]);
	return 0;
}
