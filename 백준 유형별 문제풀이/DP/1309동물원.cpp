// (1≤N≤100,000)

#include <cstdio> 
#include <cstring>

int N;

// (0 : 아무것도 안한) (1 : 왼쪽) (2 : 오른쪽) 
int cache[100000][3];

int main(){
	scanf("%d", &N);
	
	cache[0][0] = cache[0][1] = cache[0][2] = 1;
	
	for(int i = 1 ; i < N ; ++i){
		cache[i][0] = (cache[i-1][0] + cache[i-1][1] + cache[i-1][2]) % 9901;
		cache[i][1] = (cache[i-1][2] + cache[i-1][0]) % 9901;
		cache[i][2] = (cache[i-1][1] + cache[i-1][0]) % 9901;
	}
	
	int ans = cache[N-1][0] + cache[N-1][1] + cache[N-1][2];
	ans %= 9901;
	
	// OUTPUT
	// 첫째 줄에 사자를 배치하는 경우의 수를 9901로 나눈 나머지를 출력하여라.
	printf("%d", ans);

	return 0;
}
