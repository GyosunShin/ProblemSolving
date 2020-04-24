// 3 <= N <= 10000
// 1 <=  <= 100000
// N <= 총 예산 <= 1000000000

#include <cstdio> 
#include <algorithm>

using namespace std;

int N, M;
int pan[10000];
int mmax = -1;

bool check(int mid){
	int sum = 0;
	
	for(int i = 0 ; i < N ; ++i){
		if(mid <= pan[i])	sum += mid;
		else	sum += pan[i];
	}
	
	if(sum <= M)	return true;
	return false;
}

int solve(){
	
	int left = 0;
	int right = mmax;
	
	while(left <= right){
		int mid = (left + right) / 2;
		
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
	int sum = 0;
	
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &pan[i]);
		sum += pan[i];
		mmax = max(mmax, pan[i]);
	}
	scanf("%d", &M);
	
	if(sum <= M){
		printf("%d", mmax);
		return 0;
	}
	
	int ret = solve();
	
	// OUTPUT : 첫째 줄에는 배정된 예산들 중 최댓값인 정수를 출력한다. 
	printf("%d", ret);

	return 0;
}

