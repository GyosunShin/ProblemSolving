// (1 �� N(������ ��) �� 1,000,000, 1 �� M(��ǥ ���� ����) �� 2,000,000,000)
// 0 <= �� ���� ���� <= 1,000,000,000 

#include <cstdio> 

int N, M;
int pan[1000000];

bool check(int mid){
	long long sum = 0;
	
	for(int i = 0 ; i < N ; ++i){
		int tmp = pan[i] - mid; 
		if(tmp < 0)	continue;
		sum += tmp;
	}
	if(sum >= M)	return true;
	return false;
}

int solve(){
	int left = 0;	int right =  1000000000;
	
	while(left <= right){
		int mid = (left + right) / 2;
		
		if(check(mid)){
			left = mid + 1;
		}
		else	right = mid - 1;
	}
	
	return right;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &pan[i]);
	}
	
	printf("%d", solve());
	
	return 0;
}

