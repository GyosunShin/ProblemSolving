// (1 �� N, M �� 20)
//  x y(0 �� x �� N-1, 0 �� y �� M-1)
// ����� ���� K (1 �� K �� 1,000)

// ������ 1, ������ 2, ������ 3, ������ 4

// OUTPUT : �̵��� ������ �ֻ����� �� �鿡 ���� �ִ� ���� ����Ѵ�. ���� �ٱ����� �̵���Ű���� �ϴ� ��쿡�� �ش� ����� ����
//  ��µ� �ϸ� �� �ȴ�.

#include <cstdio>
#include <algorithm>

using namespace std;

int pan[20][20];
int order[1000];
int N, M, X, Y, K;
int start_r, start_c;

// �� �� �� �� 
const int dr[] = {0, 0, -1, 1};
const int dc[] = {1, -1, 0, 0};

int dice[4][3] = {
	{0,0,0},
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

void right(){
	int tmp[4][3];
	copy(&dice[0][0], &dice[0][0] + 4 * 3, &tmp[0][0]);	
	
	tmp[1][1] = dice[1][0];  // ���� 
	tmp[3][1] = dice[1][2];  // �Ʒ��� 
	tmp[1][0] = dice[3][1];  // ���ʸ� 
	tmp[1][2] = dice[1][1];  // �����ʸ� 
	
	copy(&tmp[0][0], &tmp[0][0] + 4 * 3, &dice[0][0]);
}

void left(){
	int tmp[4][3];
	copy(&dice[0][0], &dice[0][0] + 4 * 3, &tmp[0][0]);	
	
	tmp[1][1] = dice[1][2];  // ���� 
	tmp[3][1] = dice[1][0];  // �Ʒ��� 
	tmp[1][0] = dice[1][1];  // ���ʸ� 
	tmp[1][2] = dice[3][1];  // �����ʸ� 
	
	copy(&tmp[0][0], &tmp[0][0] + 4 * 3, &dice[0][0]);	
}

void up(){
	int tmp[4][3];
	copy(&dice[0][0], &dice[0][0] + 4 * 3, &tmp[0][0]);	
	
	tmp[1][1] = dice[2][1];  // ����
	tmp[3][1] = dice[0][1];  // �Ʒ���
	tmp[2][1] = dice[3][1];  // �ո� 
	tmp[0][1] = dice[1][1];  // �޸�
	
	copy(&tmp[0][0], &tmp[0][0] + 4 * 3, &dice[0][0]);	
}

void down(){
	int tmp[4][3];
	copy(&dice[0][0], &dice[0][0] + 4 * 3, &tmp[0][0]);	
	
	tmp[1][1] = dice[0][1];  // ����
	tmp[3][1] = dice[2][1];  // �Ʒ���
	tmp[2][1] = dice[1][1];  // �ո� 
	tmp[0][1] = dice[3][1];  // �޸�
	
	copy(&tmp[0][0], &tmp[0][0] + 4 * 3, &dice[0][0]);	
}

int main(){
	scanf("%d %d %d %d %d", &N, &M, &X, &Y, &K);
	
	start_r = X;
	start_c = Y;
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	for(int i = 0 ; i < K ; ++i){
		scanf("%d", &order[i]);
	}
	
	
	// OUTPUT : �̵��� ������ �ֻ����� �� �鿡 ���� �ִ� ���� ����Ѵ�. ���� �ٱ����� �̵���Ű���� �ϴ� ��쿡�� �ش� ����� ����
	//  ��µ� �ϸ� �� �ȴ�.
	for(int i = 0 ; i < K ; ++i){		
		int dir = order[i];
		dir--;
		int next_r = start_r + dr[dir];	int next_c = start_c + dc[dir];
		if(0 > next_r || next_r >= N || 0 > next_c || next_c >= M){
			continue;
		}	
		int& can = pan[next_r][next_c];
		int badak;
		if(dir == 0){
			right();
			badak = dice[3][1];
		}
		else if(dir == 1){
			left();
			badak = dice[3][1];
		}
		else if(dir == 2){
			up();
			badak = dice[3][1];
		}
		else if(dir == 3){
			down();
			badak = dice[3][1];
		}
		
		if(can == 0){
			can = badak;
		}
		else{
			dice[3][1] = can;
			can = 0;
		}
		
		printf("%d\n", dice[1][1]);
		start_r = next_r;	start_c = next_c;
	}
	return 0;
}
