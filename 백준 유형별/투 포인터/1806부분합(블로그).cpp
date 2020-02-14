//  ���ӵ� ������ �κ��� �߿� �� ���� S �̻��� �Ǵ� �� ��, ���� ª�� ���� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

//  N (10 �� N < 100,000)�� S (0 < S �� 100,000,000)
// 	1 <=  <= 10000

// OUTPUT : ���� �׷��� ���� ����� ���� �Ұ����ϴٸ� 0�� ����ϸ� �ȴ�.

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
		else{  // �̻��̸� 
			int cnt = (right - left) + 1;
			if(ans > cnt)	ans = cnt;
			sum -= map[left++];
		}
		
	}
	
	if(ans == 0x7fffffff)	printf("0");
	else	printf("%d", ans);
	
	return 0;
}
