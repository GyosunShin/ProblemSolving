//N극 : 0 / S극 : 1
//다섯째 줄에는 회전 횟수 K(1 ≤ K ≤ 100)
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int map[4][8];
int K;
vector<pair<int, int> > cmds;
int ans = 0;

void clock(int (&sawtooth)[8]){
	int len = sizeof(sawtooth) / sizeof(int);
	int tmp = sawtooth[len-1];
	for(int i = len-2 ; i >= 0 ; --i){
		sawtooth[i+1] = sawtooth[i];
	}
	sawtooth[0] = tmp;
}

void anticlock(int (&sawtooth)[8]){
	int len = sizeof(sawtooth) / sizeof(int);
	int tmp = sawtooth[0];
	for(int i = 1 ; i <= len - 1 ; ++i){
		sawtooth[i-1] = sawtooth[i];
	}
	sawtooth[len-1] = tmp;
}

int main(){
	char gear[4][9];
	for(int i = 0 ; i < 4 ; ++i){
		scanf("%s", gear[i]);
	}
	for(int i = 0 ; i < 4 ; ++i){
		for(int j = 0 ; j < 8 ; ++j){
			map[i][j] = gear[i][j] - '0';
		}
	}
	
	scanf("%d", &K);
	// (1~4)  
	// 1인 경우는 시계 방향이고, -1인 경우는 반시계 방향
	for(int i = 0 ; i < K ; ++i){
		int tmp_1, tmp_2;
		scanf("%d %d", &tmp_1, &tmp_2);
		cmds.push_back(pair<int, int>(tmp_1, tmp_2));
	}
	//###############################################
	
	for(int i = 0 ; i < K ; ++i){
		int one, two, three, four;
		if(cmds[i].first == 1){
			one = cmds[i].second;
			if(map[0][2] == map[1][6]){
			 	two = 0;  // 극이 같으면돌지 않는다. 
			}else{ two = one * -1; } // 극이 다를경우  
			if(map[1][2] == map[2][6]){
			 	three = 0;  // 극이 같으면돌지 않는다. 
			}else{ three = two * -1; } // 극이 다를경우  				
			if(map[2][2] == map[3][6]){
			 	four = 0;  // 극이 같으면돌지 않는다. 
			}else{ four = three * -1; } // 극이 다를경우  				
		}
		else if(cmds[i].first == 2){
			two = cmds[i].second;			
			if(map[1][6] == map[0][2]){
			 	one = 0;  // 극이 같으면돌지 않는다. 
			}else{ one = two * -1; } // 극이 다를경우  			
			if(map[1][2] == map[2][6]){
			 	three = 0;  // 극이 같으면돌지 않는다. 
			}else{ three = two * -1; } // 극이 다를경우  						
			if(map[2][2] == map[3][6]){
			 	four = 0;  // 극이 같으면돌지 않는다. 
			}else{ four = three * -1; } // 극이 다를경우  									
		}		
		else if(cmds[i].first == 3){
			three = cmds[i].second;						
			if(map[2][2] == map[3][6]){
			 	four = 0;  // 극이 같으면돌지 않는다. 
			}else{ four = three * -1; } // 극이 다를경우  						
			if(map[2][6] == map[1][2]){
			 	two = 0;  // 극이 같으면돌지 않는다. 
			}else{ two = three * -1; } // 극이 다를경우  									
			if(map[0][2] == map[1][6]){
			 	one = 0;  // 극이 같으면돌지 않는다. 
			}else{ one = two * -1; } // 극이 다를경우  												
		}		
		else if(cmds[i].first == 4){
			four = cmds[i].second;	
			if(map[3][6] == map[2][2]){
			 	three = 0;  // 극이 같으면돌지 않는다. 
			}else{ three = four * -1; } // 극이 다를경우			
			if(map[2][6] == map[1][2]){
			 	two = 0;  // 극이 같으면돌지 않는다. 
			}else{ two = three * -1; } // 극이 다를경우						
			if(map[1][6] == map[0][2]){
			 	one = 0;  // 극이 같으면돌지 않는다. 
			}else{ one = two * -1; } // 극이 다를경우									
		}		
		
		// one, two, three, four --> 1이면 시계 / -1이면 반시계 / 0이면 가만히
		if(one == 1){
//			printf("ONE CLOCK\n");
			clock(map[0]);
		}
		else if(one == -1){
//			printf("ONE ANTICLOCK\n");
			anticlock(map[0]);
		}
		if(two == 1){
//			printf("TWO CLOCK\n");
			clock(map[1]);
		}
		else if(two == -1){
//			printf("TWO ANTICLOCK\n");
			anticlock(map[1]);
		}
		if(three == 1){
//			printf("THREE CLOCK\n");
			clock(map[2]);
		}
		else if(three == -1){
//			printf("THREE ANTICLOCK\n");
			anticlock(map[2]);
		}
		if(four == 1){
//			printf("FOUR CLOCK\n");
			clock(map[3]);
		}
		else if(four == -1){
//			printf("FOUR ANTICLOCK\n");
			anticlock(map[3]);
		}				

//		for(int i = 0 ; i < 4 ; ++i){
//			printf("[");
//			for(int j = 0 ; j < 8 ; ++j){
//				printf("%d ", map[i][j]);
//			}
//			printf("]\n");
//		}
	}
	
	// 이제 점수 
//	1번 톱니바퀴의 12시방향(=[0])이 N(=0)극이면 0점, S(=1)극이면 1점
//	2번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 2점
//	3번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 4점
//	4번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 8점 
	for(int j = 0 ; j < 4 ; ++j) {
		if(map[j][0] == 1){
			if(j == 0)	ans += 1;
			else if(j == 1)	 ans += 2;
			else if(j == 2)	 ans += 4;
			else if(j == 3)	 ans += 8;						
		}
	}
	
	printf("%d", ans);
	
	
}


