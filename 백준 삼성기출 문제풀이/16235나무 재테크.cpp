// N, M, K(K년이 지난 후 살아남은 나무의 수 출력)
// 1 ≤ N ≤ 10
// 1 ≤ M ≤ N^2(=100)
// 1 ≤ K ≤ 1,000
// 1 ≤ A[r][c] ≤ 100
//  M개의 줄에는 상도가 심은 나무의 정보를 나타내는 세 정수 x, y, z가 주어진다.
//  처음 두 개의 정수는 나무의 위치 (x, y)를 의미하고, 마지막 정수는 그 나무의 나이를 의미한다.
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, K;
int A[10][10];
int 

priority_queue

struct tree{  // (x,y), z
	int r;
	int c;
	int age;
};

vector<tree> vec[100];

int main(){
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N; ++j){
			scanf("%d", &A[i][j]);
		}
	}
	for(int i = 0 ; i < M ; ++i){  // m개의 나무에 대한 ((x, y), z(나이))
		tree tmp;
		scanf("%d %d %d", &tmp.r, &tmp.c, &tmp.age);
		vec.push_back(tmp);
	}
	// ##########################################################################
	
	
	
	
}

  
