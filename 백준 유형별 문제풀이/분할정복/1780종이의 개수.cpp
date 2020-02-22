// (1��N��3^7, N�� 3^k ��)

// OUTPUT : ù° �ٿ� -1�θ� ä���� ������ ������, ��° �ٿ� 0���θ� ä���� ������ ������, ��° �ٿ� 1�θ� ä���� ������ ������ ����Ѵ�.

#include <cstdio> 

int N;
int pan[2187][2187];
int minus, zero, one;

void solve(int len, int start_r, int start_c){
	
	// ������� 
	if(len == 1){
		if(pan[start_r][start_c] == -1)	++minus;
		else if(pan[start_r][start_c] == 0)	++zero;
		else if(pan[start_r][start_c] == 1)	++one;
		return;
	}
	
	// ���� ���̰� ��� ���� ���� �Ǿ� �ִٸ� �� ���̸� �״�� ����Ѵ�.
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
	
	// �ش� �κп� ���Ͽ� �ٽ� 9����
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

