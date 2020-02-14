#include <stdio.h>

int n, k, m;
int map[101][101];

int head_y, head_x, tail_index;
int snake_y[10101], snake_x[10101];
char cmd[10001];

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main(){
	scanf("%d %d", &n, &k);
	
	int y, x;
	for(int i = 0 ; i < k ; ++i){ // 사과 위치 적어넣는듯 
		scanf("%d %d", &y, &x);
		map[y][x] = 1;
	}
	
	int time;
	char c;
	scanf("%d", &m);
	for(int i = 0 ; i < m ; ++i){
		scanf("%d %c", &time, &c);
		cmd[time] = c;
	}
}
