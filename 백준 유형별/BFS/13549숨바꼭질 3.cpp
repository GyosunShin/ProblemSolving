// 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)

// 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

#include <stdio.h> 
#include <queue>
#include <algorithm>

using namespace std;

bool visited[100001];

int S, D;

// <시간, 인덱스> 
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

int bfs(){
	
	visited[S] = true;
	pq.push(make_pair(0, S));
	
	while(!pq.empty()){
		int cur_idx = pq.top().second;
		int cur_time = pq.top().first;
		pq.pop();
		
//		printf("%d  /  %d\n", cur_idx, cur_time);
		
		if(cur_idx == D){
			return cur_time;
		}
		
		int next_idx, track;
		
		// *2
		next_idx = cur_idx * 2;
		if(!(0 > next_idx || next_idx > 100000 || visited[next_idx])){
			visited[next_idx] = true;
			pq.push(make_pair(cur_time, next_idx));
		}		
		// +1
		next_idx = cur_idx + 1;
		if(!(0 > next_idx || next_idx > 100000 || visited[next_idx])){
			visited[next_idx] = true;
			pq.push(make_pair(cur_time + 1, next_idx));
		}
		// -1
		next_idx = cur_idx - 1;
		if(!(0 > next_idx || next_idx > 100000 || visited[next_idx])){	
			visited[next_idx] = true;
			pq.push(make_pair(cur_time + 1, next_idx));
		}		
	}
	
}

int main(){
	scanf("%d %d", &S, &D);
	
	int ans = bfs();
	
	printf("%d", ans);
	
	return 0;
}
