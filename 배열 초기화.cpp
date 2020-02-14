#include <cstdio> 

int main(){
	
	
	// 0외의 값은 적용 안됨 
	int arr[10] = {0, };
	
	for(int i = 0 ; i < sizeof(arr) / sizeof(int) ; ++i)	printf("%d  ", arr[i]);
	
	
	return 0;
}
