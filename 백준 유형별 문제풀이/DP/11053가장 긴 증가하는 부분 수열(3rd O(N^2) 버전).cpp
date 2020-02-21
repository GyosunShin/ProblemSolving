// (1 ≤ N ≤ 1,000)
// (1 ≤ Ai ≤ 1,000)

// OUTPUT : 첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int pan[1000];
int cache[1000];

int ans = -1*0x7fffffff;

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	for(int i = 0 ; i < N ; ++i){
		int tmp = 0;
		for(int j = 0 ; j < i ; ++j){
			if(pan[j] < pan[i]){
				tmp = max(tmp, cache[j]);
			}
		}
		cache[i] = tmp + 1;
		ans = max(ans, cache[i]);
	}
	
	printf("%d", ans);
	
	return 0;
}
