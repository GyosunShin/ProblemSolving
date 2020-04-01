// (1≤N≤10,000)
// (1≤M≤300,000,000)
// 1 <= A[x] <= 30,000

#include <cstdio> 
#include <algorithm>

using namespace std;

int N, M, ans;
int pan[10000];

void solve(){
	
	int left = 0;
	int right = 0;
	int sum = pan[0];
	
	while(right < N && left < N){
		if(sum > M){
			sum -= pan[left++];
			
			if(left > right){
				right = left;
				sum = pan[left];
			}
			
		}
		else{
			if(sum == M){
				++ans;
			}
			sum += pan[++right];
		}
		
	}
	
}

int main(){
	scanf("%d %d", &N, &M);
	
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	// 투 포인터 이용
	solve(); 
	
	printf("%d", ans);
	
	return 0;
}
