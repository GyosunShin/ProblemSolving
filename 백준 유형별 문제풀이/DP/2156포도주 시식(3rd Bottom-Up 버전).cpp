// (1��n��10,000)
// 0 <= ������ �� <= 1000

// OUTPUT : ù° �ٿ� �ִ�� ���� �� �ִ� �������� ���� ����Ѵ�.

#include <cstdio> 
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int pan[10000];
int cache[10000];

int main(){;
	memset(cache, -1, sizeof(cache));
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	// �������� ���� �ִ� 3���� ��� ���� ���� ����.
	for(int i = 2 ; i < N ; ++i){
		
	}
	
	printf("%d", cache[N-1]);
	
	return 0;
}
