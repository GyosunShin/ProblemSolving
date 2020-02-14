// 첫째 줄에 보드의 크기 N (1 ≤ N ≤ 20)
// 0 : 빈칸 

//3
//2 2 2
//4 4 4
//8 8 8

//최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록을 출력한다.
#include <stdio.h>

int N;

struct BOARD{
	int map[20][20];
	
	void up(){ //위로 올리니까 일단 열부터 훑자 
		int tmp[20][20];	
		
		for(int i = 0 ; i < N ; ++i){  
			int flag = 0;
			int target = -1;
			for(int j = 0 ; j < N ; ++j){
				if(map[j][i] == 0)	continue;
				if(flag == 1 && map[j][i] == tmp[target][i]){
					tmp[target][i] *= 2;
					flag = 0;
				}
				else{
					flag = 1;
					tmp[++target][i] = map[j][i];
				}
			}
			for(++target ; target < N ; ++target){
				tmp[target][i] = 0;
			}
		}
		
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				map[i][j] = tmp[i][j]; 
			}
		}			
	}
	
	void rotate(){
		int tmp[20][20];	
		
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				tmp[i][j] = map[(N-1)-j][i]; 
			}
		}		
		
		// 원본에 copy!! 
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				map[i][j] = tmp[i][j]; 
			}
		}		
	}
	
	int getMax(){
		int tmpMax = -1 * 0x7fffffff;
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				if(map[i][j] > tmpMax){
					tmpMax = map[i][j];
				}
			}
		}
		return tmpMax;
	}
	
};


int ans = (-1 * 0x7fffffff);

void dfs(BOARD st, int cnt){
	if(cnt == 5){
		// TODO : 여기서는 이미 게임이 완료된 상태이므로 st.map에서 최대값 찾아야 함
		int tmp_max = st.getMax();
		if(tmp_max > ans){
			ans = tmp_max;
		}
		return;
	}
	
	for(int i = 0 ; i < 4 ; ++i){
		BOARD tmp = st;
		tmp.up();
		dfs(tmp, cnt + 1);
		st.rotate();
	}
}

int main(){
	BOARD start;
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &start.map[i][j]);
		}
	}
	//####################################
	
	dfs(start, 0);
	printf("%d", ans);
	return 0;
}


