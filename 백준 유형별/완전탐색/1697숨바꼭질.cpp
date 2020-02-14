// 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)

// 걷기 : +1 || -1
// 순간이동 : *2

// OUTPUT : 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

#include <stdio.h> 
#include <queue>
#include <string.h>

using namespace std;

struct INFO{
	int x, time;
};

int N, K;

queue<INFO> q;

int visited[100001];

int ans;

void bfs(){
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop(); 
		if(cur.x == K){
			ans = cur.time;
			break;
		}
		
		for(int dir = 0 ; dir < 3 ; ++dir){
			int next_x;
			if(dir == 0){
				next_x = cur.x + 1;
			}
			else if(dir == 1){
				next_x = cur.x - 1;
			}
			else if(dir == 2){
				next_x = cur.x * 2;
			}
			
			if(0 > next_x || next_x > 100000 || visited[next_x] != 0)	continue;
			INFO next;
			next.x = next_x;	next.time = cur.time + 1;
			q.push(next);
			visited[next_x] = 1;
		}
	}
	
}

int main(){
	scanf("%d %d", &N, &K);
	//######################
//	memset(visited, -1, sizeof(visited));
	
	INFO start;
	start.x = N;	start.time = 0;
	q.push(start);
	visited[N] = 1;
	bfs();
	
	printf("%d", ans);
	
	return 0;
}
