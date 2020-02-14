// OUTPUT : 수열의 i번째 수부터 j번째 수까지의 합 A[i]+A[i+1]+…+A[j-1]+A[j]가 M이 되는 경우의 수

// N(1≤N≤10,000), M(1≤M≤300,000,000)
// 1 <=  <= 30000

#include <stdio.h> 

long long N, M;
long long map[10000];

int solve(int left, int right){
	long long tmp_sum = 0;
	for(int i = left ; i <= right ; ++i){
		tmp_sum += map[i];
	}
	
//	printf("LEFT : %d / RIGHT : %d / SUM : %lld\n", left, right, tmp_sum);
	
	if(right == (N-1)){
		if(tmp_sum == M){
			return 1;
		}
		else if(tmp_sum > M){
			return solve(left + 1, right);
		}
		else{
			return 0;
		}
	}
	
	if(tmp_sum == M){
		return solve(left + 1, right) + 1;
	}
	else if(tmp_sum > M){
		return solve(left + 1, right);
	}
	else{
		return solve(left, right+1);
	}
	
}

int main(){
	scanf("%lld %lld", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		scanf("%lld", &map[i]);
	}
	
	int ans = solve(0,0);
	
	printf("%d", ans);
	
	return 0;
}
