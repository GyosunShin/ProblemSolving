#include <stdio.h>
#include <algorithm>
#include <string.h>

// n (1 ¡Â n ¡Â 100,000)

using namespace std;

int T, N;
int map[2][100001];
int cache[2][100001];

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		int ans;
		scanf("%d", &N);	
		for(int i = 0 ; i < 2 ; ++i){
			for(int j = 1 ; j <= N ; ++j){
				scanf("%d", &map[i][j]);
			}
		}
		//################################
		cache[0][0] = cache[1][0] = 0;
		cache[0][1] = map[0][1];	cache[1][1] = map[1][1];
		
		if(N == 1){
			ans = max(cache[0][1], cache[1][1]);
			printf("%d\n", ans);	
			continue;
		}
		for(int i = 2 ; i <= N ; ++i){
			cache[0][i] = map[0][i] + max(cache[1][i-1], cache[1][i-2]);
			cache[1][i] = map[1][i] + max(cache[0][i-1], cache[0][i-2]);
		}
		ans = max(cache[0][N], cache[1][N]);
		printf("%d\n", ans);
	}
	return 0;
}
