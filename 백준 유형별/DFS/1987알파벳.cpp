// 좌측 상단(1행 1열)에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 
// 말이 지나는 칸은 좌측 상단의 칸도 포함된다.
//  (1<=R,C<=20)

#include <stdio.h>

int R, C;
char map[20][21];

const int dr[] = {-1 , 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int cache[26];  // A B ~ Z(26개)

int ans = (-1 * 0x7fffffff);

void dfs(int cnt, int r, int c){
	if(cnt > ans)	ans = cnt;
	
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || cache[map[next_r][next_c] - 'A'] > 0) {
			continue;
		}
		cache[map[next_r][next_c] - 'A'] = 1;
		dfs(cnt + 1, next_r, next_c);
		cache[map[next_r][next_c] - 'A'] = 0;
	}
	
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i = 0 ; i < R ; ++i){
			scanf("%s", &map[i]);
	}
	
	cache[map[0][0] - 'A'] = 1;
	
	dfs(1, 0, 0);
	
	printf("%d", ans);
	return 0;
}

