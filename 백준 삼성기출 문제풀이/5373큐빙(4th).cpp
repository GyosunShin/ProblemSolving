// 테스트 케이스는 최대 100개이다

// 큐브를 돌린 횟수 n이 주어진다. (1 ≤ n ≤ 1000)
// (U: 윗 면)  (D: 아랫 면)  (F: 앞 면)  (B: 뒷 면)  (L: 왼쪽 면)  (R: 오른쪽 면)
// (+ 시계방향) (- 반시계 방향)

// OUTPUT : 큐브를 모두 돌린 후의 윗 면의 색상을 출력


#include <stdio.h>
#include <algorithm>

using namespace std;

int T, N;

char map[12][9] = {
	{'z','z','z','o','o','o','z','z','z'},
	{'z','z','z','o','o','o','z','z','z'},
	{'z','z','z','o','o','o','z','z','z'},
	
	{'g','g','g','y','y','y','b','b','b'},
	{'g','g','g','y','y','y','b','b','b'},
	{'g','g','g','y','y','y','b','b','b'},
	
	{'z','z','z','r','r','r','z','z','z'},
	{'z','z','z','r','r','r','z','z','z'},
	{'z','z','z','r','r','r','z','z','z'},
	
	{'z','z','z','w','w','w','z','z','z'},
	{'z','z','z','w','w','w','z','z','z'},
	{'z','z','z','w','w','w','z','z','z'},
};
char backup[12][9];

