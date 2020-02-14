#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
	return a > b;  // For) 오름차순 정렬 
}

int main(){
	int a[10] = {9,3,5,4,1,10,8,6,7,2};
	sort(a, a + 10, compare);
	for(int i = 0 ; i < sizeof(a) / sizeof(int) ; i++){
		cout << a[i] << ' ';
	}
}
