#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int a[10] = {9,3,5,4,1,10,8,6,7,2};
	sort(a, a+10);  // 정렬할 데이터의 개수를 넣어주면 된다 
	for(int i = 0 ; i < 10 ; i++) {
		cout << a[i] << ' ';
	}
}
