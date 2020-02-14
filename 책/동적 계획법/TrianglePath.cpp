#include <stdio.h>
#include <iostream>

int n;  // MAX 가로줄 개수 
int triangle[100][100];
int cache[100][100][MAX_NUMBER*100 + 1];

int path1(int r, int c, int sum){
	//기저 사례 : 맨 아랫 줄까지 돋ㄹ했을 경우 
	if((r + 1) == n) return (sum + triangle[r][c]);
	
	// Memoization
	int& ret = cache[r][c][sum];
	if(ret != -1) return ret;
	sum += triangle[r][c];
	return ret = max(path1(r+1,c+1,sum), path1(r+1, c, sum));  // 참조자 쓰는 것이므로 cache에 저장하는것이랑 동일하다! 
}

