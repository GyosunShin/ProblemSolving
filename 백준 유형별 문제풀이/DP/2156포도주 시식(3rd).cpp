// (1��n��10,000)
// 0 <= ������ �� <= 1000

// OUTPUT : ù° �ٿ� �ִ�� ���� �� �ִ� �������� ���� ����Ѵ�.

#include <cstdio> 
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int pan[10000];
bool used[10000];
int cache[10000];

int dfs(int idx){
	if(idx >= N){
		return 0;
	}
	
	int &ret = cache[idx];
	if(ret != -1)	return ret;
	
	int tmp_ret = -1 * 0x7fffffff;
	
	if(used[idx-1] && used[idx-2]){
		printf("<1>\n");
		tmp_ret = max(tmp_ret, dfs(idx + 1));
	}
	else{
		printf("<2>\n");
		tmp_ret = max(tmp_ret, dfs(idx + 1));
		used[idx] = true;
		printf("<3> : + %d\n", pan[idx]);
		tmp_ret = max(dfs(idx + 1) + pan[idx], tmp_ret);
		used[idx] = false;
	}
	
	return ret = tmp_ret;	
}

int solve(){
	int tmp_ans = -1 * 0x7fffffff;
	
	used[0] = true;	used[1] = true;
	cache[0] = pan[0];	cache[1] = cache[0] + pan[1];
	int ttmp = dfs(2);
	printf("TEST : %d\n", ttmp);
	tmp_ans = max(tmp_ans, ttmp + cache[1]);
	
	printf("1 : %d\n", tmp_ans);
	
	used[0] = true;	used[1] = false;
	cache[0] = pan[0];	cache[1] = cache[0];
	tmp_ans = max(tmp_ans, dfs(2) + cache[1]);
	printf("2 : %d\n", tmp_ans);
	
	used[0] = false;	used[1] = true;
	cache[0] = 0;	cache[1] = pan[1];
	tmp_ans = max(tmp_ans, dfs(2) + cache[1]);
	printf("3 : %d\n", tmp_ans);
	
	used[0] = false;	used[1] = false;
	cache[0] = 0;	cache[1] = 0;
	tmp_ans = max(tmp_ans, dfs(2) + cache[1]);
	printf("4 : %d\n", tmp_ans);
	
	return tmp_ans;
}

int main(){;
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	// �������� ���� �ִ� 3���� ��� ���� ���� ����.
	int ans = solve();
	printf("%d", ans);
	
	return 0;
}
