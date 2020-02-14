#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	vector<vector<int> > vv;
	
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	
	vector<int> v2;
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	
	vv.push_back(v1);
	vv.push_back(v2);
	
	for(int i = 0 ; i < vv.size() ; ++i){
		for(int j = 0 ; j < vv[i].size() ; ++j){
			printf("%d  ", vv[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
