// 집의 개수 N (2 ≤ N ≤ 200,000)
// 공유기의 개수 C (2 ≤ C ≤ N)
// 집의 좌표를 나타내는 xi (1 ≤ xi ≤ 1,000,000,000)

// OUTPUT : 첫째 줄에 가장 인접한 두 공유기 사이의 최대 거리를 출력한다.

#include <cstdio>
#include <algorithm>

using namespace std;

int N, C;
int pan[200000];

bool check(int input){
	
	int cnt = 0;
	int prev = pan[0];
	for(int i = 1 ; i < N ; ++i){
		if(pan[i] - prev >= input){
			++cnt;
			prev = pan[i];
		}
	}
	
	if(cnt >= (C-1))	return true;
	return false;
	
}

int solve(){
	
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
	
	return right;
	
}

int main(){
	scanf("%d %d", &N, &C);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &pan[i]);
	}
	
	sort(pan, pan + N);
	
	printf("%d", solve());
	
	return 0;
}
