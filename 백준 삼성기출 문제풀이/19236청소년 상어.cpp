// 1 <= 각 번호 <= 16
// 8방향 (상하좌우, 대각선)

// 일단 [0,0]에 있는 물고기 먹고 해당 물고기의 방향을 갖게됨

// 물고기 이동시작(번호작은 물고기부터!) 
//     이동가능칸(다른 물고기 (or) 빈칸) 	
//		이동 불가능칸(상어있는 칸 (or) 경계넘는곳) 
//		반시계 45도로 이동가능할때까지 방향바꾸고 그래도 없으면 움직이지 않는다.
//		이동가능하게 되면 해당 자리에 있는 물고기와 자리를 Switch!!

// 이젠 상어이동 시작 

#include <cstdio>
#include <algorithm>

using namespace std;

struct FISH{
	int r, c;
	int dir;
	bool alive;
};

FISH fishes[17];	// 1 <= Idx <= 16

int num[4][4];

// ↑(0), ↖, ←, ↙, ↓, ↘, →, ↗(7) 
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, -1, -1, -1, 0, 1, 1, 1};

int answer;

void pt(){
	for(int i = 0 ; i < 4 ; ++i){
		for(int j = 0 ; j < 4 ; ++j){
			printf("%d ", num[i][j]);
		}
		printf("\n");
	}
}

bool rangeCheck(int r, int c){
	if(0 > r || r >= 4 || 0 > c || c >= 4)	return false;
	return true;
}

void fishMove(int (&arr)[4][4], FISH (&fishes)[17]){
	
	for(int i = 1 ; i <= 16 ; ++i){
		if(fishes[i].alive){
			int cur_r = fishes[i].r;	int cur_c = fishes[i].c;
			int cur_dir = fishes[i].dir;
			
			for(int n = 0 ; n < 8 ; ++n){
				int next_dir = (cur_dir + n) % 8;
				int next_r = cur_r + dr[next_dir];
				int next_c = cur_c + dc[next_dir];
				if(!rangeCheck(next_r, next_c) || arr[next_r][next_c] == -1)	continue;
				
				fishes[i].r = next_r;	fishes[i].c = next_c;
				fishes[i].dir = next_dir;
				
				int nextIdx = arr[next_r][next_c];
				fishes[nextIdx].r = cur_r;	fishes[nextIdx].c = cur_c;
				
				int tmp = arr[next_r][next_c];
				arr[next_r][next_c] = arr[cur_r][cur_c];
				arr[cur_r][cur_c] = tmp;
				
				break;
			}	
		}
	}
	
}

void dfs(int r, int c, int dir, int sofar, int (&arr)[4][4], FISH (&fish)[17]){
	
	int backup[4][4];
	for(int i = 0 ; i < 4 ; ++i){
		for(int j = 0 ; j < 4 ; ++j){
			backup[i][j] = arr[i][j];
		}
	}
	
	FISH fishesBackUp[17];
	for(int i = 1 ; i <= 16 ; ++i){
		fishesBackUp[i].alive = fish[i].alive;
		fishesBackUp[i].r = fish[i].r;	fishesBackUp[i].c = fish[i].c;
		fishesBackUp[i].dir = fish[i].dir;
	}
		
	// 물고기 이동시작 
	fishMove(backup, fishesBackUp);
	
	// 이젠 상어이동시작 
	// 그 칸에 있는 물고기를 먹고, 그 물고기의 방향을 가지게 된다 
	// 물고기가 없는 칸으로는 이동할 수 없다 
	// 상어가 이동할 수 있는 칸이 없으면 공간에서 벗어나 집으로 간다 
	int trycnt = 0;
	for(int k = 1 ; k <= 3; ++k){
		int next_r = r + (k * dr[dir]);	int next_c = c + (k * dc[dir]);
		if(!rangeCheck(next_r, next_c))	break;
				
		int target = backup[next_r][next_c];
		if(target == 0)	continue;
		
		int next_dir = fishesBackUp[target].dir;
		
		trycnt++;
		backup[r][c] = 0;
		backup[next_r][next_c] = -1;
		fishesBackUp[target].alive = false;
		dfs(next_r, next_c, next_dir, sofar + target, backup, fishesBackUp);
		fishesBackUp[target].alive = true;
		backup[next_r][next_c] = target;
		backup[r][c] = -1;
	}
	
	if(trycnt == 0)	answer = max(answer, sofar);
}

void solve(){
	// 일단 [0,0]으로 진입 
	int initialTarget = num[0][0];
	fishes[initialTarget].alive = false;
	int initialDir = fishes[initialTarget].dir;
	num[0][0] = -1;	// 상어 있는 칸이라고 표시 
	
	dfs(0, 0, initialDir, initialTarget, num, fishes);
}

int main(){
	
	for(int i = 0 ; i < 4 ; ++i){
		for(int j = 0 ; j < 4 ; ++j){
			int tmp_dir;
			scanf("%d %d", &num[i][j], &tmp_dir);
			tmp_dir--;
			fishes[num[i][j]].r = i;	fishes[num[i][j]].c = j;
			fishes[num[i][j]].dir = tmp_dir;
			fishes[num[i][j]].alive = true;
		}
	}

	solve(); 
	
	// OUTPUT
	// 상어가 먹을 수 있는 물고기 번호의 합의 최댓값
	printf("%d", answer);
	
	return 0;
}
