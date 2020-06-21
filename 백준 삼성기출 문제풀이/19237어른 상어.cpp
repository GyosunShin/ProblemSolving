// 1 <= 상어번호 <= M
// 1의 번호를 가진 어른 상어는 가장 강력해서 나머지 모두를 쫓아낼 수 있다.

// [작업과정]
// 일단 자신의 자리에서 냄새를 뿌린다.
// 1초마다 상하좌우 중 한칸으로 이동 후 거기서 냄새를 뿌린다.
// (냄새는 상어가 K번 이동하고 나면 없어진다.) 

// [이동방향 결정방법] 
// 1st) 아무 냄새가 없는 칸	
// !! 가능한 케이스가 여러개라면 특정 우선순위에 따른다 !!
// 2nd) 자신의 냄새가 있는 칸 
// !! 가능한 케이스가 여러개라면 특정 우선순위에 따른다 !!

// 한칸에 여러 상어 있으면 가장 작은 번호만 남겨놓는다. 


// INPUT
// 2 ≤ N ≤ 20		 2 ≤ M ≤ N^2	   1 ≤ k ≤ 1,000 

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct SHARK{
	int r, c;
	int dir;
	bool alive;
};

struct INFO{
	int who;
	int timeLeft;
};

SHARK sharks[401];

int pan[20][20];	 
INFO infos[20][20];

vector<int> nextLocation[20][20];

int pr[401][4][4];

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

int N, M, K;

void timeGo(){
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			infos[i][j].timeLeft--;
		}
	}
}

bool onlyOne(){
	for(int i = 1 ; i <= M ; ++i){
		if(sharks[i].alive && i != 1)		return false;
	}
	return true;
}

bool rangeCheck(int r, int c){
	if(0 > r || r >= N || 0 > c || c >= N)	return false;
	return true;
}

void sharkMove(){
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			nextLocation[i][j].clear();
		}
	}
	
	// INFO infos[][] : 냄새를 뿌린 후 기록 남기기용
	// int pan[][] : 실제 상어의 위치 표시하기 
	
	// [이동방향 결정방법] 
	// 1st) 아무 냄새가 없는 칸	
	// !! 가능한 케이스가 여러개라면 특정 우선순위에 따른다 !!
	// 2nd) 자신의 냄새가 있는 칸 
	// !! 가능한 케이스가 여러개라면 특정 우선순위에 따른다 !!	
	for(int i = 1 ; i <= M ; ++i){
		if(sharks[i].alive){
			int cur_r = sharks[i].r;	int cur_c = sharks[i].c;
			int cur_dir = sharks[i].dir;
			
			// 1st) 아무 냄새가 없는 칸	
			int emptyCnt = 0;
			int target_r = -1;	int target_c = -1;	int target_dir = cur_dir;
			for(int dir = 0 ; dir < 4 ; ++dir){
				int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
				if(!rangeCheck(next_r, next_c))	continue;
				if(infos[next_r][next_c].timeLeft > 0)	continue;
				emptyCnt++;
				target_r = next_r;	target_c = next_c;	target_dir = dir;
			}
			
			if(emptyCnt == 1){
				nextLocation[target_r][target_c].push_back(i);
				sharks[i].dir = target_dir;
				continue;
			}
			else if(emptyCnt > 1){
				for(int j = 0 ; j < 4 ; ++j){
					int dir = pr[i][cur_dir][j];
					int nr = cur_r + dr[dir];	int nc = cur_c + dc[dir];
					if(!rangeCheck(nr, nc))	continue;	
					if(infos[nr][nc].timeLeft > 0)	continue;
					target_r = nr;	target_c = nc;	target_dir = dir;
					break;
				}
				
				nextLocation[target_r][target_c].push_back(i);
				sharks[i].dir = target_dir;
				continue;
			}
			
			// 2nd) 자신의 냄새가 있는 칸 
			int myselfCnt = 0;
			for(int dir = 0 ; dir < 4 ; ++dir){
				int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
				if(!rangeCheck(next_r, next_c))	continue;
				if(infos[next_r][next_c].who != i)	continue;
				myselfCnt++;
				target_r = next_r;	target_c = next_c;	target_dir = dir;
			}			
			
			if(myselfCnt == 1){
				nextLocation[target_r][target_c].push_back(i);
				sharks[i].dir = target_dir;
				continue;
			}
			else if(myselfCnt > 1){
				for(int j = 0 ; j < 4 ; ++j){
					int dir = pr[i][cur_dir][j];
					int nr = cur_r + dr[dir];	int nc = cur_c + dc[dir];
					if(!rangeCheck(nr, nc))	continue;	
					if(infos[nr][nc].who != i)	continue;
					target_r = nr;	target_c = nc;	target_dir = dir;
					break;
				}
				
				nextLocation[target_r][target_c].push_back(i);
				sharks[i].dir = target_dir;
			}
		
		}
	}
	
}

