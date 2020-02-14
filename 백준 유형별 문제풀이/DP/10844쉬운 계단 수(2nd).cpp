// 1,000,000,000으로 나눈 나머지를 출력한다.
// 1 <= N <= 100

#include <stdio.h>

int N;
int cache[100][10];

int main(){
	scanf("%d", &N);
	
	if(N == 1){
		printf("9");
		return 0;	
	}
	
	for(int i = 0 ; i < 10 ; ++i)	cache[0][i] = 1;
	
	for(int i = 1 ; i < N ; ++i){
		for(int j = )
		
	}
	
	return 0;
}
