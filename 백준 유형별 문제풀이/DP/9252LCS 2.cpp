// 알파벳 대문자 &  <= 1000 

// OUTPUT 
// 첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를, 둘째 줄에 LCS를 출력한다.
// LCS가 여러 가지인 경우에는 아무거나 출력하고, LCS의 길이가 0인 경우에는 둘째 줄을 출력하지 않는다.

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

string a, b;
int a_len, b_len;

int cache[1001][1001];

string ans;

int dfs(int idx1, int idx2){
	
	if(idx1 == a_len || idx2 == b_len)	return 0;
	
	int& ret = cache[idx1][idx2];
	if(ret != -1)	return ret;
	
	if(a[idx1] == b[idx2]){
		return ret = dfs(idx1 + 1, idx2 + 1) + 1;
	}
	
	ret = max(dfs(idx1 + 1, idx2), dfs(idx1, idx2 + 1));
	
	return ret;
	
}

void reconstruct(int idx1, int idx2){
	
	if(idx1 == a_len || idx2 == b_len)	return;
	
	if(a[idx1] == b[idx2]){
		ans += a[idx1];
		reconstruct(idx1+1, idx2+1);
		return;
	}
	
	if(cache[idx1+1][idx2] > cache[idx1][idx2+1]){
		reconstruct(idx1+1, idx2);
	}
	else	reconstruct(idx1, idx2+1);
	
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	cin >> a >> b;
	
	a_len = a.size();	b_len = b.size();
	
	printf("%d\n", dfs(0, 0));
	
	
	reconstruct(0, 0);
	cout << ans;
	
	return 0;
}






