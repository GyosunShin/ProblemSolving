// 재미있게 푼 DFS 문제였습니다.

// 연산자들의 (우선순위가 같고) (중첩된 괄호를 허용하지 않기) 때문에 재귀함수를 통해 
// 아래의 2가지 경우의 수를 진행하면 풀리는 간단한 문제였습니다.

// 1. 괄호로 묶지 않고 바로 다음 숫자와 연산
// 2. 괄호로 묶고 다음 숫자와 다다음 숫자를 연산한 결과와의 연산

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int N;
string s;

int result = INT_MIN;

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

void func(int idx, int value)
{
	if (idx >= N)
	{
		result = max(result, value);

		return;
	}

	char op = idx >= 1 ? s[idx - 1] : '+';
	int temp = calculate(value, s[idx] - '0', op);

	//#############################################################################
	func(idx + 2, temp);	// 1. 괄호로 묶지 않고 바로 다음 숫자와 연산
	//#############################################################################

	if (idx < N - 2)
	{
		temp = calculate(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]);
		temp = calculate(value, temp, op);

		//#############################################################################
		func(idx + 4, temp);  // 2. 괄호로 묶고 다음 숫자와 다다음 숫자를 연산한 결과와의 연산
		//#############################################################################
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	cin >> s;

	func(0, 0);

	cout << result << "\n";

	return 0;
}
