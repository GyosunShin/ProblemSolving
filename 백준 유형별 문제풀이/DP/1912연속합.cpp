// n(1 �� n �� 100,000)
// -1000 <= INPUT <= 1000

// OUTPUT : ���ӵ� �� ���� ���� �����ؼ� ���� �� �ִ� �� �� ���� ū ���� ���Ϸ��� �Ѵ�. ��, ���� �� �� �̻� �����ؾ� �Ѵ�.

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
int map[100000];
int cache[100000];

int main(){
	
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
	}
	//##############################
	
	cache[0] = map[0];
	int ans = cache[0];
	for(int i = 1 ; i < N ; ++i){
		cache[i] = max(map[i], map[i] + cache[i-1]);
		if(ans < cache[i])	ans = cache[i];
	}
	
	printf("%d", ans);
	return 0;
}
