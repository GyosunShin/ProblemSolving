//  (2 ≤ N ≤ 10) 
// 각 행렬의 성분은 1,000,000 이하의 양의 정수

// 첫째 줄에 외판원의 순회에 필요한 최소 비용을 출력한다.

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int pan[10][10];

bool cache[10];

int global_start;

int ans = 0x7fffffff;

void solve(int start, int cost, int deep){
		
	for(int i = 0 ; i < N ; ++i){
		if(deep == (N-1) && i == global_start && pan[start][i] != 0){
			ans = min(ans, cost + pan[start][i]);
			return;
		}
		if(cache[i] || pan[start][i] == 0)	continue;
		cache[i] = true;
		solve(i, cost + pan[start][i], deep+1);
		cache[i] = false;
	}
	
}

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &pan[i][j]);		
		}
	}
	
//	for(int i = 0 ; i < N ; ++i){
//		memset(cache, false, sizeof(cache));
//		global_start = i;
//		cache[i] = true;
//		solve(i, 0, 0);
//	}
	memset(cache, false, sizeof(cache));
	cache[0] = true;
	global_start = 0;
	solve(0, 0, 0);
	
	printf("%d", ans);
	
	return 0;
}
