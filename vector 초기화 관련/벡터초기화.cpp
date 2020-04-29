#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main(){
	
	int n = 5;
	
	vector<int> v1(n,-1);
	vector<int> v2(n,0);
	vector<int> v3(n,1);
	vector<int> v4(n,100);
	
	vector<int>::iterator it;
	
	vector<int> v0(10);
	for(int i = 0 ; i < v0.size(); ++i)	printf("%d  ", v0[i]);
	printf("\n");
	
	for(it = v1.begin() ; it != v1.end() ; ++it)	cout << *it << ", ";
	cout << endl;
	
	for(it = v2.begin() ; it != v2.end() ; ++it)	cout << *it << ", ";
	cout << endl;
	
	for(it = v3.begin() ; it != v3.end() ; ++it)	cout << *it << ", ";
	cout << endl;
	
	for(it = v4.begin() ; it != v4.end() ; ++it)	cout << *it << ", ";
	cout << endl;
	
}
