#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int n, k;  // n종류의 동전 | 총 k원 
	scanf("%d %d", &n, &k);
	int ns[n];
	for(int i = 0 ; i < n ; i++){		
		scanf("%d", &ns[i]);
	}
	int sum = 0;
	
	for(int i = (n-1) ; i >= 0 ; i--){
		
		sum += k / ns[i];
		k = k-((k / ns[i]) * ns[i]);
	}
	
	printf("%d", sum);
	
}
