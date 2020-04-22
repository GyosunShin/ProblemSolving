//  (1 ≤ N ≤ 100, 1 ≤ M ≤ 1000, 0 ≤ S ≤ M) 

// OUTPUT
// 첫째 줄에 가능한 마지막 곡의 볼륨 중 최댓값을 출력한다. 
// 만약 마지막 곡을 연주할 수 없다면 (중간에 볼륨 조절을 할 수 없다면) -1을 출력한다.

// 0 <= 볼륨값 <= M 

#include <cstdio> 
#include <cstring>
#include <algorithm>

using namespace std;

int N, S, M;
int pan[100];
int cache[100][1001];

const int dd[] = {1, -1};

int dfs(int idx, int sofar){
	
	if(idx == N)	return sofar;
	
	int& ret = cache[idx][sofar];
	if(ret != -1)	return ret;
	
	int mmax = -1 * 0x7fffffff;
	
	for(int dir = 0 ; dir < 2 ; ++dir){
		int next = sofar + (dd[dir] * pan[idx]);
		
		if(0 > next || next > M)	continue;
		
		mmax = max(mmax, dfs(idx+1, next));
	}
	
	return ret = mmax;
	
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	scanf("%d %d %d", &N, &S, &M);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	int ret = dfs(0, S);
	
	if(ret < 0)	ret = -1;
	
	printf("%d", ret);
	
	return 0;
}






