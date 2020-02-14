#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;

int main(){
	for(int i = 0 ; i < 5 ; ++i){
		v.push_back(i);
	}
	
	vector<int>::iterator it = v.begin();
	
	for(it = v.begin() ; it != v.end() ; ++it){
		printf("%d ", *it);
	}
	return 0;
}
