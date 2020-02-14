// �����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�, ������ �� K(0 �� K �� 100,000)

// �����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <stdio.h> 
#include <queue>
#include <algorithm>

using namespace std;

bool visited[100001];

int S, D;

// <�ð�, �ε���> 
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
