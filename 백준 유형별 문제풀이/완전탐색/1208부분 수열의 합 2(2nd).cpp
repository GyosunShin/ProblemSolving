// (1 ¡Â N ¡Â 40, |S| ¡Â 1,000,000)

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, S;
int pan[40];

vector<int> a;
vector<int> b;

int sumA, sumB;
long long ans;

void dfsB(int start, int cnt){
	
	if(cnt > 0){
		b.push_back(sumB);
		if(sumB == S)	++ans;
	}
	
	if(cnt == N-(N/2)-1)	return;
	
	for(int i = start ; i < N ; ++i){
		sumB += pan[i];
		dfsB(i+1, cnt+1);
		sumB -= pan[i];
	}
		
}

void dfsA(int start, int cnt){
	
	if(cnt > 0){
		a.push_back(sumA);
		if(sumA == S)	++ans;
	}
	
	if(cnt == (N/2)+1)	return;
	
	for(int i = start ; i <= (N/2) ; ++i){
		sumA += pan[i];
		dfsA(i+1, cnt+1);
		sumA -= pan[i];
	}
	
}

int main(){
	scanf("%d %d", &N, &S);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	dfsA(0, 0);
	dfsB(N/2+1, 0);
		
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	for(int i = 0 ; i < a.size() ; ++i){
		int cur = a[i];
		int remain = S - cur;
				
//		vector<int>::iterator lo;
//		lo = lower_bound(b.begin(), b.end(), remain);
//		vector<int>::iterator hi;
//		hi = upper_bound(b.begin(), b.end(), remain);
		
		ans += (upper_bound(b.begin(), b.end(), remain) - lower_bound(b.begin(), b.end(), remain));
	}
	
	printf("%lld", ans);
	
	return 0;
}
