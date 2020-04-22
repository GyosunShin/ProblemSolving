// 문자열은 대문자로 구성되어 있으며, 길이는 1 이상 4000 이하이다.

// OUTPUT
// 첫째 줄에 두 문자열에 모두 포함 된 부분 문자열 중 가장 긴 것의 길이를 출력한다.

#include <iostream> 
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

string a, b;
int a_len, b_len;

int cache[2][4000][4000];

int dfs(int idx1, int idx2, bool flag){
	
	if(idx1 == a_len || idx2 == b_len)	return 0;
	
	int tmp_flag;
	if(flag)	tmp_flag = 1;
	else	tmp_flag = 0;
	
	int& ret = cache[tmp_flag][idx1][idx2];
	if(ret != -1)	return ret;
	
	int mmax = -1;
	
	if(!flag){	
		mmax = max(mmax, dfs(idx1 + 1, idx2, false));
		mmax = max(mmax, dfs(idx1, idx2 + 1, false));
		if(a[idx1] == b[idx2]){
			mmax = max(mmax, dfs(idx1 + 1, idx2 + 1, true) + 1);
		}
		
	}
	else{
		if(a[idx1] != b[idx2])	return 0;
		mmax = max(mmax, dfs(idx1 + 1, idx2 + 1, true) + 1);
	}
	
	return ret = mmax;
}

int main(){
	cin >> a >> b;
	
	a_len = a.size();
	b_len = b.size();
	
	memset(cache, -1, sizeof(cache));
	
	printf("%d", dfs(0,0,false));
	
	return 0;
}




