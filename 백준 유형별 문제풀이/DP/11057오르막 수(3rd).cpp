// 수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 수는 0으로 시작할 수 있다.

// N (1 ≤ N ≤ 1,000)

// OUTPUT : 첫째 줄에 길이가 N인 오르막 수의 개수를 10,007로 나눈 나머지를 출력한다.

#include <cstdio>
#include <cstring>

int N;
int cache[1001][10];

int solve(int idx, int input){
	
	if(idx >= N)	return 1;
	
	int &ret = cache[idx][input];
	if(ret != -1)	return ret;
	
	int tmp_ret = 0;
	
	for(int i = input ; i < 10 ; ++i){
		tmp_ret += solve(idx + 1, i);
		tmp_ret %= 10007;
	}
	
	return ret = tmp_ret;
}

int main(){	
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	
	int ans = 0;
	
	for(int i = 0 ; i < 10 ; ++i){
		ans += solve(1, i);
		ans %= 10007;
	}
	
	printf("%d", ans);
	
	return 0;
}
