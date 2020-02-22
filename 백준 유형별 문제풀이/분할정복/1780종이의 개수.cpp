// (1≤N≤3^7, N은 3^k 꼴)

// OUTPUT : 첫째 줄에 -1로만 채워진 종이의 개수를, 둘째 줄에 0으로만 채워진 종이의 개수를, 셋째 줄에 1로만 채워진 종이의 개수를 출력한다.

#include <cstdio> 

int N;
int pan[2187][2187];
int minus, zero, one;

void solve(int len, int start_r, int start_c){
	
	// 기저사례 
	if(len == 1){
		if(pan[start_r][start_c] == -1)	++minus;
		else if(pan[start_r][start_c] == 0)	++zero;
		else if(pan[start_r][start_c] == 1)	++one;
		return;
	}
	
	// 만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
	bool minus_flag = true;	bool zero_flag = true;	bool one_flag = true;
	for(int i = 0 ; i < len ; ++i){
		for(int j = 0 ; j < len ; ++j){
			if(pan[start_r + i][start_c + j] == -1){
				zero_flag = false;
				one_flag = false;
			}
			else if(pan[start_r + i][start_c + j] == 0){
				minus_flag = false;
				one_flag = false;
			}
			else if(pan[start_r + i][start_c + j] == 1){
				minus_flag = false;
				zero_flag = false;
			}
		}
	}
	
	if(minus_flag){
		++minus;
		return;
	}
	else if(zero_flag){
		++zero;
		return;
	}
	else if(one_flag){
		++one;
		return;
	}
	
	// 해당 부분에 대하여 다시 9분할
	int new_len = len / 3;
	solve(new_len, start_r, start_c); 
	solve(new_len, start_r, start_c + new_len); 
	solve(new_len, start_r, start_c + new_len + new_len); 
	
	solve(new_len, start_r + new_len, start_c); 
	solve(new_len, start_r + new_len, start_c + new_len); 
	solve(new_len, start_r + new_len, start_c + new_len + new_len); 
	
	solve(new_len, start_r + new_len + new_len, start_c); 
	solve(new_len, start_r + new_len + new_len, start_c + new_len); 
	solve(new_len, start_r + new_len + new_len, start_c + new_len + new_len); 
}

int main(){
	
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){	
			scanf("%d", &pan[i][j]);	
		}
	}
	
	solve(N, 0, 0);
	
	printf("%d\n%d\n%d", minus, zero, one);
	
	return 0;
}

