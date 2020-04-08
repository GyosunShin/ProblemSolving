// 학생의 수가 정수 n (2 ≤ n ≤ 100,000)

// OUTPUT  
// 프로젝트 팀에 속하지 못한 학생들의 수를 나타내면 된다.

#include <cstdio> 
#include <cstring>

int T, N;
int pan[100001];
int cache[100001];	// (1 : 팀 결성 가능)  (0 : 팀 못 이루는 애들)
bool visited[100001];

int src_target;

int dfs(int start){	
	int next = pan[start];
	if(cache[next] != 0){
		cache[start] = -1;
		return -1;
	}
	
	if(visited[next]){
		cache[start] = 1;
		src_target = next;
		return 1;
	}
	
	visited[start] = true;
	int ret = dfs(next);
	if(ret == 1 && start == src_target){
		cache[start] = ret;
		return (-1 * ret);
	}
	return cache[start] = ret;
}

void solve(){
	
	for(int i = 1 ; i <= N ; ++i){
		if(cache[i] == 0){
			src_target = -1;
//			memset(visited, false, sizeof(visited));
			visited[i] = true;
			dfs(i);
//			printf("START  : %d\n", i);
//			for(int j =1 ; j <= N ; ++j)	printf("%d  / ", cache[j]);
//			printf("\n");
		}
	}
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1  ; z <= T ; ++z){
		memset(cache, 0, sizeof(cache));
		memset(visited, false, sizeof(visited));
		scanf("%d", &N);
		for(int i = 1 ; i <= N ; ++i){
			scanf("%d", &pan[i]);
			if(i == pan[i]){
				cache[i] = 1;
			}
		}
		
		solve();
		int ans = 0;
		for(int i = 1 ; i <= N ; ++i){
//			printf("%d  / ", cache[i]);
			if(cache[i] == -1)	++ans;
		}
//		printf("\n");
		printf("%d\n", ans);
	}
	return 0;
}
