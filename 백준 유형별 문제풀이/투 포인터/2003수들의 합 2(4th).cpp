//  N(1¡ÂN¡Â10,000), M(1¡ÂM¡Â300,000,000)

#include <cstdio> 

int N, M;
int pan[10000];

int solve(){
	int cnt = 0;
	int left = 0, right = 0, sum = pan[0];
	
	while(right < N){
		if(sum <= M){
			if(sum == M)	++cnt;
			sum += pan[++right];
		}
		else{
			sum -= pan[left++];
			
			if(left > right){
				sum = pan[left];
				right = left;
			}
		}
	}
	
	return cnt;
}

int main(){
	scanf("%d %d", &N, &M);
	
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	int ret = solve();
	
	printf("%d", ret);
	
	return 0;
}
