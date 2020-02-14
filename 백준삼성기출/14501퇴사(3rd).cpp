// N (1 ≤ N ≤ 15)
// (1 ≤ Ti ≤ 5, 1 ≤ Pi ≤ 1,000)

// OUTPUT : 백준이가 얻을 수 있는 최대 이익을 출력한다.

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N;

int T[15];
int P[15];

int cache[15];

int dp(int index){
	if(index > N)	return -1*0x7fffffff;
	if(index == N)	return 0;
	
	int& tmp = cache[index];
	
	if(tmp != -1)	return tmp;
	
	
	tmp = max(dp(index+1), dp(index + T[index]) + P[index]);  
	return tmp;
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d %d", &T[i], &P[i]);
	}
	
	int ans = dp(0);
	printf("%d", ans);
	return 0;
}


