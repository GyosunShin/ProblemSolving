// (1 ≤ N(R), M(C) ≤ 15)

// OUTPUT  
// 주어진 격자의 정보를 이용하여 설명한 조건을 만족하는 서로 다른 경로의 수를 계산하여 출력해야 한다. 

#include <cstdio>
#include <cstring>

int R, C, OR, OC, K, tr, tc;

const int dr[] = {1, 0};
const int dc[] = {0, 1};

int cache[15][15];

int dfs(int r, int c){
	if(r == (R-1) && c == (C-1))	return 1;
	
	int& ret = cache[r][c];
	if(ret != -1)	return ret;
	
	int sum = 0;
	
	for(int dir = 0 ; dir < 2; ++dir){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C)	continue;
		sum += dfs(next_r, next_c);
	}
	
	return ret = sum;
}

int main(){
	scanf("%d %d %d", &R, &C, &K);
	OR = R;	OC = C;
	
	if(K == 0){
		memset(cache, -1, sizeof(cache));
		printf("%d", dfs(0,0));
		return 0;
	}
	
	if(K != 0){
		if(K%C==0){
			tr = (K / C) - 1;
			tc = C-1;
		}
		else{
			tr = K / C;
			tc = (K % C)-1;
		}
	}
	
	memset(cache, -1, sizeof(cache));
	R = tr + 1;	C = tc + 1;
	int one = dfs(0,0);
	
	memset(cache, -1, sizeof(cache));
	R = OR;	C = OC;
	int two = dfs(tr, tc);
	
//	printf("TR : %d / TC : %d\n", tr, tc);
//	printf("ONE : %d / TWO : %d\n", one, two);
	
	printf("%d", one * two);
	
	return 0;
}
