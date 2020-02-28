// 1글자 <= 각 단어 <= 10글자 
// (1 <= N <= 10)
// 테스트 케이스의 수 C(C <= 50)

#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

char pan[5][5];
int T, N;
string strs[10];

const int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

bool bfs(int r, int c, string input){
	
	queue<pair<int, pair<int, int> > > q;
	q.push(make_pair(0, make_pair(r, c)));
	
	while(!q.empty()){
		int cur_r = q.front().second.first;	int cur_c = q.front().second.second;	int cur_cnt = q.front().first;
//		printf("%d / %d  [%c]\n",cur_r, cur_c, pan[cur_r][cur_c]);
		q.pop();
		if(cur_cnt == input.size()-1)	return true;
		
		for(int dir = 0 ; dir < 8 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			if(0 > next_r || next_r >= 5 || 0 > next_c || next_c >= 5
			|| pan[next_r][next_c] != input[cur_cnt+1])	continue;
			q.push(make_pair(cur_cnt + 1, make_pair(next_r, next_c)));
		}
		
	}
	return false;
}

void solve(){
	
	for(int z = 0 ; z < N ; ++z){
		
		bool tmp_flag = false;
		for(int i = 0 ; i < 5 ; ++i){
			if(tmp_flag)	break;
			for(int j = 0 ; j < 5 ; ++j){
				if(pan[i][j] == strs[z][0]){
					if(bfs(i, j, strs[z])){
						tmp_flag = true;
						break;
					}
				}
			}
		}
		if(tmp_flag)	cout << strs[z] << " YES" << endl;
		else	cout << strs[z] << " NO" << endl;		
		
	}
	
}

int main(){
	scanf("%d", &T);
	getchar();
	for(int z = 1 ; z <= T ; ++z){
		
		for(int i = 0 ; i < 5 ; ++i){
			for(int j = 0 ; j < 5 ; ++j){
				scanf("%1c", &pan[i][j]);
			}
			getchar();
		}		
		
		scanf("%d", &N);	
		for(int i = 0 ; i < N ; ++i){
			cin >> strs[i];
		}
		
		solve();
		
	}
	
	return 0;
}
