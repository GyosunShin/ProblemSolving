// 피자가게에서 손님이 원하는 크기의 피자를 판매하는 모든 방법의 가지 수를 계산하는 프로그램을 작성하시오

// INPUT
// 손님이 원하는 피자 : 1 <= N <= 2000000 
// 피자조각 개수 M N   ( 3≤m, n≤1000)
// 1 <= 각 피자 조각의 크기 <= 1000 

#include <stdio.h> 
#include <vector>
#include <algorithm>

using namespace std;

int N, A, B;
int mapA[1000];
int mapB[1000];

vector<int> sumA;
vector<int> sumB;

vector<int> picked;

int ans;

void dfsB(int start){
	
	if(picked.size() == 2){
		int src = picked[0];
		int dst = picked[1];
		if(dst - src + 1 == B)	return;
		if(dst - src + 1 > B || src >= B)	return;
		
		int tmp_sum = 0;
		if(dst >= B)	dst -= B;
		
		if(dst < src){
			for(int i = src ; i < B ; ++i){
				tmp_sum += mapB[i];
			}
			for(int i = 0 ; i <= dst ; ++i){
				tmp_sum += mapB[i];
			}
		}
		else{
			for(int i = src ; i <= dst ; ++i){
				tmp_sum += mapB[i];
			}
		}
		if(tmp_sum == N)	++ans;
		
		sumB.push_back(tmp_sum);
		
		return;
	}
	
	for(int i = start ; i < (B*2) - 1 ; ++i){
		picked.push_back(i);
		dfsB(i+1);
		picked.pop_back();
	}
	
}

void dfsA(int start){
	
	if(picked.size() == 2){
		int src = picked[0];
		int dst = picked[1];
		if(dst - src + 1 == A)	return;
		if(dst - src + 1 > A || src >= A)	return;
		
		int tmp_sum = 0;
		if(dst >= A)	dst -= A;
		
		if(dst < src){
			for(int i = src ; i < A ; ++i){
				tmp_sum += mapA[i];
			}
			for(int i = 0 ; i <= dst ; ++i){
				tmp_sum += mapA[i];
			}
		}
		else{
			for(int i = src ; i <= dst ; ++i){
				tmp_sum += mapA[i];
			}
		}
		if(tmp_sum == N)	++ans;
		
		sumA.push_back(tmp_sum);
		
		return;
	}
	
	for(int i = start ; i < (A*2) - 1 ; ++i){
		picked.push_back(i);
		dfsA(i+1);
		picked.pop_back();
	}
	
}

int main(){
	scanf("%d", &N);
	scanf("%d %d", &A, &B);
	int tmp = 0;
	int ttmp = 0;
	for(int i = 0 ; i < A ; ++i){
		scanf("%d", &mapA[i]);	
		if(mapA[i] == N)	++ans;
		sumA.push_back(mapA[i]);
		tmp += mapA[i];
	}
	for(int i = 0 ; i < B ; ++i){
		scanf("%d", &mapB[i]);	
		if(mapB[i] == N)	++ans;
		sumB.push_back(mapB[i]);
		ttmp += mapB[i];
	}
	
	dfsA(0);
	dfsB(0);
	sumA.push_back(tmp);
	if(tmp == N)	++ans;
	sumB.push_back(ttmp);
	if(ttmp == N)	++ans;
	
	sort(sumA.begin(), sumA.end());
	sort(sumB.begin(), sumB.end());

//	for(int i = 0 ; i < sumA.size() ; ++i){
//		printf("%d  /  ", sumA[i]);
//	}
//	printf("\n");
//	for(int i = 0 ; i < sumB.size() ; ++i){
//		printf("%d  /  ", sumB[i]);
//	}	
//	printf("\n");
	
	for(int i = 0 ; i < sumA.size() ; ++i){
		int cur = sumA[i];
		int rem = N - cur;
		vector<int>::iterator hi; 	
		hi = upper_bound(sumB.begin(), sumB.end(), rem);
		vector<int>::iterator lo;
		lo = lower_bound(sumB.begin(), sumB.end(), rem);
		ans += (hi - lo);
	}
	
	printf("%d", ans);
	
	return 0;
}
