#include <cstdio>
#include <cstring>

int R, C;
int cache[301][301];

int dfs(int r, int c){
	
//	printf("%d / %d\n", r, c);
	
	if(r == 1 && c ==1){
		return 0;
	}
	
	int& ret = cache[r][c];
	if(ret != -1){
		return ret;
	}
	
	int tmp = 0;
	
	if(r == 1 && c != 1){
		tmp += dfs(r, c/2);
		tmp += dfs(r, c - (c/2));
	}
	else if(c == 1 && r != 1){
		tmp += dfs(r/2, c);
		tmp += dfs(r - (r/2), c);
	}
	else{
		tmp += dfs(r, c/2);
		tmp += dfs(r, c - (c/2));
	}
	
	return ret = tmp+1;
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	scanf("%d %d", &R, &C);
	
	int ret = dfs(R, C);
	
	printf("%d", ret);
	
	return 0;
}
