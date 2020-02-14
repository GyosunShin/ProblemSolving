// ���� �ִ��� ���� �����ؼ� ī�� N�� �����Ϸ��� �Ѵ�.
// OUTPUT : N���� ī�带 �����ϱ� ���� �α԰� �����ؾ� �ϴ� �ݾ��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

// INPUT : (1 �� N �� 1,000) ī���� ����
// (1 �� Pi �� 10,000) 

#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int map[1001];
int cache[1001];

int main(){
	scanf("%d", &N);
	for(int i = 1 ; i <= N ; ++i){
		scanf("%d", &map[i]);	
	}
	
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j <= i ; ++j){
			cache[i] = max(cache[i], map[j] + cache[i-j]);
		}
	}
	
	printf("%d", cache[N]);
	
	return 0;
}






