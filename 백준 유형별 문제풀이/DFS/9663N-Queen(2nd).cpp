// 1 ¡Â N < 15

#include <cstdio>
#include <cstring>

int N;
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

	if(sofar == (N-1)){
		return 1;
	}
	
	int sum = 0;
	
	for(int j = 0 ; j < N ; ++j){
		if(!colUsed[j] && diagonalUsed[r+1][j] <= 0){
			diagonalMark(r+1, j);
			colUsed[j] = true;
			sum += dfs(r+1, j, sofar+1);
			unMark(r+1, j);
			colUsed[j] = false;
		}
	}

	return sum;
}

int main(){
	scanf("%d", &N);
	
	for(int j = 0 ; j < N ; ++j){
		colUsed[j] = true;
		diagonalMark(0, j);
		answer += dfs(0, j, 0);
		colUsed[j] = false;
		unMark(0, j);
	}
	
	printf("%d", answer);
	
	return 0;
}
