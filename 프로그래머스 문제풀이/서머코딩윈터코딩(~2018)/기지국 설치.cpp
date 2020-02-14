// ��� ����Ʈ�� ���ĸ� �����ϱ� ���� �����ؾ� �� ������ ������ �ּڰ��� ����

// INPUT
// 1 <=  ����Ʈ ���� <= 200,000,000(2��)
// 1 <= statoins.size <= 10000
// 1 <= w <= 10000

#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int state = 0;   // stations�� INDEX 
	int left = 1;
	int count = 0;
	while(true){
		// find left
		
		// ���� left������ �̹� ��ġ�� �������� ������� �ȿ� �ִ� ���� w + 1��ŭ JUMP ����� �� 
		if(state < stations.size() && left >= stations[state] - w){
			left = stations[state] + w + 1;
			state++;
		}
		else{  // ����ǿ� ���� ���� ���� ��� 
			int newleft = left + w;
			if((state <= (int)stations.size() - 2) && (newleft >= stations[state + 1] - w)){
				newleft = stations[state + 1] - w - 1;
			}
			left = newleft + w + 1;
			count++;  // ���ο� ������ ��ġ! 
		}
		if(left > n)	break;
	}
	return count;
}
