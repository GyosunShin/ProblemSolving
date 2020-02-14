// (1 ≤ N, M ≤ 20)
//  x y(0 ≤ x ≤ N-1, 0 ≤ y ≤ M-1)
// 명령의 개수 K (1 ≤ K ≤ 1,000)

// 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4

// OUTPUT : 이동할 때마다 주사위의 윗 면에 쓰여 있는 수를 출력한다. 만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시
//  출력도 하면 안 된다.

#include <cstdio>
#include <algorithm>

using namespace std;

int pan[20][20];
int order[1000];
int N, M, X, Y, K;
int start_r, start_c;

// 우 좌 상 하 
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
	
	tmp[1][1] = dice[1][0];  // 윗면 
	tmp[3][1] = dice[1][2];  // 아랫면 
	tmp[1][0] = dice[3][1];  // 왼쪽면 
	tmp[1][2] = dice[1][1];  // 오른쪽면 
	
	copy(&tmp[0][0], &tmp[0][0] + 4 * 3, &dice[0][0]);
}

void left(){
	int tmp[4][3];
	copy(&dice[0][0], &dice[0][0] + 4 * 3, &tmp[0][0]);	
	
	tmp[1][1] = dice[1][2];  // 윗면 
	tmp[3][1] = dice[1][0];  // 아랫면 
	tmp[1][0] = dice[1][1];  // 왼쪽면 
	tmp[1][2] = dice[3][1];  // 오른쪽면 
	
	copy(&tmp[0][0], &tmp[0][0] + 4 * 3, &dice[0][0]);	
}

void up(){
	int tmp[4][3];
	copy(&dice[0][0], &dice[0][0] + 4 * 3, &tmp[0][0]);	
	
	tmp[1][1] = dice[2][1];  // 윗면
	tmp[3][1] = dice[0][1];  // 아랫면
	tmp[2][1] = dice[3][1];  // 앞면 
	tmp[0][1] = dice[1][1];  // 뒷면
	
	copy(&tmp[0][0], &tmp[0][0] + 4 * 3, &dice[0][0]);	
}

void down(){
	int tmp[4][3];
	copy(&dice[0][0], &dice[0][0] + 4 * 3, &tmp[0][0]);	
	
	tmp[1][1] = dice[0][1];  // 윗면
	tmp[3][1] = dice[2][1];  // 아랫면
	tmp[2][1] = dice[1][1];  // 앞면 
	tmp[0][1] = dice[3][1];  // 뒷면
	
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
	
	
	// OUTPUT : 이동할 때마다 주사위의 윗 면에 쓰여 있는 수를 출력한다. 만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시
	//  출력도 하면 안 된다.
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
