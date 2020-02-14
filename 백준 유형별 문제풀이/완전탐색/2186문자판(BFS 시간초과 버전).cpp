// N(1 ¡Â N ¡Â 100), M(1 ¡Â M ¡Â 100), K(1 ¡Â K ¡Â 5)

#include <stdio.h> 
#include <string.h>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

struct INFO{
	int r, c;
	string track;
};
queue<INFO> q;

int R, C, K;
char map[100][100];
string target;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int ans;

void bfs(){
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		
//		cout << "CUR : " << cur.track << endl;
		
		if(cur.track == target){
			++ans;
			continue;
		}
		
		char next_target = target[cur.track.size()];
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			for(int walk = 1 ; walk <= K ; ++walk){
				
				int next_r = cur.r + (dr[dir] * walk);	int next_c = cur.c + (dc[dir] * walk);
				if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || map[next_r][next_c] != next_target)	continue;
				INFO next;
				next.r = next_r;	next.c = next_c;	next.track = cur.track + next_target;
				q.push(next);
				
			}
		}
	}
	
}

int main(){
	scanf("%d %d %d", &R, &C, &K);
	getchar();
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%1c", &map[i][j]);
		}
		getchar();
	}
	cin >> target;
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			if(map[i][j] == target[0]){
				INFO start;
				start.r = i;	start.c = j;	start.track += map[i][j];
				q.push(start);
			}
		}
	}
	
	bfs();
	
	printf("%d", ans);
	
	return 0;
}
