#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int K; //�Ҽ��� �����ϴ� ���� ��

int chapter[501];
int chapterSum[501]; //1����� index����� ��ģ �� ����
int cache[501][501]; //�ִ� 500

int totalSum(int first, int last){

	//���� ���: �ڱ��ڽ��� ������ �ʴ´�
	if (first >= last)
		return 0;
	//�������� �������̶��
	if (first + 1 == last)
		return chapter[first] + chapter[last];

	int &result = cache[first][last];
	if (result != -1)
		return result;
	result = numeric_limits<int>::max();
	for (int i = first; i < last; i++)
		//chapterSum[last]-chapterSum[first-1]->first~last������ ��
		//�Ҽ�å�� ������ ������������ ��ĥ �� �ִ�
		//(first~i���� ��) + (i+1~last���� ���ѵ� first~i������ ���� ������ ��) �� �ּ�
		result = min(result, totalSum(first, i) + (totalSum(i + 1, last) + chapterSum[last] - chapterSum[first - 1]));
	return result;

}

 

int main(void){

	int test_case;
	cin >> test_case;

	for (int i = 0; i < test_case; i++){
		cin >> K;
		memset(chapterSum, 0, sizeof(chapterSum));
		memset(cache, -1, sizeof(cache));
               
		for (int i = 1; i <= K; i++){
			cin >> chapter[i];
			chapterSum[i] = chapterSum[i - 1] + chapter[i]; //1~i������ ���� ��
		}

        cout << totalSum(1, K) << endl;
	}

	return 0;

}
