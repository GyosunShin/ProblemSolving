//����� �� ���� �� ��ܾ� �Ǵ� �� ��ܾ� ���� �� �ִ�. ��, �� ����� �����鼭 �̾ ���� ����̳�, ���� ���� ������� ���� �� �ִ�.
//���ӵ� �� ���� ����� ��� ��Ƽ��� �� �ȴ�. ��, �������� ��ܿ� ���Ե��� �ʴ´�.
//������ ���� ����� �ݵ�� ��ƾ� �Ѵ�.

// �� ��ܿ� ���� �ִ� ������ �־��� �� �� ���ӿ��� ���� �� �ִ� �� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int map[300];
int cache[300];

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);	
	}
	//###########################
	
	cache[0] = map[0];
	cache[1] = map[0] + map[1];
	if(N == 1){
		printf("%d", cache[0]);
		return 0;
	}
	if(N == 2){
		printf("%d", cache[1]);
		return 0;
	}	
	
	for(int i = 2 ; i < N ; ++i){
		if(i == 2){
			cache[i] = max(map[0] + map[2], map[1] + map[2]);
			continue;
		}
		cache[i] = max(map[i] +  map[i-1] + cache[i-3], map[i] + cache[i-2]);
	}
	
	printf("%d", cache[N-1]);
	return 0;
}
