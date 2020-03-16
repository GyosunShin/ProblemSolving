// 자연수가 주어졌을 때, 이 자연수를 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램을 작성하시오.
// 1 ≤ N ≤ 4,000,000

#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int N;
bool primes[4000001];
int ans;

vector<int> ps;

void era(){
	
	for(int i = 2 ; i <= (int)sqrt(4000000) ; ++i){
		for(int j = i*i ; j <= 4000000 ; j = j+i){
			primes[j] = true;
		}
	}
	
	for(int i = 2 ; i <= N ; ++i){
		if(!primes[i])	ps.push_back(i);
	}
	
}

void solve(){
	
	int left = 0;	int right = 0;
	int sum = ps[0];
	
	while(true){
		
		if(left >= ps.size() || right >= ps.size())	break;
		
		if(sum == N){
			sum -= ps[left++];
			++ans;
		}
		else if(sum > N){
			sum -= ps[left++];
		}
		else{
			sum += ps[++right];
		}
		
	}
	
	
}

int main(){
	scanf("%d", &N);
	
	if(N==1){
		printf("%d", 0);
		return 0;
	}
	
	era();
	
	solve();
	
	printf("%d", ans);
	
	return 0;
}
