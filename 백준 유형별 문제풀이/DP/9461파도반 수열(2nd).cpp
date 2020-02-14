//  (1 ¡Â N ¡Â 100)

#include <stdio.h>
#include <string.h>

int T, N;
long long cache[101];

int main(){
	scanf("%d", &T);
	
	for(int z = 0 ; z < T ; ++z){
		memset(cache, 0, sizeof(cache));
		cache[1] = 1;
		cache[2] = 1;
		cache[3] = 1;
		cache[4] = 2;
		cache[5] = 2;
		cache[6] = 3;
		cache[7] = 4;
		cache[8] = 5;
		cache[9] = 7;
		cache[10] = 9;
		scanf("%d", &N);	
		if(1 <= N && N <= 10){
			printf("%lld", cache[N]);
		}
		else{
			for(int i = 11 ; i <= N ; ++i){
				cache[i] = cache[i-1] + cache[i-5];
			}
			printf("%lld", cache[N]);
		}
	}
	
	return 0;
}

