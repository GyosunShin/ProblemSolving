// (1≤n≤10,000)
// 0 <= 포도주 양 <= 1000

// OUTPUT : 첫째 줄에 최대로 마실 수 있는 포도주의 양을 출력한다.

#include <cstdio> 
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int pan[10000];
int cache[10000];

int main(){;
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	// 연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
	for(int i = 2 ; i < N ; ++i){
		
	}
	
	printf("%d", cache[N-1]);
	
	return 0;
}