void sharkLocationCheck(){
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if((int)nextLocation[i][j].size() == 1){
				int idx = nextLocation[i][j][0];
				infos[i][j].timeLeft = K;
				infos[i][j].who = idx;
				
				sharks[idx].r = i;	sharks[idx].c = j;
			}
			else if((int)nextLocation[i][j].size() > 1){
				int firstPr = 500;
				for(int k = 0 ; k < nextLocation[i][j].size() ; ++k){
					firstPr = min(firstPr, nextLocation[i][j][k]);
				}
				
				infos[i][j].timeLeft = K;
				infos[i][j].who = firstPr;
				
				sharks[firstPr].r = i;	sharks[firstPr].c = j;
				for(int k = 0 ; k < nextLocation[i][j].size() ; ++k){
					if(nextLocation[i][j][k] != firstPr){
						sharks[nextLocation[i][j][k]].alive = false;
					}
				}
				
			}
			else{
				infos[i][j].timeLeft--;
			}
		}
	}	
	
}

int solve(){
	// [작업과정]
	// 일단 자신의 자리에서 냄새를 뿌린다. --> 이미 INPUT받으면서 infos 2차원 배열에 표기함
	// 1초마다 상하좌우 중 한칸으로 이동 후 거기서 냄새를 뿌린다.
	// (냄새는 상어가 K번 이동하고 나면 없어진다.)
	
	int time = 0; 

	while(true){		
		// 이동작업 
		// 일단 vector[][] 에 각 상어의 Index만 push_back해 보자 
		sharkMove(); 
		
		// 중복된  상어 체크, 실제로 상어 이동시키고 냄새 뿌리기 && 시간 ++1
		sharkLocationCheck(); 
	
		time++;
		// 1,000초 넘으면 바로 작업 중단하고 -1 return 하기! 
		if(time > 1000)	return -1;
		
		if(onlyOne())	return time;
	}
	
	return time;
}

int main(){
	scanf("%d %d %d", &N, &M, &K);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &pan[i][j]);
			if(pan[i][j] > 0){
				sharks[pan[i][j]].r = i;	sharks[pan[i][j]].c = j;
				// 현재 자리에서 냄새 뿌리기
				infos[i][j].timeLeft = K;
				infos[i][j].who = pan[i][j];
			}
		}
	}
	
	// 각 상어의 초기방향 
	// (1 : 상)  (2 : 하) (3 : 좌) (4 : 우)
	for(int i = 1 ; i <= M ; ++i){
		scanf("%d", &sharks[i].dir);
		sharks[i].dir--;
		sharks[i].alive = true;
	}
	
	// 각 상어의 우선순위
	// 위
	// 아래
	// 왼쪽
	// 오른쪽 
	for(int i = 1 ; i <= M ; ++i){
		for(int j = 0 ; j < 4 ; ++j){
			scanf("%d %d %d %d", &pr[i][j][0], &pr[i][j][1], &pr[i][j][2], &pr[i][j][3]);
			pr[i][j][0]--;	pr[i][j][1]--;	pr[i][j][2]--;	pr[i][j][3]--;
		}
	}	 
	
	
	int answer = solve();
	
	printf("%d", answer);
	
	return 0;
}

 
