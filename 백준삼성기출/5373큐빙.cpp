// ť�긦 ���� Ƚ�� n�� �־�����. (1 �� n �� 1000)
// U: �� ��, D: �Ʒ� ��, F: �� ��, B: �� ��, L: ���� ��, R: ������ ��

// �ⷫ : ����� w, ������� y, �������� r, ���������� o, �ʷϻ��� g, �Ķ����� b
 
#include <stdio.h>
 
int N;
char map[100][2000];
 
int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		printf("TEst\n");
		int rotate;
		scanf("%d", &rotate);
		for(int j = 0 ; j < rotate ; j = j+2){
			scanf("%c%c", &map[i][j], &map[i][j+1]);
		}
	}
	
	for(int i = 0 ; i < N ; ++i){
		printf("[");
		for(int j = 0 ; j < 2000 ; j = j+2){
			printf("%c%c ", map[i][j], map[i][j+1]);
		}
		printf("]\n");
	}	
 	
}
