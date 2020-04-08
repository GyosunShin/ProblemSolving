// 여2 + 남1
// 여N / 남M

//  (0 ≤ M ≤ 100, 0 ≤ N ≤ 100, 0 ≤ K ≤ M+N), 

#include <cstdio>
#include <algorithm>

using namespace std;

int M, N, K;

int check(int f, int m){
	
	return min((f/2), m);
	
}

int main(){
	scanf("%d %d %d", &N, &M, &K);
	
	int ans = -1;
	
	for(int i = 0 ; i <= K ; ++i){
		int tmp = check(N - i, M - (K-i));
		ans = max(ans, tmp);
	}
	
	printf("%d", ans);
	
	return 0;
}
