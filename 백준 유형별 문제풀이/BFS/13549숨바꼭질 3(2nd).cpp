// 수빈 (0 ≤ N ≤ 100,000)
// 동생 (0 ≤ K ≤ 100,000)

// OUTPUT
// 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 
// 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool visited[100001];

int bfs(){
	
	pq.push({0, N});
	visited[N] = true;
	
	while(!pq.empty()){
		
		int cur = pq.top().second;	int time = pq.top().first;
		pq.pop();
		if(cur == K){
			return time;
		}
		
		for(int i = 0 ; i < 3 ; ++i){
			int next_loc, next_time;
			
			if(i == 0){
				next_loc = cur * 2;
				next_time = time;
			}
			else if(i == 1){
				next_loc = cur + 1;
				next_time = time + 1;
			}
			else if(i == 2){
				next_loc = cur - 1;
				next_time = time + 1;
			}
			
			if(0 > next_loc || next_loc > 100000 || visited[next_loc])	continue;
			visited[next_loc] = true;
			pq.push({next_time, next_loc});
		}
			
	}
	
	
}

int main(){
	scanf("%d %d", &N, &K);
	
	printf("%d", bfs());
	
	
	return 0;
}



