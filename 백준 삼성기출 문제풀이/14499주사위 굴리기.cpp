//첫째 줄에 지도의 세로 크기 N, 가로 크기 M (1 ≤ N, M ≤ 20), 
//주사위를 놓은 곳의 좌표 x y(0 ≤ x ≤ N-1, 0 ≤ y ≤ M-1), 그리고 명령의 개수 K (1 ≤ K ≤ 1,000)가 주어진다.

#include <stdio.h>

int map[20][20];  // 지도 크기 20X20 

// 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
int order[1000]; // 명령 최대 1000개 

// 1(윗면),2,3,4,5,6,7
int dice[7]= { 0, };  // 주사위 

// 동, 서, 남, 북 
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
	//############################# 여기까지 명령 받음 ######### 
	
	// 명령 갯수 만큼 
	// 남 : 4, 동 : 1, 북 : 3, 서 : 2 
	for(int i = 0 ; i < k ; ++i){
		int tmp1 = dice[1];
		int tmp2 = dice[2];
		int tmp3 = dice[3];
		int tmp4 = dice[4];
		int tmp5 = dice[5];
		int tmp6 = dice[6];
		if(order[i] == 1) { // 동 
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
		else if(order[i] == 2) {  // 서 
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
		else if(order[i] == 3) {  // 북 
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
		else if(order[i] == 4) {  // 남 
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
		
		if(map[x][y] == 0){  // 주사위 --> 칸 
			 map[x][y] = dice[6];
		}
		else{  // 칸 --> 주사위 & 주사위 = 0 
			dice[6] = map[x][y];
			map[x][y] = 0;
		}				
		printf("%d\n", dice[1]);
	}	
}
