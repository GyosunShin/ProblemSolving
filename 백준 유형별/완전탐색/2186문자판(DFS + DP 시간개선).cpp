// N(1 ¡Â N ¡Â 100), M(1 ¡Â M ¡Â 100), K(1 ¡Â K ¡Â 5)

#include <stdio.h> 
#include <string.h>
#include <string> 
#include <iostream>

using namespace std;

int R, C, K;
char map[100][100];
string target;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int ans;

int cache[100][100][80];  // r,c,  string idx

int dfs(int start_r, int start_c, int track){
	if((track == target.size() - 1)){
		return 1;
	}
	int& ret = cache[start_r][start_c][track];
	if(ret != -1){
		return ret;
	}
	int tmp_ret = 0;
	for(int dir = 0 ; dir < 4 ; ++dir){
		for(int walk = 1 ; walk <= K ; ++walk){
			int next_r = start_r + (dr[dir] * walk);
			int next_c = start_c + (dc[dir] * walk);
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C)	break;
			if(map[next_r][next_c] != target[track + 1])	continue;
				
			tmp_ret += dfs(next_r, next_c, track+1);
			
		}
	}
	return ret = tmp_ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d %d %d", &R, &C, &K);
	getchar();
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%1c", &map[i][j]);
		}
		getchar();
	}
	cin >> target;
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			if(map[i][j] == target[0]){
				ans += dfs(i,j, 0);
			}
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
