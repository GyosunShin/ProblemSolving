#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

////최대 증가 부분 수열 문제를 해결하는 완전 탐색 알고리즘
//int lis(const vector<int>& A){
//	//기저사례 : A가 텅 비어 있을때
//	if(A.empty())  return 0;
//	int ret = 0;
//	for(int i =  ; i < A.size() ; i++){
//		vector<int> B;
//		for(int j = i+1 ; j < A.size() ; j++){
//			if(A[i] < A[j])
//				B.push_back(A[j]);
//			ret = max(ret, 1 + lis(B));
//		}
//		return ret;
//	}
//}

int n;
int cache[100];
int s[100];

int lis2(int start){
	int& ret = cache[start];
	if(ret != -1) return ret;
	
	// 항상 s[start] 는 있기 때문에 길이는 최소 1
	ret = 1;
	for(int next = start + 1 ; next < n ; next++) {
		if(s[start] < s[next])
			ret = max(ret, lis2(next) + 1);
	}
	return ret;
}



	
