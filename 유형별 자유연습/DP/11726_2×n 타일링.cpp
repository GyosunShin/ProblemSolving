#include <stdio.h>
#include <string.h>

// INPUT : 첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)
// OUTPUT : 첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

int N;
int cache[1001];

int solve(int idx){
	if(idx == 1)	return 1;
	else if(idx == 2)	return 2;
	int& ret = cache[idx];
	if(ret != -1)	return ret;
	ret = (solve(idx - 1) + solve(idx - 2)) % 10007;
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	int ret = solve(N);
	printf("%d", ret);
	
	return 0;
}
