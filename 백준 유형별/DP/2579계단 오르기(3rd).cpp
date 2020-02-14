//계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
//연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
//마지막 도착 계단은 반드시 밟아야 한다.

// 각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의 최댓값을 구하는 프로그램을 작성하시오.
#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int map[300];
int cache[300];

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);	
	}
	//###########################
	
	cache[0] = map[0];
	cache[1] = map[0] + map[1];
	if(N == 1){
		printf("%d", cache[0]);
		return 0;
	}
	if(N == 2){
		printf("%d", cache[1]);
		return 0;
	}	
	
	for(int i = 2 ; i < N ; ++i){
		if(i == 2){
			cache[i] = max(map[0] + map[2], map[1] + map[2]);
			continue;
		}
		cache[i] = max(map[i] +  map[i-1] + cache[i-3], map[i] + cache[i-2]);
	}
	
	printf("%d", cache[N-1]);
	return 0;
}
