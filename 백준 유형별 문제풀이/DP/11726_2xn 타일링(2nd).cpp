// (1 ≤ n ≤ 1,000)

// OUTPUT : 첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

#include <cstdio>

int N;
int cache[1001];

int main(){
	scanf("%d", &N);
	
	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 3;
	
	for(int i = 4 ; i <= N ; ++i){
		cache[i] = (cache[i-1] + cache[i-2]) % 10007;
	}
	
	printf("%d", cache[N]);
	
	return 0;
}
