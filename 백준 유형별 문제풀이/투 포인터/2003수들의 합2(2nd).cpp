// N(1¡ÂN¡Â10,000), M(1¡ÂM¡Â300,000,000)

#include <cstdio>

int N, M, ans;
int pan[10000];

void solve(){
	
	int left = 0;	int right = 0;
	int sum = pan[0];
	
	while(true){
		
		if(left >= N || right >= N)	break;
		
//		printf("(%d / %d) : %d\n", left,  right, sum);
		
		if(sum == M){
			sum -= pan[left++];
			ans++;
		}
		else if(sum > M){
			sum -= pan[left++];
		}
		else{
			sum += pan[++right];
		}
		
	}
	
	
}

int main(){
	scanf("%d %d", &N, &M);
	
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	
	solve();
	
	printf("%d", ans);
	
	return 0;	
}
