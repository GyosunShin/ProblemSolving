// 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오
// (1 ≤ N(종류) ≤ 10, 1 ≤ K(합) ≤ 100,000,000)

#include <cstdio>

int N, K, ans;
int pan[10];

void solve(){
	
	for(int i = N-1 ; i >= 0 ; --i){
		if(K == 0)	return;
		int cur = pan[i];
		
		ans += K / cur;
		K -= (K / cur) * cur;
	}
	
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	solve();
	
	printf("%d", ans);
	
	return 0;
}
