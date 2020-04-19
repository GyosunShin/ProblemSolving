// (N �� M)
// (0 < N �� M < 30)

// OUTPUT
// �� �׽�Ʈ ���̽��� ���� �־��� �����Ͽ� �ٸ��� ���� �� �ִ� ����� ���� ����Ѵ�.

#include <cstdio> 

int T, N, M;
int cache[31][31];

int main(){
	scanf("%d", &T);
	
	for(int i = 1 ; i <= 30 ; ++i)	cache[1][i] = i;
	
	for(int i = 2 ; i <= 30 ; ++i){
		for(int j = i ; j <= 30 ; ++j){
			for(int k = 1 ; k <= j-i+1 ; ++k){
				cache[i][j] += cache[i-1][j-k];
			}
		}
	}
	
	for(int z = 1 ; z <= T ; ++z){
		scanf("%d %d", &N, &M);	
		printf("%d\n", cache[N][M]);
	}
	
	return 0;
}
