#include <stdio.h>
#include <vector>

using namespace std;

int N, M, K;
int A[10][10];

vector<int> v[10][10];

int main(){
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &A[i][j]);	
		}
	}
	for(int i = 0 ; i < M ; ++i){  // (x, y) z(= ³ªÀÌ)
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		v[x-1][y-z].push_back(z);
	}
	//##########################################
	
	f
	
}
