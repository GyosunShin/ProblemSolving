// 1 <= R, C <= 50
// 
// OUTPUT : ù° �ٿ� ����ġ�� ����� ���� �̵��� �� �ִ� ���� ���� �ð��� ����Ѵ�. 
// ����, �����ϰ� ����� ���� �̵��� �� ���ٸ�, "KAKTUS"�� ����Ѵ�.

#include <stdio.h>
#include <queue>

using namespace std;

struct INFO{
	int r, c, time;
	int type; // -1 : �� / 1 : ����ġ 
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
		if(cur.type==-1){  // ���� ��� 
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
		else if(cur.type==1){  // ����ġ�� ��� 
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
		scanf("%s", &map[i]);   // ����ִ� ���� '.'�� ǥ�õǾ� �ְ� / ���� ���ִ� ������ '*', 
		//���� 'X'�� ǥ�õǾ� �ִ�/ ����� ���� 'D'�� / ����ġ�� ��ġ�� 'S'�� ��Ÿ������ �ִ�.
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
