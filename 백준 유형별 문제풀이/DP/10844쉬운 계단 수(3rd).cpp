// 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

// 1 <= N <= 100

// OUTPUT : 첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

#include <cstdio>
#include <cstring>

int N;
int cache[101][10];

int solve(int idx, int input){
	
	if(idx >= N)	return 1;
	
	int &ret = cache[idx][input];
	if(ret != -1)	return ret;
	
	int tmp_ret = 0;
	
	if(input == 0){
		tmp_ret += solve(idx + 1, input+1);
	}
	else if(input == 9){
		tmp_ret += solve(idx + 1, input-1);
	}
	else{
		tmp_ret += solve(idx + 1, input-1);
		tmp_ret %= 1000000000;
		tmp_ret += solve(idx + 1, input+1);
	}
	tmp_ret %= 1000000000;		
	return ret = tmp_ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	
	int ans = 0;
	for(int i = 1 ; i <= 9 ; ++i){
		ans += solve(1, i);
		ans %= 1000000000;
	}
	
	printf("%d", ans);
	
	return 0;
}

