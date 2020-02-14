// �ڿ����� �־����� ��, �� �ڿ����� ���ӵ� �Ҽ��� ������ ��Ÿ�� �� �ִ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

//  (1 �� N �� 4,000,000)

#include <stdio.h>
#include <cmath>
#include <vector>

using namespace std;

int N;

bool era[4000001];

vector<int> picked;

void check(int limit){
	int sq = (int)sqrt(limit);
	
	for(int i = 2 ; i <= limit ; ++i){
		if(era[i])	continue;
		for(int j = i + i ; j <= limit ; j = j+i){
			era[j] = true;
		}
	}
}

int main(){
	scanf("%d", &N);
	
	if(N == 1){
		printf("0");
		return 0;
	}
	
	check(N);
	
	
	
	for(int i = 2 ; i <= N ; ++i){
		if(!era[i]){
			picked.push_back(i);
		}	
	}
	
	int ans = 0;
	
	int left = 0;
	int right = 0;
	int sum = picked[0];
//	printf("TEST : %d\n", picked.size());
	while(left <= right && right < picked.size()){
//		printf("LEFT : %d / RIGHT : %d / SUM : %d\n", left, right, sum);
		if(sum >= N){
			if(sum == N)	++ans;
			sum -= picked[left++];
		}
		else{
			sum += picked[++right];
		}
	}
	
	printf("%d", ans);	
	return 0;
}


 
