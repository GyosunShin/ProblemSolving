// ���� A�� ũ�� N (1 �� N �� 1,000)
// (1 �� Ai �� 1,000)

// OUTPUT : ù° �ٿ� ���� A�� ���� ���� ū ���� �κ� ������ ���� ����Ѵ�.
#include <stdio.h>

int N;
int map[1000];
int cache[1000];

int ans;

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &map[i]);
	
	cache[0] = map[0];
	if(N == 1){
		printf("%d", cache[0]);
		return 0;
	}
	
	for(int i = 1 ; i < N ; ++i){
		int max = 0;
		for(int j = 0 ; j < i ; ++j){
			if(map[i] > map[j]){
				if(max < cache[j])	max = cache[j];
			}
		}
		cache[i] = max + map[i];
		if(ans < cache[i])	ans = cache[i];
	}	
	printf("%d", ans);
	return 0;
}
