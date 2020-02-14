// 계단개수 <= 300
// 각 계단 <= 10000
// 
// OUTPUT : 첫째 줄에 계단 오르기 게임에서 얻을 수 있는 총 점수의 최댓값을 출력한다.

#include <stdio.h>

int N;

int stair[301];

int solve(int n){
	 
}

int main(){
	scanf("%d", &N);
	for(int i = 1 ; i <= N ; ++i){
		scanf("%d", &stair[i]);
	}
	//##############################
	
	int ans = solve(0);
	printf("%d", ans);
	return 0;
}

 
