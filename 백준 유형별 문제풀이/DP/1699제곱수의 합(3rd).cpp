// 주어진 자연수 N을 이렇게 제곱수들의 합으로 표현할 때에 그 항의 최소개수를 구하는 프로그램을 작성하시오.

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int cache[100001];

int main(){
	// (1 ≤ N ≤ 100,000)
	scanf("%d", &N);
	
	cache[1] = 1;
	
	for(int i = 2 ; i <= N ; ++i){
		int tmp = (int)sqrt(i);
		int mmin = 0x7fffffff;
		for(int j = 1 ; j <= tmp ; ++j){
			int remain = i - pow(j,2);
			if(remain == 0){
				cache[i] = 1;
				break;
			}
			mmin = min(mmin, cache[j*j] + cache[remain]);
		}
		if(cache[i] == 1)	continue;
		cache[i] = mmin;
	}
	
	printf("%d", cache[N]);
	
	return 0;
}

