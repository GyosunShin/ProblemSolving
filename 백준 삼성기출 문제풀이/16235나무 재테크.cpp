// N, M, K(K���� ���� �� ��Ƴ��� ������ �� ���)
// 1 �� N �� 10
// 1 �� M �� N^2(=100)
// 1 �� K �� 1,000
// 1 �� A[r][c] �� 100
//  M���� �ٿ��� �󵵰� ���� ������ ������ ��Ÿ���� �� ���� x, y, z�� �־�����.
//  ó�� �� ���� ������ ������ ��ġ (x, y)�� �ǹ��ϰ�, ������ ������ �� ������ ���̸� �ǹ��Ѵ�.
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
	for(int i = 0 ; i < M ; ++i){  // m���� ������ ���� ((x, y), z(����))
		tree tmp;
		scanf("%d %d %d", &tmp.r, &tmp.c, &tmp.age);
		vec.push_back(tmp);
	}
	// ##########################################################################
	
	
	
	
}

  
