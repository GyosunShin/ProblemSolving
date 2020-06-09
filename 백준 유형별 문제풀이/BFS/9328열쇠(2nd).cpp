	// 상근이가 훔칠 수 있는 문서의 최대 개수

// 1 <= 테스트케이스 <= 100
// (2 ≤ h, w ≤ 100) 

// '.'		빈 공간
// '*'		벽
// '$' 		문서
// 대문자	문
// 소문자	열쇠 

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int T, R, C, answer;
char pan[102][102];
bool visited[102][102];

bool keys[26];

queue<pair<int, int>> q;

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

set<pair<int, int>> ans;

bool scopeCheck(int r, int c){
	if(0 > r || r >= R+2 || 0 > c || c >= C+2)	return false;
	return true;
}

void borderFill(){
	
	for(int i = 0 ; i <= C+1 ; ++i){
		pan[0][i] = '.';
		pan[R+1][i] = '.';
	}
	
	for(int i = 0 ; i <= R+1 ; ++i){
		pan[i][0] = '.';
		pan[i][C+1] = '.';
	}
	
}

char toLowerCase(char input){
	return input + ('a' - 'A');
}

void solve(){
	
	visited[0][0] = true;
	q.push(make_pair(0, 0));
	
	while(!q.empty()){
		int cur_r = q.front().first;	int cur_c = q.front().second;
		q.pop();
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			
			if(!scopeCheck(next_r, next_c))	continue;
			if(visited[next_r][next_c])	continue;
			
			if(pan[next_r][next_c] == '*')	continue;
			else if(pan[next_r][next_c] == '$'){
				answer++;
				pan[next_r][next_c] = '.';
				ans.insert(make_pair(next_r, next_c));
			}
			else if('A' <= pan[next_r][next_c] && pan[next_r][next_c] <= 'Z'){
				if(!keys[pan[next_r][next_c] - 'A'])	continue;
			}
			else if('a' <= pan[next_r][next_c] && pan[next_r][next_c] <= 'z'){
				if(!keys[pan[next_r][next_c] - 'a']){
					keys[pan[next_r][next_c] - 'a'] = true;
						
					memset(visited, false, sizeof(visited));
					while(!q.empty())	q.pop();
					visited[0][0] = true;
					q.push(make_pair(0, 0));
					break;						
				}
			}
			
			q.push(make_pair(next_r, next_c));
			visited[next_r][next_c] = true;
			
		}	// End of for(dir = 0 ; dir < 4 ; ++dir)
		
	}	// End of while(!q.empty())
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		ans.clear();
		memset(keys, false, sizeof(keys));
		memset(visited, false, sizeof(visited));
		answer = 0;
		scanf("%d %d", &R, &C);
		getchar();
		for(int i = 1 ; i <= R ; ++i){
			for(int j = 1 ; j <= C ; ++j){
				scanf("%1c", &pan[i][j]);
			}
			getchar();
		}
		char keyInput[27];
		scanf("%s", keyInput);
		if(keyInput[0] != '0'){
			for(int i = 0 ; i < strlen(keyInput) ; ++i){
				keys[keyInput[i] - 'a'] = true;				
			}
		}
		
		borderFill();
		
		solve();
		
		printf("%d\n", ans.size());
	}
	
	return 0;
}
