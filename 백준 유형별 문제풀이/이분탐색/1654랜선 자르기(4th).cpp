// 1 <= K <= 10000
// 1 <= N <= 1000000 

// 각 랜선의 길이 <= 2^31 - 1 

// OUTPUT : 랜선의 최대 길이

#include <cstdio>
#include <algorithm>

using namespace std;

int K, N;
int pan[10000];
int mmax = -1;

bool check(long long mid){
	long long ret = 0;
	
	for(int i = 0 ; i < K ; ++i){
		ret += (pan[i] / mid);
	}
	
	if(ret >= N)	return true;
	return false;
}

int solve(){
	
	long long left = 1;
	long long right = mmax;
	
	while(left <= right){
		long long mid = (left + right) / 2;
		
		if(check(mid)){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	
	return right;
	
}

int main(){
	scanf("%d %d", &K, &N);
	
	for(int i = 0 ; i < K ; ++i){
		scanf("%d", &pan[i]);
		mmax = max(mmax, pan[i]);
	}
	
	printf("%d", solve());
	
	return 0;
}
