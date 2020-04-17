// (1 ¡ÂN ¡Â 1,000, 0 ¡ÂK ¡Â N)

#include <cstdio>
#include <vector>

using namespace std;

int N, K;

vector<int> a, b;

int main(){
	
	scanf("%d %d", &N, &K);
	
	int start = 1;
	
	for(int i = 0 ; i < K ; ++i){
		a.push_back(N);
		N--;
		b.push_back(start);
		start++;
	}
	
	for(int i = 0 ; i < b.size() ; ++i){
		int cur = b[i];
		if(cur == 1)	continue;
		for(int j = 0 ; j < a.size() ; ++j){
			
			int ccur = a[j];
			
			if(ccur % cur == 0){
				a[j] /= cur;
				b[i] = 1;
				break;
			}
		}
	}
	
	for(int i = 0 ; i < a.size() ; ++i){
		printf("%d  ", a[i]);
	}
	printf("\n");
	for(int i = 0 ; i < b.size() ; ++i){
		printf("%d  ", b[i]);
	}
	
	long long ans = 1;
	for(int i = 0 ; i < a.size() ; ++i){
		ans *= a[i];
		ans %= 10007;
	}
	
	
	
	return 0;
}
