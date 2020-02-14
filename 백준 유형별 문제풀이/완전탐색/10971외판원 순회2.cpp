//  (2 ¡Â N ¡Â 10)
// 1 <=   <= 1,000,000

#include <stdio.h> 
#include <vector>
#include <string.h>

using namespace std;

int N;

int map[10][10];
int cache[10];

vector<int> picked;

int ans = 0x7fffffff;

void dfs(){
	if(picked.size() == N){
		
		printf("[");
		for(int i = 0 ; i < picked.size() ; ++i){
			printf("%d ", picked[i]);
		}
		printf("]\n");
		
		
		bool tmp_flag = true;
		int tmp_sum = 0;
		for(int i = 0 ; i < picked.size() - 1 ; ++i){
			int tmp = map[picked[i]][picked[i+1]];
			if(tmp == 0){
				tmp_flag = false;
				break;
			}
			tmp_sum += tmp;
		}
		
		int ttmp = map[picked[picked.size() - 1]][picked[0]];
		
		if(ttmp == 0)	tmp_flag = false;
		tmp_sum += ttmp;
		
		if(tmp_flag){
			if(ans > tmp_sum)	ans = tmp_sum;
		}

		return;
	}
	
	for(int i = 0 ; i < N ; ++i){
		if(cache[i] != -1)	continue;
		picked.push_back(i);
		cache[i] = 1;
		dfs();
		picked.pop_back();
		cache[i] = -1;
	}
	
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	//##################################
	
	// nPr ÀÌ¿ë
	dfs();
	
	printf("%d", ans);
	
	return 0;
}
