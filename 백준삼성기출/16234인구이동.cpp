// N, L, R�� �־�����. (1 �� N �� 50, 1 �� L �� R �� 100)
#include <stdio.h> 
#include <algorithm>
#include <queue>

using namespace std;

int dr[] = {-1, 1, 0, 0};  // ��, ��, ��, ��  
int dc[] = {0, 0, -1, 1};

int N, L, R;
int map[50][50];
int flag[50][50];

int ans;

queue<pair<int, int> > q;

void update(){
//	printf("UPDATE\n");
//	for(int i = 0 ; i < N ; ++i) {
//		printf("[");
//		for(int j = 0 ; j < N ; ++j){
//			printf("%d", flag[i][j]);
//		}
//		printf("]\n");
//	}	
	// �ϴ� flag[][]�߿� �ְ� ã��
	int max = 0;
	for(int i = 0 ; i < N ; ++i) {
		for(int j = 0 ; j < N ; ++j){
			if(flag[i][j] > max){
				max = flag[i][j];
			}
		}
	}
	
	int avg[max] = { 0, };
	int cnt[max] = { 0, };
	
	for(int i = 0 ; i < N ; ++i) {
		for(int j = 0 ; j < N ; ++j){	
			if(flag[i][j] != 0){
				avg[flag[i][j] - 1] += map[i][j];
				++cnt[flag[i][j] - 1];
			}
		}
	}
	
	for(int i = 0 ; i < sizeof(avg) / sizeof(int) ; ++i){
		avg[i] = avg[i] / cnt[i];
	}
	
	for(int i = 0 ; i < N ; ++i) {
		for(int j = 0 ; j < N ; ++j){
			if(flag[i][j] != 0){
				map[i][j] =  avg[flag[i][j] - 1];
			}
		}
	}
	
//	printf("AFTER UPDATE\n");
//	for(int i = 0 ; i < N ; ++i) {
//		printf("<");
//		for(int j = 0 ; j < N ; ++j){
//			printf("%d ", map[i][j]);
//		}
//		printf(">\n");
//	}		
	
}

int main(){
	scanf("%d %d %d", &N, &L, &R);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	// ##################################	
	
	// BFS�� ������Ű�� ���Ͽ� �ϴ� [0,0] �ε��� ��ġ�� ���� ����ִ´�.
	while(1){
//		printf("EVERYTIME!!\n");
//		for(int i = 0 ; i < N ; ++i) {
//			printf("(");
//			for(int j = 0 ; j < N ; ++j){
//				printf("%d ", map[i][j]);
//			}
//			printf(")\n");
//		}				
		
		int check = 0;  // �̰� �ѹ��� �ȹٲ�� �ٷ� ���� 
//		printf("CHECK CHECK!!!! : %d\n" ,check);
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				flag[i][j] = 0;
			}
		}
		
		int flag_cnt = 0;
		
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
//				printf("flag[%d][%d] = %d / flag_cnt = %d\n", i, j, flag[i][j]);
				if(flag[i][j] <= flag_cnt && flag[i][j] != 0){
//					printf("SAME AS BEFORE! \n");
					continue;
				}
				++flag_cnt;
				
				q.push(pair<int, int>(i,j));	// �������� �־��ش�.	
				while(!q.empty()){
					int cur_r = q.front().first;
					int cur_c = q.front().second;
					
//					printf("CUR_R : %d / CUR_C : %d\n", cur_r , cur_c);
					q.pop();
					flag[cur_r][cur_c] = flag_cnt;
					
					for(int k = 0 ; k < 4 ; ++k){
						int next_r = cur_r + dr[k];
						int next_c = cur_c + dc[k];
//						printf("NEXT_R : %d / NEXT_C : %d\n", next_r , next_c);
						if(next_r < 0 || next_r >= N || next_c < 0 || next_c >= N){
//							printf("CONTINE\n");
							continue;
						}	
//						printf("DIFF : %d\n", abs(map[cur_r][cur_c] - map[next_r][next_c]));
						if(L <= abs(map[cur_r][cur_c] - map[next_r][next_c]) && abs(map[cur_r][cur_c] - map[next_r][next_c]) <= R){
							if(flag[next_r][next_c] != 0){
//								printf("EATED!\n");
								continue;
							}
							flag[next_r][next_c] = flag_cnt;
//							printf("CORRECT\n");
							++check;
							q.push(pair<int, int>(next_r,next_c));
						}
					} // �� ���� ���� 4���� ���� �Ȱ� ���ǿ� �����ϴ°� queue�� �������						
				}  // queue�� empty�� ����
				
//				printf("BECOME EMPTY!!!! \n");				
			}
		}  // ��� ���� ���Ͽ� �����Ա� ���� �Ϸ�
//		printf("####### check : %d\n\n", check);
		if(check == 0){  // ���� �ϳ��� �ȿ��ȴٴ� �� 
			printf("%d", ans);
			return 0;	
		}
		
		// �״ϱ� ���� �������� �� �̿��ؼ� �α��̵� �����ؼ� Average������ map ������ �� Update����� ��
		update(); 
		++ans;  // �ּ��� �Ѱ��� ������ ������ �α��̵��� �Ͼ��! 
	}
	
		 
}




