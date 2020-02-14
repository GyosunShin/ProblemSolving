// N(1 ≤ N ≤ 200), K(1 ≤ K ≤ 200)

// OUTPUT : 첫째 줄에 답을 1,000,000,000으로 나눈 나머지를 출력한다.

#include <stdio.h>

using namespace std;

int N, K;	
int cache[200+1][200];

int main(){
	scanf("%d %d", &N, &K);
	
	if(K == 1){
		printf("1");
		return 0;
	}
	for(int i = 0 ; i <= N ; ++i)	cache[i][0] = 1;
	for(int i = 1 ; i < K ; ++i){
		for(int j = 0 ; j <= N ; ++j){
			for(int z = 0 ; z <= j ; ++z){
				cache[j][i] = ((cache[j][i] + cache[j-z][i-1]) % 1000000000);
			}
		}
	}
	
	printf("%d", cache[N][K-1]);
	
	return 0;
}
