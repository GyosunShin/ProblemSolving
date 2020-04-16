// (1 ¡Â N(R), M(C) ¡Â 300)

#include <cstdio>

int R, C, K;
int pan[300][300];
int cache[300][300];

int main(){
	
	scanf("%d %d", &R, &C);
	
	int sum = 0;
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%d", &pan[i][j]);
			sum += pan[i][j];
			cache[i][j] = sum;
		}
	}
	
	
	scanf("%d", &K);
	for(int i = 0; i < K ; ++i){
		int sr, sc, dr, dc;
		scanf("%d %d %d %d", &sr, &sc, &dr, &dc);	
		sr--;	sc--;	dr--;	dc--;
		
		int ans = cache[dr][dc] - cache[sr][sc] + pan[sr][sc];
		if(sr != dr){
			int tmp_sum = 0;
			if(dc != C-1){
				for(int j = sr ; j < dr ; ++j){				
					tmp_sum += cache[j][C-1] - cache[j][dc+1] + pan[j][dc+1];
				}
			}
			if(sc != 0){
				for(int j = sr+1 ; j <= dr ; ++j){
					tmp_sum += cache[j][sc-1] - cache[j][0] + pan[j][0];
				}
			}
			ans -= tmp_sum;
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}

