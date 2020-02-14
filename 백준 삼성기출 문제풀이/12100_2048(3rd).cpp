// ù° �ٿ� ������ ũ�� N (1 �� N �� 20)
// 0 : ��ĭ 

//3
//2 2 2
//4 4 4
//8 8 8

//�ִ� 5�� �̵����Ѽ� ���� �� �ִ� ���� ū ����� ����Ѵ�.
#include <stdio.h>

int N;

struct BOARD{
	int map[20][20];
	
	void up(){ //���� �ø��ϱ� �ϴ� ������ ���� 
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
		
		// ������ copy!! 
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
		// TODO : ���⼭�� �̹� ������ �Ϸ�� �����̹Ƿ� st.map���� �ִ밪 ã�ƾ� ��
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


