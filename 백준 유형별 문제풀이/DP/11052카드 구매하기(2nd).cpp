// 돈을 최대한 많이 지불해서 카드 N개 구매하려고 한다.
// OUTPUT : N개의 카드를 구매하기 위해 민규가 지불해야 하는 금액의 최댓값을 구하는 프로그램을 작성하시오.

// INPUT : (1 ≤ N ≤ 1,000) 카드의 개수
// (1 ≤ Pi ≤ 10,000) 

#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int map[1001];
int cache[1001];

int main(){
	scanf("%d", &N);
	for(int i = 1 ; i <= N ; ++i){
		scanf("%d", &map[i]);	
	}
	
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j <= i ; ++j){
			cache[i] = max(cache[i], map[j] + cache[i-j]);
		}
	}
	
	printf("%d", cache[N]);
	
	return 0;
}






