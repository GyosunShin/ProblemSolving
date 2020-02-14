#include <stdio.h>
#include <vector>
#include <algorithm>

// ## upper_bound랑 lower_bound는 #include<algorithm> 해줘야 하고 오름차순 이 사전에 되어 있어야 한다! ##

using namespace std;

int main(){
	vector<int> v1;
	vector<int> v2;
	
	v1.push_back(1);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	
//	for(int i = 0 ; i < v1.size() ; ++i){
//		int low = lower_bound(v2.begin(), v2.end(), 5 - v1[i]) - v2.begin();
//		int high = upper_bound(v2.begin(), v2.end(), 5 - v1[i]) - v2.begin();
//		
//		printf("LOW : %d / HIGH : %d\n", low, high);
//	}

	int low = lower_bound(v1.begin(), v1.end(), 3) - v1.begin();
	int high = upper_bound(v1.begin(), v1.end(), 3)  - v1.begin();
	printf("LOW : %d / HIGH : %d\n", low, high);
	printf("TEST : %d\n", v1.end() - v1.begin());
	
	return 0;
}
