#include <cstdio> 

int main(){
	
	
	// 0���� ���� ���� �ȵ� 
	int arr[10] = {0, };
	
	for(int i = 0 ; i < sizeof(arr) / sizeof(int) ; ++i)	printf("%d  ", arr[i]);
	
	
	return 0;
}
