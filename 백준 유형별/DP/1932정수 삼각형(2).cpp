// �ﰢ���� ũ�� n(1 �� n �� 500)�� �־�����
// OUTPUT : ù° �ٿ� ���� �ִ밡 �Ǵ� ��ο� �ִ� ���� ���� ����Ѵ�.

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
int map[500][500];
int cache[500][500];

int solve(int r, int c){
	if(r == n-1)	return map[r][c];
	int& ret = cache[r][c];
	if(ret != -1)	return ret;
	
	ret = max(solve(r+1, c), solve(r+1, c+1)) + map[r][c];
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j <= i ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	
	int ans = solve(0,0);
	printf("%d", ans);
	return 0;
}
