//  (1 ¡Â N ¡Â 1,000)

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int pan[1000];
int cache[1000];

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &pan[i]);	
	}
	
	cache[0] = 1;
	
	for(int i = 1; i < N ; ++i){
		int tmp = 0;
		for(int j = 0 ; j < i ; ++j){
			if(pan[i] > pan[j]){
				tmp = max(tmp, cache[j]);
			}
		}
		cache[i] = tmp + 1;
	}
	
	int ans = -1;
	for(int i = 0 ; i < N ; ++i){
		ans = max(ans, cache[i]);
	}
	printf("%d", ans);
	
	return 0;
}
