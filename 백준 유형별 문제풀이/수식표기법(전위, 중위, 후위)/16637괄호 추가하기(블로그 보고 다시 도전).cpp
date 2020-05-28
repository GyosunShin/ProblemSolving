 // 괄호를 적절히 추가해 만들 수 있는 식의 결과의 최댓값을 구하는 프로그램을 작성
// 1 ≤ N(수식의 길이) ≤ 19
// + - *

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
char pan[19];

int answer = -1 * 0x7fffffff;

int oper(int left, int right, char operand){
	
	switch(operand){
		case '+':
			return left + right;
		case '-':
			return left - right;
		case '*':
			return left * right;			
	}
	
}

void dfs(int idx, int sofar){
	
	if(idx == N-1){
		answer = max(answer, sofar);
		return;
	}
	
	int next_far = oper(sofar, pan[idx + 2] - '0', pan[idx + 1]);
	dfs(idx + 2, next_far);
	
	if(idx < N-3){
		int tmp = oper(pan[idx + 2] - '0', pan[idx + 4] - '0', pan[idx+3]);
		int tmp_sofar = oper(sofar, tmp, pan[idx + 1]);		
		dfs(idx + 4, tmp_sofar);
	}
	
}

int main(){
	scanf("%d", &N);
	getchar();
	for(int i = 0 ; i < N ; ++i)	scanf("%1c", &pan[i]);
	
	// Operator의 개수 = N/2
	// 1 ~ 3 ~~~~ (N-2)
	dfs(0, pan[0] - '0');
	printf("%d", answer);
	
	return 0;
}
