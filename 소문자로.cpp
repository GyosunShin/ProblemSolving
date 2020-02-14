#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	string str = "FUCK YOU BITCH!";
	cout << str << endl;
	
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	
	cout << str;
	
	return 0;
}
