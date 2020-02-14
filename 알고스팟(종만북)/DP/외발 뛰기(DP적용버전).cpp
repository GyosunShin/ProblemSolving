// 테스트 케이스의 수 C(C <= 50)
// 격자의 크기 n(2 <= n <= 100)

// 출력 : 각 테스트 케이스마다 한 줄로, 시작점에서 끝 점으로 도달할 수 있을 경우 "YES"를, 아닐 경우 "NO"를 출력합니다. (따옴표 제외) 

#include <stdio.h> 
#include <string.h>

int T, N;
int map[100][100];
int cache[100][100];

int solve(int r, int c){
	if(r == (N-1) && c == (N-1)){
		return 1;
	}
	if(0 > r || r >= N || 0 > c || c >= N)	return 0;
	
	int jmp = map[r][c];
	int& ret = cache[r][c];
	if(ret != -1)	return ret;
	ret = solve(r+jmp, c) || solve(r, c+jmp);
	return ret;
}

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		memset(map, 0, sizeof(map));
		memset(cache, -1, sizeof(cache));
		scanf("%d", &N);
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &map[i][j]);		
			}
		}
		
		int ans = solve(0, 0);
		if(ans == 1)	printf("YES\n");
		else	printf("NO\n");
	}
	
	return 0;
}


