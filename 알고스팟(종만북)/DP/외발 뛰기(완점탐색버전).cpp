// �׽�Ʈ ���̽��� �� C(C <= 50)
// ������ ũ�� n(2 <= n <= 100)

// ��� : �� �׽�Ʈ ���̽����� �� �ٷ�, ���������� �� ������ ������ �� ���� ��� "YES"��, �ƴ� ��� "NO"�� ����մϴ�. (����ǥ ����) 

#include <stdio.h> 
#include <string.h>

int T, N;
int map[100][100];
bool flag = false;

void solve(int r, int c){
	if(r == (N-1) && c == (N-1)){
		flag = true;
		return;
	}
	
	if(0 > r || r >= N || 0 > c || c >= N)	return;
	
	int jmp = map[r][c];
	solve(r+jmp, c);
	solve(r, c+jmp);
}

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		flag = false;	
		memset(map, 0, sizeof(map));
		scanf("%d", &N);
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &map[i][j]);		
			}
		}
		
		solve(0, 0);
		if(flag)	printf("YES\n");
		else	printf("NO\n");
	}
	
	return 0;
}

