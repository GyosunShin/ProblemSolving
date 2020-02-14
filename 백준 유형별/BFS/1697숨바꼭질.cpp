// �����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�, ������ �� K(0 �� K �� 100,000)

// OUTPUT : �����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.
#include <stdio.h>
#include <queue>

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
		
		for(int i = 0 ; i < 3 ; ++i){
			int next_x;
			if(i == 0)	next_x = cur.x * 2;  // �����̵� 
			else if(i == 1)	next_x = cur.x + 1;  
			else if(i == 2)	next_x = cur.x - 1;
			
			if(0 > next_x || next_x > 100000 || visited[next_x] == 1)	continue;
			if(visited[next_x] == 0){
				visited[next_x] = 1;
				INFO next;
				next.x = next_x;	next.time = cur.time + 1;
				q.push(next);
			}
			
		}
	}
	
}

int main(){
	scanf("%d %d", &N, &K);   // ���ʴ�� ����, ���� 
	
	INFO start;
	start.x  = N;
	start.time = 0;
	
	q.push(start);
	visited[start.x] = 1;
	bfs();
	
	printf("%d", ans);
	return 0;
}

 
 
