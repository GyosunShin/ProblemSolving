// (10 �� N < 100,000)	(0 < S �� 100,000,000)

// OUTPUT : ù° �ٿ� ���ϰ��� �ϴ� �ּ��� ���̸� ����Ѵ�. ���� �׷��� ���� ����� ���� �Ұ����ϴٸ� 0�� ����ϸ� �ȴ�.

#include <cstdio>
#include <algorithm>

using namespace std;

int N, S;
int pan[100000];
int ans = 0x7fffffff;

void solve(){
	int left = 0;	int right = 0;
	int sum = pan[0];
	
	while(true){
		
		if(left >= N || right >= N)	break;
		
		if(sum >= S){
			ans = min(ans, right-left+1);
			sum -= pan[left++];
		}
		else{
			sum += pan[++right];
		}
		
	}
}

int main(){
	scanf("%d %d", &N, &S);
	for(int i = 0; i < N ; ++i){
		scanf("%d", &pan[i]);	
	}
		
	solve();
	
	if(ans == 0x7fffffff)	ans = 0;
	printf("%d", ans);
	
	return 0;
}
