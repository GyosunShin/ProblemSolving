// ���� ���� N (2 �� N �� 200,000)
// �������� ���� C (2 �� C �� N)
// ���� ��ǥ�� ��Ÿ���� xi (1 �� xi �� 1,000,000,000)

// OUTPUT : ù° �ٿ� ���� ������ �� ������ ������ �ִ� �Ÿ��� ����Ѵ�.

#include <cstdio>
#include <algorithm>

using namespace std;

int N, C;
int pan[200000];

bool check(int input){
	
	int cnt = 0;
	int prev = pan[0];
	for(int i = 1 ; i < N ; ++i){
		if(pan[i] - prev >= input){
			++cnt;
			prev = pan[i];
		}
	}
	
	if(cnt >= (C-1))	return true;
	return false;
	
}

int solve(){
	
	int left = 0;
	int right = pan[N-1] - pan[0];
	
	while(left <= right){
		
		int mid = (left + right) / 2;
		
		if(check(mid)){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
		
	}
	
	return right;
	
}

int main(){
	scanf("%d %d", &N, &C);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &pan[i]);
	}
	
	sort(pan, pan + N);
	
	printf("%d", solve());
	
	return 0;
}
