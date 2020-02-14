// �׽�Ʈ ���̽��� �� C(C <= 50)
// ������ ũ�� n(2 <= n <= 100)

// ��� : �� �׽�Ʈ ���̽����� �� �ٷ�, ���������� �� ������ ������ �� ���� ��� "YES"��, �ƴ� ��� "NO"�� ����մϴ�. (����ǥ ����) 

#include <stdio.h> 
#include <string.h>

int T, N;
int map[100][100];
int cache[100][100];

int solve(int r, int c){
	if(r == (N-1) && c == (N-1)){
		return 1;
	}
	if(0 > r || r >= N || 0 > c || c >= N)	return 0;
	
	int jmp = map[r][c];
	int& ret = cache[r][c];
	if(ret != -1)	return ret;
	ret = solve(r+jmp, c) || solve(r, c+jmp);
	return ret;
}

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		memset(map, 0, sizeof(map));
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &map[i][j]);		
			}
		}
		
		int ans = solve(0, 0);
		if(ans == 1)	printf("YES\n");
		else	printf("NO\n");
	}
	
	return 0;
}


