// 1 <= (세로 크기 N, 가로 크기 M) <= 100

#include <stdio.h>

int R, C;

int map[100][100];

int main(){
	scanf("%d %d", &R, &C);  // N = R   ||  M = C
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%1d", &map[i][j]);
		}
	}
	
	
	
}


 
