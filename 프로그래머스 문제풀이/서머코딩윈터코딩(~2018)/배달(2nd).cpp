// N���� ���� �߿��� K �ð� ���Ϸ� ����� ������ ���������� �ֹ��� �������� �մϴ�
// ������ ���� N�� 1 �̻� 50 ������ �ڿ����Դϴ�.


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int, int> > pan[51];
int visited[51];

void solve(){
	// pair<cost, dst>
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
	
	visited[1] = 0;
	pq.push(make_pair(0, 1));
	
	while(!pq.empty()){
		int cur_node = pq.top().second;	int cur_cost = pq.top().first;	pq.pop();
		
		for(int i = 0 ; i < pan[cur_node].size() ; ++i){
			int dst_node = pan[cur_node][i].first;	int dst_cost = pan[cur_node][i].second;
			if(visited[dst_node] != -1){
				if(visited[dst_node] <= cur_cost + dst_cost)	continue;
			}
			visited[dst_node] = cur_cost + dst_cost;
			pq.push(make_pair(cur_cost + dst_cost, dst_node));
		}
		
	}
	
	
}

int solution(int N, vector<vector<int> > road, int K) {
	memset(visited, -1, sizeof(visited));
    int answer = 0;
    int src, dst, cost;

	for(int i = 0 ; i < road.size() ; ++i){
		src = road[i][0];	dst = road[i][1];	cost = road[i][2];
		pan[src].push_back(make_pair(dst, cost));	pan[dst].push_back(make_pair(src, cost));
	}

	solve();
	
	int ans = 0;
	
	for(int i = 1 ; i <= N ; ++i){
		if(visited[i] <= K)	++ans;
	}
	
	cout << ans;

    return ans;
}
