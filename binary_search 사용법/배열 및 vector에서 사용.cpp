#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	
	vector<int> v{5,3,1,8,22,0};
	sort(v.begin(), v.end());
	
	int arr[] = {5,3,1,8,22,0};
	
	if(binary_search(v.begin(), v.end(), 8))	cout << "EXIST !" << endl;
	if(binary_search(arr, arr + 6, 8))	cout << "EXIST !" << endl;
	
	
	return 0;
}
