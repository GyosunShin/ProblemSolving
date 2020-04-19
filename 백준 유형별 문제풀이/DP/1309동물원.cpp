// (1��N��100,000)

#include <cstdio> 
#include <cstring>

int N;

// (0 : �ƹ��͵� ����) (1 : ����) (2 : ������) 
int cache[100000][3];

int main(){
	scanf("%d", &N);
	
	cache[0][0] = cache[0][1] = cache[0][2] = 1;
	
	for(int i = 1 ; i < N ; ++i){
		cache[i][0] = (cache[i-1][0] + cache[i-1][1] + cache[i-1][2]) % 9901;
		cache[i][1] = (cache[i-1][2] + cache[i-1][0]) % 9901;
		cache[i][2] = (cache[i-1][1] + cache[i-1][0]) % 9901;
	}
	
	int ans = cache[N-1][0] + cache[N-1][1] + cache[N-1][2];
	ans %= 9901;
	
	// OUTPUT
	// ù° �ٿ� ���ڸ� ��ġ�ϴ� ����� ���� 9901�� ���� �������� ����Ͽ���.
	printf("%d", ans);

	return 0;
}
