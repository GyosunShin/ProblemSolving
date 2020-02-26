// ������ �ʿ��� ��ŭ�� ������ ���������� �Ѵ�. 
// �̶�, ��� M������ ������ ���� �������� ���ؼ� ���ܱ⿡ ������ �� �ִ� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

// INPUT :  (1 �� N �� 1,000,000, 1 �� M �� 2,000,000,000)

#include <stdio.h>

int N, M;
long long map[1000000];
long long small = 1;
long long big = (-1 * 0x7fffffff);

int main(){
	scanf("%d %d", &N, &M);
	
	for(int i = 0 ; i < N ; ++i){
		scanf("%lld", &map[i]);
		if(map[i] > big)	big = map[i];
	}
	
	while(small <= big){
		printf("%d   %d\n", small, big);
		long long mid = (small + big) / 2;
		
		long long tmp_sum = 0;
		for(int i = 0 ; i < N ; ++i){
			if(map[i] > mid)	tmp_sum += (map[i] - mid);
		}
		printf("<%d>\n", tmp_sum);
		if(tmp_sum >= M){
			small = mid + 1;
		}
		else if(tmp_sum < M){
			big = mid - 1;
		}
	}
	printf("%lld", big);
	return 0;
}
