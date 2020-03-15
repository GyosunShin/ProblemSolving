#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int pan[3][3];

set<string> visited;
queue<pair<string, int> > q;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int start_r, start_c;

const string ans = "123456780";

int bfs(){
	
	while(!q.empty()){
		int empty_idx;
		string cur = q.front().first;	int cur_cnt = q.front().second;
		q.pop();
//		cout << "CUR : " << cur << " / QSIZE : " << q.size() << endl;
		if(cur == ans){
			return cur_cnt;
		}
		for(int i = 0 ; i < cur.size() ; ++i){
			if(cur[i] == '0'){
				empty_idx = i;
				break;
			}
		}
		
		int cur_r = empty_idx / 3;
		int cur_c = empty_idx % 3;
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			if(0 > next_r || next_r >= 3 || 0 > next_c || next_c >= 3)	continue;
			
			string next = cur;
			next[cur_r*3 + cur_c] = cur[next_r*3 + next_c];
			next[next_r*3 + next_c] = '0';
			
			set<string>::iterator it;
			
			it = visited.find(next);
			if(!(it == visited.end()))	continue;

//			for(it = visited.begin() ; it != visited.end() ; ++it){
//				if(*it == next)	break;
//			}
//			if(it != visited.end()){
//				continue;
//			}
			
			visited.insert(next);
			q.push(make_pair(next, cur_cnt + 1));
//			printf("NEXT\n");
		}
		
	}
	return -1;
	
}

int main(){
	string start;
	for(int i = 0 ; i < 3 ; ++i){
		for(int j = 0 ; j < 3 ; ++j){
			scanf("%d", &pan[i][j]);
			start += to_string(pan[i][j]);
			if(pan[i][j] == 0){
				start_r = i;	start_c = j;
			}
		}
	}
	
	visited.insert(start);
	q.push(make_pair(start, 0));
	int ret = bfs();
	
	// OUTPUT 
	// 첫째 줄에 최소의 이동 횟수를 출력한다. 이동이 불가능한 경우 -1을 출력한다.
	printf("%d", ret);
	
	return 0;
}
