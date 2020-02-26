// K개 --> N개
// N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다

// OUTPUT :  이때 만들 수 있는 최대 랜선의 길이를 구하는 프로그램을 작성

// 1 <= K <= 10,000

#include <cstdio> 
#include <algorithm>

using namespace std;

long long K;
long long N;
long long pan[10000];

long long mmax = -1;
long long ans = -1;

bool check(int input){
	long long tmp_cnt = 0;
	
	for(int i = 0 ; i < K ; ++i){
		tmp_cnt += pan[i] / input;
	}
	
	if(tmp_cnt >= N)	return true;
	return false;
}

void solve(){
	// 1 ~ mmax
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
		ans = right;
	}
}

int main(){
	scanf("%lld %lld", &K, &N);
	
	for(int i = 0 ; i < K ; ++i){
		scanf("%lld", &pan[i]);
		mmax = max(mmax, pan[i]);
	}
	
	solve();
	
	printf("%lld", ans);
	
	return 0;
}
