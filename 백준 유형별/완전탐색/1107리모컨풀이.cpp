#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

int check(int);
int X[10];  // 보니까 처음에는 다 0으로 초기화되네.. 

// N : 희망하는 채널
// M : 고장난 버튼의 개수 
int ans, N, M;

int main(){
	scanf("%d%d", &N, &M);
	for(int i = 0 ; i < M ; ++i){
		int n;
		scanf("%d", &n);
		X[n] = 1; //고장난 애들 
	}
	ans = abs(100 - N);
	
	for(int i = 0 ; i <= 1000000 ; ++i){
		// check라는 함수에서 각 자릿수에 해당하는 숫자가
		// 고장난 숫자이면 0을 return
		// 고장난 버튼이 아니라면 i에 대한 length반환 
		int len = check(i);
		
		// i에 고장난 버튼이 하나도 없는 경 우  
		if(len)
			ans = min(abs(N - i) + len, ans);
		cout << "test : "  << ans << endl;
	}
	cout << ans;
}


int check(int num){  // 0 ~ 1백만 까지 체크한다. 
	string s = to_string(num);
	int len = s.length();
	for(int i = 0 ; i < len ; ++i){
		if(X[s[i] - '0']) // 고장난 버튼이라면 return 0한다 
			return 0;
	}
	return len;
	// 결국 고장난 버튼이 하나도 없다면 아예 length반환! 
}


