// 학생의 수 n (2 <= n <= 10) 
// 친구 쌍의 수 m (0 <= m <= n*(n-1)/2)

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int T, N, M;

bool areFriends[10][10];	// 서로 친구인가를 확인하기 위한 2차원 배열 선언
bool taken[10];

int solve(int start, int cnt){
	if(cnt == (N/2))	return 1;
	
	int tmp_cnt = 0;
	
	for(int i = start ; i < N ; ++i){
		for(int j = i+1 ; j < N ; ++j){
			if(!taken[i] && !taken[j] && areFriends[i][j]){
				taken[i] = true;	taken[j] = true;
				tmp_cnt += solve(i+1, cnt+1);
				taken[i] = false;	taken[j] = false;				
			}
		}
	}
	
	return	tmp_cnt;
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		memset(areFriends, false, sizeof(areFriends));
		scanf("%d %d", &N, &M);
		for(int i = 0 ; i < M ; ++i){
			int x,y;
			scanf("%d %d", &x, &y);
			areFriends[x][y] = true; 	areFriends[y][x] = true; 
		}
		int ans = solve(0, 0);
		printf("%d\n", ans);
	}
	
	return 0;
}
