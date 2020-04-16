//  (2 ≤ R, C ≤ 20)

#include <cstdio>
#include <cstring>

int T, R, C;
char pan[20][20];
bool cache[20][20][4][16];

int memory;

// 상 하 좌  우  
const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

bool dfs(int r, int c, int dir){
	
//	printf("(%d / %d) [ %c ] %d : %d\n", r,c,pan[r][c], memory, dir);
	
	if(cache[r][c][dir][memory]){
//		cache[r][c][dir][memory] = false;
		return false;
	}
	
	cache[r][c][dir][memory] = true;
	
	int next_dir = dir;
	
	if(pan[r][c] == '<'){
		next_dir = 2;
	}
	else if(pan[r][c] == '>'){
		next_dir = 3;
	}
	else if(pan[r][c] == '^'){
		next_dir = 0;
	}
	else if(pan[r][c] == 'v'){
		next_dir = 1;
	}
	else if(pan[r][c] == '_'){
		if(memory == 0){
			next_dir = 3;	
		}
		else	next_dir = 2;	
	}
	else if(pan[r][c] == '|'){
		if(memory == 0){
			next_dir = 1;	
		}
		else	next_dir = 0;	
	}
	else if(pan[r][c] == '?'){	// 이동 방향을 상하좌우 중 하나로 무작위로 바꾼다. 방향이 바뀔 확률은 네 방향 동일하다.
		bool tmp_ret = false;
		
		int tmp_next_r[] = {r + dr[0],r + dr[1],r + dr[2],r + dr[3]};
		int tmp_next_c[] = {c + dc[0],c + dc[1],c + dc[2],c + dc[3]};
		
		for(int j = 0 ; j < 4 ; ++j){
			int next_tmp_r = tmp_next_r[j];	int next_tmp_c = tmp_next_c[j];
			if(next_tmp_c == C)	next_tmp_c = 0;
			if(next_tmp_c == -1)	next_tmp_c = C-1;
			if(next_tmp_r == R)	next_tmp_r = 0;
			if(next_tmp_r == -1)	next_tmp_r = R-1;
			
			tmp_ret |= dfs(next_tmp_r, next_tmp_c, j);	
		}
//		cache[r][c][dir][memory] = false;
		return tmp_ret;
	}	
	else if(pan[r][c] == '@'){
//		cache[r][c][dir][memory] = false;
		return true;
	}
	else if('0' <= pan[r][c] && pan[r][c] <= '9'){
		memory = pan[r][c] - '0';
	}
	else if(pan[r][c] == '+'){
		if(memory == 15)	memory = 0;
		else	memory++;
	}
	else if(pan[r][c] == '-'){
		if(memory == 0)	memory = 15;
		else	memory--;
	}
	
	int next_r = r + dr[next_dir];	int next_c = c + dc[next_dir];
	
	if(next_c == C)	next_c = 0;
	if(next_c == -1)	next_c = C-1;
	if(next_r == R)	next_r = 0;
	if(next_r == -1)	next_r = R-1;
	
	bool ret = dfs(next_r, next_c, next_dir);
//	cache[r][c][dir][memory] = false;
	return ret;
	
}

bool solve(){
	return dfs(0,0,3);
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1;  z <= T ; ++z){
		memset(cache, false, sizeof(cache));
		memory = 0;
		scanf("%d %d", &R, &C);	
		getchar();
		for(int i = 0 ; i < R ; ++i){
			for(int j = 0 ; j < C ; ++j){
				scanf("%1c", &pan[i][j]);
			}
			getchar();
		}
		
		if(solve()){
			printf("#%d YES\n", z);
		}
		else{
			printf("#%d NO\n", z);
		}
	}
	
	return 0;
}
