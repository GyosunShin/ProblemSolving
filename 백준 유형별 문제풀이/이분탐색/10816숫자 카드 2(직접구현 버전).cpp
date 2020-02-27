// 각 수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 공백으로 구분해 출력한다.

#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int Npan[500000];
int Mpan[500000];

int up(int target){
	int left = 0;
	int right = N-1;
	int mid;
	
	while(left <= right){
		mid = (left + right) / 2;
		
		if(Npan[mid] > target){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	return left;
}

int low(int target){
	
	int left = 0;
	int right = N-1;
	int mid;
	
	while(left <= right){
		mid = (left + right) / 2;
		
		if(Npan[mid] >= target){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}	
	}
	
	return left;
}

int solve(int target){
	
	int up_idx = up(target);
	int low_idx = low(target);
	
	return (up_idx - low_idx);
	
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
