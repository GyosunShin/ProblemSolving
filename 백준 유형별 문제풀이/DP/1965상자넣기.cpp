// ������ ���� n (1 �� n �� 1000)

// OUTPUT : ù° �ٿ� �� �ٿ� ���� �� �ִ� �ִ��� ���� ������ ����Ѵ�.

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int pan[1000];
int cache[1000];

void solve(){
	
	cache[0] = 1;
	
	for(int i = 1 ; i < N ; ++i){
		int mmax = 0;
		for(int j = 0 ; j < i ; ++j){
			if(pan[j] < pan[i]){
				mmax = max(mmax, cache[j]);
			}
		}
		cache[i] = mmax + 1;
	}
	
}

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	solve();
	
	sort(cache, cache + N);
	
	printf("%d", cache[N-1]);
	
	return 0;
}
