// N : ������ �� / M : ���������� ������ ���� 
// INPUT :  (1 �� N �� 1,000,000, 1 �� M �� 2,000,000,000)
// �� ������ ���� 0 <=   <= 1,000,000,000 

// OUTPUT : ��� M������ ������ ���� �������� ���ؼ� ���ܱ⿡ ������ �� �ִ� ������ �ִ��� ����Ѵ�.

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
