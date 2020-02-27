// 마을의 개수 N, 각 마을을 연결하는 도로의 정보 road, 음식 배달이 가능한 시간 K가 매개변수로 주어질 때
// OUTPUT : 음식 주문을 받을 수 있는 마을의 개수를 return 

#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct INFO{
	int node, len;
};
queue<INFO> q;

// 1 <= N <= 50
vector<pair<int, int> > map[51];  //pair<dst, cost>
int visited[51];

int ans;
int limit;

void bfs(){
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
//		cout << "CUR_NODE : " << cur.node << "  /  CUR_LEN : " << cur.len << "  / LIMIT : " << limit << "  /  AND : " << ans << endl;
		
		for(int i = 0 ; i < map[cur.node].size() ; ++i){
			int next_node = map[cur.node][i].first;
			int next_cost = map[cur.node][i].second;
			
			if(cur.len + next_cost > limit)	continue;
			INFO next;	next.node = next_node;	next.len = cur.len + next_cost;
			if(visited[next_node] == -1){
				visited[next_node] = next.len;
				++ans;
//				cout << "+++" << endl;
			}	
			if(visited[next_node] <	 next.len){
//				cout << "CONTINUE   visited[next_node] : " << visited[next_node] << "  / NEXT_LEN : " << next.len << endl;
				continue;
			}	
			visited[next_node] = next.len;
			q.push(next);
		}
	}
	
}

int solution(int N, vector<vector<int> > road, int K) {
	limit = K;
    memset(visited, -1, sizeof(visited));
    for(int i = 0 ; i < road.size() ; ++i){
    	int src = road[i][0];
    	int dst = road[i][1];
    	int cost = road[i][2];
    	map[src].push_back(make_pair(dst, cost));
    	map[dst].push_back(make_pair(src, cost));
    }
    
    INFO start;
    start.node = 1;	start.len = 0;
    q.push(start);
    visited[start.node] = 0;
    ++ans;
    bfs();
    
    return ans;
}
