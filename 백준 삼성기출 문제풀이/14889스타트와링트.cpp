#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int map[20][20];
int chk[20] = { 0, };
int ans;

void dfs(int count, int cur){
	if(count == (N/2)){				
		int one = 0;
		int zero = 0;
		
		for(int i = 0 ; i < N ; ++i){
			if(chk[i] == 1){
				for(int j = 0 ; j < N ; ++j){
					if(chk[j] == 1 && j != i){
						one += map[i][j];
					}
				}
			}
			if(chk[i] == 0){
				for(int j = 0 ; j < N ; ++j){
					if(chk[j] == 0 && j != i){
						zero += map[i][j];
					}
				}
			}
		}
		int dif = abs(one - zero);
		if(dif < ans){
			ans = dif;
		}
		return;
	}
	
	for(int i = cur ; i < N ; ++i){
		chk[i] = 1;
		dfs(count + 1, i+1);
		chk[i] = 0;
	
	}
}

int main(){
	ans = 0x7fffffff;
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	//###########################################

	dfs(0, 0);
	
	printf("%d", ans);
	return 0;
}
