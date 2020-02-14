// INPUT : 첫째 줄에 N (1 ≤ N ≤ 1,000)이 주어진다.
// OUTPUT : 첫째 줄에 길이가 N인 오르막 수의 개수를 10,007로 나눈 나머지를 출력한다.

#include <stdio.h> 
#include <string.h>

int cache[10][1001];  // [NUMBER][DEPTH]
int N;

int main(){
	memset(cache, 0, sizeof(cache));
	scanf("%d", &N);
	
	for(int i = 0 ; i < 10 ; ++i)	cache[i][1] = 1;
	
	if(N == 1){
		printf("10");
		return 0;
	}
	
	for(int i = 2 ; i <= N ; ++i){
		for(int j = 0 ; j < 10 ; ++j){
			for(int k = j ; k < 10 ; ++k){
				cache[k][i] += cache[j][i-1];
				cache[k][i] %= 10007;
			}
		}
	}
	
	int ans = 0;
	for(int i = 0 ; i < 10 ; ++i){
		ans += cache[i][N];
	}
	ans %= 10007;
	printf("%d", ans);
	return 0;
}
