// (0 ≤ N(여학생) ≤ 100), (0 ≤ M(남학생) ≤ 100), (0 ≤ K ≤ M+N)

// OUTPUT : 만들 수 있는 팀의 최댓값을 출력하면 된다.

#include <cstdio>

int N, M, K, ans;

void solve(){
	int f = 2;	int m = 1;
	int cnt = 0;
	
	while(true){
		if(f > N || m > M){
			break;
		}
		if((N+M-K) < f+m ){
			break;
		}
		
		f += 2;	m += 1;
		++cnt;
	}
	
	ans = cnt;
	
}

int main(){
	scanf("%d %d %d", &N, &M, &K);
	
	solve();
	
	printf("%d", ans);
	
	return 0;
}


