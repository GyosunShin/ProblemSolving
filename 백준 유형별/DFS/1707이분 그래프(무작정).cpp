// 케이스의 개수 K(2≤K≤5)
// 정점의 개수 V(1≤V≤20,000)	간선의 개수 E(1≤E≤200,000)
// E개의 줄에 거쳐서 간선에 대한 정보

#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;
  
int T;

vector<int> picked;

int cache[20001];

vector<int> vs[20001];

bool ans;

void dfs(int n, int v){
	vector<int> unpicked;	
	for(int i = 1 ; i <= v ; ++i){
		if(cache[i] == 0)	unpicked.push_back(i);
	}
	
	bool tmp = true;
	
//	printf("[");
//	for(int i = 0 ; i < picked.size() ; ++i){
//		printf("%d ", picked[i]);
//	}
//	printf("]\n");
//	printf("<");
//	for(int i = 0 ; i < unpicked.size() ; ++i){
//		printf("%d ", unpicked[i]);
//	}
//	printf(">\n\n");		
	
	for(int i = 0 ; i < picked.size() ; ++i){
		for(int j = 0 ; j < vs[picked[i]].size() ; ++j){
			if(cache[vs[picked[i]][j]] == 1)	tmp = false;
		}
	}
//	printf("UNPICKED SIZE : %d\n",  unpicked.size());
	for(int i = 0 ; i < unpicked.size() ; ++i){
//		printf("vs[unpicked[%d]].size() : %d\n", i,  vs[unpicked[i]].size());
		for(int j = 0 ; j < vs[unpicked[i]].size() ; ++j){
			if(cache[vs[unpicked[i]][j]] == 0)	tmp = false;
		}
//		printf("escape\n");
	}
	
	if(tmp){
//		printf("TTTTT!\n");
		ans = true;
	}	
	
	for(int i = n ; i <= v ; ++i){
		picked.push_back(i);
		cache[i] = 1;
		dfs(i + 1, v);
		picked.pop_back();
		cache[i] = 0;
	}
}

int main(){
	scanf("%d", &T);
	for(int t = 0 ; t < T ; ++t){
		memset(cache, 0, sizeof(cache));
		int V, E;
		for(int i = 0 ; i < 20002 ; ++i)	vs[i].clear();
		ans = false;
		scanf("%d %d", &V, &E);
		for(int i = 0 ; i < E ; ++i){
			int tmp1, tmp2;
			scanf("%d %d", &tmp1, &tmp2);
			vs[tmp1].push_back(tmp2);	vs[tmp2].push_back(tmp1);
		}
		//######################################################
		dfs(1, V);
		if(ans)	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}
