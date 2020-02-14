// 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.

//(1<=R,C<=20) 

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int R, C;
char map[20][20];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

bool cache[26];

int dfs(int r, int c){
	int sum = 0;
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || cache[map[next_r][next_c] - 'A'])	continue;
		cache[map[next_r][next_c] - 'A'] = true;
		sum = max(dfs(next_r, next_c) + 1, sum);
		cache[map[next_r][next_c] - 'A'] = false;
	}
	return sum;
}

int main(){
	scanf("%d %d", &R, &C);
	getchar();
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%1c", &map[i][j]);
		}
		getchar();
	}
	
	cache[map[0][0] - 'A'] = true;
	
	printf("%d", dfs(0, 0) + 1);
	
	return 0;
}
