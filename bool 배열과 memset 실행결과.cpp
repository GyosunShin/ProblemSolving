#include <iostream>
#include <string.h>

using namespace std;

bool flag[3];

int main(){
	if(!flag[1])	cout<<"TEST1" << endl;
	
	memset(flag, true, sizeof(flag));
	if(flag[1])	cout<<"TEST2"<<endl;
	
	memset(flag, false, sizeof(flag));
	if(flag[1])	cout<<"TEST3" << endl;
	
	
	return 0;
}
