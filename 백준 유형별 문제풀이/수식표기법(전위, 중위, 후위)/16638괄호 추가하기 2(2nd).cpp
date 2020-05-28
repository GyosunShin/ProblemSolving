// 시간 제한 : 0.5초
// +, -, * 

// 1 <= N <= 19

// 중첩된 괄호는 사용불가
// * > +, - 

#include <cstdio> 
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int N;
char pan[21];

int answer = -1 * 0x7fffffff;

vector<string> picked;

int operater(int left, int right, char op){
	switch(op){
		case '+':
			return left + right;
		case '-':
			return left - right;
		case '*':
			return left * right;
	}
}

int check(){ 
	
	for(int i = 0 ; i < picked.size() ; ++i){
		cout << picked[i] << " ";
		
		
		
	}
	cout << "\n";
	
	return 0;
}

void dfs(int idx){
	
	if(idx == N-1){
		answer = max(answer, check());
		return;
	}
	
	int next_sum = 0;
	
//	next_sum = operater(sofar, pan[idx+2] - '0', pan[idx+1]);
	
	if(idx == 0)	picked.push_back(to_string(pan[0] - '0'));
	string tmp = "";
	tmp += pan[idx+1];
	picked.push_back(tmp);
	picked.push_back(to_string(pan[idx+2] - '0'));
	dfs(idx + 2);
	if(idx == 0)	picked.pop_back();
	picked.pop_back();
	picked.pop_back();
	
	if(idx + 3 < N){
		int tmp_sum  = operater(pan[idx+2] - '0', pan[idx+4] - '0', pan[idx+3]);
//		next_sum = operater(sofar, tmp_sum, pan[idx+1]);
		if(idx == 0)	picked.push_back(to_string(pan[0] - '0'));
		string tmp = "";
		tmp += pan[idx+1];
		picked.push_back(tmp);
		picked.push_back(to_string(tmp_sum));
		dfs(idx + 4);
		if(idx == 0)	picked.pop_back();
		picked.pop_back();
		picked.pop_back();
	}
	
}

int main(){
	pan[0] = '0';	pan[1] = '+';
	scanf("%d", &N);
	N = N+2;
	getchar();
	for(int i = 2 ; i < N ; ++i)	scanf("%1c", &pan[i]);
	
	dfs(0);
	
	// OUTPUT
	// 괄호를 적절히 추가해서 얻을 수 있는 결과의 최댓값을 출력
	printf("%d", answer);
	
	return 0;
}
