//  (1<=R,C<=20)

// OUTPUT : 말이 지날 수 있는 최대의 칸 수를 출력한다.

#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int R, C;
char pan[20][20];
bool visited[20][20];

bool cache[26];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

map<int, int> s[20][20];

int track = 0;

map<int, int>::iterator it;

int dfs(int r, int c){
	
	printf("%d / %d\n", r, c);
	
	it = s[r][c].find(track);
	if(it != s[r][c].end()){
		return it->second;
	}
	
	int mmax = 0;
	
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		
		if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || visited[next_r][next_c]
		|| cache[pan[next_r][next_c] - 'A'])	continue;
		track |= (1 << (pan[next_r][next_c] - 'A'));
		visited[next_r][next_c] = true;
		cache[pan[next_r][next_c] - 'A'] = true;
		
		mmax = max(mmax, dfs(next_r, next_c));
		
		track &= (((1 << 26) - 1) - (1 << (pan[next_r][next_c] - 'A')));
		visited[next_r][next_c] = false;
		cache[pan[next_r][next_c] - 'A'] = false;
	}
	
	s[r][c][track] = mmax;
	return mmax + 1;
}

int main(){
	scanf("%d %d", &R, &C);
	getchar();
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			char ch;
			scanf("%1c", &ch);
			pan[i][j] = ch;
		}
		getchar();
	}
	
//	for(int i = 0 ; i < R ; ++i){
//		for(int j = 0 ; j < C ; ++j){
//			printf("%c ", pan[i][j]) ;
//		}
//		printf("\n");
//	}
	
	visited[0][0] = true;
	cache[pan[0][0] - 'A'] = true;
	int tmp = pan[0][0] - 'A';
	track |= (1 << tmp);
	int ans = dfs(0,0);
	
	printf("%d", ans);
	
	return 0;
}



