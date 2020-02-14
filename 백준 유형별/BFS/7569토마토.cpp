// 2 �� M(���� = COLUMN) �� 100, 2 �� N(���� : ROW) �� 100, 1 �� H �� 100
// 1: ���� �丶��/ 0 : ���� ���� �丶��/ -1: �� ĭ

// OUTPUT : ó������ ��� ���� : 0 / ���ΰ� ���� ���ϴ� case : -1 

#include <stdio.h>
#include <queue>

using namespace std;

struct INFO{
	int r, c, h, time;
};

int M, N, H;
int map[100][100][100];
int visited[100][100][100];

queue<INFO> q;

const int dh[] = {1, -1, 0, 0, 0, 0};
const int dr[] = {0, 0, -1, 1, 0, 0};
const int dc[] = {0, 0, 0, 0, -1, 1};

int count;
int ans;

void bfs(){
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		ans = cur.time;
//		printf("CUR_H : %d / CUR_R : %d / CUR_C : %d\n", cur.h, cur.r, cur.c);
		for(int dir = 0 ; dir < 6 ; ++dir){
			int next_h = cur.h + dh[dir];	int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
//			printf("NEXT_H : %d / NEXT_R : %d / NEXT_C : %d\n", next_h, next_r, next_c);
			if(0 > next_h || next_h >= H || 0 > next_r || next_r >= N || 0 > next_c || next_c >= M || visited[next_h][next_r][next_c] == 1 || map[next_h][next_r][next_c] == -1){
				continue;
			}
			visited[next_h][next_r][next_c] = 1;
			INFO next;
			next.h = next_h;	next.r = next_r;	next.c = next_c;	next.time = cur.time + 1;
			q.push(next);
			map[next_h][next_r][next_c] = 1;
			
			++count;
//			printf("+++++ COUNT : %d\n",count);
		}
//		printf("\n");
	}
}

int main(){
	int first_ans = 0;
	scanf("%d %d %d", &M, &N, &H);
	for(int i = 0 ; i < H ; ++i){
		for(int j = 0 ; j < N ; ++j){
			for(int k = 0 ; k < M ; ++k){
				scanf("%d", &map[i][j][k]);
				if(map[i][j][k] == 0)	++first_ans;
				else if(map[i][j][k] == 1){
					INFO tmp;
					tmp.h = i;	tmp.r = j;	tmp.c = k;	tmp.time = 0;
					q.push(tmp);
					visited[i][j][k] = 1;
				}
			}
		}
	}
	
	if(first_ans == 0){  // ���� ������ �ϳ��� �����ٸ� 
		printf("0");
		return 0;
	}
	//#####################################
	
	bfs();
	
	
	if(count == first_ans){  // ���� �� ����! 
//		printf("COuNT : %d / FIRST_ANS : %d\n", count, first_ans);
		printf("%d", ans);
		return 0;		
	}
	else{
		printf("-1");
		return 0;		
	}
}
