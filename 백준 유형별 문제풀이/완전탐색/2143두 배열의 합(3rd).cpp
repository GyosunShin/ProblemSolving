// (-1,000,000,000 ¡Â T ¡Â 1,000,000,000)
// (1 ¡Â n ¡Â 1,000)
// -1,000,000 <= °¢ ¿ø¼Ò <= 1,000,000
// (1¡Âm¡Â1,000)

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M;
int panA[1000];
int panB[1000];

vector<int> a;
vector<int> b;

long long ans;

void sumA(){
	
	int sum = 0;
	int idx = 0;
	while(true){
		if(idx >= N)	break;
		sum += panA[idx++];
		a.push_back(sum);
	}
	
	int start = 1;
	int end = a.size();
	for(int i = 1 ; i < N ; ++i){
		
		for(int j = start ; j < end ; ++j){
			a.push_back(a[j] - panA[i-1]);
		}
		start = end+1;
		end = a.size();
	}	
	
}

void sumB(){
	
	int sum = 0;
	int idx = 0;
	while(true){
		if(idx >= M)	break;
		sum += panB[idx++];
		b.push_back(sum);
	}
	
	int start = 1;
	int end = b.size();
	for(int i = 1 ; i < M ; ++i){
		
		for(int j = start ; j < end ; ++j){
			b.push_back(b[j] - panB[i-1]);
		}
		start = end+1;
		end = b.size();
	}	
	
}

void solve(){
	
	sumA();
	sumB();
	
	sort(a.begin(), a.end());	sort(b.begin(), b.end());
	for(int i = 0 ; i < a.size() ; ++i){
		int cur = a[i];
		int rem = T - cur;
		ans += (upper_bound(b.begin(), b.end(), rem) - lower_bound(b.begin(), b.end(), rem));
	}
	
}

int main(){
	scanf("%d", &T);
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &panA[i]);
	scanf("%d", &M);
	for(int i = 0 ; i < M ; ++i)	scanf("%d", &panB[i]);
	
	solve();
	
	printf("%lld", ans);
	
	return 0;
}
