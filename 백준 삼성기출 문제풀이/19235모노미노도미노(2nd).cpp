// ����� �̵��� �ٸ� ����� �����ų� ������ ��踦 ������ ������ ����ؼ� �̵��Ѵ�. 

// INPUT
// ����� ���� Ƚ�� 1 �� N �� 10,000
// t x y

#include <cstdio>
#include <vector>

using namespace std;

int N; 
int t, r, c;

int pan[10][10];

void pt(){
	
	for(int i = 0 ; i < 10 ; ++i){
		for(int j = 0 ; j < 10 ; ++j){
			printf("%d ", pan[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
}

int blueWhere(int r, int c){
	int target = -1;
	
	for(int i = c+1 ; i <= 9 ; ++i){
		if(pan[r][i] != 0){
			target = i-1;
			break;
		}
		target = i;
	}
	
	if(target == -1)	return 9;
	else	return target;
}

int blueWhereThree(int r, int c){
	int target = -1;
	
	for(int i = c+1 ; i <= 9 ; ++i){
		if(pan[r][i] != 0 || pan[r+1][i] != 0){
			target = i-1;
			break;
		}
		target = i;
	}
	
	if(target == -1)	return 9;
	else	return target;
}

int greenWhere(int r, int c){
	int target = -1;
	
	for(int i = r+1 ; i <= 9 ; ++i){
		if(pan[i][c] != 0){
			target = i-1;
			break;
		}
	}
	
	if(target == -1)	return 9;
	return target;
}

int greenWhereTwo(int r, int c){
	int target = -1;
	
	for(int i = r+1 ; i <= 9 ; ++i){
		if(pan[i][c] != 0 || pan[i][c+1] != 0){
			target = i-1;
			break;
		}
	}
	
	if(target == -1)	return 9;
	return target;
}

void rightPush(){
	
	int tmp = 4;
	while(tmp--){
		for(int i = 9 ; i >= 6 ; --i){
			
			bool flag = true;
			for(int j = 0 ; j < 4 ; ++j){
				if(pan[j][i] != 0){
					flag = false;
					break;
				}
			}
			
			// [0,4] ~~~ [0, i-1]
			// [1,4] ~~~ [1, i-1]
			// [2,4] ~~~ [2, i-1]
			// [3,4] ~~~ [3, i-1]
			if(flag){
				for(int j = i-1 ; j >= 4 ; --j){
					for(int k = 0 ; k < 4 ; ++k){
						if(pan[k][j] == 3){
							// [k, j]
							// [k+1, j]
							int target = blueWhereThree(k, j);
							pan[k][target] = 3;	pan[k+1][target] = 3;
							pan[k][j] = 0;	pan[k+1][j] = 0;
							++k;
						}
						else{
							int target = blueWhere(k, j);
							pan[k][target] = pan[k][j];
							pan[k][j] = 0;
						}
					}
				}
				for(int j = 0 ; j < 4 ; ++j){
					pan[j][4] = 0;
				}
			}
			
		}
	}	

	
}

void downPush(){
	
	int tmp = 4;
	while(tmp--){
		for(int i = 9 ; i >= 6 ; --i){
			bool flag = true;
			for(int j = 0 ; j < 4 ; ++j){
				if(pan[i][j] != 0){
					flag = false;
					break;
				}
			}
			
			// [4,0] ~~ [4,3]
			// ....
			// [i-1,0] ~~ [i-1, 3]
			if(flag){
				for(int j = i-1 ; j >= 4 ; --j){
					for(int k = 0 ; k < 4 ; ++k){
						if(pan[j][k] == 2){
							// [j, k][j, k+1]
							int target = greenWhereTwo(j, k);
							pan[target][k] = 2;	pan[target][k+1] = 2;
							pan[j][k] = 0;	pan[j][k+1] = 0;
							++k;
						}
						else{
							int target = greenWhere(j, k);
							pan[target][k] = pan[j][k];
							pan[j][k] = 0;
						}
					}
				}
				for(int j = 0 ; j < 4 ; ++j)	pan[4][j] = 0;
			}
			
		}
	}
	
}

int colCheck(){
	int score = 0;
	
	while(true){
		int cnt = 0;
	
		for(int i = 9 ; i >= 6 ; --i){
			bool flag = true;
			for(int j = 0 ; j < 4 ; ++j){
				if(pan[j][i] == 0){
					flag = false;
					break;
				}
			}
			if(flag){
				cnt++;
				score++;
				for(int j = 0 ; j < 4 ; ++j){
					pan[j][i] = 0;
				}
			}
		}	
		rightPush();
		if(cnt == 0)	break;
	}
	
	return score;
}

int rowCheck(){
	int score = 0;
	
	while(true){	
		
		int cnt = 0;
	
		for(int i = 9 ; i >= 6 ; --i){
			bool flag = true;
			for(int j = 0 ; j < 4 ; ++j){
				if(pan[i][j] == 0){
					flag = false;
					break;
				}
			}
			if(flag){
				cnt++;
				score++;
				for(int j = 0 ; j < 4 ; ++j){
					pan[i][j] = 0;
				}
			}
		}
		downPush();
		if(cnt == 0)	break;
	}
	
	return score;
}

void whiteBlue(){
	
	// [0, 4] ~ [0, 5]
	// [1, 4] ~ [1, 5]
	// [2, 4] ~ [2, 5]
	// [3, 4] ~ [3, 5]
	
	int howMany = 0;
	for(int i = 0 ; i < 4 ; ++i){
		if(pan[i][4] != 0){
			howMany++;
			break;
		}
	}
	for(int i = 0 ; i < 4 ; ++i){
		if(pan[i][5] != 0){
			howMany++;
			break;
		}
	}
	
	for(int i = 0 ; i < howMany ; ++i){
		for(int j = 0 ; j < 4 ; ++j){
			pan[j][9-i] = 0;
		}
	}
	
	rightPush();
}

void whiteGreen(){
	
	// [4, 0] [4, 1] [4, 2] [4, 3]
	// [5, 0] [5, 1] [5, 2] [5, 3]
	
	int howMany = 0;
	for(int i = 0 ; i < 4 ; ++i){
		if(pan[4][i] != 0){
			howMany++;
			break;
		}
	}
	for(int i = 0 ; i < 4 ; ++i){
		if(pan[5][i] != 0){
			howMany++;
			break;
		}
	}	
	
	for(int i = 0 ; i < howMany ; ++i){
		for(int j = 0 ; j < 4 ; ++j){
			pan[9-i][j] = 0;
		}
	}	
	
	downPush();
}


// t = 1: ũ�Ⱑ 1��1�� ����� (x, y)�� ���� ���
int solveOne(int r, int c){
	
	int score = 0;
	
	// Blue �������� ã��
	int bWhere = blueWhere(r, c);
	// ��¥�� ����߸���
	pan[r][bWhere] = 1;
	// ��(����) �������� �ִ��� Ȯ���ϱ� 
	score += colCheck();
	// ���ѻ� ó�� 
	whiteBlue(); 	
	 
	// Green �������� ã��
	int gWhere = greenWhere(r, c);
	// ��¥�� ����߸���
	pan[gWhere][c] = 1;
	// ��(����) �������� �ִ��� Ȯ���ϱ� 
	score += rowCheck();
	// ���ѻ� ó��
	whiteGreen();
	
	return score;
}

// t = 2: ũ�Ⱑ 1��2�� ����� (x, y), (x, y+1)�� ���� ���
int solveTwo(int r, int c){
	int score = 0;
	
	// Blue �������� ã��
	int bWhere = blueWhere(r, c+1);
	// ��¥�� ����߸���
	pan[r][bWhere-1] = 2;	pan[r][bWhere] = 2;
	// ��(����) �������� �ִ��� Ȯ
	score += colCheck();
	// ���ѻ� ó�� 
	whiteBlue(); 
	 
	// Green �������� ã��
	int gWhere = greenWhereTwo(r, c);
	// ��¥�� ����߸���
	pan[gWhere][c] = 2;	pan[gWhere][c+1] = 2;
	// ��(����) �������� �ִ��� Ȯ���ϱ� 
	score += rowCheck();
	// ���ѻ� ó��
	whiteGreen();
	
	return score;
}

// t = 3: ũ�Ⱑ 2��1�� ����� (x, y), (x+1, y)�� ���� ��� 
int solveThree(int r, int c){
	int score = 0;
	
	// Blue �������� ã��
	int bWhere = blueWhereThree(r, c);
	// ��¥�� ����߸���
	pan[r][bWhere] = 3;	pan[r+1][bWhere] = 3;
	// ��(����) �������� �ִ��� Ȯ���ϱ� 
	score += colCheck();
	// ���ѻ� ó�� 
	whiteBlue();
	 
	// Green �������� ã��
	int gWhere = greenWhere(r+1, c);
	// ��¥�� ����߸���
	pan[gWhere-1][c] = 3;	pan[gWhere][c] = 3;
	// ��(����) �������� �ִ��� Ȯ���ϱ� 
	score += rowCheck();
	whiteGreen();
	
	return score;
}

int main(){
	int answer = 0;
	
	scanf("%d", &N);
	for(int z = 0 ; z < N ; ++z){
		scanf("%d %d %d", &t, &r, &c);
		if(t == 1)	answer += solveOne(r, c);
		else if(t == 2)	answer += solveTwo	(r, c);
		else if(t == 3)	answer += solveThree(r, c);
	}
	
	printf("%d\n", answer);
	int blueGreen = 0;
	for(int i = 4 ; i <= 9 ; ++i){
		for(int j = 0 ; j < 4 ; ++j){
			if(pan[i][j] != 0)	blueGreen++;
		}
	}
	for(int i = 4 ; i <= 9 ; ++i){
		for(int j = 0 ; j < 4 ; ++j){
			if(pan[j][i] != 0)	blueGreen++;
		}
	}
	printf("%d\n", blueGreen);
	
	return 0;
}
