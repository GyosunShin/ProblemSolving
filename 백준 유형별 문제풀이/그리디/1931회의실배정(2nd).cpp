// ȸ���� �� N(1 �� N �� 100,000)

//  0 <= ���� �ð��� ������ �ð��� 2^31-1

// OUTPUT : ù° �ٿ� �ִ� ����� �� �ִ� ȸ���� �ִ� ������ ����Ѵ�.

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer;
int start[100000];
int eend[100000];
vector<pair<int, int>> v;

int main(){
	scanf("%d", &N);
	
	for(int i= 0 ; i < N ; ++i){
		scanf("%d %d", &start[i], &eend[i]);	
		v.push_back({eend[i], start[i]});
	}
	
	sort(v.begin(), v.end());
	
	int div = 0;
	for(int i = 0 ; i < v.size() ; ++i){
		if(v[i].second >= div){
			++answer;
			div = v[i].first;
		}
	}
	
	
	printf("%d", answer);
	
	return 0;
}
