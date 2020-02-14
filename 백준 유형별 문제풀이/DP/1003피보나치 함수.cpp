// OUTPUT : 0이 출력되는 횟수와 (공백) 1이 출력되는 횟수  

#include <stdio.h>  
#include <string.h>
#include <vector>

using namespace std;

int T;
int zero;
int one;

int cache[41];
int cache2[41];
int cache3[41];

vector<pair<int, int> > v;

int solve(int n) {   // 0 <= N <= 40
//	printf("N : %d\n", n);
	if(n == 0){
//		printf("++ZERO\n");
		++zero;
		return 0;
	}	
	if(n == 1){
//		printf("++ONE\n");
		++one;
		return 1;
	}	
	
	
	
	int& ret = cache[n];
	if(ret != -1){
		if(cache2[n] == -1 && cache3[n] == -1){
			cache2[n] = cache2[n-1] + cache2[n-2];	cache3[n] = cache3[n-1] + cache3[n-2];
		}
		zero += cache2[n];	one += cache3[n];
		return ret;
	}	
	
	ret = solve(n-1) + solve(n-2);
//	printf("SOLVE(%d) + SOLVE(%d)\n", n-1, n-2);
	return ret;
}

int main(){
	scanf("%d", &T);
	for(int i = 0 ; i < T ; ++i){
		memset(cache, -1, sizeof(cache));
		memset(cache2, -1, sizeof(cache2));  // for) zero
		memset(cache3, -1, sizeof(cache3));  // for) one
		cache2[0] = 1;	cache2[1] = 0;
		cache3[0] = 0;	cache3[1] = 1;
		
		zero = 0;	one = 0;	
		int N;  
		scanf("%d", &N);
		
		solve(N);
		printf("%d %d\n", zero, one);
//		v.push_back(pair<int, int>(zero, one));
	}
	
//	for(int i = 0 ; i < v.size() ; ++i){
//		printf("%d %d\n", v[i].first, v[i].second);
//	}
	
	return 0;
}





