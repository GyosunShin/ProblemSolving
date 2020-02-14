// �׽�Ʈ ���̽��� �ִ� 100���̴�

// ť�긦 ���� Ƚ�� n�� �־�����. (1 �� n �� 1000)
// (U: �� ��)  (D: �Ʒ� ��)  (F: �� ��)  (B: �� ��)  (L: ���� ��)  (R: ������ ��)
// (+ �ð����) (- �ݽð� ����)

// OUTPUT : ť�긦 ��� ���� ���� �� ���� ������ ���


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

// (U: �� ��)  (D: �Ʒ� ��)  (F: �� ��)  (B: �� ��)  (L: ���� ��)  (R: ������ ��)
// (+ �ð����) (- �ݽð� ����)
void solve(int myun, int dir){
	
	// backup������ ��ƾ� �� 
	
	if(myun == 'U'){
		if(dir == '+'){  // �ð���� 
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
			
			
			// ��... ���� ���� ������ ����
			// �ð�����̱� �ݽð� ��������
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
		else if(dir == '-'){  // �ݽð���� 
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
			
			// �ݽð�ϱ� �ò��������� 		
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
		if(dir == '-'){  // �ݽð���� 
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
			
			//�ݽð�����̴ϱ� �ð��������
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
		else if(dir == '+'){  // �ð����
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
			
			// �ò����� �̴ϱ� �ݽð� ������ ��
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
		if(dir == '+'){  // �ð���� 
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
			
			// �ð�����̴ϱ� �ݽð�������� 
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
		else if(dir == '-'){  // �ݽð���� 
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
			
			// �ݽð� �����̴ϱ� �ð��������
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
		if(dir == '-'){  // �ݽð���� 
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
			
			// �ݽð� �����̴ϱ� �ð��������
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
		else if(dir == '+'){  // �ð���� 
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
			
			// �ð�����̴ϱ� �ݽð��������
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
		if(dir == '+'){  // �ð���� 	
			char tmp1 = backup[0][3];
			char tmp2 = backup[1][3];
			char tmp3 = backup[2][3];
			
			for(int i = 0 ; i <= 8 ; ++i){
				backup[i][3] = backup[i+3][3];
			}
			
			backup[11][3] = tmp3;
			backup[10][3] = tmp2;
			backup[9][3] = tmp1;
			
			// �ð�����̴ϱ� �ݽð��������
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
		else if(dir == '-'){  // �ݽð���� 	
			char tmp1 = backup[9][3];
			char tmp2 = backup[10][3];
			char tmp3 = backup[11][3];
			
			for(int i = 11 ; i >= 3 ; --i){
				backup[i][3] = backup[i-3][3];
			}
			
			backup[0][3] = tmp1;
			backup[1][3] = tmp2;
			backup[2][3] = tmp3;		
			
			// �ݽð�����̴ϱ� �ð������ ��  
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
		if(dir == '-'){  // �ݽð���� 	
			char tmp1 = backup[0][5];
			char tmp2 = backup[1][5];
			char tmp3 = backup[2][5];
			
			for(int i = 0 ; i <= 8 ; ++i){
				backup[i][5] = backup[i+3][5];
			}
			
			backup[11][5] = tmp3;
			backup[10][5] = tmp2;
			backup[9][5] = tmp1;	
			
			// 	�ݽð� �����̴ϱ� �ò���������
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
		else if(dir == '+'){  // �ð���� 	
			char tmp1 = backup[9][5];
			char tmp2 = backup[10][5];
			char tmp3 = backup[11][5];
			
			for(int i = 11 ; i >= 3 ; --i){
				backup[i][5] = backup[i-3][5];
			}
			
			backup[0][5] = tmp1;
			backup[1][5] = tmp2;
			backup[2][5] = tmp3;		
			
			// �ð�����̴ϱ� �ݽð� ��������
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
		
//			printf("�ѹ� �ҋ�����\n");
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
			
//			printf("�ѹ� �ҋ�����\n");
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
