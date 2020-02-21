//N (1 ≤ N ≤ 1,000)
//(1 ≤ Ai ≤ 1,000)

// 첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다.

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int pan[1000];
int cache[1000];

int ans = -1 * 0x7fffffff;

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	for(int i = 0 ; i < N ; ++i){
		int tmp_max = -1;
		for(int j = 0 ; j < i ; ++j){
			if(pan[i] > pan[j]){
				tmp_max = max(tmp_max, cache[j]);
			}
		}
		if(tmp_max == -1)	tmp_max = 0;
		cache[i] = pan[i] + tmp_max;
		ans = max(ans, cache[i]);
	}
	
	printf("%d", ans);
	
	return 0;
}
