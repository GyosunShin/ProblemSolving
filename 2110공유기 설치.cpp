// 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램을 작성하시오.
// 집의 개수 N (2 ≤ N ≤ 200,000)    공유기의 개수 C (2 ≤ C ≤ N)
// xi (1 ≤ xi ≤ 1,000,000,000)

// OUTPUT : 첫째 줄에 가장 인접한 두 공유기 사이의 최대 거리를 출력한다.

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
int map[200000];

vector<int> picked;

int ans = -1 * 0x7fffffff;

int solve(){
	int tmp_ans = 0x7fffffff;
	for(int i = 0 ; i < picked.size() - 1 ; ++i){
		int tmp = abs(map[picked[i+1]] - map[picked[i]]);
		if(tmp < tmp_ans)	tmp_ans = tmp;
	}
	
	return tmp_ans;
}

void dfs(int start){
	if(picked.size() == C){
		int tmp_ans = solve();
		if(ans < tmp_ans)	ans = tmp_ans;
		return;
	}
	
	for(int i = start ; i < N ; ++i){
		picked.push_back(i);
		dfs(i + 1);
		picked.pop_back();
	}
	
}

int main(){
	scanf("%d %d", &N, &C);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
	}
	//##############################
	
	sort(map, map + N);
	
	dfs(0);
	
	printf("%d", ans);
	
	return 0;
}
