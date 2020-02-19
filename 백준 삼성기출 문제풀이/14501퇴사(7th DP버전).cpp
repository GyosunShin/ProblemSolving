// ����� ������ ���� ��, �����̰� ���� �� �ִ� �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

// N (1 �� N �� 15)
// (1 �� Ti �� 5, 1 �� Pi �� 1,000)

#include <cstdio>
#include <cstring>
#include <algorithm> 

using namespace std;	

int N;
int T[15];
int P[15];
int cache[15];

int solve(int idx){
	if(idx == N)	return 0;
	
	int &ret = cache[idx];
	if(ret != -1)	return ret;
	
	if(idx + T[idx] > N){
		ret = max(ret, solve(idx + 1));	// ���� ���ϰ� �׳� ���Ϸ� �ѱ��. 
	}
	else{
		// ���� �Ѵ�.
		ret = max(ret, solve(idx + T[idx]) + P[idx]);
		
		// ���� ���ϰ� �׳� ���Ϸ� �ѱ��. 
		ret = max(ret, solve(idx + 1));	
	}	
	
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d %d", &T[i], &P[i]);	
	}
	
	printf("%d", solve(0));
	
	return 0;
}
