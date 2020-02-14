//  연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 프로그램을 작성하시오.

//  N (10 ≤ N < 100,000)과 S (0 < S ≤ 100,000,000)
// 	1 <=  <= 10000

// OUTPUT : 만일 그러한 합을 만드는 것이 불가능하다면 0을 출력하면 된다.

#include <stdio.h> 
#include <string.h>

using namespace std;

int ans = 0x7fffffff;

int N, S;
int map[100000];

int main(){
	scanf("%d %d", &N, &S);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
	}
	
	int left = 0;
	int right = 0;
	long long sum = map[0];
	
	while(left <= right && right < N){
		
		if(sum < S){
			sum += map[++right];
		}
		else if(sum == S){
			int cnt = (right - left) + 1;
			if(ans > cnt)	ans = cnt;
			sum += map[++right];
		}
		else{  // 이상이면 
			int cnt = (right - left) + 1;
			if(ans > cnt)	ans = cnt;
			sum -= map[left++];
		}
		
	}
	
	if(ans == 0x7fffffff)	printf("0");
	else	printf("%d", ans);
	
	return 0;
}
