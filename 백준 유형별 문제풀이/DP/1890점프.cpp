// �ݵ�� �������̳� �Ʒ������θ� �̵�

// (4 �� N �� 100)

// OUTPUT
// ���� ���� �� ĭ���� ���� ������ �Ʒ� ĭ���� ������ ��Ģ�� �°� �� �� �ִ� ����� ������ ����Ѵ�. 
// ����� ������ 2^63-1���� �۰ų� ����.

#include <cstdio>
#include <cstring>

int N;
int pan[100][100];
long long cache[100][100];

const int dr[] = {0,1};
const int dc[] = {1,0};

long long dfs(int r, int c){
	
	if(r == N-1 && c == N-1)	return 1;
	
	long long& ret = cache[r][c];
	if(ret != -1)	return ret;
	
	long long tmp_sum = 0;
	
	for(int dir = 0 ; dir < 2 ; ++dir){
		int next_r = r + dr[dir]*pan[r][c];	int next_c = c + dc[dir]*pan[r][c];
		
		if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N
		|| (pan[next_r][next_c] == 0 && next_r != N-1 && next_c != N-1))	continue;
		
		tmp_sum += dfs(next_r, next_c);
	}
	
	return ret = tmp_sum;
	
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	
	printf("%lld", dfs(0,0));	
	
	return 0;
}




