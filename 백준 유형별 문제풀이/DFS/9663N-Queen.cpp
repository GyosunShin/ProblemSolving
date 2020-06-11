// 1 ¡Â N < 15

#include <cstdio>
#include <cstring>

int N;
bool rowUsed[14];
bool colUsed[14];
int diagonalUsed[14][14];

int answer;

const int dr[] = {-1,-1,1,1};
const int dc[] = {-1,1,-1,1};

bool scopeCheck(int r, int c){
	if(0 > r || r >= N || 0 > c || c >= N)	return false;
	return true;
}

void diagonalMark(int r, int c){
	
	for(int dir = 0 ; dir < 4 ; ++dir){	
		int start_r = r + dr[dir];	int start_c = c + dc[dir];
		while(true){
			if(!scopeCheck(start_r, start_c))	break;
			diagonalUsed[start_r][start_c]++;
			start_r += dr[dir];	start_c += dc[dir];
		}	
	}
	
}

void unMark(int r, int c){
	
	for(int dir = 0 ; dir < 4 ; ++dir){	
		int start_r = r + dr[dir];	int start_c = c + dc[dir];
		while(true){
			if(!scopeCheck(start_r, start_c))	break;
			diagonalUsed[start_r][start_c]--;
			start_r += dr[dir];	start_c += dc[dir];
		}	
	}
	
}

int dfs(int r, int c, int sofar){
	
//	printf("[%d][%d] : %d\n", r, c, sofar);

	if(sofar == (N-1)){
		return 1;
	}
	
	int sum = 0;
	
	for(int i = r ; i < N ; ++i){
		for(int j = c ; j < N ; ++j){
			if(!rowUsed[i] && !colUsed[j] && diagonalUsed[i][j] <= 0){
				diagonalMark(i, j);
				rowUsed[i] = true;
				colUsed[j] = true;				
				sum += dfs(i, j, sofar+1);
				unMark(i, j);
				rowUsed[i] = false;
				colUsed[j] = false;								
			}
		}
		c = 0;
	}

	return sum;
}

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			rowUsed[i] = true;
			colUsed[j] = true;
			diagonalMark(i, j);
			answer += dfs(i, j, 0);
			rowUsed[i] = false;
			colUsed[j] = false;
			unMark(i, j);
		}
	}
	
	printf("%d", answer);
	
	return 0;
}
