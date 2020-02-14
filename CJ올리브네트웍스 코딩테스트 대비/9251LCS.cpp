#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

// INPUT : 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.
using namespace std;

int cache[1001][1001];

string str1;
string str2;

int len1, len2;

int solve(int n1, int n2){
	if(n1 == (len1) || n2 == (len2))	return 0;
	if(str1[n1] == str2[n2])	return 1 + solve(n1 + 1, n2 + 1);
	int& ret = cache[n1][n2];
	if(ret != -1)	return ret;
	ret = max(solve(n1+1, n2), solve(n1, n2+1));
	return ret;
}

int main(){
	memset(cache, -1, sizeof(cache));
	cin >> str1;
	cin >> str2;
	
	len1 = str1.size();
	len2 = str2.size();
		
	int ans = solve(0, 0);
	printf("%d", ans);
	return 0;	
}
