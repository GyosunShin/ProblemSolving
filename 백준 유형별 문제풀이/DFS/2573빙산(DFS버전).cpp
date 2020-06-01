// (0 : �ٴ�) (1~ : ���� ����)

// OUTPUT
// �� ����� ������ �־��� ��, 
// �� ������ �� ��� �̻����� �и��Ǵ� ������ �ð�(��)�� ���ϴ� ���α׷��� �ۼ�

// !!!! ���� �� ���� ������ �� ��� �̻����� �и����� ������ ���α׷��� 0�� ����Ѵ�. !!!!

// 3 <= R, C <= 300

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int R, C;
int pan[300][300];
int backup[300][300];
bool visited[300][300];

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

void pt(){
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			printf("%d ", pan[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
}

void dfs(int cur_r, int cur_c){
	
	visited[cur_r][cur_c] = true;
	
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
		if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C
		|| visited[next_r][next_c] || pan[next_r][next_c] <= 0)	continue;
		dfs(next_r, next_c);
	}
}


int check(){
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	int flag = 0;
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			
			if(!visited[i][j] && pan[i][j] > 0){
				dfs(i, j);
				cnt++;
			}
			if(pan[i][j] > 0)	++flag;
		}
	}
	
	if(flag <= 0){
		return -1;
	}
	return cnt;
}

void melt(){
	
	for(int i = 0 ; i < R ; ++i)
		for(int j = 0 ; j < C ; ++j)
			backup[i][j] = pan[i][j];
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			if(backup[i][j] > 0){
				int tmp = 0;
				for(int dir = 0 ; dir < 4 ; ++dir){
					int next_r = i + dr[dir];	int next_c = j + dc[dir];
					if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C)	continue;
					if(backup[next_r][next_c] <= 0)	tmp++;
				}
				pan[i][j] -= tmp;
			}
		}
	}
	
}

int solve(){
	int ret = 0;
	
	while(true){
		int piece = check();
		if(piece == -1)	return 0;
		if(piece >= 2)	return ret;
		
		melt();
		
		ret++;
	}
	
	return ret;
}

int main(){
	scanf("%d %d", &R, &C);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	
	int ret = solve();
	printf("%d", ret);
	
	return 0;
}
