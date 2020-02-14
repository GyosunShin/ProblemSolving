#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
	vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
	
	sort(v.begin(), v.end());
	
	for(int i = 0 ; i < v.size() ; ++i)	printf("%d ", v[i]);
	
	return 0;
}
  
