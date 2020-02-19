// (1 �� n �� 1,000)

// OUTPUT : ù° �ٿ� 2��n ũ���� ���簢���� ä��� ����� ���� 10,007�� ���� �������� ����Ѵ�.

#include <cstdio>
#include <cstring>

int N;
int cache[1001];

int main(){
	scanf("%d", &N);
	
	// ��ȭ�� : cache[N] = cache[N-1] + (cache[N-2] * 2)
	cache[1] = 1;
	cache[2] = 3;
	
	for(int i = 3 ; i <= N ; ++i){
		cache[i] = (cache[i-1] + (2 * cache[i-2])) % 10007;	
	}
	
	printf("%d", cache[N]);
	
	return 0;
}
