#include <stdio.h>
#include <map>
#include <iostream>

using namespace std;

int main(){
	map<int, int> m;
	
	m[1] = 100;
	m[2] = 90;
	m[3] = 80;
	
	map<int, int>::iterator it;
	it = m.find(1);
	if(it == m.end()){
		cout << "cant find" << endl;
	}
	else{
		cout << "you found it! and this is : " << it->first << " / " << it->second << endl;
	}
	
	return 0;
}

