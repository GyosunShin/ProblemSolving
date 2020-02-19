// 가장 적은 비용으로 수영장을 이용할 수 있는 방법을 찾고 그 비용을 정답으로 출력하는 프로그램을 작성하라.

// 10 <=  모든 이용권 <= 3000
// 이용권 종류 : 1일, 1달, 3달, 1년
 
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int T;
int d, m, ms, y;
int plan[12];
int cache[12];

int solve(int index){
	if(index > 11){
		return 0;
	}
	int& ret = cache[index];
	if(ret != -1)	return ret;
	
	ret = min(solve(index+1) + (plan[index] * d), solve(index+1) + (m));
	ret = min(ret, solve(index + 3) + ms);
	ret = min(ret, solve(index + 12) + y);
	
	return ret;
}

int main(){
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		memset(cache, -1, sizeof(cache));
		scanf("%d %d %d %d", &d, &m, &ms, &y);
		for(int i = 0 ; i < 12 ; ++i)	scanf("%d", &plan[i]);
		//####################################################
		
		int ans = solve(0);
		
		
		// 영장을 이용하는 경우 중 가장 적게 지출하는 '비용'이다.
		printf("#%d %d\n", z, ans);  
	}
	return 0;
}
