// 1 <= N <= 1,000,000

// OUTPUT : 첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

#include <cstdio>
#include <algorithm>

using namespace std;

int N;

int solve(int input){
	if(input == 1)	return 0;
	
	int ret = 0x7fffffff;
	
	if(input % 3 == 0){
		ret = min(ret, solve(input/3) + 1);
	}
	if(input % 2 == 0){
		ret = min(ret, solve(input/2) + 1);
	}
	ret = min(ret, solve(input-1) + 1);
	
	return ret;
}

int main(){
	scanf("%d", &N);
	
	printf("%d", solve(N));
	
	return 0;
}
