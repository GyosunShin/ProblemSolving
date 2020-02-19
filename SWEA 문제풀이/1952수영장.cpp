// ���� ���� ������� �������� �̿��� �� �ִ� ����� ã�� �� ����� �������� ����ϴ� ���α׷��� �ۼ��϶�.

// 10 <=  ��� �̿�� <= 3000
// �̿�� ���� : 1��, 1��, 3��, 1��
 
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int T;
int d, m, ms, y;
int plan[12];
int cache[12];

int solve(int index){
	if(index > 11){
		return 0;
	}
	int& ret = cache[index];
	if(ret != -1)	return ret;
	
	ret = min(solve(index+1) + (plan[index] * d), solve(index+1) + (m));
	ret = min(ret, solve(index + 3) + ms);
	ret = min(ret, solve(index + 12) + y);
	
	return ret;
}

int main(){
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		memset(cache, -1, sizeof(cache));
		scanf("%d %d %d %d", &d, &m, &ms, &y);
		for(int i = 0 ; i < 12 ; ++i)	scanf("%d", &plan[i]);
		//####################################################
		
		int ans = solve(0);
		
		
		// ������ �̿��ϴ� ��� �� ���� ���� �����ϴ� '���'�̴�.
		printf("#%d %d\n", z, ans);  
	}
	return 0;
}
