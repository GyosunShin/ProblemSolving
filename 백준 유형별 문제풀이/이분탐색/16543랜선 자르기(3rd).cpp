// 1 <= K <= 10000
// 1 <= N <= 1000000
// K <= N

// OUTPUT : 첫째 줄에 N개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수로 출력한다.

#include <cstdio>

long long K, N;
long long pan[10000];

long long mmin = 0x7fffffff;
long long mmax = 0;

bool check(long long input){
	long long tmp_ret = 0;
	for(int i = 0 ; i < K ; ++i){
		tmp_ret += pan[i] / input;
	}
//	printf("RET : %d\n", tmp_ret);
	if(tmp_ret >= N)	return true;
	return false;
}

long long solve(){
	
	long long left = 1;
	long long right = mmax;
	
	while(left <= right){
		long long mid = (left + right) / 2;
//		printf("(%d  /  %d)  MID : %d\n", left, right, mid);
		
		if(check(mid)){
			left = mid + 1;
		}
		else	right = mid - 1;
	}
	
	return right;
}

int main(){
	scanf("%lld %lld", &K, &N);

	for(int i = 0 ; i < K ; ++i){
		scanf("%lld", &pan[i]);
		if(mmin > pan[i])	mmin = pan[i];
		if(mmax < pan[i])	mmax = pan[i];
	}
	
	printf("%lld", solve());
	
	return 0;
}
