#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num;

int main(){
	
	for(int z = 1 ; z <= 10 ; ++z){
		vector<int> v;
		scanf("%d", &num);
		for(int i = 0 ; i < 100 ; ++i){
			int tmp;
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		
		for(int i = 0 ; i < num ; ++i){
			sort(v.begin(), v.end());	
			v[0] += 1;
			v[99] -= 1;
		}
		sort(v.begin(), v.end());	
//		printf("[%d] - [%d\n]", v[99], v[0]);
		int ans = v[99] - v[0];
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}


