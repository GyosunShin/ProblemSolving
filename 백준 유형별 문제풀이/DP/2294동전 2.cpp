
//  (1 �� n �� 100, 1 �� k �� 10,000) 

// OUTPUT 
// ù° �ٿ� ����� ������ �ּ� ������ ����Ѵ�. �Ұ����� ��쿡�� -1�� ����Ѵ�.

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, K;
int pan[100];
int cache[10001];

int main(){
	memset(cache, -1, sizeof(cache));
	
	scanf("%d %d", &N, &K);
	
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	cache[0] = 0;
	
	for(int i = 0 ; i < N ; ++i){
		int cur = pan[i];
		for(int j = cur ; j <= K ; ++j){
			if(cache[j-cur] == -1)	continue;
			if(cache[j] == -1)	cache[j] = cache[j-cur] + 1;
			else	cache[j] = min(cache[j], cache[j-cur] + 1);
		}
	}
	
	printf("%d", cache[K]);
	
	return 0;
}





