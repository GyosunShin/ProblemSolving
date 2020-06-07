// A[i][j] = i¡¿j

// 1 <= N <= 100000
// 1 <= K <= min(10^9, N^2) 

#include <cstdio>
#include <algorithm>

using namespace std;

int N, K;

int solve(){
	
	int left = 1;
	int right = K;
	
	while(left <= right){
		int mid = (left + right) / 2;
		int cnt = 0;
		for(int i = 1 ; i <= N ; ++i)	cnt += min(N, mid / i);
		if(cnt >= K){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	
	return left;
}

int main(){
	scanf("%d", &N);
	scanf("%d", &K);
	
	int ret = solve();	
	printf("%d", ret);
	
	return 0;
}
