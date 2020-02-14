// (1 �� N, M �� 1,000,000)

// OUTPUT : ù° �ٿ� �� �迭�� ��ģ �� ������ ����� ����Ѵ�.

#include <stdio.h> 
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int a[1000000];
int b[1000000];

vector<int> ret;

int main(){
	scanf("%d %d", &N, &M);
	
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &a[i]);	
		ret.push_back(a[i]);
	}
	for(int j = 0 ; j < M ; ++j){
		scanf("%d", &b[j]);	
		ret.push_back(b[j]);
	}
	
	sort(ret.begin(), ret.end());
	for(int i = 0 ; i < ret.size() ; ++i){
		printf("%d ", ret[i]);
	}
	
	return 0;
}


