// 1 ≤ N ≤ 1,000
// 10,007로 나눈 나머지를 출력한다.
#include <stdio.h>

int N;
int cache[1000][10];

int main(){
	scanf("%d", &N);
	
	if(N == 1){
		printf("10");
		return 0;
	}
	
	for(int i = 0 ; i < 10 ; ++i){
		cache[0][i] = 1;
	}
	
	for(int i = 1 ; i < N ; ++i){
		for(int j = 0 ; j < 10 ; ++j){
			for(int k = 0 ; k <= j ; ++k){
				cache[i][j] += cache[i-1][k];
				cache[i][j] %= 10007;
			}
		}
	}
	
	int ans = 0;
	for(int i = 0 ; i < 10 ; ++i){
		ans += (cache[N-1][i]);
	} 
	ans %= 10007;
	printf("%d", ans);
	
	return 0;
}
