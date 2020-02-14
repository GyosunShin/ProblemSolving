// 계단의 개수 <= 300
// 계단에 쓰여 있는 점수 <= 10,000

#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int map[300];
int cache[300];

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
	}
	
	cache[0] = map[0];
	if(N == 1){
		printf("%d", cache[0]);
		return 0;
	}
	
	for(int i = 1 ; i < N ; ++i){
		cache[i] = max(map[i] + map[i-1] + cache[i-3], map[i] + cache[i-2]);
	}
	
	printf("%d", cache[N-1]);
	return 0;
}
