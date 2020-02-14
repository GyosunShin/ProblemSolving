// N (2 �� N �� 100)�� L (1 �� L �� N)
// �� ĭ�� ���� <= 10 

// OUTPUT : ù° �ٿ� ������ �� �ִ� ���� ������ ����Ѵ�.

#include <stdio.h>
#include <algorithm>

using namespace std;

int N, L, ans;
int map[200][100];

bool garo(int r){
	
	// (r, 0) ~ (r, N-1)
	
	int cnt = 1;
	int cur = map[r][0];
	
	for(int i = 1 ; i < N ; ++i){
		
//		printf("map : %d / cur : %d\n", map[r][i], cur);
		
		if(map[r][i] == cur)	++cnt;
		else if(map[r][i] > cur){   // ������ 
			if(abs(map[r][i] - cur) > 1)	return false;
			if(cnt < L){
				return false;
			}
			else{
				cur = map[r][i];
				cnt = 1;
			}
		}
		else if(map[r][i] < cur){	// ������
			if(abs(map[r][i] - cur) > 1)	return false;
			if(cnt < 0)	return false;
			cur = map[r][i];
			cnt = 1 - L;			
		}
	}
	if(cnt >= 0)	return true;
	else	return false;
}

int main(){
	scanf("%d %d", &N, &L);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	
	// �ݽð� �������� 90�� ������ �� �κп� �߰�����
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			map[j + N][(N-1)-i] = map[i][j];
		}
	}	 
//		
//	for(int i = 0 ; i < 2 * N ; ++i){
//		for(int j = 0 ; j < N ; ++j){
//			printf("%d  ", map[i][j]);
//		}
//		printf("\n");
//	}	 
//	printf("\n");
	
	for(int i = 0 ; i < 2*N ; ++i){
		if(garo(i)){
//			printf("���� %d\n", i);
			++ans;
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
