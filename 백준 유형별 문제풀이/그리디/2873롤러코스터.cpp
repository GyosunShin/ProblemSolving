#include <cstdio> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int R, C;
int pan[1000][1000];
int cache[1000][1000];
bool visited[1000][1000];

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};
const char cc[] = {'U', 'D', 'L', 'R'};

vector<char> ans;

int dfs(int r, int c){
	
	if(r == R-1 && c == C-1)	return pan[r][c];
	
	int& ret = cache[r][c];
	if(ret != -1)	return ret;
	
	int mmax = 0;
	int who;
	
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		
		if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C
		|| visited[next_r][next_c])	continue;
		visited[next_r][next_c] = true;
		
		int tmp =dfs(next_r, next_c) + pan[r][c];
		if(mmax < tmp){
			who = dir;
			mmax = tmp;
		}
		
		visited[next_r][next_c] = false;
	}
	
	ans.push_back(cc[who]);
	
	return ret = mmax;
}

int main(){
	memset(cache, -1, sizeof(cache));
	
	scanf("%d %d", &R, &C);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < R ; ++j){	
			scanf("%d", &pan[i][j]);	
		}
	}
	
	visited[0][0] = true;
	int ret = dfs(0,0);
	
	vector<char>::reverse_iterator rit;
	for(rit = ans.rbegin() ; rit != ans.rend() ; ++rit)	cout << *rit;
	
	return 0;
}
