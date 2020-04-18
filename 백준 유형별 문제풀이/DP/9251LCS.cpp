
// 문자열 길이 <= 1000 

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string a, b;
int a_len, b_len;
int cache[1001][1001];

int dfs(int pos1, int pos2){
	
	if(pos1 == a_len || pos2 == b_len)	return 0;
	
	if(a[pos1] == b[pos2]){
		return dfs(pos1 + 1, pos2 + 1) + 1;
	}
	
	int& ret = cache[pos1][pos2];
	if(ret != -1)	return ret;
	ret = max(dfs(pos1 + 1, pos2), dfs(pos1, pos2 + 1));
	return ret;
		
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	cin >> a >> b;
	
	a_len = a.size();	b_len = b.size();
	
	printf("%d", dfs(0,0));
	
	return 0;
}
