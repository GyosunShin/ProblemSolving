// N : 나무의 수 / M : 가져가려는 나무의 길이 
// INPUT :  (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)
// 각 나무의 높이 0 <=   <= 1,000,000,000 

// OUTPUT : 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 출력한다.

#include <stdio.h> 

int N, M; 
int map[1000000];

int best = -1;
int low = 1;
long long mid;

long long ans;

bool cal(int h){
	long long tmp_sum = 0;
	for(int i = 0 ; i < N ; ++i){
		if(map[i] - h > 0)	tmp_sum += (map[i] - h);
	}
	
	if(tmp_sum >= M)	return true;
	else	return false;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
		if(best < map[i])	best = map[i];
	}
	//###############################
	
	while(low <= best){
		printf("EVERY] low : %d / best : %d / mid : %d / ans : %d\n", low, best, (low + best)/2, ans);
		mid = (low + best)/2;
		if(cal(mid)){
//			printf("POSSIBLE : %d\n", mid);
			if(ans < mid)	ans = mid;
			low = mid + 1;
		}
		else{
			best = mid - 1;
		}
	}
	
	printf("%d", ans);
	return 0;
}
