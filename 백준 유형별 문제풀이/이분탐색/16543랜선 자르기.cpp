// (1 <= K <= 10000) --> (1 <= N <= 1000000)
// ������ ���� <= 2^31-1

// OUTPUT : ���� �� �ִ� �ִ� ������ ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h>

int K;
long long N;
int map[100000];

int max = -1 * 0x7fffffff;

int main(){
	scanf("%d %lld", &K, &N);
	for(int i = 0 ; i < K ; ++i){
		scanf("%d", &map[i]);
		if(max < map[i])	max = map[i];
	}
	
	
	int left = 1;
	int right = max;
	int start = (left + right) / 2;
	while(left <= right){
		long long tmp = 0;
		for(int i = 0 ; i < K ; ++i){
			tmp += map[i] / start;
		}
		if(tmp < N){
			right = start - 1;
		}
		else{
			left = start + 1;
		}
		start = (left + right) / 2;
	}
	printf("%d", right);
		
	return 0;
}
