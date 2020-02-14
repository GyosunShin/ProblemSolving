#include <stdio.h> 
#include <algorithm>

using namespace std;

vector<int> v;

int main(){
	
	
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);v.push_back(1);
	
	for(int i = 0 ; i < v.size() ; ++i){
		printf("%d  ", v[i]);
	}
	printf("\n");
	
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	
	for(int i = 0 ; i < v.size() ; ++i){
		printf("%d  ", v[i]);
	}
	printf("\n");
	
	return 0;
}

