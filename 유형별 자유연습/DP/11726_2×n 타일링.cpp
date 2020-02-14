#include <stdio.h>
#include <string.h>

// INPUT : ù° �ٿ� n�� �־�����. (1 �� n �� 1,000)
// OUTPUT : ù° �ٿ� 2��n ũ���� ���簢���� ä��� ����� ���� 10,007�� ���� �������� ����Ѵ�.

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
