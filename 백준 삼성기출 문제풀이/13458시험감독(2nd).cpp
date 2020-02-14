// 첫째 줄에 시험장의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다.
// 둘째 줄에는 각 시험장에 있는 응시자의 수 Ai (1 ≤ Ai ≤ 1,000,000)가 주어진다.
// 셋째 줄에는 B와 C가 주어진다. (1 ≤ B, C ≤ 1,000,000)
// 
// INPUT
// 3
// 3 4 5
// 2 2
// 
// OUTPUT
// 필요한 감독관의 최소 수를 출력한다.
#include <stdio.h>

int N;
int map[1000000]; // 시험장마다 들어있는 응시자 수 저장용
int B, C;
long long ans;

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
	}
	scanf("%d %d", &B, &C);
	//###############################
	
	ans += N;
	for(int i = 0 ; i < N ; ++i){
		map[i] -= B;
		if(map[i] <= 0)	continue;
		int tmp = map[i] / C;
		if((map[i] % C != 0)){
			++tmp;
//			printf("test : %d \n", tmp);
		}	
		ans += tmp;
	}	
	
	printf("%ld", ans);
	return 0;
}


		




 
