// 첫째 줄에 N (2 ≤ N ≤ 100)과 L (1 ≤ L ≤ N)
// 둘째 줄부터 N개의 줄에 지도가 주어진다
// 각 칸의 높이는 10보다 작거나 같은 자연수이다.
#include <stdio.h> 

int N, M;
int map[100][100];
int ans = 0;

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N; ++j){
			scanf("%d", &map[i][j]);		
		}
	}
	//####################################
	
	// 한 행씩 CHECK!! 
	for(int i = 0 ; i < N ; ++i){
		int flag1 = 1;
		int flag2 = 1;
		int start_1 = map[i][0];
		int start_2 = map[0][i];
		int switch_1 = 0;
		int switch_2 = 0;
		int cnt_1 = 0;
		int cnt_2 = 0;
		for(int j = 0 ; j < N; ++j){
			if(map[i][j] != start_1){  // 행 
				flag1 = 0;
			}
			if(map[j][i] != start_2){  // 열 
				flag1 = 0;
			}			
			if(j != 0){
				int dif_1 = map[i][j-1] - map[i][j];
				int dif_2 = map[j-1][i] - map[j][i];
				if(abs(dif_1) == 1){
					switch_1 = 1;
				}
				if(abs(dif_2) == 1){
					switch_2 = 1;
				}
				if(dif_1 == 0 && switch_1 == 1){
					cnt_1 = 1;
				}
				if(dif_2 == 0 && switch_2 == 1){
					cnt_2 = 1;
				}				
				
				
			}
			
		}
		if(flag1){  // '행' 전부다 동일한 값일 경우 
			++ans;
		}
		if(flag2){  // '열' 전부다 동일한 값일 경우 
			++ans;
		}
		
	}
	
}

