// (2 ≤ N ≤ 10)
// 1 <=   <= 1,000,000

#include <stdio.h> 
#include <algorithm>

using namespace std;

int N;

int map[10][10];
bool visited[10];

int dfs(int start){
	bool tmp_flag = true;
	for(int i = 0 ; i < N ; ++i){
		if(!visited[i]){
			tmp_flag = false;
			break;
		}
	}
	
	if(tmp_flag){  // 모든 city를 방문했을 때 
		if(map[start][0] == 0)	return 0x7fffffff;
		else	return map[start][0];
	}
	
	int tmp = 0x7fffffff;
	
	for(int i = 0 ; i < N ; ++i){
		if(map[start][i] == 0 || visited[i])	continue;
		visited[i] = true;
		int ttmp = dfs(i);
		int ret;
		if(ttmp == 0x7fffffff){
			ret = ttmp;
		}
		else{
			ret = ttmp + map[start][i];
		}
		tmp = min(tmp, ret);
		visited[i] = false;
	}
	return tmp;
}

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	//##################################
	visited[0] = true;
	int ans = dfs(0);
	
	printf("%d", ans);
	
	return 0;
}
