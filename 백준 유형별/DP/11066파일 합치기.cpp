// K (3 ≤ K ≤ 500)
// 파일 크기 <= 10000 

// OUTPUT : 프로그램은 표준 출력에 출력한다. 각 테스트 데이터마다 정확히 한 행에 출력하는데, 
// 모든 장을 합치는데 필요한 최소비용을 출력한다.

#include <stdio.h> 
#include <algorithm>
#include <string.h>

using namespace std;

int T;
int cache[500];
int K;

int solve(int n){
	
	
	int& ret = cache[n];
	if(ret != -1)	return ret;
	ret = max(, );
	return ret;
}

int main(){
	scanf("%d", &T);
	for(int t = 0 ; t < T ; ++t){
		memset(cache, -1, sizeof(cache));
		int map[500];
		scanf("%d", &K);	 
		for(int k = 0 ; k < K ; ++k){
			scanf("%d", &map[k]);
		}
		int ans = solve(0);
		printf("%d\n", ans);
	}
	return 0;
}
