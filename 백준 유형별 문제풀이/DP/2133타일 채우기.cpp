// 1 ¡Â N ¡Â 30

#include <stdio.h> 

int N;
int cache[31];

int main{
	scanf("%d", &N);
	
	if(N == 1){
		printf("0");
		return 0;
	}
	if(N == 2){
		printf("3");
		return 0;
	}
	cache[1] = 0;
	cache[2] = 3;
	
	for(int i = 3 ; i <= N ; ++i){
		
	}
	
	printf("%d", cache[N]);
	return 0;
}
