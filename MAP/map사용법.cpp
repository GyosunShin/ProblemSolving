#include <stdio.h>
#include <map>
#include <iostream>

using namespace std;

int main(){
//	map<int, int> m;
	map<int, int, greater<int>> m;
	
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	
	m[1] += 1;
	
//	printf("%d", m[1]);
	
	map<int, int>::iterator it;
	for(it = m.begin() ; it != m.end() ; ++it){
		cout << it->first << " " << it->second << endl;
	}
	
	// erase¹æ¹ý
//	m.erase(1);
}

