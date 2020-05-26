//  (1 ¡Â N ¡Â 20, |S| ¡Â 1,000,000)

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, S;
int pan[20];

int ans;
int ccnt;

void solve(int start, int cnt){
	
	if(ans == S && cnt > 0)	ccnt++;
	
	if(cnt == N)	return;
	
	for(int i = start ; i < N ; ++i){
		ans += pan[i];
		solve(i+1, cnt+1);
		ans -= pan[i];
	}
	
}

int main(){
	scanf("%d %d", &N, &S);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	solve(0, 0);
	
	printf("%d", ccnt);
	
	return 0;
}
