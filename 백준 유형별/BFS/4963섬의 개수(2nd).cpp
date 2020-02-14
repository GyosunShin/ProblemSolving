// w, h <= 50
// (1 : 땅) (0 : 바다)

// 대각선도 가능!

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

struct INFO{
	int r, c;
};

int w,h;
int map[50][50];
int visited[50][50];

const int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

queue<INFO> q;

void bfs(){
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		
		for(int i = 0 ; i < 8 ; ++i){
			INFO next;
			next.r = cur.r + dr[i];	next.c = cur.c + dc[i];
			if(0 > next.r || next.r >= h || 0 > next.c || next.c >= w || visited[next.r][next.c] != 0 || map[next.r][next.c] != 1)	continue;
			visited[next.r][next.c] = 1;
			q.push(next);
		}
	}
	
}

int main(){
	
	while(1){
		scanf("%d %d", &w, &h);
		if(w == 0  && h == 0)	break;
		memset(visited, 0, sizeof(visited));
		int ans = 0;
		q.empty();
		for(int i = 0 ; i < h ; ++i){
			for(int j = 0 ; j < w ; ++j){
				scanf("%d", &map[i][j]);		
			}
		}
		
		for(int i = 0 ; i < h ; ++i){
			for(int j = 0 ; j < w ; ++j){
				if(visited[i][j] == 0 && map[i][j] == 1){
					visited[i][j] = 1;
					INFO start;	start.r = i;	start.c = j;
					q.push(start);
					bfs();
					++ans;
				}
			}
		}
		
		printf("%d\n", ans);
		
	}
	return 0;
}

