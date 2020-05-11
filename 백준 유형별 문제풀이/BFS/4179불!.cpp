// 1 ≤ R, C ≤ 1000
// #: 벽
// .: 지나갈 수 있는 공간
// J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
// F: 불이난 공간 

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int R, C;
char pan[1000][1000];
int fire[1000][1000];
int jiwhoon[1000][1000];
int start_r, start_c;

queue<pair<int, pair<int, int>>> fires;

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

void fire_spread(){
	
	while(!fires.empty()){
		int cur_time = fires.front().first;
		int cur_r = fires.front().second.first;	int cur_c = fires.front().second.second;
		fires.pop();
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];	int next_time = cur_time + 1;
			
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C
			|| fire[next_r][next_c] != -1 || pan[next_r][next_c] == '#')	continue;
			
			fires.push(make_pair(next_time, make_pair(next_r, next_c)));
			fire[next_r][next_c] = next_time;
		}
	}
	
}

void jiwhoon_spread(){
	
	fires.push(make_pair(0, make_pair(start_r, start_c)));
	
	while(!fires.empty()){
		int cur_time = fires.front().first;
		int cur_r = fires.front().second.first;	int cur_c = fires.front().second.second;
		fires.pop();
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];	int next_time = cur_time + 1;
			
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C
			|| jiwhoon[next_r][next_c] != -1 || pan[next_r][next_c] == '#')	continue;
			
			fires.push(make_pair(next_time, make_pair(next_r, next_c)));
			jiwhoon[next_r][next_c] = next_time;
		}
	}	
	
}


int main(){	
	int fire_cnt = 0;

	memset(fire, -1, sizeof(fire));
	memset(jiwhoon, -1, sizeof(jiwhoon));

	scanf("%d %d", &R, &C);
	getchar();
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%1c", &pan[i][j]);
			if(pan[i][j] == 'J'){
				start_r = i;	start_c = j;
				jiwhoon[i][j] = 0;
			}
			else if(pan[i][j] == 'F'){
				fire_cnt++;
				fires.push(make_pair(0, make_pair(i,j)));
				fire[i][j] = 0;
			}
		}
		getchar();
	}
	
	if(start_r == 0 || start_r == R-1 || start_c == 0 || start_c == C-1){
		printf("1");
		return 0;
	}
	
	fire_spread();
	jiwhoon_spread();
	
//	for(int i = 0 ; i < R ; ++i){
//		for(int j = 0 ; j < C ; ++j){
//			printf("%d ", fire[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	
//	for(int i = 0 ; i < R ; ++i){
//		for(int j = 0 ; j < C ; ++j){
//			printf("%d ", jiwhoon[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");	
	
	// IMPOSSIBLE (or) 가장 빠은 탈출시간 
	
	// (jiwhoon[][] < fire[][])이용 
	int mmin = 0x7fffffff;
	
	if(fire_cnt == 0){
		for(int i = 0 ; i < C ; ++i){
			if(pan[0][i] != '#'){
				mmin = min(mmin, jiwhoon[0][i] + 1);
			}
		}
		for(int i = 0 ; i < C ; ++i){
			if(pan[R-1][i] != '#'){
				mmin = min(mmin, jiwhoon[R-1][i] + 1);
			}
		}
		for(int i = 0 ; i < R ; ++i){
			if(pan[i][0] != '#'){
				mmin = min(mmin, jiwhoon[i][0] + 1);
			}
		}
		for(int i = 0 ; i < R ; ++i){
			if(pan[i][C-1] != '#'){
				mmin = min(mmin, jiwhoon[i][C-1] + 1);
			}
		}		
	}
	else{
		for(int i = 0 ; i < C ; ++i){
			if(pan[0][i] != '#' && (jiwhoon[0][i] < fire[0][i])){
				mmin = min(mmin, jiwhoon[0][i] + 1);
			}
		}
		for(int i = 0 ; i < C ; ++i){
			if(pan[R-1][i] != '#' && (jiwhoon[R-1][i] < fire[R-1][i])){
				mmin = min(mmin, jiwhoon[R-1][i] + 1);
			}
		}
		for(int i = 0 ; i < R ; ++i){
			if(pan[i][0] != '#' && (jiwhoon[i][0] < fire[i][0])){
				mmin = min(mmin, jiwhoon[i][0] + 1);
			}
		}
		for(int i = 0 ; i < R ; ++i){
			if(pan[i][C-1] != '#' && (jiwhoon[i][C-1] < fire[i][C-1])){
				mmin = min(mmin, jiwhoon[i][C-1] + 1);
			}
		}
	}

	if(mmin == 0x7fffffff)	printf("IMPOSSIBLE");
	else	printf("%d", mmin);
	
	return 0;
}

