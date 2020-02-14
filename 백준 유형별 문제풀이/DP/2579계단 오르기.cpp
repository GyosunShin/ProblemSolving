// 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다.
// 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
// 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
// 마지막 도착 계단은 반드시 밟아야 한다.

// OUTPUT : 얻을 수 있는 총 점수의 최댓값을 출력한다.

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int stair[301];
int cache[301];
int visited[301];

int solve(int n, int (&visited)[301]){
	printf("%d [", n);
	for(int i = 0 ; i <= N ; ++i){
		printf("%d ", visited[i]);
	}
	printf("]  [");
	for(int i = 0 ; i <= N ; ++i){
		printf("%d ", cache[i]);
	}	
	printf("]\n");
	
	
	if(n == N){
		printf("n == N\n");
		return stair[N];
	}	
	if(n > N){
		printf("n > N\n");
		return (-1 * 0x7fffffff);
	}	
	if(visited[n-1] == 1 && visited[n-2] == 1 && n >= 3){
		printf("SUCCESSIVE!\n");
		return (-1 * 0x7fffffff);
	}
	
	int& ret = cache[n];
	if(n != 0)	visited[n] = 1;
	if(ret != -1)	return ret;
	
	ret = max(stair[n] + solve(n+1, visited), stair[n] + solve(n+2, visited));
	printf("cache[%d] : %d\n", n, ret);
	
	
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i = 1 ; i <= N ; ++i){
		scanf("%d", &stair[i]);
	}
	//##########################
	
	int ans = solve(0, visited);
	
	printf("%d\n", ans);
	
	for(int i = 0 ; i <= N ; ++i)	printf("%d ", cache[i]);
	
	return 0;
}

