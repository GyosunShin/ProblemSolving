// 큐브를 돌린 횟수 n이 주어진다. (1 ≤ n ≤ 1000)
// U: 윗 면, D: 아랫 면, F: 앞 면, B: 뒷 면, L: 왼쪽 면, R: 오른쪽 면

// 출략 : 흰색은 w, 노란색은 y, 빨간색은 r, 오렌지색은 o, 초록색은 g, 파란색은 b
 
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
