// (1 ≤ N ≤ 500,000)
// -10,000,000 <= 숫자카드에 적힌 수 <= 10,000,000
// (1 ≤ M ≤ 500,000)

// OUTPUT :  상근이가 가지고 있으면 1을, 아니면 0

#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int Npan[500000];
int Mpan[500000];

void solve(int target){
	
	int left = 0;
	int right = (N-1);
	bool tmp_flag = false;
	
	while(left <= right){
		
		int mid = (left + right) / 2;
		int cur = Npan[mid];
		if(cur > target){
			right = mid-1;
		}
		else if(cur < target){
			left = mid + 1;
		}
		else if(cur == target){
			tmp_flag = true;
			break;
		}
		
	}
	
	if(tmp_flag){
		printf("1 ");
	}
	else	printf("0 ");
	
}

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &Npan[i]);
	
	scanf("%d", &M);
	for(int i = 0 ; i < M ; ++i)	scanf("%d", &Mpan[i]);
	
	sort(Npan, Npan + N);
	
	for(int i = 0 ; i < M ; ++i){
		solve(Mpan[i]);	
	}
	
	return 0;
}
