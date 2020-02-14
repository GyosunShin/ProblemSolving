//ù° �ٿ� ������ ���� ũ�� N, ���� ũ�� M (1 �� N, M �� 20), 
//�ֻ����� ���� ���� ��ǥ x y(0 �� x �� N-1, 0 �� y �� M-1), �׸��� ����� ���� K (1 �� K �� 1,000)�� �־�����.

#include <stdio.h>

int map[20][20];  // ���� ũ�� 20X20 

// ������ 1, ������ 2, ������ 3, ������ 4
int order[1000]; // ��� �ִ� 1000�� 

// 1(����),2,3,4,5,6,7
int dice[7]= { 0, };  // �ֻ��� 

// ��, ��, ��, �� 
int dr[] = {0, 0, 1, -1} ;
int dc[] = {1, -1, 0, 0} ;

int main(){	
	int N, M, x, y, k;
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &k);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	
	for(int i = 0 ; i < k ; ++i){
		scanf("%d", &order[i]);
	}
	//############################# ������� ��� ���� ######### 
	
	// ��� ���� ��ŭ 
	// �� : 4, �� : 1, �� : 3, �� : 2 
	for(int i = 0 ; i < k ; ++i){
		int tmp1 = dice[1];
		int tmp2 = dice[2];
		int tmp3 = dice[3];
		int tmp4 = dice[4];
		int tmp5 = dice[5];
		int tmp6 = dice[6];
		if(order[i] == 1) { // �� 
			x += dr[0];
			y += dc[0];
//			printf("x : %d, y : %d\n", x, y);
			if(!(0 <= x && x <= N-1 && 0<= y && y <= M-1)){
				x -= dr[0];
				y -= dc[0];				
				continue;
			} 
			dice[1] = tmp4;
			dice[2] = tmp2;
			dice[3] = tmp1;
			dice[4] = tmp6;
			dice[5] = tmp5;
			dice[6] = tmp3;
		}
		else if(order[i] == 2) {  // �� 
			x += dr[1];
			y += dc[1];			
//			printf("x : %d, y : %d\n", x, y);
			if(!(0 <= x && x <= N-1 && 0<= y && y <= M-1)){
				x -= dr[1];
				y -= dc[1];				
				continue;
			} 
			dice[1] = tmp3;
			dice[2] = tmp2;
			dice[3] = tmp6;
			dice[4] = tmp1;
			dice[5] = tmp5;
			dice[6] = tmp4;
		}
		else if(order[i] == 3) {  // �� 
			x += dr[3];
			y += dc[3];
//			printf("x : %d, y : %d\n", x, y);
			if(!(0 <= x && x <= N-1 && 0<= y && y <= M-1)){
				x -= dr[3];
				y -= dc[3];				
				continue;
			} 
			dice[1] = tmp5;
			dice[2] = tmp1;
			dice[3] = tmp3;
			dice[4] = tmp4;
			dice[5] = tmp6;
			dice[6] = tmp2;						
		}
		else if(order[i] == 4) {  // �� 
			x += dr[2];
			y += dc[2];
//			printf("x : %d, y : %d\n", x, y);
			if(!(0 <= x && x <= N-1 && 0<= y && y <= M-1)){
				x -= dr[2];
				y -= dc[2];				
				continue;
			} 
			dice[1] = tmp2;
			dice[2] = tmp6;
			dice[3] = tmp3;
			dice[4] = tmp4;
			dice[5] = tmp1;
			dice[6] = tmp5;						 
		}
		
		if(map[x][y] == 0){  // �ֻ��� --> ĭ 
			 map[x][y] = dice[6];
		}
		else{  // ĭ --> �ֻ��� & �ֻ��� = 0 
			dice[6] = map[x][y];
			map[x][y] = 0;
		}				
		printf("%d\n", dice[1]);
	}	
}
