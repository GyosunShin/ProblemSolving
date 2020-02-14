#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int main(){
	vector<int> v(4);
	
	for(int i = 0 ; i < v.size() ; i++){
		v[i] = i;
	}
	for(int i = 0 ; i < v.size() ; i++){
		cout << v[i] << endl;
	}
	
	sort(v.begin(), v.end());
	
	do{
		for(int i = 0 ; i < v.size() ; i++){
			printf("%d", v[i]);
		}
		cout << endl;
	}while(next_permutation(v.begin(), v.end()));
}
