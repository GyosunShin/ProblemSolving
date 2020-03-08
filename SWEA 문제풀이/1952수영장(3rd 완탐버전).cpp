#include <cstdio>
#include <algorithm>

using namespace std;

int T, day, month, three, year;
int pan[12];

int solve(int idx){
	
	if(idx >= 12)	return 0;
	
	int tmp_ret = 0x7fffffff;
	
	tmp_ret = min(tmp_ret, solve(idx+1) + (pan[idx] * day));
	
	tmp_ret = min(tmp_ret, solve(idx+1) + month);
	
	tmp_ret = min(tmp_ret, solve(idx+3) + three);
	
	tmp_ret = min(tmp_ret, solve(idx+12) + year);
	 
	return tmp_ret;
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		scanf("%d %d %d %d", &day, &month, &three, &year);	
		for(int i = 0 ; i < 12 ; ++i)	scanf("%d", &pan[i]);
		
		int ans = solve(0);
		
		// OUTPUT : 가장 적게 지출하는 비용
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}
