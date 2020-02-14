//  (1 ≤ E ≤ 15, 1 ≤ S ≤ 28, 1 ≤ M ≤ 19)

// OUTPUT : 첫째 줄에 E S M으로 표시되는 가장 빠른 연도를 출력한다. 1 1 1은 항상 1이기 때문에, 정답이 음수가 나오는 경우는 없다.

#include <stdio.h>

int E, S, M;

int ans = 1;

int main(){
	scanf("%d %d %d", &E, &S, &M);
	//##############################
	// 15 / 28 / 19
	
	while(1){
		bool flag = false;	
		
//		if(ans % 15 == E && ans % 28 == S && ans %19 == M){
//			break;
//		}
		if((ans-E) % 15 == 0 && (ans - S) % 28 == 0 && (ans - M)%19 == 0){
			break;
		}
		
		++ans;	
	}
	
	printf("%d", ans);
	
	return 0;
}
