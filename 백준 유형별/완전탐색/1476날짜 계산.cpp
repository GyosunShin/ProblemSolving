//  (1 �� E �� 15, 1 �� S �� 28, 1 �� M �� 19)

// OUTPUT : ù° �ٿ� E S M���� ǥ�õǴ� ���� ���� ������ ����Ѵ�. 1 1 1�� �׻� 1�̱� ������, ������ ������ ������ ���� ����.

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
