// 2 �� M,N �� 1,000
//  1�� ���� �丶��, ���� 0�� ���� ���� �丶��, ���� -1�� �丶�䰡 ������� ���� ĭ

// OUTPUt :  ����, ����� ������ ��� �丶�䰡 �;��ִ� �����̸� 0�� ����ؾ� �ϰ�, �丶�䰡 ��� ������ ���ϴ� ��Ȳ�̸� -1�� ����ؾ� �Ѵ�.

#include <stdio.h>
#include <queue>

using namespace std;

struct INFO{
	int r, c, time;
};

int R, C;
int map[1000][1000];
int visited[1000][1000];

queue<INFO> q;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int ans = 0;

void bfs(){
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		int cur_time = cur.time;
		ans = cur_time;
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || visited[next_r][next_c] == 1 || map[next_r][next_c] != 0){
				continue;
			}
			visited[next_r][next_c] = 1;
			map[next_r][next_c] = 1;
			INFO next;
			next.r = next_r;	next.c = next_c;	next.time = cur_time + 1;
			q.push(next);
		}
		
	}
	
}

int main(){
	scanf("%d %d", &C, &R);
	bool flag = true;
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1){
				INFO tmp;
				tmp.r = i;	tmp.c = j;	tmp.time = 0;
				q.push(tmp);
			}
			if(map[i][j] == 0){
				flag = false;
			}
		}
	}
	
	if(flag){
		printf("0");
		return 0;	
	}
	
	
	bfs();
	
	bool check = false;
	for(int i = 0 ; i < R ; ++i){
		if(check)	break;
		for(int j = 0 ; j < C ; ++j){
			if(map[i][j] == 0){
				check = true;
				break;
			}
		}
	}
	
	if(check){
		printf("-1");
	}
	else{
		printf("%d", ans);
	}
	return 0;	
}


