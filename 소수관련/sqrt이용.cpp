#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

bool check(int n){
	int sq = (int)sqrt(n);
	for(int i = 2 ; i <= sq ; ++i){
		if(n % i == 0)	return false;
	}	
	return true;
}

int main(){
	while(1){
		int n;
		scanf("%d", &n);
		
		bool tmp = check(n);
		if(tmp)	printf("Prime Number\n");
		else	printf("Not Prime Number\n");
	}
	
	return 0;
}
