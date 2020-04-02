
// �ִ� �� ����� ¡�˴ٸ��� �ǳ� �� �ִ��� return 

// 1 <= stones.size() <= 200,000
// 1 <= stones[i] <= 200,000,000

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer;
int mmax = -1;
int mmin = 0x7fffffff;
int K;

vector<int> backup;

bool check(vector<int>& stones, int input){
	
	int max_dis = -1;
	
	backup.clear();
	for(int i = 0 ; i < stones.size() ; ++i){
		int tmp = stones[i] - input;
		if(tmp <= 0)	tmp = 0;
		backup.push_back(tmp);
	}
	
	int cnt = 0;
	for(int i = 0 ; i < backup.size() ; ++i){
		if(backup[i] == 0){
			cnt++;	
		}
		else{
			if(cnt != 0)	max_dis = max(max_dis, cnt);
			cnt = 0;
		}
	}
	
	if(cnt > 0)	max_dis = max(max_dis, cnt);
	
	if(max_dis >= K)	return false;
	return true;
}

int solve(vector<int>& stones){
	
	int left = mmin;
	int right = mmax;
	int mid;
	
	while(left <= right){
		mid = (left + right) / 2;
		
		if(check(stones, mid)){	// ���� �ǳ� �� ������ �ǹ� 
		// �׷��Ƿ� �� �÷��� ��
			left = mid + 1;
		}
		else{
		// ���� �� �ǳʹٴ� ���� �ǹ�
		// �׷��Ƿ� ���� �� ��������
			right = mid - 1; 
		}
	}
	
	return right + 1;
}

int solution(vector<int> stones, int k) {
    K = k;
    for(int i = 0 ; i < stones.size() ; ++i){
    	mmax = max(mmax, stones[i]);
    	mmin = min(mmin, stones[i]);
    }
	
	int answer = solve(stones);
    
    return answer;
}





