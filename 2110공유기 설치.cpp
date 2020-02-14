// ���� ������ �� ������ ������ �Ÿ��� �ִ�� �ϴ� ���α׷��� �ۼ��Ͻÿ�.
// ���� ���� N (2 �� N �� 200,000)    �������� ���� C (2 �� C �� N)
// xi (1 �� xi �� 1,000,000,000)

// OUTPUT : ù° �ٿ� ���� ������ �� ������ ������ �ִ� �Ÿ��� ����Ѵ�.

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
