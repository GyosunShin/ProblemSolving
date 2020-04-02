// ���� (0 �� N �� 100,000)
// ���� (0 �� K �� 100,000)

// OUTPUT
// �����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� 
// ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

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



