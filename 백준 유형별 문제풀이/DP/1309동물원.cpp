// (1��N��100,000)

#include <cstdio> 
#include <cstring>

int N;

int cache[2][100000];

int dfs(int r, int c){
	
	if(c == N-1)	return 1;
	
	int& ret = cache[r][c];
	if(ret != -1)	return ret;
	
	int sum = 0;
	
	sum += dfs(r, )
	
	
}

int main(){
	
	memset(cache, -1, sizeof(cache));
	
	scanf("%d", &N);
	
	int ans = 0;
	
	ans += dfs(0, 0);
	ans %= 9901;
	ans += dfs(1, 0);
	ans %= 9901;
	ans += dfs(0, 1);
	ans %= 9901;
	ans += dfs(1, 1);
	ans %= 9901;
	
	// OUTPUT
	// ù° �ٿ� ���ڸ� ��ġ�ϴ� ����� ���� 9901�� ���� �������� ����Ͽ���.
	printf("%d", ans);

	return 0;
	
}
