// INPUT :  길이(N)는 1 이상 100,000 이하
// 1 <= sticker[i] <= 100

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

// dp1 : 첫번째 스티커를 뜯었을 경우 
// dp2 : 첫번째 스티커를 안 뜯었을 경우
int dp1[100000], dp2[100000];

int solution(vector<int> sticker)
{
	int N = sticker.size();
	dp1[0] = sticker[0];
	dp1[1] = dp1[0];
	dp2[0] = 0;
	dp2[1] = sticker[1];
	
	if(N == 1){
		return max(dp1[0], dp2[0]);
	}
	
	// dp1의 경우 dp[N-2] 까지만 구하면 됨 
	for(int i = 2 ; i <= N-2 ; ++i){
		dp1[i] = max(dp1[i-2] + sticker[i], dp1[i-1]);
	}
	
	// dp2의 경우 dp[N-1] 까지 구해야 함 
	for(int i = 2 ; i <= N-1 ; ++i){
		dp2[i] = max(dp2[i-2] + sticker[i], dp2[i-1]);
	}
	
	
	return max(dp1[N-2], dp2[N-1]);
}
