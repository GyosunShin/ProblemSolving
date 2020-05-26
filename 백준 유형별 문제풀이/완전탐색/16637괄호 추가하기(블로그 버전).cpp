// ����ְ� Ǭ DFS ���������ϴ�.

// �����ڵ��� (�켱������ ����) (��ø�� ��ȣ�� ������� �ʱ�) ������ ����Լ��� ���� 
// �Ʒ��� 2���� ����� ���� �����ϸ� Ǯ���� ������ ���������ϴ�.

// 1. ��ȣ�� ���� �ʰ� �ٷ� ���� ���ڿ� ����
// 2. ��ȣ�� ���� ���� ���ڿ� �ٴ��� ���ڸ� ������ ������� ����

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
	func(idx + 2, temp);	// 1. ��ȣ�� ���� �ʰ� �ٷ� ���� ���ڿ� ����
	//#############################################################################

	if (idx < N - 2)
	{
		temp = calculate(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]);
		temp = calculate(value, temp, op);

		//#############################################################################
		func(idx + 4, temp);  // 2. ��ȣ�� ���� ���� ���ڿ� �ٴ��� ���ڸ� ������ ������� ����
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
