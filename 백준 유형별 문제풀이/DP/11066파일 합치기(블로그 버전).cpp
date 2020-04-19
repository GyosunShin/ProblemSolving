#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int K; //소설을 구성하는 장의 수

int chapter[501];
int chapterSum[501]; //1장부터 index장까지 합친 값 저장
int cache[501][501]; //최대 500

int totalSum(int first, int last){

	//기저 사례: 자기자신은 더하지 않는다
	if (first >= last)
		return 0;
	//다음장이 마지막이라면
	if (first + 1 == last)
		return chapter[first] + chapter[last];

	int &result = cache[first][last];
	if (result != -1)
		return result;
	result = numeric_limits<int>::max();
	for (int i = first; i < last; i++)
		//chapterSum[last]-chapterSum[first-1]->first~last까지의 합
		//소설책은 연속한 페이지끼리만 합칠 수 있다
		//(first~i까지 합) + (i+1~last까지 합한뒤 first~i까지의 합을 더해준 것) 중 최소
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
			chapterSum[i] = chapterSum[i - 1] + chapter[i]; //1~i까지의 누적 합
		}

        cout << totalSum(1, K) << endl;
	}

	return 0;

}
