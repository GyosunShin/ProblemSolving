#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std; 

bool compare(int a, int b){  // ���� �Լ��� �����Ͽ� �������� ������� = ū ���� ���� ��� 
	return a > b;
}

int main(){
	vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
	
	sort(v.begin(), v.end(), compare);
	
	for(int i = 0 ; i < v.size() ; ++i)	printf("%d ", v[i]);
	
	return 0;
}
  
