//  N (1 ≤ N ≤ 1,000)
// (1 ≤ Ai ≤ 1,000)

// EX) 10 30 10 20 20 10

#include <stdio.h>

int map[1000];
int N;
int cache[1000];

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);	
	}
	//############################
	
	cache[0] = map[0];
	if(N == 1){
		printf("1");
		return 0;
	}
	
	int idx = 1;   // 새로 들어갈 수 있는 index 위치 의미 
	// 작은것만이 idx 위치에 삽입 될 수 있다. 
	for(int i = 1 ; i < N ; ++i){
		if(cache[idx - 1] > map[i]){
			cache[idx] = map[i];
			++idx;
		}
		else{
			for(int j = (idx - 1) ; j >= 0 ; --j){
				if(cache[j] > map[i]){
					cache[j + 1] = map[i];
					break;
				}
				if(j == 0){
					cache[j] = map[i];
				}
			}
		}
	}
	
	printf("%d", idx);
	
	return 0;
}


