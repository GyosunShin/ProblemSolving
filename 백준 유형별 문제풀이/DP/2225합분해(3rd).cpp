// N(1 ≤ N ≤ 200), K(1 ≤ K ≤ 200)

// OUTPUT : 첫째 줄에 답을 1,000,000,000으로 나눈 나머지를 출력한다.

#include <cstdio>

int N, K;

int cache[201][201];

int main(){
	scanf("%d %d", &N, &K);
	
	for(int i = 0 ; i <= N ; ++i){
		cache[i][1] = 1;
	}
	
	for(int i = 2 ; i <= K ; ++i){
		for(int j = 0 ; j <= N ; ++j){
			for(int k = 0 ; k <= j ; ++k){
				cache[j][i] += cache[k][i-1];
				cache[j][i] %= 1000000000;
			}
		}
	}
	
	printf("%d", cache[N][K]);
	
	return 0;
}
