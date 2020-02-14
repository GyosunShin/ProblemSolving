// ù° �ٿ� �巡�� Ŀ���� ���� N(1 �� N �� 20)�� �־�����
// ��° �ٺ��� N���� �ٿ��� �巡�� Ŀ���� ������ �־�����(x, y, d, g)
// x�� y�� �巡�� Ŀ���� ���� ��, d�� ���� ����, g�� �����̴�. (0 �� x, y �� 100, 0 �� d �� 3, 0 �� g �� 10)
// 0: x��ǥ�� �����ϴ� ���� (��)
// 1: y��ǥ�� �����ϴ� ���� (��)
// 2: x��ǥ�� �����ϴ� ���� (��)
// 3: y��ǥ�� �����ϴ� ���� (��)
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int map[101][101];  // ����: 0 �� x �� 100, 0 �� y �� 100�� ��ȿ�� ��ǥ
int input[20][4];  // [column, row, direction, generation]

int ans;

void check(){
//	for(int i = 0 ; i < 8 ; ++i) {
//		printf("[");
//		for(int j = 0 ; j < 8 ; ++j){
//			printf("%d ", map[i][j]);
//		}
//		printf("]\n");
//	}
	
	// map���� �簢�� �� 1�� ���°� ����� CHECK!
	for(int i = 0 ; i < 100 ; ++i) {
		for(int j = 0 ; j < 100 ; ++j){
			if(map[i][j] == 1 && map[i][j+1] == 1 && map[i+1][j] == 1 && map[i+1][j+1] == 1){
				++ans;
			}
		}
	}
}

int main(){
	scanf("%d", &N);  // �巡��Ŀ���� ���� 
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < 4 ; ++j){  // x(=c), y(=r), d, g
			scanf("%d", &input[i][j]);
		}
	}
	//###################### �Է� �� ##################################
	
	
	for(int i = 0 ; i < N ; ++i){
		vector<int> tmp;
		tmp.push_back(input[i][2]);  // �ϴ� ó�� ������ ����ִ´�. 
		for(int j = 0 ; j < input[i][3] ; ++j) {  // ���븸ŭ  (g == 0�̸� �� �̻� ������)
			int len = tmp.size();  // ������� ��� ��� �ִ���.
			for(int k = len-1 ; k >= 0 ; --k){  // ������� �ִ� ��ŭ ����ִ´�. 
//				printf("#### tmp[k] : %d\n", tmp[k]);
				if(tmp[k] == 0){
					tmp.push_back(1);
				}
				else if(tmp[k] == 1){
					tmp.push_back(2);
				}
				else if(tmp[k] == 2){
					tmp.push_back(3);
				}
				else if(tmp[k] == 3){
					tmp.push_back(0);
				}								
			}	 
		}
		//  �� �� ����־�����, ���� vector�� ����ִ� dir���� ������� �Ͽ� ��ǥ�� 1�� �ٲ��شپ�! 
		
		int len = tmp.size();
//		for(int j = 0 ; j < len ; ++j){
//			printf("%d ", tmp[j]);
//		}
		int start_r = input[i][1];
		int start_c = input[i][0];
//		printf("start_r : %d / start_c : %d\n", start_r, start_c);
		map[start_r][start_c] = 1;  // �ϴ� ó�� �������� �̸� 1�� �ٲ��ش�. 
		for(int j = 0 ; j < len ; ++j){  //���⿡ ���� ���� �� map[][]�� ���� 1�� �ٲ��ش�. 
			int dir = tmp[j];
			if(dir == 0){  // ���� 
//				printf("right!\n");
				map[start_r][start_c+1] = 1;
				++start_c;
			}
			else if(dir == 1){  // �� 
//				printf("up!\n");
				map[start_r-1][start_c] = 1;
				--start_r;
			}
			else if(dir == 2){  // �� 
//				printf("left!\n");
				map[start_r][start_c-1] = 1;
				--start_c;
			}	
			else if(dir == 3){  // �Ʒ� 
//				printf("down!\n");
				map[start_r+1][start_c] = 1;
				++start_r;
			}			
//			printf("next_r : %d / next_c : %d\n", start_r, start_c);
		}
//		printf("EACH!!!\n");
	}
	check(); 
	
	printf("%d", ans);
}

