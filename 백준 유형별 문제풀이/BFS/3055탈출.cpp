// 1 <= R, C <= 50
// 
// OUTPUT : 첫째 줄에 고슴도치가 비버의 굴로 이동할 수 있는 가장 빠른 시간을 출력한다. 
// 만약, 안전하게 비버의 굴로 이동할 수 없다면, "KAKTUS"를 출력한다.

#include <stdio.h>
#include <queue>

using namespace std;

struct INFO{
	int r, c, time;
	int type; // -1 : 물 / 1 : 고슴도치 
};

int R, C;
char map[50][51];
int visited[50][50];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int start_r, start_c;

queue<INFO> q;

int ans;


bool bfs(){
	while(!q.empty()){
		for(int i = 0 ; i < R ; ++i){
			for(int j = 0 ; j < C ; ++j){
				printf("%c ", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		
		
		INFO cur = q.front();	q.pop();
		if(cur.type==-1){  // 물인 경우 
			for(int dir = 0 ; dir < 4 ; ++dir){
				int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
				if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || map[next_r][next_c] == 'X' || map[next_r][next_c] == 'D' || visited[next_r][next_c] != 0){
					continue; 
				}
				visited[next_r][next_c] = 1;	map[next_r][next_c] = '*';
				INFO tmp;	tmp.r = next_r;	tmp.c = next_c;	tmp.time = cur.time + 1;	tmp.type = -1;
				q.push(tmp);
			}
		}
		else if(cur.type==1){  // 고슴도치인 경우 
			for(int dir = 0 ; dir < 4 ; ++dir){
				int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
				if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || map[next_r][next_c] == 'X' || map[next_r][next_c] == '*'|| visited[next_r][next_c] != 0){
					continue; 
				}
				visited[next_r][next_c] = 1;	
//				map[next_r][next_c] = '*';
				INFO tmp;	tmp.r = next_r;	tmp.c = next_c;	tmp.time = cur.time + 1;	tmp.type = 1;
				q.push(tmp);
				if(map[next_r][next_c] == 'D'){
					ans = tmp.time;
					return true;
				}
			}			
		}
	}
	return false;
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i = 0 ; i < R ; ++i){
		scanf("%s", &map[i]);   // 비어있는 곳은 '.'로 표시되어 있고 / 물이 차있는 지역은 '*', 
		//돌은 'X'로 표시되어 있다/ 비버의 굴은 'D'로 / 고슴도치의 위치는 'S'로 나타내어져 있다.
		for(int j = 0 ; j < C ; ++j){
			if(map[i][j] == 'S'){
				start_r = i;	start_c = j;
				visited[i][j] = 1;
			}
			if(map[i][j] == '*'){
				INFO tmp;
				tmp.r = i;	tmp.c = j;	tmp.type = -1;	tmp.time = 0;
				q.push(tmp);
				visited[i][j] = 1;
			}			
		}
	}
	INFO start;
	start.r = start_r;	start.c = start_c;	start.time = 0;	start.type = 1;
	q.push(start);
	//############################################################################################
	
	if(bfs()){
		printf("%d", ans);
	}
	else{
		printf("KAKTUS");
	}
	
	
	return 0;
}
