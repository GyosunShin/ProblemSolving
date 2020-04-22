// 2 <= N <= 200 

// OUTPUT
// 첫째 줄에는 번호 순서대로 줄을 세우는데 옮겨지는 아이들의 최소 수를 출력한다.

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int pan[200];
int cache[200];

void solve(){
	
	cache[0] = 1;
	
	for(int i = 1 ; i < N ; ++i){
		int mmax = 0;
		for(int j = 0 ; j < i ; ++j){
			if(pan[j] < pan[i])	{
				mmax = max(mmax, cache[j]);
			}
		}
		cache[i] = mmax + 1;
	}
	
	sort(cache, cache+N);
	
}

int main(){
	
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	solve();
	
	printf("%d", N - cache[N-1]);
	
	return 0;
}
