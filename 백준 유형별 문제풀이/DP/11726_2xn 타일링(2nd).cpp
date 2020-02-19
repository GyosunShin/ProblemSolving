// (1 �� n �� 1,000)

// OUTPUT : ù° �ٿ� 2��n ũ���� ���簢���� ä��� ����� ���� 10,007�� ���� �������� ����Ѵ�.

#include <cstdio>

int N;
int cache[1001];

int main(){
	scanf("%d", &N);
	
	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 3;
	
	for(int i = 4 ; i <= N ; ++i){
		cache[i] = (cache[i-1] + cache[i-2]) % 10007;
	}
	
	printf("%d", cache[N]);
	
	return 0;
}
