// 두 정수 N, M (3 ≤ N, M ≤ 10)
// '.', '#', 'O', 'R', 'B'
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct INFO{
	int red_r;
	int red_c;
	int blue_r;
	int blue_c;
	int len;
};
queue<INFO> q;

int N, M;

char map[10][11];
int visited[10][10][10][10];

int ans = -1;

int dr[] = {-1, 1, 0, 0};  // 상 하 좌 우 
int dc[] = {0, 0, -1, 1};

void bfs(){
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
	//		printf("CUR_RED_R : %d / CUR_RED_C : %d / char : %c\n", cur.red_r, cur.red_c, map[cur.red_r][cur.red_c]);
	//		printf("CUR_BLUE_R : %d / CUR_BLUE_C : %d / char : %c\n", cur.blue_r, cur.blue_c, map[cur.blue_r][cur.blue_c]);
	//		printf("CUR_LEN : %d\n", cur.len);
		if(cur.len > 10){
			ans = -1;
			break;
		}
		if(map[cur.red_r][cur.red_c] == 'O' && map[cur.blue_r][cur.blue_c] != 'O'){
//			printf("ONLY RED!\n");
			ans = cur.len;
			break;
		}
		
		for(int i = 0 ; i < 4 ; ++i){
			int tmp_red_r = cur.red_r;
			int tmp_red_c = cur.red_c;
			int tmp_blue_r = cur.blue_r;
			int tmp_blue_c = cur.blue_c;
			int tmp_len = cur.len;
			
			int red_dist = 0;
			int blue_dist = 0;
			
			// 일단 red먼저 움직인다 
			while(map[tmp_red_r][tmp_red_c] != '#' && map[tmp_red_r][tmp_red_c] != 'O'){
				tmp_red_r = tmp_red_r + dr[i];
				tmp_red_c = tmp_red_c + dc[i];
				++red_dist;
			}
			if(map[tmp_red_r][tmp_red_c] == '#'){
				tmp_red_r = tmp_red_r - dr[i];
				tmp_red_c = tmp_red_c - dc[i];				
				--red_dist;
			}

			// 이번엔 blue 움직인다 
			while(map[tmp_blue_r][tmp_blue_c] != '#' && map[tmp_blue_r][tmp_blue_c] != 'O'){
				tmp_blue_r = tmp_blue_r + dr[i];
				tmp_blue_c = tmp_blue_c + dc[i];
				++blue_dist;
			}
			if(map[tmp_blue_r][tmp_blue_c] == '#'){
				tmp_blue_r = tmp_blue_r - dr[i];
				tmp_blue_c = tmp_blue_c - dc[i];								
				--blue_dist;
			}
			
			
			// 이제 red랑 blue 충돌검사에 따른 예외처리!
			if(tmp_red_r == tmp_blue_r && tmp_red_c == tmp_blue_c){
				if(map[tmp_red_r][tmp_red_c] != 'O'){
					if(red_dist > blue_dist){  // 더 많이 걸어온놈을 후퇴! 
//						printf("RED  BACK!!\n");
						tmp_red_r = tmp_red_r - dr[i];
						tmp_red_c = tmp_red_c - dc[i];						
					}
					else{
//						printf("BLUE  BACK!!\n");
						tmp_blue_r = tmp_blue_r - dr[i];
						tmp_blue_c = tmp_blue_c - dc[i];											
					}
				}
			}
			
			INFO next;
			next.red_r = tmp_red_r;
			next.red_c = tmp_red_c;
			next.blue_r = tmp_blue_r;
			next.blue_c = tmp_blue_c;
			next.len = tmp_len + 1;
			if(visited[next.red_r][next.red_c][next.blue_r][next.blue_c] == 0){
//				printf("CHECKED!\n");
//				printf("NEXT_RED_R : %d / NEXT_RED_C : %d\n", next.red_r, next.red_c);
//				printf("NEXT_BLUE_R : %d / NEXT_BLUE_C : %d\n\n", next.blue_r, next.blue_c);				
				visited[next.red_r][next.red_c][next.blue_r][next.blue_c] = 1;
				q.push(next);		
			}
			
			
		} // The End of 4 DIRs! 
	}
	
}


int main(){
	INFO start;
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		scanf("%s", map[i]);
		for(int j = 0 ; j < M ; ++j){
			if(map[i][j] == 'R'){
				start.red_r = i;
				start.red_c = j;
			}
			if(map[i][j] == 'B'){
				start.blue_r = i;
				start.blue_c = j;
			}			
		}
	}
	start.len = 0;
	q.push(start);
	visited[start.red_r][start.red_c][start.blue_r][start.blue_c] = 1;
	//########################################
	
	bfs();
	printf("%d", ans);
	return 0;	
}
