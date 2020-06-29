// 'S'(이다‘솜’파) 'Y'(임도‘연’파)

#include <cstdio>
#include <cstring> 
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

char pan[5][5];
bool backup[5][5];
bool visited[5][5];

int answer;

vector<pair<int ,int>> picked;

queue<pair<int ,int>> q;

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

bool rangeCheck(int r, int c){
	if(0 > r || r >= 5 || 0 > c || c >= 5)	return false;
	return true;
}

bool bfs(int r, int c){
	
	memset(visited, false, sizeof(visited));
	
	visited[r][c] = true;
	q.push(make_pair(r, c));
	
	int cnt = 0;
	
	while(!q.empty()){
		int cur_r = q.front().first;	int cur_c = q.front().second;
		q.pop();
		cnt++;
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			if(!rangeCheck(next_r, next_c))	continue;
			if(visited[next_r][next_c])	continue;
			if(!backup[next_r][next_c])	continue;
			visited[next_r][next_c] = true;
			q.push(make_pair(next_r, next_c));
		}
	}
	
	if(cnt < 7)	return false;
	return true;
}

bool check(){
	bool ret = false;
	
	//  ‘이다솜(S)파’의 학생이 적어도 4명 이상은 반드시 포함되어 있어야 한다.
	int sc = 0;
	for(int i = 0 ; i < picked.size() ; ++i){
		if(pan[picked[i].first][picked[i].second] == 'S')	sc++;
		backup[picked[i].first][picked[i].second] = true;
	}
	if(sc < 4){
		for(int i = 0 ; i < picked.size() ; ++i){
			backup[picked[i].first][picked[i].second] = false;
		}			
		return false;
	}
	
	// 7명의 자리는 서로 가로나 세로로 반드시 인접해 있어야 한다.
	if(bfs(picked[0].first, picked[0].second)){
		ret = true;
	}
	
	for(int i = 0 ; i < picked.size() ; ++i){
		backup[picked[i].first][picked[i].second] = false;
	}	
	
	return ret;
}

void dfs(int r, int c, int cnt){
	
	if(cnt == 7){		
		if(check())	++answer;
		return;
	}
	
	for(int i = r ; i < 5 ; ++i){
		for(int j = c ; j < 5 ; ++j){
			int next_r = i;	int next_c = j+1;
			if(next_c >= 5){
				next_c = 0;
				next_r++;
			}
			picked.push_back(make_pair(i, j));
			dfs(next_r, next_c, cnt+1);
			picked.pop_back();
		}
		c = 0;
	}
	
}

void solve(){
	
	for(int i = 0 ; i < 5 ; ++i){
		for(int j = 0 ; j < 5 ; ++j){
			picked.push_back(make_pair(i, j));
			int next_r = i;	int next_c = j+1;
			if(next_c >= 5){
				next_c = 0;
				next_r++;
			}			
			dfs(next_r, next_c, 1);
			picked.pop_back();
		}
	}
	
}

int main(){
	
	for(int i = 0 ; i < 5 ; ++i){
		for(int j = 0 ; j < 5 ; ++j){
			scanf("%1c", &pan[i][j]);
		}
		getchar();
	}
	
	solve();
	
	// OUTPUT
	//  ‘소문난 칠공주’를 결성할 수 있는 모든 경우의 수를 출력한다.
	printf("%d", answer);
	
	return 0;
}
