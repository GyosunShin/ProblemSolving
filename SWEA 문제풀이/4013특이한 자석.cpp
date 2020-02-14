//  �ڼ� ȸ�� Ƚ�� ( 1 �� K �� 20 )
// �ð���� : 1   �ݽð���� : -1
// N�� : 0   S�� : 1
// �ڼ���ȣ : 1 ~ 4

// OUTPUT : ������ ��� �ڼ��� ȸ���� ���� �� ȹ���� ������ �� ���̴�.

#include <stdio.h>


int T, K;

int map[4][8];

int bunho[20];
int dir[20];

void rotate(int bunho, int dir){
	if (dir == 0)	return;
	if (dir == 1){  // �ð������ ���
		int tmp = map[bunho][0];
		map[bunho][0] = map[bunho][7];
		for (int i = 6; i >= 1; --i){
			map[bunho][i + 1] = map[bunho][i];
		}
		map[bunho][1] = tmp;
	}
	else if (dir == -1){  // �ݽð������ ���
		int tmp = map[bunho][0];
		map[bunho][0] = map[bunho][1];
		for (int i = 2; i <= 7; ++i){
			map[bunho][i - 1] = map[bunho][i];
		}
		map[bunho][7] = tmp;
	}
	
}

int main(){
	scanf("%d", &T);
	for (int z = 1; z <= T; ++z){
		scanf("%d", &K);
		for (int i = 0; i < 8; ++i){
			scanf("%d", &map[0][i]);
		}
		for (int i = 0; i < 8; ++i){
			scanf("%d", &map[1][i]);
		}
		for (int i = 0; i < 8; ++i){
			scanf("%d", &map[2][i]);
		}
		for (int i = 0; i < 8; ++i){
			scanf("%d", &map[3][i]);
		}

		// �ڼ��� ��ȣ, ȸ������
		for (int i = 0; i < K; ++i){
			scanf("%d %d", &bunho[i], &dir[i]);
		}
		//#######################################

		for (int z = 0; z < K; ++z){
			/*printf("Z : %d\n", z);*/
			int cur_top = (bunho[z] - 1); // �ڼ���ȣ : 1 ~ 4
			/*printf("CUR_TPO : %d\n", cur_top);*/
			int cur_dir = dir[z];  // �ð���� : 1   �ݽð���� : -1
			int decision[4] = { 0, };
			decision[cur_top] = cur_dir;

			if (cur_top == 0){
				if (map[0][2] != map[1][6]){
					decision[1] = cur_dir * -1;
				}
				if (decision[1] != 0){
					if (map[1][2] != map[2][6]){
						decision[2] = decision[1] * -1;
					}
				}
				if (decision[2] != 0){
					if (map[2][2] != map[3][6]){
						decision[3] = decision[2] * -1;
					}
				}
			}
			else if (cur_top == 1){
				if (map[1][6] != map[0][2]){
					decision[0] = cur_dir * -1;
				}
				if (map[1][2] != map[2][6]){
					decision[2] = cur_dir * -1;
				}
				if (decision[2] != 0){
					if (map[2][2] != map[3][6]){
						decision[3] = decision[2] * -1;
					}
				}
			}
			else if (cur_top == 2){
				if (map[2][6] != map[1][2]){
					decision[1] = cur_dir * -1;
				}
				if (map[2][2] != map[3][6]){
					decision[3] = cur_dir * -1;
				}
				if (decision[1] != 0){
					if (map[1][6] != map[0][2]){
						decision[0] = decision[1] * -1;
					}
				}
			}
			else if (cur_top == 3){
				if (map[3][6] != map[2][2]){
					decision[2] = cur_dir * -1;
				}
				if (decision[2] != 0){
					if (map[2][6] != map[1][2]){
						decision[1] = decision[2] * -1;
					}
				}
				if (decision[1] != 0){
					if (map[1][6] != map[0][2]){
						decision[0] = decision[1] * -1;
					}
				}
			}
			for (int i = 0; i < 4; ++i){
				rotate(i, decision[i]);
			}
			//printf("A DIR : %d\n", decision[0]);
			//for (int i = 0; i < 8; ++i){
			//	printf("%d ", map[0][i]);
			//}
			//printf("\n");
			//printf("B DIR : %d\n", decision[1]);
			//for (int i = 0; i < 8; ++i){
			//	printf("%d ", map[1][i]);
			//}
			//printf("\n");
			//printf("C DIR : %d\n", decision[2]);
			//for (int i = 0; i < 8; ++i){
			//	printf("%d ", map[2][i]);
			//}
			//printf("\n");
			//printf("D DIR : %d\n", decision[3]);
			//for (int i = 0; i < 8; ++i){
			//	printf("%d ", map[3][i]);
			//}
			//printf("\n");
		}

		int ans = 0;
		if (map[0][0] == 1)	ans += 1;
		if (map[1][0] == 1)	ans += 2;
		if (map[2][0] == 1)	ans += 4;
		if (map[3][0] == 1)	ans += 8;
		printf("#%d %d\n", z, ans);
	}
	return 0;
}
