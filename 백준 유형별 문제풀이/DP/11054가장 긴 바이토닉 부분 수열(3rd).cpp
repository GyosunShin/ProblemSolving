// (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

// OUTPUT : 첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int pan[1000];
int up[1000];
int down[1000];

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	
	// for) 오름 
	for(int i = 0 ; i < N ; ++i){
		int tmp_max = 0;
		for(int j = 0 ; j < i ; ++j){
			if(pan[i] > pan[j]){
				tmp_max = max(tmp_max, up[j]);
			}
		}
		up[i] = tmp_max + 1;
	}
	
	
	// for) 내림
	for(int i = N-1 ; i >= 0 ; --i){
		int tmp_max = 0;
		for(int j = N-1 ; j > i ; --j){
			if(pan[i] > pan[j]){
				tmp_max = max(tmp_max, down[j]);
			}
		}
		down[i] = tmp_max + 1;
	}
	
	int ans = -1 * 0x7fffffff;
	for(int i = 0 ; i < N ; ++i){
		ans = max(ans, (up[i] + down[i]));
	}
	
	
	printf("%d", ans - 1);
	
	return 0;
}

