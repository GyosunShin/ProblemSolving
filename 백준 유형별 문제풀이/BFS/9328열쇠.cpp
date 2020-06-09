
// 테스트 케이스<= 100
// (2 ≤ h, w ≤ 100)

// '.'      빈공간
// '*'      벽
// '$'      훔쳐야할 문서 
// 대문자   문
// 소문자   열쇠 

// OUTPUT : 상근이가 훔칠 수 있는 문서의 최대 개수

#include <cstdio> 
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int T, R, C; 
char pan[100][100];
bool visited[100][100][27];

char keyInput[27];
int keyHold[26];

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

int answer = 0;

set<pair<int, int>> target;

int keyNum(){
	int ret = 0;
	for(int i = 0 ; i < 27 ; ++i){
		if(keyHold[i] > 0)	ret++;
	}
	return ret;
}

bool canStart(int r, int c){
	if(pan[r][c] == '.')	return true;
	if('A' <= pan[r][c] && pan[r][c] <= 'Z' && keyHold[pan[r][c] - 'A'])	return true;
	return false;
}

int upperToLower(char input){
	return (input - 'A');
}

int dfs(int cur_r, int cur_c){
	
//	printf("<%d / %d> [%d]\n", cur_r, cur_c, keyNum());
	
	int local_sum = 0;
	
	// '.'      빈공간
	// '*'      벽
	// '$'      훔쳐야할 문서 
	// 대문자   문 
	// 소문자   열쇠 
	
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
		if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C
		|| pan[next_r][next_c] == '*')	continue;
		
		if('A' <= pan[next_r][next_c] && pan[next_r][next_c] <= 'Z'){
			if(keyHold[upperToLower(pan[next_r][next_c])] <= 0){
				continue;
			}
			else{
				if(visited[next_r][next_c][keyNum()])	continue;
				visited[next_r][next_c][keyNum()] = true;
				local_sum += dfs(next_r, next_c);
				visited[next_r][next_c][keyNum()] = false;	
			}
		}
		else if('a' <= pan[next_r][next_c] && pan[next_r][next_c] <= 'z'){
			keyHold[pan[next_r][next_c] - 'a']++;
			if(visited[next_r][next_c][keyNum()])	continue;
			visited[next_r][next_c][keyNum()] = true;
			local_sum += dfs(next_r, next_c);
			visited[next_r][next_c][keyNum()] = false;
			keyHold[pan[next_r][next_c] - 'a']--;
		}		
		else if(pan[next_r][next_c] == '$'){
			if(visited[next_r][next_c][keyNum()])	continue;
			visited[next_r][next_c][keyNum()] = true;
			local_sum += dfs(next_r, next_c) + 1;
			target.insert(make_pair(next_r, next_c));
			visited[next_r][next_c][keyNum()] = false;	
		}
		else{
			if(visited[next_r][next_c][keyNum()])	continue;
			visited[next_r][next_c][keyNum()] = true;
			local_sum += dfs(next_r, next_c);
			visited[next_r][next_c][keyNum()] = false;	
		}
	}
	
	return local_sum;
}

void solve(){
	
	// 빌딩 가장자리의 빈 공간이나 문을 통해 빌딩 안팎을 드나들 수 있다
	for(int i = 0 ; i < C ; ++i){
		if(canStart(0, i)){
//			printf("START [%d / %d]\n", 0, i);
			visited[0][i][keyNum()] = true;
			answer = max(answer, dfs(0, i));
			visited[0][i][keyNum()] = false;
		}
		if(canStart(R-1, i)){
//			printf("START [%d / %d]\n", R-1, i);
			visited[R-1][i][keyNum()] = true;
			answer = max(answer, dfs(R-1, i));
			visited[R-1][i][keyNum()] = false;
		}
	}
	for(int i = 1 ; i < R-1 ; ++i){
		if(canStart(i, 0)){
//			printf("START [%d / %d]\n", i, 0);
			visited[i][0][keyNum()] = true;
			answer = max(answer, dfs(i, 0));
			visited[i][0][keyNum()] = false;
		}
		if(canStart(i, C-1)){
//			printf("START [%d / %d]\n", i, C-1);
			visited[i][C-1][keyNum()] = true;
			answer = max(answer, dfs(i, C-1));
			visited[i][C-1][keyNum()] = false;
		}
	}
	
}

int main(){
	scanf("%d", &T);
		
	for(int z = 1 ; z <= T ; ++z){
		target.clear();
		answer = 0;
		memset(keyHold, 0, sizeof(keyHold));
		scanf("%d %d", &R, &C);
		getchar();
		for(int i = 0 ; i < R ; ++i){
			for(int j = 0 ; j < C ; ++j){
				scanf("%1c", &pan[i][j]);
			}
			getchar();
		}
		
		scanf("%s", keyInput);
		if(keyInput[0] != '0'){
			for(int i = 0 ; i < strlen(keyInput) ; ++i)	keyHold[keyInput[i] - 'a']++;
		}
		
		solve();
		
		printf("%d\n", target.size());
	}
	
	return 0;
}
