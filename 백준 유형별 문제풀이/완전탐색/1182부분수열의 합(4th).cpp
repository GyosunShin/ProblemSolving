// 1 ≤ N ≤ 20, |S| ≤ 1,000,000
// -100,000 <= pan[i] <= 100,000

#include <cstdio>
#include <cmath>

int N, S, answer;
int pan[20];

void solve(){
	for(int i = 1 ; i < (int)pow(2, N) ; ++i){
		int sum = 0;
		
		for(int j = 0 ; j < N ; ++j){
			if(((int)pow(2, j) & i) != 0){
				sum += pan[j];
			}
		}
		
		if(sum == S)	++answer;
	}
}

int main(){
	scanf("%d %d", &N, &S);
	
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	solve();
	
	// OUTPUT
	// 첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.
	printf("%d", answer);
	
	return 0;
}
