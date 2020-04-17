// 1 <= N <= 1,000,000

// OUTPUT
// 첫 번째 줄에 지원이가 만들 수 있는 길이가 N인 모든 2진 수열의 개수를 15746으로 나눈 나머지를 출력한다.

#include <cstdio> 

int N;
int cache[1000001];

int main(){
	scanf("%d", &N);
	
	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 3;
	
	for(int i = 4 ; i <= N ; ++i){
		cache[i] = cache[i-1] + cache[i-2];
		cache[i] %= 15746;
	}
	
	printf("%d", cache[N]);
	
	return 0;
}
