// (10 ¡Â N < 100,000)	(0 < S ¡Â 100,000,000)

#include <cstdio>
#include <algorithm>

using namespace std;

int N,S;
int pan[100000];
int mmin = 0x7fffffff;

void solve(){
	
	int left = 0;
	int right = 0;
	int sum = pan[0];
	
	while(left < N && right < N){
		
		if(sum >= S){
			int tmp = right - left + 1;
			mmin = min(mmin, tmp);
			sum -= pan[left++];
		}
		else{
			sum += pan[++right];
		}
		
	}
	
}

int main(){
	scanf("%d %d", &N, &S);
	for(int i =0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	solve();
	
	if(mmin == 0x7fffffff)	mmin = 0;
	
	printf("%d", mmin);
	return 0;
}
