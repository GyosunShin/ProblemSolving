// 집의 개수 N (2 ≤ N ≤ 200,000)
// 공유기의 개수 C (2 ≤ C ≤ N)
// (1 ≤ xi ≤ 1,000,000,000)

// OUTPUT : 가장 인접한 두 공유기 사이의 최대 거리를 출력한다.

#include <cstdio> 
#include <algorithm>

using namespace std;

int N, C;
int pan[200000];
int ans;

bool check(int input){
	
	int prev = pan[0];
	int cnt = 1;
	for(int i = 1 ; i < N ; ++i){
		if(pan[i] - prev >= input){
			++cnt;
			prev = pan[i];
		}
	}
	
	if(cnt >= C)	return true;
	return false;
	
}

void solve(){
	
	int left = 0;
	int right = pan[N-1] - pan[0];
	
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
	scanf("%d %d", &N, &C);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &pan[i]);
	}
	
	sort(pan, pan + N);

	solve();
	
	printf("%d", ans);
	
	return 0;
}
