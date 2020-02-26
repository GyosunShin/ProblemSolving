// 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 구하는 프로그램을 작성하시오.

// (1 ≤ N(나무의 수) ≤ 1,000,000, 1 ≤ M(나무의 길이) ≤ 2,000,000,000)

#include <cstdio> 
#include <algorithm>

using namespace std;

int N, M;
int pan[1000000];
int mmax = -1;
int ans;

bool check(int input){
	long long tmp_cnt = 0;
	for(int i = 0 ; i < N ; ++i){
		int tmp = pan[i] - input;
		if(tmp < 0)	continue;
		tmp_cnt += tmp;
	}
	if(tmp_cnt >= M)	return true;
	return false;
}

void solve(){
	int left = 1;
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
	ans = right;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &pan[i]);
		mmax = max(mmax, pan[i]);
	}
	
	solve(); 
	printf("%d", ans);
	
	return 0;
}
