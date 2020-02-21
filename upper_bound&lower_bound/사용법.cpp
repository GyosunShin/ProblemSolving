#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	vector<int> a;
	a.push_back(1);	a.push_back(2);	a.push_back(3);	a.push_back(4);	a.push_back(5);	a.push_back(6);	a.push_back(6);	a.push_back(6);	a.push_back(7);
	
	
	vector<int>::iterator hi;
	// 6을 초과하는 가장 첫번째 원소의 위치 반환
	// 즉! 6과 같은 값이 아닌  6을 초과하는 가장 첫번째 원소의 위치 반환
	hi = upper_bound(a.begin(), a.end(), 6);
	vector<int>::iterator lo;
	// 6이 없으면 6보다 큰 가장 작은 정수의 위치 반환 
	lo = lower_bound(a.begin(), a.end(), 6);
	cout << hi - lo << endl;
	
	return 0;
}
