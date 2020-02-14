#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int T;
int n;
int cache[1000];
vector<int> a[1000];
int ans;
int map[1000];

void dfs(int start){
//	printf("START : %d\n", start);
	if(cache[start] != -1){
//		printf("RETURN\n");
		return;	
	}
//	printf("RETURN\n");
	cache[start] = 1;
	dfs(a[start][0]);
}


int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		ans = 0;
		memset(cache, -1, sizeof(cache));
		for(int i = 0  ; i< n ; ++i){
			a[i].clear();
		}
		scanf("%d", &n);
		for(int i = 0  ; i< n ; ++i){
			scanf("%d", &map[i]);		
			a[i].push_back(map[i] - 1);
		}
		
		for(int i = 0  ; i< n ; ++i){
			if(cache[i] == -1){
				dfs(i);
				++ans;
			}	
			
		}
		
		printf("%d\n", ans);
		
	}
	return 0;
}
