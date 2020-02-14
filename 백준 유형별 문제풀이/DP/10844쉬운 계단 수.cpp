// 1 <= N <= 100
// 
// OUTPUT : 첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.
#include <stdio.h>
#include <string.h>
int N;

long long cache[101][10];

int main(){
	scanf("%d", &N);
	
	for(int i = 1 ; i < 10 ; ++i){
		cache[1][i] = 1;
	}
	
	if(N == 1){
		printf("9");
		return 0;
	}
	
	for(int i = 2 ; i <= N ; ++i){
		for(int j = 0 ; j < 10 ; ++j){
			if(j == 0){
				cache[i][j] = cache[i-1][1];
			}
			else if(j == 9){
				cache[i][j] = cache[i-1][8];
			}
			else{
				cache[i][j] = (cache[i-1][j-1] + cache[i-1][j+1]) % 1000000000;
			}
		}
	}
	
	long long ans = 0;
	for(int i = 0 ; i < 10 ; ++i){
		ans += cache[N][i];
	}
	ans %= 1000000000;
	printf("%lld", ans);
	return 0;
}
