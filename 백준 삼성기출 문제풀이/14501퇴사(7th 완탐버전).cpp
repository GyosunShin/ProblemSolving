// ����� ������ ���� ��, �����̰� ���� �� �ִ� �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

// N (1 �� N �� 15)
// (1 �� Ti �� 5, 1 �� Pi �� 1,000)

#include <cstdio>
#include <algorithm> 

using namespace std;	

int N;
int T[15];
int P[15];

int solve(int idx){
	printf("IDX : %d\n", idx);
	
	if(idx >= N)	return 0;
	
	int ret = -1 * 0x7fffffff;
	
	if(idx + T[idx] > N){
		// ���� ���Ѵ�. 
		ret = max(ret, solve(idx + 1));	
	}
	else{
		// ���� �Ѵ�.
		ret = max(ret, solve(idx + T[idx]) + P[idx]);
		
		// ���� ���Ѵ�. 
		ret = max(ret, solve(idx + 1));	
	}
	
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d %d", &T[i], &P[i]);	
	}
	
	printf("%d", solve(0));
	
	return 0;
}
