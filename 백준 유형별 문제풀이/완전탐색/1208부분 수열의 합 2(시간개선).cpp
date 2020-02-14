// 2���� �������� �迭�� ���� dfs�̿��Ͽ� ������ ��� �κм����� �� vector�� ����
//  (A�� ���ҷθ� ������ ���) + (A+B�� ������ ���) + (B�θ� ������ ���)   -->  COUNTING!

// (1 �� N �� 40, |S| �� 1,000,000)

#include <stdio.h> 
#include <vector>
#include <algorithm>

using namespace std;

int N, S, divv;
int map[40];
long long ans;

vector<int> picked;
vector<int> sumA;
vector<int> sumB;

void dfsB(int start){
	
	if(picked.size() > 0){
		int tmp_sum = 0;
		for(int i = 0 ; i < picked.size() ; ++i){
			tmp_sum += map[picked[i]];
		}
		sumB.push_back(tmp_sum);
		if(tmp_sum == S)	++ans;
	}
	
	if(picked.size() == (N-divv)){
		return;
	}
	
	for(int i = start ; i < N ; ++i){
		picked.push_back(i);
		dfsB(i + 1);
		picked.pop_back();
	}
}

void dfsA(int start){
		
	if(picked.size() > 0){
		int tmp_sum = 0;
		for(int i = 0 ; i < picked.size() ; ++i){
			tmp_sum += map[picked[i]];
		}
		sumA.push_back(tmp_sum);
		if(tmp_sum == S)	++ans;
	}
	
	if(picked.size() == divv){
		return;
	}
	
	for(int i = start ; i < divv ; ++i){
		picked.push_back(i);
		dfsA(i + 1);
		picked.pop_back();
	}
}

int main(){
	scanf("%d %d", &N, &S);
	
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &map[i]);
	}
	
	divv = (int)(N/2);
		
	// nCr
	dfsA(0);
	dfsB(divv);

	sort(sumA.begin(), sumA.end());
	sort(sumB.begin(), sumB.end());

	for (int i = 0; i < sumB.size(); i++) {
		int temp = S - sumB[i];
		
		// temp���� �ʰ��ϴ� ���� ù��° ������ ��ġ ��ȯ 
		// ��! temp�� ���� ���� �ƴ�  temp���� �ʰ��ϴ� ���� ù��° ������ ��ġ ��ȯ 
		auto hi = upper_bound(sumA.begin(), sumA.end(), temp);
		
		// temp���� ������ temp������ ū ���� ���� ������ ��ġ ��ȯ 
		auto lo = lower_bound(sumA.begin(), sumA.end(), temp);
		ans += hi - lo;
	}
	
	printf("%lld", ans);
	
	return 0;
}
