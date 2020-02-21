//(1 �� N �� 100,000)

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
	
	// OUTPUT : �־��� �ڿ����� �������� ������ ��Ÿ�� ���� �� ������ ���� �ּ� ������ ����Ѵ�.
	printf("%d", solve(N));
	
	return 0;
}
