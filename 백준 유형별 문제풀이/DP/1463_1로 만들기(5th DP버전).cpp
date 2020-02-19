// 1 <= N <= 1,000,000

// OUTPUT : 첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int cache[1000001];

int solve(int input){
	if(input == 1)	return 0;
	
	int &ret = cache[input];
	if(ret != -1)	return ret;
	
	int tmp = 0x7fffffff;
	
	if(input % 3 == 0){
		tmp = min(tmp, solve((input / 3)) + 1);
	}
	if(input % 2 == 0){
		tmp = min(tmp, solve((input / 2)) + 1);
	}
	tmp = min(tmp, solve((input - 1)) + 1);
	
	return ret = tmp;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	printf("%d", solve(N));
	return 0;
}
