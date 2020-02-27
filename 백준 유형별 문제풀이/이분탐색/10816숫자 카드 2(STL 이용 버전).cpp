// �� ���� ���� ���� ī�带 ����̰� �� �� ������ �ִ����� �������� ������ ����Ѵ�.

#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int Npan[500000];
int Mpan[500000];

int solve(int target){
	
	return (upper_bound(Npan, Npan + N, target) - lower_bound(Npan, Npan + N, target));
	
}

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &Npan[i]);
	
	scanf("%d", &M);
	for(int i = 0 ; i < M ; ++i)	scanf("%d", &Mpan[i]);
	
	sort(Npan, Npan + N);
	
	for(int i = 0 ; i < M ; ++i){
		int ret = solve(Mpan[i]);
		printf("%d ", ret);
	}
	
	return 0;
}
