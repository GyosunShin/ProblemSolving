// �л��� ���� 1000���̸�, �� �л��� ������ 0�� �̻� 100�� ������ ���̴�.

#include <cstdio> 
#include <cstring> 
#include <algorithm>

int cache[101];

int T, N, tmp;

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		memset(cache, 0, sizeof(cache));
		scanf("%d", &N);
		
		for(int i = 0 ; i < 1000 ; ++i){
			scanf("%d", &tmp);	
			cache[tmp]++;
		}
		
		int mmax = -1;
		int ans;
		for(int i = 0 ; i < 101 ; ++i){
			if(mmax <= cache[i]){
				mmax = cache[i];
				ans = i;
			}
		}
		
		printf("#%d %d\n", z, ans);
	}
	
	
	return 0;
}
