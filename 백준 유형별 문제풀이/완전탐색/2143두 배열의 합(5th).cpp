// -1,000,000,000 ≤ T ≤ 1,000,000,000
// 1 ≤n ≤1,000
// -1,000,000 <= 각 배열원솟값 <= 1,000,000 
// 1 ≤m ≤1,000

#include <cstdio> 
#include <vector>
#include <algorithm>

using namespace std;

int T;
int N, M;
int A[1000];
int B[1000];
long long sumA[1000];
long long sumB[1000];

vector<long long> va, vb;

void sumBuild(){
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = i ; j < N ; ++j){
			va.push_back(sumA[j] - sumA[i] + A[i]);
		}
	}
	
	for(int i = 0 ; i < M ; ++i){
		for(int j = i ; j < M ; ++j){
			vb.push_back(sumB[j] - sumB[i] + B[i]);
		}
	}	
	
}

long long solve(){
	long long ret = 0;
	
	sort(vb.begin(), vb.end());
	
	for(int i = 0 ; i < va.size() ; ++i){
		long long cur = va[i];
		long long rem = T - cur;
		
		ret += upper_bound(vb.begin(), vb.end(), rem)
		- lower_bound(vb.begin(), vb.end(), rem);
	}
	
	return ret;
}

int main(){
	scanf("%d", &T);
	scanf("%d", &N);
	long long tmp = 0;
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &A[i]);
		tmp += A[i];
		sumA[i] = tmp;
	}
	tmp = 0;
	scanf("%d", &M);
	for(int i = 0 ; i < M ; ++i){
		scanf("%d", &B[i]);
		tmp += B[i];
		sumB[i] = tmp;
	}
	
	sumBuild();
	
	printf("%lld", solve());
	
	return 0;
}
