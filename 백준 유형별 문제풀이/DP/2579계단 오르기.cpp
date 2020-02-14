// ����� �� ���� �� ��ܾ� �Ǵ� �� ��ܾ� ���� �� �ִ�.
// ��, �� ����� �����鼭 �̾ ���� ����̳�, ���� ���� ������� ���� �� �ִ�.
// ���ӵ� �� ���� ����� ��� ��Ƽ��� �� �ȴ�. ��, �������� ��ܿ� ���Ե��� �ʴ´�.
// ������ ���� ����� �ݵ�� ��ƾ� �Ѵ�.

// OUTPUT : ���� �� �ִ� �� ������ �ִ��� ����Ѵ�.

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int stair[301];
int cache[301];
int visited[301];

int solve(int n, int (&visited)[301]){
	printf("%d [", n);
	for(int i = 0 ; i <= N ; ++i){
		printf("%d ", visited[i]);
	}
	printf("]  [");
	for(int i = 0 ; i <= N ; ++i){
		printf("%d ", cache[i]);
	}	
	printf("]\n");
	
	
	if(n == N){
		printf("n == N\n");
		return stair[N];
	}	
	if(n > N){
		printf("n > N\n");
		return (-1 * 0x7fffffff);
	}	
	if(visited[n-1] == 1 && visited[n-2] == 1 && n >= 3){
		printf("SUCCESSIVE!\n");
		return (-1 * 0x7fffffff);
	}
	
	int& ret = cache[n];
	if(n != 0)	visited[n] = 1;
	if(ret != -1)	return ret;
	
	ret = max(stair[n] + solve(n+1, visited), stair[n] + solve(n+2, visited));
	printf("cache[%d] : %d\n", n, ret);
	
	
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i = 1 ; i <= N ; ++i){
		scanf("%d", &stair[i]);
	}
	//##########################
	
	int ans = solve(0, visited);
	
	printf("%d\n", ans);
	
	for(int i = 0 ; i <= N ; ++i)	printf("%d ", cache[i]);
	
	return 0;
}

