// (1 ≤ n ≤ 1,000)

// OUTPUT : 첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

#include <cstdio>
#include <cstring>

int N;
int cache[1001];

int main(){
	scanf("%d", &N);
	
	// 점화식 : cache[N] = cache[N-1] + (cache[N-2] * 2)
	cache[1] = 1;
	cache[2] = 3;
	
	for(int i = 3 ; i <= N ; ++i){
		cache[i] = (cache[i-1] + (2 * cache[i-2])) % 10007;	
	}
	
	printf("%d", cache[N]);
	
	return 0;
}
