//(1 ≤ N ≤ 100,000)

#include <cstdio>
#include <cmath>

int N;

int solve(int input){
//	printf("[] %d\n", input);
	if(input == 0)	return 0;
	
	int rem = (int)sqrt(input);
	input -= (rem * rem);
	return solve(input) + 1;
}

int main(){
	scanf("%d", &N);
	
	// OUTPUT : 주어진 자연수를 제곱수의 합으로 나타낼 때에 그 제곱수 항의 최소 개수를 출력한다.
	printf("%d", solve(N));
	
	return 0;
}
