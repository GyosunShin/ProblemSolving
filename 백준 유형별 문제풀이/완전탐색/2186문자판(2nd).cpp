// 영단어를 만들 수 있는 경로가 총 몇 개 존재하는지 알아내는 프로그램을 작성하시오.
// N(1 ≤ N ≤ 100), M(1 ≤ M ≤ 100), K(1 ≤ K ≤ 5)
// 1자 이상 80자 이하의 영단어가 주어진다

// !! 같은 칸을 여러 번 방문할 수 있다 !!

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int R, C, K;
char pan[100][100];
int cache[100][100][81];
string target;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int solve(int start_r, int start_c, int sofar){
	
	if(sofar == target.size()){
		return 1;
	}
	
	int& ret = cache[start_r][start_c][sofar];
	if(ret != -1)	return ret;
	
	
	int tmp_ret = 0;
	for(int dir = 0 ; dir < 4 ; ++dir){
		for(int k = 1 ; k <= K ; ++k){
			
			int next_r = start_r + (dr[dir]*k);	int next_c = start_c + (dc[dir]*k);
			if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || (pan[next_r][next_c] != target[sofar]))	continue;
			tmp_ret += solve(next_r, next_c, sofar+1);
			
		}
	}
	
	return ret = tmp_ret;
	
}


int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d %d %d", &R, &C, &K);
	getchar();
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%1c", &pan[i][j]);
		}
		getchar();
	}
	cin >> target;
	
	
	int ans = 0;
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			if(pan[i][j] == target[0]){
				ans += solve(i, j, 1);	
			}
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
