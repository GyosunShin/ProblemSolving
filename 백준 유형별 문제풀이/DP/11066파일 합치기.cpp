// K (3 �� K �� 500)
// ���� ũ�� <= 10000 

// OUTPUT : ���α׷��� ǥ�� ��¿� ����Ѵ�. �� �׽�Ʈ �����͸��� ��Ȯ�� �� �࿡ ����ϴµ�, 
// ��� ���� ��ġ�µ� �ʿ��� �ּҺ���� ����Ѵ�.

#include <stdio.h> 
#include <algorithm>
#include <string.h>

using namespace std;

int T;
int cache[500];
int K;

int solve(int n){
	
	
	int& ret = cache[n];
	if(ret != -1)	return ret;
	ret = max(, );
	return ret;
}

int main(){
	scanf("%d", &T);
	for(int t = 0 ; t < T ; ++t){
		memset(cache, -1, sizeof(cache));
		int map[500];
		scanf("%d", &K);	 
		for(int k = 0 ; k < K ; ++k){
			scanf("%d", &map[k]);
		}
		int ans = solve(0);
		printf("%d\n", ans);
	}
	return 0;
}
