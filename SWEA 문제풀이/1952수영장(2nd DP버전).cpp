// 가장 적은 비용으로 수영장을 이용할 수 있는 방법을 찾고 그 비용을 정답으로 출력하는 프로그램을 작성하라.

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, day, month, three, year;
int pan[12];
int cache[12];

int solve(int idx){

	if(idx >= 12)	return 0;
	
	int &ret = cache[idx];
	if(ret != -1)	return ret;
	
	ret = 0x7fffffff;
	
	int cnt;
	// 1일 이용권(안사는거 포함)
	cnt = pan[idx] * day;
	ret = min(ret, solve(idx + 1) + cnt);
	
	// 1달 사용권
	ret = min(ret, solve(idx + 1) + month); 
	
	// 3달 사용권
	ret = min(ret, solve(idx + 3) + three);
	
	// 1년 사용권 
	ret = min(ret, solve(idx + 12) + year);
	
	return ret;
}


int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		memset(cache, -1, sizeof(cache));
		scanf("%d %d %d %d", &day, &month, &three, &year);	
		for(int i = 0 ; i < 12 ; ++i)	scanf("%d", &pan[i]);
		
		printf("#%d %d\n", z, solve(0));
	}
	
	return 0;
}
