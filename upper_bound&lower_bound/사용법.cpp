#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	vector<int> a = {1,2,3,4,5,6,6,6,7,8,9,9,10,11};
	
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
