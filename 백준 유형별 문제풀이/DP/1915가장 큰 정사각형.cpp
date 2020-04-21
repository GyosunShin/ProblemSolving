// (1 ¡Â n(R), m(C) ¡Â 1,000)

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int R, C;
int pan[1000][1000];
int cache[1000][1000];

int main(){
	scanf("%d %d", &R, &C);
	
	getchar();
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%1d", &pan[i][j]);
		}
		getchar();
	}
	
	for(int i = 0 ; i < R ; ++i){
		cache[i][0] = pan[i][0];
	}
	for(int i = 0 ; i < C ; ++i){
		cache[0][i] = pan[0][i];
	}
	
	for(int i = 1 ; i < R ; ++i){
		for(int j = 1 ; j < C ; ++j){
			int tmp = min(min(cache[i-1][j-1], cache[i-1][j]), cache[i][j-1]);
			if(tmp == 0)	cache[i][j] = pan[i][j];
			else{
				if(pan[i][j] == 0){
					cache[i][j] = 0;
				}
				else	cache[i][j] = tmp+1;
			}
		}
	}	
	
	int ans = -1;
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			ans = max(ans, cache[i][j]);
		}
	}
	
	printf("%d", ans*ans);
	
	return 0;
}
