// 사람의 수 N(1 ≤ N ≤ 1,000)
//  (1 ≤ Pi ≤ 1,000)

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int pan[1000];

vector<int> v;

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &pan[i]);
		v.push_back(pan[i]);
	}
	
	
	sort(v.begin(), v.end());
	
	int ans = 0;
	
	for(int i = 0 ; i < v.size() ; ++i){
		ans += v[i] * (v.size() - i);
	}
	
	printf("%d", ans);
	
	return 0;
}
