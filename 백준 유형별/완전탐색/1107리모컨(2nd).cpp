// 현재 수빈이 채널 100 위치
// OUTPUT : 어떤 버튼이 고장났는지 주어졌을 때,
// 채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오.  

// INPUT :  N (0 ≤ N ≤ 500,000) --> 목표채널
// 고장난 버튼의 개수 M (0 ≤ M ≤ 10)  --> 일부 '숫자'  버튼만 고장! 


// (Exhaustive Search = Brute-Force Searching = 완전탐색) 기법 이용 
#include <stdio.h> 
#include <algorithm>

using namespace std;

int ans = 0x7fffffff;

int N, M;
int map[10];

int check(int n){
	int back_up = n;
	int cnt = 0;
	
	if(back_up / 10 == 0){
		int ttmp = back_up % 10;
		if(map[ttmp] == 1){
			return -1;
		}
		else	return 1;
	}
//	printf("N : %d / CNT : %d\n", n, cnt);
	
	while(back_up > 0){
		int ttmp = back_up % 10;
		if(map[ttmp] == 1){
			cnt = -1;
			break;
		}
		back_up /= 10;
		++cnt;
	}
//	if(map[back_up] == 1)	cnt=-1;
//	printf("N : %d / CNT : %d\n", n, cnt);
	return cnt;
}

int main(){
	scanf("%d", &N);  // 목표채널 
	scanf("%d", &M);  
	for(int i = 0 ; i < M ; ++i){
		int tmp;
		scanf("%d", &tmp);
		map[tmp] = 1;
	}
	//###############################
	
	int first = abs(100 - N);
	if(ans > first)	ans = first;
	
	for(int i = 0 ; i < 1000000 ; ++i){
		int tmp_diff;
		int tmp_chk = check(i); 
		if(tmp_chk != -1){    // -1안나오면 계기판으로 만들 수 있는 CASE 
			tmp_diff = abs(i - N);
			tmp_diff += tmp_chk;
			if(tmp_diff < ans)	ans = tmp_diff;
		}
		else	continue;
		
//		if(tmp_diff < ans)	ans = tmp_diff;
	}
	
	printf("%d", ans);
	return 0;
}
