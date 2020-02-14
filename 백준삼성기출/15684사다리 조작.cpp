// 세로선의 개수 N / 가로선의 개수 M / 세로선마다 가로선을 놓을 수 있는 위치의 개수 H
// (2 ≤ N ≤ 10, 1 ≤ H ≤ 30, 0 ≤ M ≤ (N-1)×H)
// (1 ≤ a ≤ H, 1 ≤ b ≤ N-1) 
// 
// i번 세로선의 결과가 i번이 나오도록 사다리 게임을 조작하려면, 추가해야 하는 가로선 개수의 최솟값을 출력한다. 
// 만약, 정답이 3보다 큰 값이면 -1을 출력한다. 또, 불가능한 경우에도 -1을 출력한다.
#include <stdio.h>
#include <stdlib.h>



int N, M, H;
int map[30][19] = { 0, };

// 하, 우, 좌 
int dr[] = {-1, 0, 0}; 
int dc[] = {0, 1, -1};

void map_copy(int dsc[30][19], int src[30][19]){
	for(int i = 0 ; i < 30 ; ++i){
		for(int j = 0 ; j < 19 ; ++j){
			dsc[i][j] = src[i][j];
		}
	}
}

// 일단 map[][] 따라내려가는 함수 구현
// 범위를 벗어낫을 경우의 column값을 통해 어디에 도착하였는지 확인! 
bool track() {
	printf("<TRACK>\n");
	for(int i = 0 ; i < 30 ; ++i){
		printf("[");
		for(int j = 0 ; j < 19 ; ++j){
			printf("%d ", map[i][j]);
		}
		printf("]\n");
	}	
	bool ret = true; // 하나라도 자신과 동일한 위치에서 멈추지 않으면 0으로 바뀌고 정답이 아님을 의미. 
	for(int i = 0 ; i <= ((2 * N) - 2) ; i = i+2){  // 0 -> 2 -> 4 -> 6 -> 8
		int r = 0;
		int c = i;
		int flag = 0;	
		while(0 <= r && r <= H-1){
			printf("r : %d / c : %d\n", r, c);
			
			// 현재위치 기준 양쪽 옆 확인
			int dir = 0; // 0 : 바로 밑으로 | 1 : 우로 | 2 : 좌로 
			int r_r = r;
			int r_c = c+1; 
			int l_r = r;
			int l_c = c-1;
			printf("r_r : %d / r_c : %d\n", r_r, r_c);
			printf("l_r : %d / l_c : %d\n", l_r, l_c);
			if(1 <= r_c && r_c <= (2*N - 3) && map[r_r][r_c] == 1 && flag == 0){
				printf("RIGHT\n");
				dir = 1;
			}
			if(1 <= l_c && l_c <= (2*N - 3) && map[l_r][l_c] == 1 && flag == 0){
				printf("LEFT\n");
				dir = 2;
			}
			
			if(dir == 0){
				printf("DOWN\n\n");
				flag = 0;
				++r;
			}
			else if(dir == 1){
				flag = 1;
				c = c+2;
			}
			else if(dir == 2){
				flag = 1;
				c = c-2;
			}			
		}  // The End of While Loop
		printf("i : %d / c : %d\n", i, c);
		// 이제 끝부분에 r == H가 되어버림 그래서 이제는 c값을 이용하여 i와 동일한지 판단해야 함
		if(c != i) {
			printf("RETURN FALSE\n");
			return false;
		}
	} // the End of 모든 사다리 타고 다 자신과 동일한 위치에 도착
	printf("RETURN TRUE\n");
	return true; 
}


// 걍 dfs써서 (0,1,2,3)개의 가로선을 추가하였을 경우 각 모든 case마다 track()함수 이용해서 true반환되면 끝냅시다.
// 4개 이상써야 할 경우 '-1' 출력하셈~~~ 
int dfs(int count){
	printf("COUNT : %d\n", count);
	if(count == 4){
		printf("-1");
		return 0;
	}
	// 이전과는 달리 'count == 4' 가 아닌경우에는 추가할때마다  'bool track()' 요 함수 확! 돌려버린다!
	if(count != 0 && track()) {
		printf("%d", count);
		exit(0);
//		return 0;
	}
	
	int backup[30][19];
	// 1개->2개->3개(스택에 쌓으면서) 추가부터 시작
	for(int i = 1 ; i < (2*N - 2) ; i = i+2){
		for(int j = 0 ; j < H ; ++j){
			map_copy(backup, map);  // 뭔 짓하기 전에 이전것을 뺶업! 해놓는다. 
			int r_c = i+2;
			int l_c = i-2;
			if(map[j][i] == 1){
				continue;
			}
			if(1 <= r_c && r_c <= (2*N - 3) && map[j][r_c] == 1){
				continue;
			}
			if(1 <= l_c && l_c <= (2*N - 3) && map[j][l_c] == 1){
				continue;
			}			
			map[j][i] = 1;
			printf("ADD 1 (j : %d / i : %d )\n", j, i);
			dfs(count+1);
			map_copy(map, backup);
		}
	}
	 
}


int main() {
	scanf("%d %d %d", &N, &M, &H);
	for(int i = 0 ; i < M ; ++i){
		int a, b;
		scanf("%d %d", &a, &b);	  // (a,b) b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결
		map[a-1][2*b-1] = 1;
	}
	
	for(int i = 0 ; i < 30 ; ++i){
		printf("[");
		for(int j = 0 ; j < 19 ; ++j){
			printf("%d ", map[i][j]);
		}
		printf("]\n");
	}
	
	// 아무것도 안 추가해도 되는경우
	if(track()){
		printf("0");
		return 0;
	}
	// 이제부터는 최소한 1개의 사다리 추가하는 경우 
	dfs(0);
	return 0;
}
