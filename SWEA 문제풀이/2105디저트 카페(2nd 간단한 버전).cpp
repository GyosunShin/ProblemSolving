// ����Ʈ�� ���� ���� ���� �� �ִ� ��θ� ã��, �� ���� ����Ʈ ���� �������� ����ϴ� ���α׷��� �ۼ��϶�.
// ����, ����Ʈ�� ���� �� ���� ��� -1�� ����Ѵ�.

//  (4 �� N �� 20)
//  1 <= ����Ʈ ���� <= 100

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, N;
int pan[20][20];

bool cache[101];

const int dr[] = {1, 1, -1, -1};
const int dc[] = {1, -1, -1, 1};

int global_r, global_c;

int ans = -1;

void dfs(int start_r, int start_c, int dir, int cnt){
	if(dir == 3 && start_r == global_r && start_c == global_c){
		ans = max(ans, cnt);
		return;
	}
	int next_r, next_c, next_dir;
	for(int i = 0 ; i < 2 ; ++i){
		if(i == 0){	// ���� �ٲٴ� �� 
			if(start_r == global_r && start_c == global_c)	continue;
			next_r = start_r + dr[dir+1];	next_c = start_c + dc[dir+1];
			next_dir = dir + 1;
		}
		else{  // ���� �ȹٲٰ� �״�� 
			next_r = start_r + dr[dir];	next_c = start_c + dc[dir];
			next_dir = dir;
		}
		
		if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N){
			continue;
		}
		
		if(next_r == global_r && next_c == global_c){
			dfs(next_r, next_c, next_dir, cnt + 1);
		}
		else{
			if(!cache[pan[next_r][next_c]]){
				cache[pan[next_r][next_c]] = true;
				dfs(next_r, next_c, next_dir, cnt + 1);
				cache[pan[next_r][next_c]] = false;
			}
		}	
	}
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		ans = -1;
		scanf("%d", &N);	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &pan[i][j]);		
			}
		}
		
		for(int i = 0 ; i < N-2 ; ++i){
			for(int j = 1 ; j < N-1 ; ++j){
				global_r = i;	global_c = j;
				cache[pan[i][j]] = true;
				dfs(i, j, 0, 0);
				cache[pan[i][j]] = false;
			}
		}
		
		printf("#%d %d\n", z, ans);
	}
	return 0;
}



