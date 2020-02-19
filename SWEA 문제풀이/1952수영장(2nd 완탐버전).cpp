// 가장 적은 비용으로 수영장을 이용할 수 있는 방법을 찾고 그 비용을 정답으로 출력하는 프로그램을 작성하라.

#include <cstdio>
#include <algorithm>

using namespace std;

int T, day, month, three, year;
int pan[12];

int solve(int whatkind, int m){	// (whatkinf : 0(day) / 1(month) / 2(3 months) / 3(year))
	int ret = 0x7fffffff;

	if(m>= 12)	return 0;
	
	int cost;
	
	// day
	if(whatkind == 0){
		cost = pan[m] * day;
//		printf("DAY_COOST : %d\n", cost);
		
		for(int i = 0 ; i < 4 ; ++i)	ret = min(ret, solve(i, m+1) + cost);		
	}
	
	// month
	if(whatkind == 1){
		if(pan[m] < 0)	cost = 0;
		else	cost = month;
//		printf("MONTH_COOST : %d\n", cost);
		
		for(int i = 0 ; i < 4 ; ++i)	ret = min(ret, solve(i, m+1) + cost);	
	}
	
	// 3 months
	if(whatkind == 2){
		cost = three;
//		printf("33MONTH_COOST : %d\n", cost);
		for(int i = 0 ; i < 4 ; ++i)	ret = min(ret, solve(i, m+3) + cost);	
	}	
	
	// year
	if(whatkind == 3){
		cost = year;
//		printf("YEAR_COOST : %d\n", cost);
		
		for(int i = 0 ; i < 4 ; ++i)	ret = min(ret, solve(i, m+12) + cost);	
	}	

	return ret;	
}


int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		
		scanf("%d %d %d %d", &day, &month, &three, &year);	
		for(int i = 0 ; i < 12 ; ++i)	scanf("%d", &pan[i]);
		
		int ans = 0x7fffffff;
		
		for(int i = 0 ; i < 4 ; ++i){
			ans = min(ans, solve(i, 0));
		}
		
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}
