//X�� 3���� ������ ��������, 3���� ������.
//X�� 2�� ������ ��������, 2�� ������.
//1�� ����.

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int map[1000001];

int solve(int start){
	if(start == 1)	return 0;
	
	int& ret = map[start];
	if(ret != -1)	return ret;
	int tmp_min = 0x7fffffff;
	if(start % 3 == 0){
		tmp_min = min(tmp_min, solve(start/3) + 1);
	}
	if(start % 2 == 0){
		tmp_min = min(tmp_min, solve(start/2) + 1);
	}
	tmp_min = min(tmp_min, solve(start-1) + 1);
	ret = tmp_min;
	
	return ret;
}

int main(){
	memset(map, -1, sizeof(map));
	scanf("%d", &N);
	
	int ans = solve(N);
	printf("%d", ans);
	
	return 0;
}
