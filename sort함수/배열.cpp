// �� �迭�� �������� ������
#include <stdio.h> 
#include <algorithm>

using namespace std;

bool compare(int a, int b){  // ���� �Լ��� �����Ͽ� �������� ������� = ū ���� ���� ��� 
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
