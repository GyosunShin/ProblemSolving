#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	vector<int> a;
	a.push_back(1);	a.push_back(2);	a.push_back(3);	a.push_back(4);	a.push_back(5);	a.push_back(6);	a.push_back(6);	a.push_back(6);	a.push_back(7);
	
	
	vector<int>::iterator hi;
	// 6�� �ʰ��ϴ� ���� ù��° ������ ��ġ ��ȯ
	// ��! 6�� ���� ���� �ƴ�  6�� �ʰ��ϴ� ���� ù��° ������ ��ġ ��ȯ
	hi = upper_bound(a.begin(), a.end(), 6);
	vector<int>::iterator lo;
	// 6�� ������ 6���� ū ���� ���� ������ ��ġ ��ȯ 
	lo = lower_bound(a.begin(), a.end(), 6);
	cout << hi - lo << endl;
	
	return 0;
}
