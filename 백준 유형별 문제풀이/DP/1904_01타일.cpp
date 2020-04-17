// 1 <= N <= 1,000,000

// OUTPUT
// ù ��° �ٿ� �����̰� ���� �� �ִ� ���̰� N�� ��� 2�� ������ ������ 15746���� ���� �������� ����Ѵ�.

#include <cstdio> 

int N;
int cache[1000001];

int main(){
	scanf("%d", &N);
	
	cache[1] = 1;
	cache[2] = 2;
	cache[3] = 3;
	
	for(int i = 4 ; i <= N ; ++i){
		cache[i] = cache[i-1] + cache[i-2];
		cache[i] %= 15746;
	}
	
	printf("%d", cache[N]);
	
	return 0;
}
