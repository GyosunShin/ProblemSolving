#include <stdio.h>

int cache[1000];
int map[1000];
int N;

int ans = -1 * 0x7fffffff;

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);	
	}
	
	cache[0] = 1;
	if(N == 1){
		printf("1");
		return 0;
	}
	
	for(int i = 1 ; i < N ; ++i){
		int max = 0;
		for(int j = 0 ; j < i ; ++j){
			if(map[i] > map[j]){
				if(max < cache[j])	max = cache[j];
			}
		}
		cache[i] = max + 1;
		if(ans < cache[i])	ans = cache[i];	
	}
	
	printf("%d", ans);
	
	return 0;
}
