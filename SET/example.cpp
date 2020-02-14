#include <stdio.h> 
#include <iostream>
#include <set>

using namespace std;

int main(){
	set<int> s;
//	set<int, greater<int>> s;
	
//	for(int i = 1 ; i <= 100 ; ++i)	s.insert(i);
	s.insert(1);
	s.insert(7);
	s.insert(3);
	
//	auto it = s.find(50);
	
	for(auto it = s.begin() ; it != s.end() ; ++it){
		cout << *it << endl;
	}
	
	
	return 0;
}
