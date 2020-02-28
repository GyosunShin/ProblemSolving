// (1 <= H,W <= 20) 
// # Àº °ËÀº Ä­, . ´Â Èò Ä­
// °ÔÀÓÆÇ¿¡ ÀÖ´Â Èò Ä­ÀÇ ¼ö´Â 50 À» ³ÑÁö ¾Ê½À´Ï´Ù.

#include <cstdio>

char pan[50][50];

int T, R, C;

const int dr[4][2] = {
	{1, 0},
	{1, 0},
	{1, 1},
	{1, 1}
};
const int dc[4][2] = {
	{0, 1},
	{1, 1},
	{0, 1},
	{-1, 0}	
};

int solve(int howmany){
	if(howmany == 0)	return 1;
	
	
//	for(int i = 0 ; i < R ; ++i){
//		for(int j = 0 ; j < C ; ++j){
//			printf("%c ", pan[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
	
	// ÁÂÃø ÃÖ»ó´Ü ÈòÄ­ Ã£¾Æ³õ±â
	int tr = -1;	int tc = -1;
	for(int i = 0 ; i < R ; ++i){
		if(tr != -1 && tc != -1)	break;
		for(int j = 0 ; j < C ; ++j){
			if(pan[i][j] == '.'){
				tr = i;	tc = j;
				break;
			}
		}	
	}
	
	int tmp_sum = 0;
	for(int i = 0 ; i < 4 ; ++i){
		int t1r = tr + dr[i][0];	int t1c = tc + dc[i][0];	int t2r = tr + dr[i][1];	int t2c = tc + dc[i][1];
		//3Ä­ÀÌ ¸ðµÎ ¹üÀ§ ³»¿¡ Á¸Àç && ¸ðµÎ ÈòÄ­ÀÌ¾î¾ß ÇÔ
		if(0 > t1r || t1r >= R || 0 > t1c || t1c >= C || 0 > t2r || t2r >= R || 0 > t2c || t2c >= C)	continue;
		if(pan[t1r][t1c] == '#' || pan[t2r][t2c] == '#')	continue;
		pan[tr][tc] = '#';	pan[t1r][t1c] = '#';	pan[t2r][t2c] = '#';
		tmp_sum += solve(howmany-3);
		pan[tr][tc] = '.';	pan[t1r][t1c] = '.';	pan[t2r][t2c] = '.';
	}
	
	return tmp_sum;	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		int left = 0;
		scanf("%d %d", &R, &C);
		for(int i = 0 ; i < R ; ++i){
			getchar();
			for(int j = 0 ; j < C ; ++j){
				scanf("%1c", &pan[i][j]);
				if(pan[i][j] == '.')	++left;
			}
		}
				
		int ans = solve(left);
		
		printf("%d\n", ans);
	}
	
	return 0;
}
