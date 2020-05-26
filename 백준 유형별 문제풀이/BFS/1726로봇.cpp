// 1 <= R, C <= 100

#include <cstdio> 
#include <cstring>
#include <queue>

using namespace std;

struct INFO{
	int r, c, d, sofar;
};

int R, C;
int pan[100][100];
bool visited[100][100][4];
int start_r, start_c, start_dir, end_r, end_c, end_dir;

const int dr[] = {0,0,1,-1};
const int dc[] = {1,-1,0,0};
const int change_dir[2][4] = {
	{3,2,0,1},	// left
	{2,3,1,0}	// righr
};

queue<INFO> q;

bool range_check(int sr, int sc, int er, int ec, int dir){
	if(0 > er || er >= R || 0 > ec || ec >= C)	return false;
	if(pan[er][ec] == 1)	return false;
	
	while(true){
		sr += dr[dir];	sc += dc[dir];
		if(sr == er && sc == ec)	break;
		if(pan[sr][sc] == 1)	return false;
	}
	
	return true;
}

// Go k(1,2,3)
// Turn dir(left, right)
int solve(){

	visited[start_r][start_c][start_dir] = true;
	INFO start = {start_r, start_c, start_dir, 0};
	q.push(start);
	
	while(!q.empty()){
		int cur_r = q.front().r;	int cur_c = q.front().c;
		int cur_dir = q.front().d;	int cur_sofar = q.front().sofar;
		q.pop();
		
//		printf("[%d, %d] : %d / %d\n", cur_r, cur_c, cur_dir, cur_sofar);
		
		if(cur_r == end_r && cur_c == end_c && cur_dir == end_dir)	return cur_sofar;
		
		int next_r;	int next_c;	int next_dir = cur_dir;	int next_sofar = cur_sofar + 1;
		
		for(int jump = 1 ; jump < 4 ; ++jump){
			next_r = cur_r + (dr[cur_dir] * jump);	next_c = cur_c + (dc[cur_dir] * jump);
			if(!range_check(cur_r, cur_c, next_r, next_c, cur_dir))	continue;
			if(visited[next_r][next_c][next_dir])	continue;
			visited[next_r][next_c][next_dir] = true;
			INFO next = {next_r, next_c, next_dir, next_sofar};
			q.push(next);
		}
		
		for(int dir = 0 ; dir < 2 ; ++dir){	// left, right
			next_r = cur_r;	next_c = cur_c;	next_dir = change_dir[dir][cur_dir];
			if(visited[next_r][next_c][next_dir])	continue;
			visited[next_r][next_c][next_dir] = true;
			INFO next = {next_r, next_c, next_dir, next_sofar};
			q.push(next);
		}
	}
	
	return -1;
}

int main(){
	memset(visited, false, sizeof(visited));
	scanf("%d %d", &R, &C);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	
	// ������ 1, ������ 2, ������ 3, ������ 4
	scanf("%d %d %d", &start_r, &start_c, &start_dir);
	scanf("%d %d %d", &end_r, &end_c, &end_dir);
	start_r--;	start_c--;	start_dir--;
	end_r--;	end_c--;	end_dir--;
	
	int ret = solve();
	
	// OUTPUT 
	// ù° �ٿ� �κ��� ���� ������ ���ϴ� �������� �̵���Ű�µ� �ʿ��� �ּ� ��� Ƚ���� ����Ѵ�.
	printf("%d", ret);
	
	return 0;
}
