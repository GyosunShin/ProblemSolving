//  (4 ≤ N ≤ 20)

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, N;
int pan[20][20];
bool cache[101];

int ans = -1 * 0x7fffffff;

int start_r, start_c, walk;

const int dr[] = {1, 1, -1, -1};
const int dc[] = {1, -1, -1, 1};

int dfs(int cur_r, int cur_c, int cur_dir){
	walk++;
	
	int tmp_ret = -1 * 0x7fffffff;
	
	int next_r = cur_r + dr[cur_dir];	int next_c = cur_c + dc[cur_dir];
	
	if(cur_dir == 0){
		
		if(walk == 0){
			if((0 > next_r || next_r >= N || 0 > next_c || next_c >= N) || cache[pan[next_r][next_c]])	return -1 * 0x7fffffff;
			cache[pan[next_r][next_c]] = true;
			tmp_ret = max(tmp_ret, dfs(next_r, next_c, cur_dir) + 1);
			cache[pan[next_r][next_c]] = false;
		}
		else{
			int tmp_r = cur_r + dr[cur_dir + 1];	int tmp_c = cur_c + dc[cur_dir + 1];
			if(!(0 > next_r || next_r >= N || 0 > next_c || next_c >= N) && !cache[pan[next_r][next_c]]){
				cache[pan[next_r][next_c]] = true;
				tmp_ret = max(tmp_ret, dfs(next_r, next_c, cur_dir) + 1);
				cache[pan[next_r][next_c]] = false;
			}
			if(!(0 > tmp_r || tmp_r >= N || 0 > tmp_c || tmp_c >= N) && !cache[pan[tmp_r][tmp_c]]){	
				cache[pan[tmp_r][tmp_c]] = true;
				tmp_ret = max(tmp_ret, dfs(tmp_r, tmp_c, cur_dir + 1) + 1);
				cache[pan[tmp_r][tmp_c]] = false;
			}
//			if(cache[pan[next_r][next_c]] && cache[pan[tmp_r][tmp_c]])	return -1 * 0x7fffffff;
		}
		
	}
	else if(cur_dir == 1){

		int tmp_r = cur_r + dr[cur_dir + 1];	int tmp_c = cur_c + dc[cur_dir + 1];
		if(!(0 > next_r || next_r >= N || 0 > next_c || next_c >= N) && !cache[pan[next_r][next_c]]){	
			cache[pan[next_r][next_c]] = true;
			tmp_ret = max(tmp_ret, dfs(next_r, next_c, cur_dir) + 1);
			cache[pan[next_r][next_c]] = false;
		}
		if(!(0 > tmp_r || tmp_r >= N || 0 > tmp_c || tmp_c >= N) && !cache[pan[tmp_r][tmp_c]]){	
			cache[pan[tmp_r][tmp_c]] = true;
			tmp_ret = max(tmp_ret, dfs(tmp_r, tmp_c, cur_dir + 1) + 1);
			cache[pan[tmp_r][tmp_c]] = false;
		}
//		if(cache[pan[next_r][next_c]] && cache[pan[tmp_r][tmp_c]])	return -1 * 0x7fffffff;
		
	}
	else if(cur_dir == 2){
		
		int tmp_r = cur_r + dr[cur_dir + 1];	int tmp_c = cur_c + dc[cur_dir + 1];
		if(!(0 > next_r || next_r >= N || 0 > next_c || next_c >= N) && !cache[pan[next_r][next_c]]){	
			cache[pan[next_r][next_c]] = true;
			tmp_ret = max(tmp_ret, dfs(next_r, next_c, cur_dir) + 1);
			cache[pan[next_r][next_c]] = false;
		}
		if(!(0 > tmp_r || tmp_r >= N || 0 > tmp_c || tmp_c >= N)){
			if(tmp_r == start_r && tmp_c == start_c){
				return 0;
			}
			if(!cache[pan[tmp_r][tmp_c]]){
				cache[pan[tmp_r][tmp_c]] = true;
				tmp_ret = max(tmp_ret, dfs(tmp_r, tmp_c, cur_dir + 1) + 1);
				cache[pan[tmp_r][tmp_c]] = false;
			}
		}
//		if(cache[pan[next_r][next_c]] && cache[pan[tmp_r][tmp_c]])	return -1 * 0x7fffffff;
		
	}
	else if(cur_dir == 3){
		if(next_r == start_r && next_c == start_c){
			return 0;
		}
		if((0 > next_r || next_r >= N || 0 > next_c || next_c >= N) || cache[pan[next_r][next_c]])	return -1 * 0x7fffffff;
		cache[pan[next_r][next_c]] = true;
		tmp_ret = max(tmp_ret, dfs(next_r, next_c, cur_dir) + 1);
		cache[pan[next_r][next_c]] = false;
	}
	
	return tmp_ret;
}

void solve(){
	
	for(int i = 0 ; i < N-2 ; ++i){
		for(int j = 1 ; j < N-1 ; ++j){
			walk = 0;
			memset(cache, false, sizeof(cache));
			start_r = i;	start_c = j;
			cache[pan[i][j]] = true;
			ans = max(dfs(i, j, 0) + 1, ans);
			cache[pan[i][j]] = false;
		}
	}
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		ans = -1 * 0x7fffffff;
		scanf("%d", &N);
		
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &pan[i][j]);
			}
		}
			
		solve();
		
		if(ans < 0)	ans = -1;
		// 디저트를 먹을 수 없는 경우 정답은 -1이다.
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}
