// OUTPUT : 각 test case에 대해 두 소수 사이의 변환에 필요한 최소 회수를 출력한다. 불가능한 경우 Impossible을 출력한다.

#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>

using namespace std;

int T;

int start, final;

int cache[10][10][10][10];

bool check(int n){
	int sq = (int)sqrt(n);
	for(int i = 2 ; i <= sq ; ++i){
		if(n % i == 0)	return false;
	}	
	return true;
}

int solve(int n){
	int backup = n; 
//	printf("n : %d\n", n);
	if(n == final){
		printf("N == FINAL : %d\n", n);
		return 0;
	}
	
	int a,b,c,d;
	d = backup % 10;
	backup /= 10;
	c = backup % 10;
	backup /= 10;
	b = backup % 10;
	backup /= 10;
	a = backup % 10;
	backup /= 10;	
	
//	printf("RET11 = %d\n", cache[a][b][c][d]);
	int& ret = cache[a][b][c][d];
//	printf("RET22 = %d\n", ret);	 

	if(ret != -1){
//		printf("ret != -1\n");
		return ret;
	}	
	
	if(!check(n)){  // 소수가 아니면 
//		printf("소수 아닌 경우\n");
		return ret = 0x7fffffff;
	}				
	printf("n : %d\n", n);
	ret = 0x7fffffff;
	
	for(int i = 1 ; i <= 9 ; ++i){
		if(i == a)	continue;
		int tmp = (i * 1000) + (b * 100) + (c * 10) + d;
//		printf("[1]n : %d / ret = %d\n", n, ret);
		if(solve(tmp) == 0x7fffffff)	continue;
		else	ret = min(solve(tmp) + 1, ret);
//		printf("[2]n : %d / min = %d\n", n, ret);
	}
	for(int i = 0 ; i <= 9 ; ++i){
		if(i == b)	continue;
		int tmp = (a* 1000) + (i * 100) + (c * 10) + d;
		if(solve(tmp) == 0x7fffffff)	continue;
		else	ret = min(solve(tmp) + 1, ret);
	}
	for(int i = 0 ; i <= 9 ; ++i){
		if(i == c)	continue;
		int tmp = (a* 1000) + (b * 100) + (i * 10) + d;
		if(solve(tmp) == 0x7fffffff)	continue;
		else	ret = min(solve(tmp) + 1, ret);
	}
	for(int i = 0 ; i <= 9 ; ++i){
		if(i == d)	continue;
		int tmp = (a* 1000) + (b * 100) + (c * 10) + i;
		if(solve(tmp) == 0x7fffffff)	continue;
		else	ret = min(solve(tmp) + 1, ret);
	}
	printf("RET : %d\n", ret);
	return ret;
}

int main(){
	
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		memset(cache, -1, sizeof(cache));
		scanf("%d %d", &start, &final);
		int ans = solve(start);
		if(ans == -1)	printf("Impossible\n");
		else	printf("%d\n", ans);
	}
	
	return 0;
}


