// (1 ¡Â n ¡Â 4000)

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long ans;

int N;
int A[4000];
int B[4000];
int C[4000];
int D[4000];

vector<int> a;
vector<int> b;

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	}
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			a.push_back(A[i] + B[j]);
			b.push_back(C[i] + D[j]);
		}
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	for(int i = 0 ; i < a.size() ; ++i){
		int cur = a[i];
		int remain = cur * -1;
		ans += upper_bound(b.begin(), b.end(), remain) - lower_bound(b.begin(), b.end(), remain);
	}
	
	printf("%lld", ans);
	
	return 0;
}


