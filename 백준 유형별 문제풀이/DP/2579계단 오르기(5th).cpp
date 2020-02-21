// 각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의 최댓값을 구하는 프로그램을 작성하시오.

// 1 <= 계단 개수 <= 300
// 1 <= 각 계단의 점수 <= 10000

// OUTPUT : 첫째 줄에 계단 오르기 게임에서 얻을 수 있는 총 점수의 최댓값을 출력한다.

#include <cstdio> 
#include <algorithm>

using namespace std;

int N;
int pan[300];
int cache[300];

int main(){
	
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	cache[0] = pan[0];
	cache[1] = cache[0] + pan[1];
	cache[2] = max(pan[0] + pan[2], pan[1] + pan[2]);
	
	for(int i = 3 ; i < N ; ++i){
		cache[i] = max(pan[i] + cache[i-2], pan[i] + pan[i-1] + cache[i-3]);
	}
	
	printf("%d", cache[N-1]);
	
	return 0;
}

