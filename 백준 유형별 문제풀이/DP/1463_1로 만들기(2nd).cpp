//X가 3으로 나누어 떨어지면, 3으로 나눈다.
//X가 2로 나누어 떨어지면, 2로 나눈다.
//1을 뺀다.

//INPUT : 1 <= N <= 10^6
//OUTPUT : 첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int cache[1000001];

int solve(int n){
	if(n == 1)	return 1;
	
	int& ret = cache[n];
	if(ret != -1)	return ret;
	
	if(n % 3 == 0)	ret = min(solve(n), solve(n / 3)) + 1;
	if(n % 2 == 0)	ret = min(solve(ret), solve(n / 3)) + 1;
	ret = min(solve(n-1), solve(ret)) + 1;
	
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	
	int ans = solve(N);
	printf("%d", ans);
	return 0;
}
