// (-1,000,000,000 ≤ T ≤ 1,000,000,000)
// (1 ≤ n ≤ 1,000)
// (1 ≤m ≤1,000)
// -1,000,000 <= 배열 원소는 <= 1,000,000

#include <cstdio> 
#include <algorithm>
#include <vector>

using namespace std;

int T, N, M;
int A[1000];
int B[1000];

vector<int> sumA;
vector<int> sumB;


int main(){
	scanf("%d", &T);
	scanf("%d", &N);
	for(int i =0 ; i < N ; ++i){
		scanf("%d", &A[i]);
	}
	
	scanf("%d", &M);
	for(int i =0 ; i < M ; ++i){
		scanf("%d", &B[i]);
	}
	
	
	for(int i = 0 ; i < N ; ++i){
		int tmp_sum = 0;
		for(int j = i ; j < N ; ++j){
			tmp_sum += A[j];
			sumA.push_back(tmp_sum);
		}
	}
	for(int i = 0 ; i < M ; ++i){
		int tmp_sum = 0;
		for(int j = i ; j < M ; ++j){
			tmp_sum += B[j];
			sumB.push_back(tmp_sum);
		}
	}	
	
		
	sort(sumA.begin(), sumA.end());
	sort(sumB.begin(), sumB.end());
	
	long long ans = 0;
	
	for(int i = 0 ; i < sumA.size() ; ++i){
		int cur = sumA[i];
		int rem = T - cur;
		
		ans += upper_bound(sumB.begin(), sumB.end(), rem) - lower_bound(sumB.begin(), sumB.end(), rem);
	}
	
	printf("%d", ans);

	return 0;
}
