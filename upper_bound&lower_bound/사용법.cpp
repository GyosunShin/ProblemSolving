#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	vector<int> a = {1,2,3,4,5,6,6,6,7,8,9,9,10,11};
	
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
