// 최대 몇 개의 부서에 물품을 지원할 수 있는지 return

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int solution(vector<int> d, int budget) {
    int ans = 0;
    sort(d.begin(), d.end());
    
    for(int i = 0 ; i < d.size() ; ++i){
    	if(budget >= d[i])	++ans;
    	budget -= d[i];
    }
    return ans;
}
