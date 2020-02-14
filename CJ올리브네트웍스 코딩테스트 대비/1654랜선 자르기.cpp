// 만들 수 있는 최대 랜선의 길이를 구하는 프로그램

// 이미 가지고 있는 랜선의 개수 K(1 <=  <= 10000), 그리고 필요한 랜선의 개수 N(1 <=  <= 1000000)

#include <stdio.h>

long long map[10000];
long long K, N;

long long big = -1 * 0x7fffffff;

int main(){
	scanf("%lld %lld", &K, &N);
	for(int i = 0 ; i < K ; ++i){
		scanf("%lld", &map[i]);
		if(big < map[i])	big = map[i];
	}
	//################################
	
	long long left = 1;
	long long right = big;
	
	long long mid;
	
	while(left <= right){
		printf("LEFT : %d / RIGHT : %d\n", left, right);
		mid = (left + right) / 2;
		int tmp = 0;
		for(int i = 0 ; i < K ; ++i){
			tmp += map[i] / mid;
		}
		if(tmp < N){
			right = mid-1;
		}
		else if(tmp >= N){
			left = mid + 1;
		}
	}
	printf("LEFT : %d / RIGHT : %d\n", left, right);
	
	printf("%lld", right);
	
	return 0;
}

 
