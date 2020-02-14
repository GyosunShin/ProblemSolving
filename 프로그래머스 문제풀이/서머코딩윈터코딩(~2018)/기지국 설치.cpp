// 모든 아파트에 전파를 전달하기 위해 증설해야 할 기지국 개수의 최솟값을 리턴

// INPUT
// 1 <=  아파트 개수 <= 200,000,000(2억)
// 1 <= statoins.size <= 10000
// 1 <= w <= 10000

#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int state = 0;   // stations의 INDEX 
	int left = 1;
	int count = 0;
	while(true){
		// find left
		
		// 현재 left지점이 이미 설치된 기지국의 영향범위 안에 있는 경우는 w + 1만큼 JUMP 해줘야 함 
		if(state < stations.size() && left >= stations[state] - w){
			left = stations[state] + w + 1;
			state++;
		}
		else{  // 영향권에 없는 곳에 있을 경우 
			int newleft = left + w;
			if((state <= (int)stations.size() - 2) && (newleft >= stations[state + 1] - w)){
				newleft = stations[state + 1] - w - 1;
			}
			left = newleft + w + 1;
			count++;  // 새로운 기지국 설치! 
		}
		if(left > n)	break;
	}
	return count;
}
