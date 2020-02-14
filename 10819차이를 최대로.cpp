// |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

// N (3 ¡Â N ¡Â 8)

#include <stdio.h> 
#include <algorithm>
#include <vector>

using namespace std;

int N;
int map[8];
int visited[8];

vector<int> picked;

int ans = -1 * 0x7fffffff;

int solve(){
	int tmp_ans = 0;
	for(int i = 0 ; i < picked.size()-1 ; ++i){
		tmp_ans += abs(map[picked[i]] - map[picked[i+1]]);
	}
	return tmp_ans;
}

void dfs(){
	if(picked.size() == N){
		int tmp_ans = solve();
		if(tmp_ans > ans)	ans = tmp_ans;
		return;
	}
	
	for(int i = 0 ; i < N ; ++i){
		if(visited[i] != 0)	continue;
		picked.push_back(i);
		visited[i] = 1;
		dfs();
		picked.pop_back();
		visited[i] = 0;
	}
	
}

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &map[i]);
	//#####################################################
	
	dfs();
	
	printf("%d", ans);
	
	return 0;
}
