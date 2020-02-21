//N (1 �� N �� 1,000)
//(1 �� Ai �� 1,000)

// ù° �ٿ� ���� A�� ���� ���� ū ���� �κ� ������ ���� ����Ѵ�.

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int pan[1000];
int cache[1000];

int ans = -1 * 0x7fffffff;

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	for(int i = 0 ; i < N ; ++i){
		int tmp_max = -1;
		for(int j = 0 ; j < i ; ++j){
			if(pan[i] > pan[j]){
				tmp_max = max(tmp_max, cache[j]);
			}
		}
		if(tmp_max == -1)	tmp_max = 0;
		cache[i] = pan[i] + tmp_max;
		ans = max(ans, cache[i]);
	}
	
	printf("%d", ans);
	
	return 0;
}
