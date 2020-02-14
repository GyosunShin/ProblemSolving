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
	int ans = 0;   
	int start = 1;     // ���� ���� 
	int stat_idx = 0;  // stations�� IDX 
	
	while(true) {
//		cout << "CUR : " << start << endl;
		if(stat_idx >= stations.size()){
			start = start + w + w + 1;
			++ans;	
		}
		if(start < stations[stat_idx] - w && stat_idx < stations.size()){
			int next_start = start + w;
			if(next_start >= stations[stat_idx] - w){
				next_start = stations[stat_idx] - w - 1;
			}
			start = next_start + w + 1;
			++ans;	
		}
		if(start >= stations[stat_idx] - w && stat_idx < stations.size()){
			start = stations[stat_idx] + w + 1;
			++stat_idx;
		}

		if(start > n)	break;
	}
    return ans;
}
