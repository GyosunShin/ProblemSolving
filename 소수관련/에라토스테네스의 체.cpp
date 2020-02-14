// 120이라 가정해보자
// 밑의 코드에 의해 bool map 배열이 완성이 되었다면
// 값이 0을 갖는 index가 소수인 것이다.(이유 : 다른 놈들에 의해 체킹되지 않았으므로!) 

#include <stdio.h>
#include <cmath>

bool map[121];

int main(){
	
	int sq = (int)sqrt(120);
	
	for(int i = 2 ; i <= sq ; ++i){
		if(map[i])	continue;
		for(int j = i * i ; j <= 120 ; j = j + i){
			map[j] = true;
		}
	}
		
	for(int i = 0 ; i < 12 ; ++i){
		for(int j = 1 ; j <= 10 ; ++j){
			if(map[i*10 + j])	printf("1 ");
			else printf("0 ");
		}
		printf("\n");
	}	
	
	return 0;
}
