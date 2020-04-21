// (1 ≤ N ≤ 100,000)
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 중의 하나

// OUTPUT
// 첫째 줄에 얻을 수 있는 최대 점수와 최소 점수를 띄어서 출력한다.

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int pan[100000][3];

const int dc[] = {-1,0,1};

int cache[3];

int main(){
	
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < 3 ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	
	int mmax;
	cache[0] = pan[0][0];	cache[1] = pan[0][1];	cache[2] = pan[0][2];
	
	for(int i = 1 ; i < N ; ++i){
		
		int one = max(cache[0], cache[1]);
		int two = max(max(cache[0], cache[1]), cache[2]);
		int three = max(cache[1], cache[2]);
		
		cache[0] = pan[i][0] + one;
		cache[1] = pan[i][1] + two;
		cache[2] = pan[i][2] + three;
		
	}
	
	mmax = max(max(cache[0], cache[1]), cache[2]);
	
	int mmin;
	cache[0] = pan[0][0];	cache[1] = pan[0][1];	cache[2] = pan[0][2];
	
	for(int i = 1 ; i < N ; ++i){
		int one = min(cache[0], cache[1]);
		int two = min(min(cache[0], cache[1]), cache[2]);
		int three = min(cache[1], cache[2]);
		
		cache[0] = pan[i][0] + one;
		cache[1] = pan[i][1] + two;
		cache[2] = pan[i][2] + three;
	}
	
	mmin = min(min(cache[0], cache[1]), cache[2]);
	
	// 최댓값 최솟값
	printf("%d %d", mmax, mmin);
	
	return 0;
}
