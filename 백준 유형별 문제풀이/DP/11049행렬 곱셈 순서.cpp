// 행렬의 개수 N(1 ≤ N ≤ 500)
// (1 ≤ r, c ≤ 500)

// OUTPUT
// 첫째 줄에 입력으로 주어진 행렬을 곱하는데 필요한 곱셈 연산의 최솟값을 출력

#include <cstdio> 
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int pan[500][2];
int cache[500][500];

int dfs(int start, int end){
	
	int& ret = cache[start][end];
	if(ret != -1)	return ret;
	
	if(start + 1 == end){
		return ret = pan[start][0] * pan[start][1] * pan[end][1];
	}
	
	int mmin = 0x7fffffff;
	
	for(int i = start ; i < end ; ++i){
		int one = i - start;	int two = end - (i+1);
		
		if(one == 0){
			int tmp = (pan[start][0] * pan[start][1] * pan[end][1]) + dfs(i+1, end);
			mmin = min(mmin, tmp);
		}
		else if(two == 0){
			int tmp = (pan[start][0] * pan[i][1] * pan[end][1]) + dfs(start, i);
			mmin = min(mmin, tmp);
		}
		else{
			mmin = min(mmin, dfs(start, i) + dfs(i+1, end) + (pan[start][0] * pan[i][1] * pan[end][1]) );	
		}
	}
	
	return ret = mmin;
	
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		scanf("%d %d", &pan[i][0], &pan[i][1]);
	}
	
	int ans = dfs(0, N-1);
	
	printf("%d", ans);
	
	return 0;
}


