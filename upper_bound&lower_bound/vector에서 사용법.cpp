#include <iostream> 
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	
	vector<int> a;
	a.push_back(1);	a.push_back(2);	a.push_back(3);	a.push_back(4);	a.push_back(5);	
	a.push_back(6);	a.push_back(6);	a.push_back(6);	a.push_back(7);
	
	// 6�� �ʰ��ϴ� ���� ù��° ������ ��ġ ��ȯ
	// ��! 6�� ���� ���� �ƴ�  6�� �ʰ��ϴ� ���� ù��° ������ ��ġ ��ȯ	
	vector<int>::iterator hi;
	hi = upper_bound(a.begin(), a.end(), 6);
	printf("[UPPER_BOUND] : %d\n", hi - a.begin());
	
	// 6�� ������ 6���� ū ���� ���� ������ ��ġ ��ȯ 	
	vector<int>::iterator lo;
	lo = lower_bound(a.begin(), a.end(), 6);
	printf("[LOWER_BOUND] : %d\n", lo - a.begin());
	
	cout << hi - lo << endl;
	
	return 0;
}
