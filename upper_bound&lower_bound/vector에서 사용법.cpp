#include <iostream> 
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	
	vector<int> a;
	a.push_back(1);	a.push_back(2);	a.push_back(3);	a.push_back(4);	a.push_back(5);	
	a.push_back(6);	a.push_back(6);	a.push_back(6);	a.push_back(7);
	
	// 6을 초과하는 가장 첫번째 원소의 위치 반환
	// 즉! 6과 같은 값이 아닌  6을 초과하는 가장 첫번째 원소의 위치 반환	
	vector<int>::iterator hi;
	hi = upper_bound(a.begin(), a.end(), 6);
	printf("[UPPER_BOUND] : %d\n", hi - a.begin());
	
	// 6이 없으면 6보다 큰 가장 작은 정수의 위치 반환 	
	vector<int>::iterator lo;
	lo = lower_bound(a.begin(), a.end(), 6);
	printf("[LOWER_BOUND] : %d\n", lo - a.begin());
	
	cout << hi - lo << endl;
	
	return 0;
}
