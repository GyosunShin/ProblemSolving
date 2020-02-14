#include <stdio.h> 
#include <vector>

using namespace std;

int main(){
	
	vector<int> v1(10);
	for(int i = 0 ; i < v1.size(); ++i)	printf("%d  ", v1[i]);
	printf("\n");
	
	vector<int> v2(10, 222);
	for(int i = 0 ; i < v2.size(); ++i)	printf("%d  ", v2[i]);
	printf("\n");
	
	vector<int> v3{1,2,3,4,5,6};
	for(int i = 0 ; i < v3.size(); ++i)	printf("%d  ", v3[i]);
	printf("\n");
	
	return 0;
}
