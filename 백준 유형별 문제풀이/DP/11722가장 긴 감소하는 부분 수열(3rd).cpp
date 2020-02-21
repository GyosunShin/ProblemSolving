// (1 ¡Â N ¡Â 1,000)
// (1 ¡Â Ai ¡Â 1,000)

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int pan[1000];
int cache[1000];

int ans = -1*0x7fffffff;

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	for(int i = 0 ; i < N ; ++i){
		int tmp = 0;
		for(int j = 0 ; j < i ; ++j){
			if(pan[j] > pan[i]){
				tmp = max(tmp, cache[j]);
			}
		}
		cache[i] = tmp + 1;
		ans = max(ans, cache[i]);
	}
	
	printf("%d", ans);
	
	return 0;
}
