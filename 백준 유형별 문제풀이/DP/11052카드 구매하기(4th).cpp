// (1 ≤ N ≤ 1,000)
// (1 ≤ Pi ≤ 10,000)

// OUTPUT
// 첫째 줄에 민규가 카드 N개를 갖기 위해 지불해야 하는 금액의 최댓값을 출력한다.

#include <cstdio> 
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int pan[1001];
int cache[1001];


int dfs(int cnt){
	if(cnt > N){
		return -1*0x7fffffff;	
	}
	if(cnt == N){
		return 0;
	}
	
	int& ret = cache[cnt];
	if(ret != -1)	return ret;
	
	int mmax = -1;
	
	for(int i = 1 ; i <= N ; ++i){
		int money = pan[i];
		mmax = max(mmax, dfs(cnt + i) + money);
	}
	
	return ret = mmax;
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	scanf("%d", &N);
	
	for(int i = 1 ; i <= N ; ++i){
		scanf("%d", &pan[i]);
	}
	
	int ret = dfs(0);
	
	printf("%d", ret);
	
	return 0;
}
