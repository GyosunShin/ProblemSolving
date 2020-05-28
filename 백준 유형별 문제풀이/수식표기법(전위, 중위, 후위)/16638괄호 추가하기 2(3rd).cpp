// �ð� ���� : 0.5��
// +, -, * 

// 1 <= N <= 19

// ��ø�� ��ȣ�� ���Ұ�
// * > +, - 

#include <cstdio> 
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int N;
char pan[21];

int answer = -1 * 0x7fffffff;

string prefix_notation;

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

int opPrece(char op){
	switch(op){
		case '*':
			return 3;
		case '+':	case '-':
			return 2;
		case '(':
			return 1;
	}
}

int opComp(char op1, char op2){	// (Stack�� �ִ� ������, ���ο� ������)
	if(opPrece(op1) > opPrece(op2))	return 1;	// ��� �� 
	else if(opPrece(op1) < opPrece(op2))	return -1;	// ��� ��! 
	else	return 0;	// ���º�! 
}

string change(string& prefix){
	string ret = "";
	stack<char> st;
	
	for(int i = 0 ; i < prefix.size() ; ++i){
		if('0' <= prefix[i] && prefix[i] <= '9'){
			ret.push_back(prefix[i]);
		}
		else{
			if(prefix[i] == '('){
				st.push(prefix[i]);
			}
			else if(prefix[i] == ')'){
				while(true){
					char curOp = st.top();
					st.pop();
					if(curOp == '(')	break;
					ret.push_back(curOp);
				}
			}
			else{
				while(!st.empty()
				&& opComp(st.top(), prefix[i]) >= 0){
					ret.push_back(st.top());
					st.pop();
				}
				st.push(prefix[i]);
			}
		}
	}
	
	while(!st.empty()){
		ret.push_back(st.top());
		st.pop();
	}
	
	return ret;
}

int calc(string& post){
	
	stack<int> st;
	
	for(int i = 0 ; i < post.size() ; ++i){
		if('0' <= post[i] && post[i] <= '9'){
			st.push(post[i] - '0');
		}
		else{
			char curOp = post[i];
			int right = st.top();	st.pop();
			int left = st.top();	st.pop();
			int ret = operater(left, right, curOp);
			st.push(ret);
		}
	}
	
	return st.top();
}

int check(){ 
	// prefix_notation --> postfix_notation 
	string postfix = change(prefix_notation);
	int ret = calc(postfix);
	return ret;
}

void dfs(int idx){
	
	if(idx == N-1){
		answer = max(answer, check());
		return;
	}
	
	int next_sum = 0;
	
	if(idx == 0)	prefix_notation.push_back(pan[0]);
	prefix_notation.push_back(pan[idx+1]);
	prefix_notation.push_back(pan[idx+2]);
	dfs(idx + 2);
	if(idx == 0)	prefix_notation.pop_back();
	prefix_notation.pop_back();
	prefix_notation.pop_back();
	
	if(idx + 3 < N){
		if(idx == 0)	prefix_notation.push_back(pan[0]);
		prefix_notation.push_back(pan[idx+1]);
		prefix_notation.push_back('(');
		prefix_notation.push_back(pan[idx+2]);
		prefix_notation.push_back(pan[idx+3]);
		prefix_notation.push_back(pan[idx+4]);
		prefix_notation.push_back(')');
		dfs(idx + 4);
		if(idx == 0)	prefix_notation.pop_back();
		prefix_notation.pop_back();
		prefix_notation.pop_back();
		prefix_notation.pop_back();
		prefix_notation.pop_back();
		prefix_notation.pop_back();
		prefix_notation.pop_back();
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
	// ��ȣ�� ������ �߰��ؼ� ���� �� �ִ� ����� �ִ��� ���
	printf("%d", answer);
	
	return 0;
}
