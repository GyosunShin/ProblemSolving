// N(1 ≤ N ≤ 90)이 주어졌을 때, N자리 이친수의 개수를 구하는 프로그램을 작성하시오.

#include <cstdio>
#include <cstring>

int N;
long long cache[90][2];

long long solve(int idx, int input){
	if(idx >= N)	return 1;
	
	long long &ret = cache[idx][input];
	if(ret != -1)	return ret;
	
	long long tmp_ret = 0;
	
	if(input == 1){
		tmp_ret += solve(idx + 1, 0);
	}
	else{
		tmp_ret += solve(idx + 1, 0);
		tmp_ret += solve(idx + 1, 1);
	}
	
	return ret = tmp_ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	
	long long ans = solve(1, 1);
	
	printf("%lld", ans);
	
	return 0;
}
