//  (3 ≤ N ≤ 100) 
// 0 <= 주어지는 수 <= 9 

// 음수 X
// 20초과 X
// 0 <=   <= 20

// OUTPUT
// 첫째 줄에 상근이가 만들 수 있는 올바른 등식의 개수를 출력한다. 이 값은 2^63-1 이하이다.

#include <cstdio> 
#include <cstring>

int N;
int pan[100];

long long cache[100][21];

long long dfs(int idx, int sofar){
	
	if(idx == N-2){
		if(sofar == pan[N-1]){
			return 1;
		}
		else{
			return 0;
		}
	}
	
	if(0 > sofar || sofar > 20)	return 0;
	
	long long& ret = cache[idx][sofar];
	if(ret != -1)	return ret;
	
	long long sum = 0;
 	sum += dfs(idx+1, sofar + pan[idx+1]) + dfs(idx+1, sofar - pan[idx+1]);
	
	return ret = sum;
}


int main(){
	memset(cache, -1, sizeof(cache));
	
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &pan[i]);	
	}
	
	printf("%lld", dfs(0, pan[0]));
	
	return 0;
}
