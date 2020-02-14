// (1 �� n �� 1,000)
// OUTPUT : ù° �ٿ� 2��n ũ���� ���簢���� ä��� ����� ���� 10,007�� ���� �������� ����Ѵ�.

#include <stdio.h>
#include <string.h>

using namespace std;

int N;
int cache[1001];

int solve(int n){
	if(n == 1)	return 1;
	if(n == 2)	return 2;
	int& ret = cache[n];
	if(ret != -1)	return ret;
	
	ret = (solve(n-1) + solve(n-2)) % 10007;
	
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	int ans = solve(N);
	printf("%d", ans);
	return 0;
}




 
