// 첫째 줄에 최소의 이동 횟수를 출력한다. 이동이 불가능한 경우 -1을 출력한다.

#include <stdio.h>
#include <queue>
#include <set>
#include <string>
#include <iostream>

using namespace std;

struct INFO{
	string map;
	int len;
	int r, c;
};

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

queue<INFO> q;

set<string> visited;


int trans(int a, int b){
	return (a*3) + b;
}

int bfs(){
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
//		cout << cur.len << "[] " << cur.map << endl;
//		cout << "CUR : " << cur.map << " / QSIZE : " << q.size() << endl;
		
		if(cur.map == "123456780"){
		 	return cur.len;
		 }
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
			
			if(0 > next_r || next_r >= 3 || 0 > next_c || next_c >= 3)	continue;
			int src = trans(cur.r, cur.c);
			int dst = trans(next_r, next_c); 
			string new_str = cur.map;
			char tmp = new_str[src];
			new_str[src] = new_str[dst];
			new_str[dst] = tmp;
			
			set<string>::iterator it;
			it = visited.find(new_str);
			if(!(it == visited.end()))	continue;
			INFO next;
			next.r = next_r;	next.c = next_c;
			next.len = cur.len + 1;
			next.map = new_str;
			visited.insert(new_str);
			q.push(next);
		}		
	}
	return -1;
}

int main(){
	int start_r, start_c;
	INFO start;
	for(int i = 0 ; i < 3 ; ++i){
		for(int j = 0 ; j < 3 ; ++j){
			char input;
			scanf("%c", &input);
			getchar();
			start.map += input;
			if(input == '0'){
				start_r = i;
				start_c = j;
			}
		}
	}
	start.len = 0;
	start.r = start_r;	start.c = start_c;
	visited.insert(start.map);
	q.push(start);
	
	int ans = bfs();
	printf("%d", ans);
	return 0;
}
