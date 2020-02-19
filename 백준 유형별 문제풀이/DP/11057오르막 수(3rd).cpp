// ���� ���� N�� �־����� ��, ������ ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� 0���� ������ �� �ִ�.

// N (1 �� N �� 1,000)

// OUTPUT : ù° �ٿ� ���̰� N�� ������ ���� ������ 10,007�� ���� �������� ����Ѵ�.

#include <cstdio>
#include <cstring>

int N;
int cache[1001][10];

int solve(int idx, int input){
	
	if(idx >= N)	return 1;
	
	int &ret = cache[idx][input];
	if(ret != -1)	return ret;
	
	int tmp_ret = 0;
	
	for(int i = input ; i < 10 ; ++i){
		tmp_ret += solve(idx + 1, i);
		tmp_ret %= 10007;
	}
	
	return ret = tmp_ret;
}

int main(){	
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	
	int ans = 0;
	
	for(int i = 0 ; i < 10 ; ++i){
		ans += solve(1, i);
		ans %= 10007;
	}
	
	printf("%d", ans);
	
	return 0;
}
