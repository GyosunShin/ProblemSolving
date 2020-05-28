#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cstring>
#include <climits>
#include <map>

using namespace std;

const int MAX = 20;

int N;
int result = INT_MIN;
string s;
map<char, int> priority;
char parenthesis[MAX];

void setPriority(void)
{
	priority['('] = 2;
	priority['*'] = 1;
	priority['+'] = 0;
	priority['-'] = 0;
}

bool isNotParenthesis(int idx)
{
	return (parenthesis[idx] != '(' && parenthesis[idx] != ')');
}

bool isOperand(char c)
{
	return (c >= '0' && c <= '9');
}

int calculate(int a, int b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}

int calculatePostfix(string tempS)
{
	stack<int> postfixStack;

	for (int i = 0; i < tempS.size(); i++)
	{
		if (isOperand(tempS[i]))
		{
			postfixStack.push(tempS[i] - '0');

			continue;
		}

		if (postfixStack.size() >= 2)
		{
			int second = postfixStack.top();
			postfixStack.pop();
			int first = postfixStack.top();
			postfixStack.pop();

			int temp = calculate(first, second, tempS[i]);
			postfixStack.push(temp);
		}
	}

	return postfixStack.top();
}

int postfixResult()
{
	string tempS;
	stack<char> st;

	for (int i = 0; i < N; i++)
	{
		if (isOperand(s[i]))
		{
			tempS += s[i];
		}

		switch (parenthesis[i])
		{
		case '(':
			st.push('(');

			break;
		case ')':
			while (st.empty() == false && st.top() != '(')
			{
				tempS += st.top();

				st.pop();
			}

			st.pop();

			break;
		default:
			if (isOperand(s[i]))
			{
				break;
			}

			while (st.empty() == false && priority[st.top()] >= priority[s[i]])
			{
				if (st.top() == '(')
				{
					break;
				}

				tempS += st.top();
				st.pop();
			}

			st.push(s[i]);

			break;
		}
	}

	while (st.empty() == false)
	{
		tempS += st.top();

		st.pop();
	}

	return calculatePostfix(tempS);
}

void func(int idx)
{
	if (idx >= N)
	{
		result = max(result, postfixResult());
		return;
	}

	for (int i = idx; i < N; i += 2)
	{
		if (i >= N - 2)
		{
			func(i + 1);
			continue;
		}


		if (isNotParenthesis(i) && isNotParenthesis(i + 2))
		{
			parenthesis[i] = '(';
			parenthesis[i + 2] = ')';
			func(i + 2);
			parenthesis[i] = ' ';
			parenthesis[i + 2] = ' ';
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	cin >> s;

	setPriority();

	func(0);

	cout << result << "\n";

	return 0;
}
