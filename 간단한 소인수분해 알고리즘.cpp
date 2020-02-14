#include <stdio.h>
#include <vector>

using namespace std;

vector<int> factor(int n){
	if(n == 1)	return vector<int>(1,1);
	vector<int> ret;
	for(int div = 2 ; n > 1 ; ++div){
		while(n % div == 0){
			n /= div;
			ret.push_back(div);
		}
	}
	return ret;
}

int main(){
	int input;
	scanf("%d", &input);
	
	vector<int> ret = factor(input);
	
	for(int i= 0 ; i < ret.size() ; ++i){
		printf("%d ", ret[i]);
	}
	
	return 0;
}
