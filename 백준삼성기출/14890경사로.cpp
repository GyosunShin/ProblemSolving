// ù° �ٿ� N (2 �� N �� 100)�� L (1 �� L �� N)
// ��° �ٺ��� N���� �ٿ� ������ �־�����
// �� ĭ�� ���̴� 10���� �۰ų� ���� �ڿ����̴�.
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
	
	// �� �྿ CHECK!! 
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
			if(map[i][j] != start_1){  // �� 
				flag1 = 0;
			}
			if(map[j][i] != start_2){  // �� 
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
		if(flag1){  // '��' ���δ� ������ ���� ��� 
			++ans;
		}
		if(flag2){  // '��' ���δ� ������ ���� ��� 
			++ans;
		}
		
	}
	
}

