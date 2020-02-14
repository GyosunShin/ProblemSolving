// w, h <= 50
// 1은 땅, 0은 바다이다.
// 0 0 입력되면 끝! 

// OUTPUT : 각 테스트 케이스에 대해서, 섬의 개수를 출력한다.

#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct INFO{
	int r, c;
};

vector<INFO> v;

int map[50][50];
int visited[50][50] = { 0, };

const int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

int R, C;

int dfs(){
	int tmp_ans = 0;
	
	for(int i = 0 ; i < v.size() ; ++i){
		int cur_r = v[i].r;	int cur_c = v[i].c;
		if(visited[cur_r][cur_c] != 0){
			continue;
		}
		else{
			visited[cur_r][cur_c] = 1;
			++tmp_ans;
		}
		
		// BFS 시작! 
		queue<INFO> q;
		q.push(v[i]);
		
		while(!q.empty()){
			INFO cur = q.front();	q.pop();
			for(int dir = 0 ; dir < 8 ; ++dir){
				int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
				if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || visited[next_r][next_c] != 0 || map[next_r][next_c] == 0)	continue;
				visited[next_r][next_c] = 1;
				INFO next;
				next.r = next_r;	next.c = next_c;
				q.push(next);
			}
		}
		
	}
	
	return tmp_ans;
}



int main(){
	while(1){
		int w,h;
		memset(visited, 0, sizeof(visited));
		v.clear();
		scanf("%d %d", &w, &h);  // (w = C / h = R)
		if(w == 0 && h == 0)	break;
		R = h;	C = w;
		
		for(int i = 0 ; i < h ; ++i){
			for(int j = 0 ; j < w ; ++j){
				scanf("%d", &map[i][j]);
				if(map[i][j] == 1){
					INFO tmp;	 tmp.r = i;	tmp.c = j;
					v.push_back(tmp);
				}
			}
		}
		//###################################
		
		int ans = dfs();
		printf("%d\n", ans);
	}
	
	return 0;
}

