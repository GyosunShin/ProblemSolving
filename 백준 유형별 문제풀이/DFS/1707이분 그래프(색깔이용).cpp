// K(2≤K≤5)
// V(1≤V≤20,000)와 간선의 개수 E(1≤E≤200,000)
// 1 ~ V 

#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector<int> vs[200001];
int cache[200001];
bool ans = true;

void dfs(int start, int v, int flag){
	if(!ans)	return;
	
	int next_flag;
	if(flag == 0)	next_flag = 1;
	else if(flag == 1)	next_flag = 0;
	
	if(cache[start] == -1){  // 아직 아무도 거치지 않았다면 
		cache[start] = flag;
	}
	else{
		if(cache[start] == next_flag){
			ans = false;
			return;
		}
		return;
	}
	
	
	for(int i = 0 ; i < vs[start].size() ; ++i){
		dfs(vs[start][i], v, next_flag);
	}
	
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0 ; t < T ; ++t){
		ans = true;
		memset(cache, -1, sizeof(cache));
		int V, E;
		scanf("%d %d", &V, &E);
		for(int i = 0 ; i <= V ; ++i)	vs[i].clear();
		for(int i = 0 ; i < E ; ++i){
			int tmp1, tmp2;
			scanf("%d %d", &tmp1, &tmp2);	
			vs[tmp1].push_back(tmp2);	vs[tmp2].push_back(tmp1);
		}
		//#######################################################
		bool tmp_ans = true;
		for(int i = 1 ; i <= V ; ++i){
			if(cache[i] == -1){
				dfs(i, V, 0);	
				if(!ans){
					tmp_ans = false;
					break;
				}
			}
		}
		if(tmp_ans)	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}
