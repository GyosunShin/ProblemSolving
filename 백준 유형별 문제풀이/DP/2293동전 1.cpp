// (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 

// 각 동전의 가치 <= 100000 

#include <cstdio> 

int N, K;
int value[100];

int cache[100001];

void solve(){
	cache[0] = 1;	
	
	for(int i = 0 ; i < N ; ++i){
		int cur = value[i];
		
		for(int j = cur ; j <= K ; ++j){
			cache[j] += cache[j - cur];
		}
		
	}
}

int main(){
	scanf("%d %d", &N, &K);
	
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &value[i]);
	}
	
	solve();
	
	printf("%d", cache[K]);
	
	return 0;
}
