#include <stdio.h> 
#include <algorithm>

using namespace std;

int N;
int T[15], P[15];

//#####################################
int cache[15];   // For) DP Programming
//#####################################

int solve(int day){
	if(day > N) return -987654321;
	if(day == N) return 0;
	
	int& ret = cache[day];
	if(ret != -1) return ret;
	
	ret = max(solve(day + 1), solve(day + T[day]) + P[day]);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d %d", &T[i], &P[i]);
		cache[i] = -1;
	}
	
	int ret = solve(0);
	printf("%d\n", ret);
}
