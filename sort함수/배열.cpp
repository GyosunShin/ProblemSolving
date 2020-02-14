// 걍 배열을 오름차순 순서로
#include <stdio.h> 
#include <algorithm>

using namespace std;

bool compare(int a, int b){  // 따로 함수를 정의하여 내림차순 순서대로 = 큰 숫자 먼저 출력 
	return a > b;
}

int main(){
	int a[] = {3,1,2,5,4,6,8,7,9,10};
	sort(a, a+10, compare);
	for(int i = 0 ; i < sizeof(a) / sizeof(int) ;  ++i){
		printf("%d ", a[i]);
	}
	return 0;
}
