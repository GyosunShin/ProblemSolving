// A의 부 배열의 합에 B의 부 배열의 합을 더해서 T

// (-1,000,000,000 ≤ T ≤ 1,000,000,000)
// n(1 ≤ n ≤ 1,000)   m(1≤m≤1,000)
// -1000000 <= 각 원소 <= 1000000 

// OUTPUT : 가능한 경우가 한 가지도 없을 경우에는 0을 출력한다.

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M;
int A[1000];
int B[1000];

long long ans;

vector<long long> sumA;
vector<long long> sumB;
vector<int> picked;

void dfsB(int start){
	
	if(picked.size() == 2){
		int src = picked[0];
		int dst = picked[1];
		long long sum = 0;
		for(int i = src ; i <= dst ; ++i)	sum += B[i];
		sumB.push_back(sum);
		return;
	}
	
	for(int i = start ; i < M ; ++i){
		picked.push_back(i);
		dfsB(i+1);
		picked.pop_back();
	}
	
}

void dfsA(int start){
	
	if(picked.size() == 2){
		int src = picked[0];
		int dst = picked[1];
		long long sum = 0;
		for(int i = src ; i <= dst ; ++i)	sum += A[i];
		sumA.push_back(sum);
		return;
	}
	
	for(int i = start ; i < N ; ++i){
		picked.push_back(i);
		dfsA(i+1);
		picked.pop_back();
	}
	
}

int main(){
	scanf("%d", &T);
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &A[i]);
		sumA.push_back(A[i]);
	}
	scanf("%d", &M);
	for(int i = 0 ; i < M ; ++i){
		scanf("%d", &B[i]);
		sumB.push_back(B[i]);
	}	
	
	dfsA(0);
	dfsB(0);
	
	sort(sumA.begin(), sumA.end());
	sort(sumB.begin(), sumB.end());
	
//	for(int i = 0 ; i < sumA.size() ; ++i){
//		printf("%d / ", sumA[i]);
//	}
//	printf("\n");
//	for(int i = 0 ; i < sumB.size() ; ++i){
//		printf("%d / ", sumB[i]);
//	}
//	printf("\n");	 
	
	for(int i = 0 ; i < sumA.size() ; ++i){
		long long cur = sumA[i];
		long long rem = T - cur;
		vector<long long>::iterator hi;
		hi = upper_bound(sumB.begin(), sumB.end(), rem);
		vector<long long>::iterator lo;
		lo = lower_bound(sumB.begin(), sumB.end(), rem);
		ans += (hi - lo);
	}
		
	printf("%lld", ans);
	
	return 0;
}

