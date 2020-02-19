// 상담을 적절히 했을 때, 백준이가 얻을 수 있는 최대 수익을 구하는 프로그램을 작성하시오.

// N (1 ≤ N ≤ 15)
// (1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1,000)

#include <cstdio>
#include <cstring>
#include <algorithm> 

using namespace std;	

int N;
int T[15];
int P[15];
int cache[15];

int solve(int idx){
	if(idx == N)	return 0;
	
	int &ret = cache[idx];
	if(ret != -1)	return ret;
	
	if(idx + T[idx] > N){
		ret = max(ret, solve(idx + 1));	// 오늘 안하고 그냥 내일로 넘긴다. 
	}
	else{
		// 오늘 한다.
		ret = max(ret, solve(idx + T[idx]) + P[idx]);
		
		// 오늘 안하고 그냥 내일로 넘긴다. 
		ret = max(ret, solve(idx + 1));	
	}	
	
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d %d", &T[i], &P[i]);	
	}
	
	printf("%d", solve(0));
	
	return 0;
}
