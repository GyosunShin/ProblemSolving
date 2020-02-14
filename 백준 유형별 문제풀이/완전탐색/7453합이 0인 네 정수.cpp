// �迭�� ũ�� n (1 �� n �� 4000)
// �迭�� ����ִ� ������ ������ �ִ� 228�̴�.

// A[a] + B[b] + C[c] + D[d] = 0�� ����� ���� ���϶� 

#include <stdio.h> 
#include <vector>
#include <algorithm>

using namespace std;

int N;

int map[4][4000];

vector<int> sumA;
vector<int> sumB;

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < 4 ; ++j){
			scanf("%d", &map[j][i]);		
		}
	}
	
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			sumA.push_back(map[0][i] + map[1][j]);
			sumB.push_back(map[2][i] + map[3][j]);
		}
	}
	
	sort(sumA.begin(), sumA.end());
	sort(sumB.begin(), sumB.end());
	
	long long ans = 0;
	
	for(int i = 0 ; i < sumA.size() ; ++i){
		int rem = -1 * sumA[i];
		vector<int>::iterator hi;
		hi = upper_bound(sumB.begin(), sumB.end(), rem);
		vector<int>::iterator lo;
		lo = lower_bound(sumB.begin(), sumB.end(), rem);
		ans += hi - lo;
	}
	
	printf("%lld", ans);
	
	return 0;
}
