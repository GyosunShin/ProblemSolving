//  n을 1, 2, 3의 합으로 나타내는 방법의 수

#include <stdio.h>

int T;

int solve(int n){
	
}

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		int tmp;
		scanf("%d", &tmp);	
		int ans = solve(tmp);
		printf("%d\n", ans);
	}
	return 0;
}
