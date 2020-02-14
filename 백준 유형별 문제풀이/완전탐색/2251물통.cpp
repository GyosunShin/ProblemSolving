// A, B, C(1≤A, B, C≤200)

#include <stdio.h> 
#include <iostream> 
#include <string.h> 
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct INFO{
	int map[3];  // a, b, c
};
queue<INFO> q;

bool visited[201][201][201];

int limit[3];

set<int> ans;

const int dr[] = {0,0,1,1,2,2};
const int dc[] = {1,2,2,0,0,1};

void bfs(){
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		
//		printf("<%d> <%d> <%d>\n", cur.map[0], cur.map[1], cur.map[2]);
		// 첫 번째 물통(용량이 A인)이 비어 있을 때, 세 번째 물통(용량이 C인)에 담겨있을 수 있는 물의 양
		if(cur.map[0] == 0){
			ans.insert(cur.map[2]);
		}
		
		// 6가지 존재 
		for(int dir = 0 ; dir < 6 ; ++dir){
			int src = dr[dir];	int dst = dc[dir];
			if(cur.map[src] == 0)	continue;
			int dst_remain = limit[dst] - cur.map[dst];
			INFO next;
			copy(cur.map, cur.map + 3, next.map);
			if(cur.map[src] > dst_remain){
				next.map[dst] = limit[dst];
				next.map[src] -= dst_remain;
			}
			else{
				next.map[src] = 0;
				next.map[dst] += cur.map[src];
			}
			if(visited[next.map[0]][next.map[1]][next.map[2]])	continue;
			visited[next.map[0]][next.map[1]][next.map[2]] = true;
			q.push(next);
		}
	}
	
}

int main(){
//	memset(visited, false, sizeof(visited));
	scanf("%d %d %d", &limit[0], &limit[1], &limit[2]);
	
	INFO start;
	start.map[0] = 0;	start.map[1] = 0;	start.map[2] = limit[2];
	q.push(start);
	visited[0][0][limit[2]] = true;
	ans.insert(limit[2]);
	bfs();
	
	set<int>::iterator it;
	for(it = ans.begin() ; it != ans.end() ; ++it){
		cout << *it << " ";
	}
	
	return 0;
}
