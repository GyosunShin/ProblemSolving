// 상자의 개수 n (1 ≤ n ≤ 1000)

// OUTPUT : 첫째 줄에 한 줄에 넣을 수 있는 최대의 상자 개수를 출력한다.

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
