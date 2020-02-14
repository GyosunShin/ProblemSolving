#include <stdio.h>
#include <iostream>

int n;  // MAX ������ ���� 
int triangle[100][100];
int cache[100][100][MAX_NUMBER*100 + 1];

int path1(int r, int c, int sum){
	//���� ��� : �� �Ʒ� �ٱ��� �������� ��� 
	if((r + 1) == n) return (sum + triangle[r][c]);
	
	// Memoization
	int& ret = cache[r][c][sum];
	if(ret != -1) return ret;
	sum += triangle[r][c];
	return ret = max(path1(r+1,c+1,sum), path1(r+1, c, sum));  // ������ ���� ���̹Ƿ� cache�� �����ϴ°��̶� �����ϴ�! 
}

