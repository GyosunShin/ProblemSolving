// �����Ϸ��� �ϴ� ī���� ���� N�� �־�����. (1 �� N �� 1,000)
// Pi�� P1���� PN���� ������� �־�����. (1 �� Pi �� 10,000)

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
	//############################
	
	map[0] = cache[0] = 0;
	
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j <= i ; ++j){
			cache[i] = max(cache[i], cache[i-j] + map[j]);
		}
	}
	
	printf("%d", cache[N]);
	
	return 0;
}
