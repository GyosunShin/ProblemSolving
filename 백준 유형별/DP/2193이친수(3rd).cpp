// N(1 �� N �� 90)�� �־����� ��, N�ڸ� ��ģ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <stdio.h>

int N;
long long cache[91][2];

int main(){
	scanf("%d", &N);
	
	if(N == 1){
		printf("1");
		return 0;
	}
	
	cache[1][1] = 1;
	
	for(int i = 2 ; i <= N ; ++i){
		cache[i][0] += cache[i-1][0] + cache[i-1][1];
		cache[i][1] += cache[i-1][0];
	}
	
	long long ans = (cache[N][0] + cache[N][1]);
	
	printf("%ld", ans);
	
	return 0;
}



