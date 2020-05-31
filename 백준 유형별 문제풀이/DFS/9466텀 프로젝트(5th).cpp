#include <cstdio>
#include <cstring>

int T, N;
int pan[100001];
int cache[100001];
bool visited[100001];

int global_idx;

int dfs(int idx){
	visited[idx] = true;
	
	int next_idx = pan[idx];
	
	if(cache[next_idx] != 0){
		cache[idx] = -1;
		return -1;
	}
	
	if(visited[next_idx]){
		global_idx = next_idx;
		cache[idx] = 1;
		if(idx == next_idx)	return -1;
		return 1;
	}
	
	int ret = dfs(next_idx);
	
	cache[idx] = ret;
	
	if(ret == 1 && idx == global_idx){
		return -1;
	}
	return cache[idx];
	
}

void solve(){
	for(int i = 1 ; i <= N ; ++i){
		if(cache[i] == 0){
			dfs(i);
		}	
	}
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		memset(cache, 0, sizeof(cache));
		memset(visited, false, sizeof(visited));
		// 2 ¡Â n ¡Â 100,000
		scanf("%d", &N);
		for(int i = 1 ; i <= N ; ++i)	scanf("%d", &pan[i]);
		
		solve();
		
		int ans = 0;
		for(int i = 1 ; i <= N ; ++i){
			if(cache[i] == -1)	++ans;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
