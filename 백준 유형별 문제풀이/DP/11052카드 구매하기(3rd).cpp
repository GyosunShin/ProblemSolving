//  N���� ī�带 �����ϱ� ���� �α԰� �����ؾ� �ϴ� �ݾ��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�

// ī���� ����  (1 �� N �� 1,000)
// (1 �� Pi �� 10,000)

#include <cstdio> 
#include <algorithm>

using namespace std;

int N;
int pan[1001];
int cache[1001];

int main(){
	scanf("%d", &N);
	for(int i = 1 ; i <= N ; ++i)	scanf("%d", &pan[i]);
	
	// Bottom-Up Approach
	cache[1] = pan[1];
	for(int i = 2 ; i <= N ; ++i){
		int tmp_max = pan[i];
		for(int j = 1 ; j < i ; ++j){
			tmp_max = max(tmp_max, cache[j] + pan[i-j]);
		}
		cache[i] = tmp_max;
	}
	
//	for(int i = 1 ; i <= N ; ++i)	printf("%d  ", cache[i]);
//	printf("\n");
	
	
	printf("%d", cache[N]);
	
	return 0;
}
