// N (1 ¡Â N ¡Â 1,000)
// (1 ¡Â Ai ¡Â 1,000)

#include <stdio.h>
#include <string.h>

int N;
int map[1000];
int cache[1000];

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
	}
	//############################
	int idx = 0;
	for(int i = 0 ; i < N ; ++i){
//		for(int j = 0 ; j < idx ; ++j){
//			printf("%d  ", cache[j]);
//		}
//		printf("\n");
		int cur = map[i];
		if(i == 0){
			cache[0] = cur;
			++idx;
			continue;
		}
		
		if(cur > cache[idx-1]){
			cache[idx] = cur;
			++idx;
		}
		else{
			for(int j = (idx-1) ; j >= 0 ; --j){
				if(cur > cache[j]){
					cache[j+1] = cur;
					break;
				}
				if(j == 0){
					cache[0] = cur;
				}
			}
		}
	}
	
	printf("%d", idx);
	
	return 0;
}
