// n(1 ≤ n ≤ 100,000)
// -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수

#include <stdio.h>
#include <algorithm>

using namespace std;

int map[100000];
int N;
int cache[100000];

int ans = -1 * 0x7fffffff;

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
	}
	//############################
	
	cache[0] = map[0];	
	if(ans < cache[0])	ans = cache[0];
	for(int i = 1 ; i < N ; ++i){
		cache[i] = max(map[i], map[i] + cache[i - 1]);
		if(ans < cache[i])	ans = cache[i];	
	}
	
	printf("%d", ans);
	
	return 0;
}
