// 수열 A의 크기 N (1 ≤ N ≤ 1,000)
// (1 ≤ Ai ≤ 1,000)

// OUTPUT : 첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다.
#include <stdio.h>

int N;
int map[1000];
int cache[1000];

int ans;

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &map[i]);
	
	cache[0] = map[0];
	if(N == 1){
		printf("%d", cache[0]);
		return 0;
	}
	
	for(int i = 1 ; i < N ; ++i){
		int max = 0;
		for(int j = 0 ; j < i ; ++j){
			if(map[i] > map[j]){
				if(max < cache[j])	max = cache[j];
			}
		}
		cache[i] = max + map[i];
		if(ans < cache[i])	ans = cache[i];
	}	
	printf("%d", ans);
	return 0;
}
