// (1 ≤N ≤ 1,000, 0 ≤K ≤ N)

// OUTPUT
// 를 10,007로 나눈 나머지를 출력한다.

#include <cstdio>

using namespace std;

int N, K;
int cache[1001][1001];

void solve(){
	
	for(int i = 0 ; i <= 1000 ; ++i){
		cache[i][0] = 1;	cache[i][i] = 1;	cache[i][1] = i;
	}
	
	for(int i = 3 ; i <= 1000 ; ++i){
		for(int j = 2 ; j <= i ; ++j){
			cache[i][j] = (cache[i-1][j] + cache[i-1][j-1]) % 10007;
		}
	}
	
}

int main(){
	
	scanf("%d %d", &N, &K);
	
	solve();
	
	printf("%d", cache[N][K]);

	return 0;
}