// (U: 윗 면)  (D: 아랫 면)  (F: 앞 면)  (B: 뒷 면)  (L: 왼쪽 면)  (R: 오른쪽 면)
// (+ 시계방향) (- 반시계 방향)
void solve(int myun, int dir){
	
	// backup가지고 놀아야 함 
	
	if(myun == 'U'){
		if(dir == '+'){  // 시계방향 
			char tmp1 = backup[0][3];
			char tmp2 = backup[0][4];
			char tmp3 = backup[0][5];
			
			backup[0][3] = backup[5][0];
			backup[0][4] = backup[4][0];
			backup[0][5] = backup[3][0];
			
			backup[5][0] = backup[8][5];
			backup[4][0] = backup[8][4];
			backup[3][0] = backup[8][3];
			
			backup[8][5] = backup[3][8];
			backup[8][4] = backup[4][8];
			backup[8][3] = backup[5][8];
			
			backup[3][8] = tmp1;
			backup[4][8] = tmp2;
			backup[5][8] = tmp3;
			
			
			// 하... 이제 윗면 돌리기 시작
			// 시계방향이까 반시계 방향으로
			char ttmp1 = backup[9][3]; 
			char ttmp2 = backup[9][4]; 
			char ttmp3 = backup[9][5]; 
			backup[9][3] = backup[9][5];
			backup[9][4] = backup[10][5];
			backup[9][5] = backup[11][5];
			
			backup[9][5] = backup[11][5];
			backup[10][5] = backup[11][4];
			backup[11][5] = backup[11][3];
			
			backup[11][5] = backup[11][3];
			backup[11][4] = backup[10][3];
			backup[11][3] = backup[9][3];
			
			backup[11][3] = ttmp1;
			backup[10][3] = ttmp2;
			backup[9][3] = ttmp3;
			
		}
		else if(dir == '-'){  // 반시계방향 
			char tmp1 = backup[3][0];
			char tmp2 = backup[4][0];
			char tmp3 = backup[5][0];
			
			backup[3][0] = backup[0][5];
			backup[4][0] = backup[0][4];
			backup[5][0] = backup[0][3];
			
			backup[0][5] = backup[5][8];
			backup[0][4] = backup[4][8];
			backup[0][3] = backup[3][8];
			
			backup[5][8] = backup[8][3];
			backup[4][8] = backup[8][4];
			backup[3][8] = backup[8][5];
			
			backup[8][3] = tmp1;
			backup[8][4] = tmp2;
			backup[8][5] = tmp3;
			
			// 반시계니까 시꼐방향으로 		
			char ttmp1 = backup[9][3]; 
			char ttmp2 = backup[9][4]; 
			char ttmp3 = backup[9][5]; 
			
			backup[9][5]= backup[9][3];
			backup[9][3]= backup[11][3];
			backup[9][4]= backup[10][3];
			
			backup[9][3]= backup[11][3];
			backup[11][3]= backup[11][5];
			backup[10][3]= backup[11][4];
			
			backup[11][4]= backup[10][5];
			backup[11][3]= backup[11][5];
			backup[11][5]= backup[9][5];
			
			backup[9][5]= ttmp1;
			backup[10][5]= ttmp2;
			backup[11][5]= ttmp3;
				
		}
	}
	
	if(myun == 'D'){
		if(dir == '-'){  // 반시계방향 
			char tmp1 = backup[2][3];
			char tmp2 = backup[2][4];
			char tmp3 = backup[2][5];
			
			backup[2][3] = backup[5][2];
			backup[2][4] = backup[4][2];
			backup[2][5] = backup[3][2];
			
			backup[5][2] = backup[6][5];
			backup[4][2] = backup[6][4];
			backup[3][2] = backup[6][3];
			
			backup[6][5] = backup[3][6];
			backup[6][4] = backup[4][6];
			backup[6][3] = backup[5][6];
			
			backup[3][6] = tmp1;
			backup[4][6] = tmp2;
			backup[5][6] = tmp3;		
			
			//반시계방향이니까 시계방향으로
			char ttmp1 = backup[3][3];
			char ttmp2 = backup[3][4];
			char ttmp3 = backup[3][5];
			
			backup[3][5] = backup[3][3];
			backup[3][3] = backup[5][3];
			backup[3][4] = backup[4][3];
			
			backup[4][3] = backup[5][4];
			backup[3][3] = backup[5][3];
			backup[5][3] = backup[5][5];
			
			
			backup[5][3] = backup[5][5];
			backup[5][5] = backup[3][5];
			backup[5][4] = backup[4][5];
			
			backup[3][5] = ttmp1;
			backup[4][5] = ttmp2;
			backup[5][5] = ttmp3;
			
		}
		else if(dir == '+'){  // 시계방향
			char tmp1 = backup[3][2];
			char tmp2 = backup[4][2];
			char tmp3 = backup[5][2];
			
			backup[3][2] = backup[2][5];
			backup[4][2] = backup[2][4];
			backup[5][2] = backup[2][3];
			
			backup[2][5] = backup[5][6];
			backup[2][4] = backup[4][6];
			backup[2][3] = backup[3][6];
			
			backup[5][6] = backup[6][3];
			backup[4][6] = backup[6][4];
			backup[3][6] = backup[6][5];
			
			backup[6][3] = tmp1;
			backup[6][4] = tmp2;
			backup[6][5] = tmp3;		
			
			// 시꼐방향 이니까 반시계 방향으 로
			char ttmp1 = backup[3][3];
			char ttmp2 = backup[3][4];
			char ttmp3 = backup[3][5];
			
			backup[3][4] = backup[4][5];
			backup[3][5] = backup[5][5];
			backup[3][3] = backup[3][5];
			
			backup[3][5] = backup[5][5];
			backup[4][5] = backup[5][4];
			backup[5][5] = backup[5][3];
			
			backup[5][5] = backup[5][3];
			backup[5][4] = backup[4][3];
			backup[5][3] = backup[3][3];
			
			backup[5][3] = ttmp1;
			backup[4][3] = ttmp2;
			backup[3][3] = ttmp3;
			
		}
	}	

	if(myun == 'F'){
		if(dir == '+'){  // 시계방향 
			char tmp1 = backup[5][0];
			char tmp2 = backup[5][1];
			char tmp3 = backup[5][2];
			
			backup[5][0] = backup[5][3];
			backup[5][1] = backup[5][4];
			backup[5][2] = backup[5][5];
			
			backup[5][3] = backup[5][6];
			backup[5][4] = backup[5][7];
			backup[5][5] = backup[5][8];
			
			backup[5][6] = backup[9][5];
			backup[5][7] = backup[9][4];
			backup[5][8] = backup[9][3];
			
			backup[9][5] = tmp1;
			backup[9][4] = tmp2;
			backup[9][3] = tmp3;
			
			// 시계방향이니까 반시계방향으로 
			char ttmp1 = backup[6][3];
			char ttmp2 = backup[6][4];
			char ttmp3 = backup[6][5];
			
			backup[6][3] = backup[6][5];
			backup[6][4] = backup[7][5];
			backup[6][5] = backup[8][5];
			
			backup[6][5] = backup[8][5];
			backup[7][5] = backup[8][4];
			backup[8][5] = backup[8][3];
			
			backup[8][5] = backup[8][3];
			backup[8][4] = backup[7][3];
			backup[8][3] = backup[6][3];
			
			backup[8][3] = ttmp1;
			backup[7][3] = ttmp2;
			backup[6][3] = ttmp3;
		}
		else if(dir == '-'){  // 반시계방향 
			char tmp1 = backup[5][0];
			char tmp2 = backup[5][1];
			char tmp3 = backup[5][2];
			
			backup[5][0] = backup[9][5];
			backup[5][1] = backup[9][4];
			backup[5][2] = backup[9][3];
			
			backup[9][5] = backup[5][6];
			backup[9][4] = backup[5][7];
			backup[9][3] = backup[5][8];
			
			backup[5][6] = backup[5][3];
			backup[5][7] = backup[5][4];
			backup[5][8] = backup[5][5];
			
			backup[5][3] = tmp1;
			backup[5][4] = tmp2;
			backup[5][5] = tmp3;
			
			// 반시계 방향이니까 시계방향으로
			char ttmp1 = backup[6][3];
			char ttmp2 = backup[6][4];
			char ttmp3 = backup[6][5];
			
			backup[6][5] = backup[6][3];
			backup[6][3] = backup[8][3];
			backup[6][4] = backup[7][3];
			
			backup[6][3] = backup[8][3];
			backup[8][3] = backup[8][5];
			backup[7][3] = backup[8][4];
			
			backup[8][3] = backup[8][5];
			backup[8][5] = backup[6][5];
			backup[8][4] = backup[7][5];
			
			backup[6][5] = ttmp1;
			backup[7][5] = ttmp2;
			backup[8][5] = ttmp3;
		}
	}	
	
	if(myun == 'B'){
		if(dir == '-'){  // 반시계방향 
			char tmp1 = backup[11][3];
			char tmp2 = backup[11][4];
			char tmp3 = backup[11][5];
			
			backup[11][3] = backup[3][2];
			backup[11][4] = backup[3][1];
			backup[11][5] = backup[3][0];
			
			backup[3][2] = backup[3][5];
			backup[3][1] = backup[3][4];
			backup[3][0] = backup[3][3];
			
			backup[3][5] = backup[3][8];
			backup[3][4] = backup[3][7];
			backup[3][3] = backup[3][6];
			
			backup[3][8] = tmp1;
			backup[3][7] = tmp2;
			backup[3][6] = tmp3;
			
			// 반시계 방향이니까 시계방향으로
			char ttmp1 = backup[0][3];
			char ttmp2 = backup[0][4];
			char ttmp3 = backup[0][5];
			
			backup[0][5] = backup[0][3];
			backup[0][3] = backup[2][3];
			backup[0][4] = backup[1][3];
			
			backup[0][3] = backup[2][3];
			backup[2][3] = backup[2][5];
			backup[1][3] = backup[2][4];
			
			backup[2][3] = backup[2][5];
			backup[2][5] = backup[0][5];
			backup[2][4] = backup[1][5];
			
			backup[0][5] = ttmp1;
			backup[1][5] = ttmp2;
			backup[2][5] = ttmp3;
		}
		else if(dir == '+'){  // 시계방향 
			char tmp1 = backup[11][3];
			char tmp2 = backup[11][4];
			char tmp3 = backup[11][5];
			
			backup[11][3] = backup[3][8];
			backup[11][4] = backup[3][7];
			backup[11][5] = backup[3][6];
			
			backup[3][8] = backup[3][5];
			backup[3][7] = backup[3][4];
			backup[3][6] = backup[3][3];
			
			backup[3][5] = backup[3][2];
			backup[3][4] = backup[3][1];
			backup[3][3] = backup[3][0];
			
			backup[3][2] = tmp1;
			backup[3][1] = tmp2;
			backup[3][0] = tmp3;
			
			// 시계방향이니까 반시계방향으로
			char ttmp1 = backup[0][3];
			char ttmp2 = backup[0][4];
			char ttmp3 = backup[0][5];
			
			backup[0][3] = backup[0][5];
			backup[0][4] = backup[1][5];
			backup[0][5] = backup[2][5];
			
			backup[0][5] = backup[2][5];
			backup[1][5] = backup[2][4];
			backup[2][5] = backup[2][3];
			
			backup[2][5] = backup[2][3];
			backup[2][4] = backup[1][3];
			backup[2][3] = backup[0][3];
			
			backup[2][3] = ttmp1;
			backup[1][3] = ttmp2;
			backup[0][3] = ttmp3;
		}
	}	
	
	if(myun == 'L'){
		if(dir == '+'){  // 시계방향 	
			char tmp1 = backup[0][3];
			char tmp2 = backup[1][3];
			char tmp3 = backup[2][3];
			
			for(int i = 0 ; i <= 8 ; ++i){
				backup[i][3] = backup[i+3][3];
			}
			
			backup[11][3] = tmp3;
			backup[10][3] = tmp2;
			backup[9][3] = tmp1;
			
			// 시계방향이니까 반시계방향으로
			char ttmp1 = backup[3][0];
			char ttmp2 = backup[3][1];
			char ttmp3 = backup[3][2];
			
			backup[3][0] = backup[3][2];
			backup[3][1] = backup[4][2];
			backup[3][2] = backup[5][2];
			
			backup[3][2] = backup[5][2];
			backup[4][2] = backup[5][1];
			backup[5][2] = backup[5][0];
			
			backup[5][2] = backup[5][0];
			backup[5][1] = backup[4][0];
			backup[5][0] = backup[3][0];
			
			backup[5][0] = ttmp1;
			backup[4][0] = ttmp2;
			backup[3][0] = ttmp3;
			
		}
		else if(dir == '-'){  // 반시계방향 	
			char tmp1 = backup[9][3];
			char tmp2 = backup[10][3];
			char tmp3 = backup[11][3];
			
			for(int i = 11 ; i >= 3 ; --i){
				backup[i][3] = backup[i-3][3];
			}
			
			backup[0][3] = tmp1;
			backup[1][3] = tmp2;
			backup[2][3] = tmp3;		
			
			// 반시계방향이니까 시계방향으 로  
			char ttmp1 = backup[3][0];
			char ttmp2 = backup[3][1];
			char ttmp3 = backup[3][2];
			
			backup[3][2] = backup[3][0];
			backup[3][0] = backup[5][0];
			backup[3][1] = backup[4][0];
			
			backup[3][0] = backup[5][0];
			backup[5][0] = backup[5][2];
			backup[4][0] = backup[5][1];
			
			backup[5][0] = backup[5][2];
			backup[5][2] = backup[3][2];
			backup[5][1] = backup[4][2];
			
			backup[3][2] = ttmp1;
			backup[4][2] = ttmp2;
			backup[5][2] = ttmp3;
		}
	}	
	
	if(myun == 'R'){
		if(dir == '-'){  // 반시계방향 	
			char tmp1 = backup[0][5];
			char tmp2 = backup[1][5];
			char tmp3 = backup[2][5];
			
			for(int i = 0 ; i <= 8 ; ++i){
				backup[i][5] = backup[i+3][5];
			}
			
			backup[11][5] = tmp3;
			backup[10][5] = tmp2;
			backup[9][5] = tmp1;	
			
			// 	반시계 방향이니까 시꼐방향으로
			char ttmp1 = backup[3][6];
			char ttmp2 = backup[3][7];
			char ttmp3 = backup[3][8];
			
			backup[3][8] = backup[3][6];
			backup[3][6] = backup[5][6];
			backup[3][7] = backup[4][6];
			
			backup[3][6] = backup[5][6];
			backup[5][6] = backup[5][8];
			backup[4][6] = backup[5][7];
			
			backup[5][6] = backup[5][8];
			backup[5][8] = backup[3][8];
			backup[5][7] = backup[4][8];
			
			backup[3][8] = ttmp1;
			backup[4][8] = ttmp2;
			backup[5][8] = ttmp3;
		}
		else if(dir == '+'){  // 시계방향 	
			char tmp1 = backup[9][5];
			char tmp2 = backup[10][5];
			char tmp3 = backup[11][5];
			
			for(int i = 11 ; i >= 3 ; --i){
				backup[i][5] = backup[i-3][5];
			}
			
			backup[0][5] = tmp1;
			backup[1][5] = tmp2;
			backup[2][5] = tmp3;		
			
			// 시계방향이니까 반시계 방향으로
			char ttmp1 = backup[3][6];
			char ttmp2 = backup[3][7];
			char ttmp3 = backup[3][8];
			
			backup[3][6] = backup[3][8];
			backup[3][7] = backup[4][8];
			backup[3][8] = backup[5][8];
			
			backup[3][8] = backup[5][8];
			backup[4][8] = backup[5][7];
			backup[5][8] = backup[5][6];
			
			backup[5][8] = backup[5][6];
			backup[5][7] = backup[4][6];
			backup[5][6] = backup[3][6];
			
			backup[5][6] = ttmp1;
			backup[4][6] = ttmp2;
			backup[3][6] = ttmp3;
			
		}
	}					
	
}

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		
		copy(&map[0][0], &map[0][0] + 12 * 9, &backup[0][0]);
		
//			printf("한번 할떄ㅏ맏\n");
//			for(int i = 0 ; i < 12 ; ++i){
//				for(int j = 0 ; j < 9 ; ++j){
//					printf("%c", backup[i][j]);
//				}
//				printf("\n");
//			}
//			printf("\n");		
		
		scanf("%d", &N);	
		getchar();
		for(int i = 0 ; i < N ; ++i){
			char myun, dir;
			scanf("%1c%1c", &myun, &dir);
			getchar();
			solve(myun, dir);
			
//			printf("한번 할떄ㅏ맏\n");
//			for(int i = 0 ; i < 12 ; ++i){
//				for(int j = 0 ; j < 9 ; ++j){
//					printf("%c", backup[i][j]);
//				}
//				printf("\n");
//			}
//			printf("\n");
		}
		
		for(int i = 11 ; i >= 9 ; --i){
			for(int j = 3 ; j <= 5 ; ++j){
				printf("%c", backup[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
