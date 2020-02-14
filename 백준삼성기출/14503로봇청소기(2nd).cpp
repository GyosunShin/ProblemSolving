//  (3 ≤ N, M ≤ 50)


// 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽
// (0 : 상) (1 : 우 ) (2 : 하) (3 : 좌)
// (0 : 빈칸) (1 : 벽)

#include <cstdio>

int map[50][50];
bool cleaned[50][50];
int R, C, start_r, start_c, start_dir;

// 상  우  하  좌 
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int dir_change[] = {3, 0, 1, 2};
const int back_r[] = {1, 0, -1, 0};
const int back_c[] = {0, -1, 0, 1};
const int left[4][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};

int ans;

	// OUTPUT : 로봇 청소기가 청소하는 칸의 개수를 출력한다.
	//현재 위치를 청소한다.
	//현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
		//왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
		//왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
		//네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
		//네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
void dfs(int r, int c, int dir){
	
//	printf("R : %d / C : %d\n", r, c);
	
	int cur_dir = dir;
	
	bool tmp_flag = true;
	for(int i = 0 ; i < 4 ; ++i){
		dir = dir_change[dir];
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		if(map[next_r][next_c] == 0 && !cleaned[next_r][next_c] && tmp_flag){
			++ans;
			cleaned[next_r][next_c] = true;
			dfs(next_r, next_c, dir);
			tmp_flag = false;
			break;
		}
	}
	
	if(tmp_flag){
		int b_r = r + back_r[dir];	int b_c = c + back_c[dir];
		if(map[b_r][b_c] == 1){
			// 작동을 멈춘다.
			return;
		}
		else{
			// 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
			dfs(b_r, b_c, dir);
		}
	}
}

int main(){
	scanf("%d %d", &R, &C);
	scanf("%d %d %d", &start_r, &start_c, &start_dir);
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%d", &map[i][j]);
		}
	}

	++ans;
	cleaned[start_r][start_c] = true;
	dfs(start_r, start_c, start_dir);
	
	printf("%d", ans);
	return 0;
}

