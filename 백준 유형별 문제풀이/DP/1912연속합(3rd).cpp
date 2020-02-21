// (1 ¡Â n ¡Â 100,000)
// -1000 <= °¢ ¼ö <= 1000

#include <cstdio> 
#include <algorithm>

using namespace std;

int N;
int pan[100000];
int cache[100000];

int ans = -1 * 0x7fffffff;

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	int sum = 0;
	for(int i = 0 ; i < N ; ++i){
		sum += pan[i];
		if(sum < pan[i])	sum = pan[i];
		cache[i] = sum;
		ans = max(ans, cache[i]);
	}
	
	printf("%d  ", ans);
	
	return 0;
}
