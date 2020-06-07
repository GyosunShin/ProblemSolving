// 대문자 구성
// 1 <= 길이 <= 4000

// OUTPUT : 가장 긴 것의 길이를 출력

#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

char strA[4001];
char strB[4001];
string a, b;

int cache[4000][4000];

int dfs(int idx1, int idx2){	
	if(idx1 == (int)a.size() || idx2 == (int)b.size()){
		return 0;
	}

	int& ret = cache[idx1][idx2];
	if(ret != -1)	return ret;
	
	if(a[idx1] == b[idx2]){
		return ret = dfs(idx1 + 1, idx2 + 1) + 1;
	}
	else	return ret =  0;
}

int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%s", strA);
	scanf("%s", strB);
	
	a = string(strA);	b = string(strB);
	
	int answer = 0;
	
	for(int i = 0 ; i < a.size() ; ++i){
		for(int j = 0 ; j < b.size() ; ++j){
			answer = max(answer, dfs(i, j));
		}
	}
	
	printf("%d", answer);
		
	return 0;	
}


