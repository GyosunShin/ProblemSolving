/* BFS를 이용해서 로봇청소기의 움직임을 구현해야 할 듯 */

//(3 ≤ N, M ≤ 50)
//로못청소기 (r, c)  | 0:북 1:동 2:남 3:서
//0:빈칸 1:벽
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int r, c, dir;
int map[50][50];
int cleaned[50][50] = { 0, };
int ans = 0;

int check = 0;

// 상 하 좌 우 
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

queue<pair<int, int> > q;

void bfs(){
	// 일단 이미 start점은 queue.push()된 상태 
	
	while(!q.empty()){
		printf("ONCE!!  %d\n", ans);
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		printf("r : %d , c : %d\n", cur_r, cur_c);
		printf("check : %d\n", check);
		q.pop();		
		int next_dir = -1;
		int next_r, next_c; 
		int back_r, back_c; 
		
		// 0:북 1:동 2:남 3:서
		if(dir == 0){ // 북 -> 서=좌(2) 
			next_r = cur_r + dr[2]; 
			next_c = cur_c + dc[2];
			back_r = cur_r + dr[1];  // 북 -> 남=하(1) 
			back_c = cur_c + dc[1];
			next_dir = 3;
		}
		else if(dir == 1){ // 동 -> 북=상(0) 
			next_r = cur_r + dr[0]; 
			next_c = cur_c + dc[0];
			back_r = cur_r + dr[2];  // 동 -> 서=좌(2) 
			back_c = cur_c + dc[2];
			next_dir = 0;
		}
		else if(dir == 2){ // 남 -> 동=우(3) 
			next_r = cur_r + dr[3]; 
			next_c = cur_c + dc[3];
			back_r = cur_r + dr[0];  // 남 -> 북=상(0) 
 			back_c = cur_c + dc[0];
			next_dir = 1;
		}		
		else if(dir == 3){ // 서 -> 남=하(1) 
			next_r = cur_r + dr[1]; 
			next_c = cur_c + dc[1];
			back_r = cur_r + dr[3];   // 서 -> 동=우(3) 
			back_c = cur_c + dc[3];
			next_dir = 2;
		}		
		printf("next_r : %d , next_c : %d\n", next_r, next_c);
		
		// 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 '후진'을 하고 2번으로 돌아간다.
		if(check == 4 && map[back_r][back_c] != 1){
			printf("BACK!!\n");
			q.push(pair<int, int>(back_r, back_c));
			check = 0;
		}
		// 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
		else if(check == 4 && map[back_r][back_c] == 1){
			printf("END   : %d\n", ans);
			check = 0;
			return;
		}		
		// 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
		else if(map[next_r][next_c] == 0 && cleaned[next_r][next_c] != 1) {
			cleaned[cur_r][cur_c] = 1;
			printf("CLEAN!!\n");
			++ans;
			dir = next_dir;
			q.push(pair<int, int>(next_r, next_c));
			check = 0;
		}
		// 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
		else if(map[next_r][next_c] == 1 || cleaned[next_r][next_c] == 1){
			printf("ROTATE!!!!\n");
			dir = next_dir;
			q.push(pair<int, int>(cur_r, cur_c));
			++check; // 이거 4번 돌면 4방향 전부 불 
			
			
		}
		printf("\n");
	}
}
 
int main(){
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &dir);   // dir --> 0:북 1:동 2:남 3:서
	cleaned[r][c] = 1;
	++ans;
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	// ------------ 여기까지 입력 끝 -------------
	q.push(pair<int, int>(r,c));
	bfs();
	printf("%d", ans);
}
 
