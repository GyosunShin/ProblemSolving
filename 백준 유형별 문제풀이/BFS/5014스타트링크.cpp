//  (����, U�� ��, �Ǵ� D�� �Ʒ��� �ش��ϴ� ���� ���� ����, ���������ʹ� �������� �ʴ´�)
// S --> G

// INPUT  : F, S, G, U, D  (1 �� S, G �� F �� 1000000, 0 �� U, D �� 1000000)

// OUTPUT : ��ư�� ��� �� �� ������ �ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 
// ����, ���������͸� �̿��ؼ� G���� �� �� ���ٸ�, "use the stairs"�� ����Ѵ�.

#include <stdio.h>
#include <queue>

using namespace std;

struct INFO{
	int track;
	int cnt;
};

queue<INFO> q;

int F, S, G, U, D;
int dr[2];

bool visited[1000001];

int bfs(){
	
	while(!q.empty()){
		
		INFO cur = q.front();	q.pop();
		
//		printf("CUR.track : %d  /  cur.cnr : %d\n", cur.track, cur.cnt);
		
		if(cur.track == G){
			return cur.cnt;
		}
		
		for(int dir = 0 ; dir < 2 ; ++dir){  // (0 : UP)  (1 : DOWN)
			int next_track = cur.track + dr[dir];
//			printf("NEXT_track : %d\n", next_track);
			if(1 > next_track || next_track > F || visited[next_track])	continue;
			visited[next_track] = true;
			INFO next;
			next.track = next_track;	next.cnt = cur.cnt + 1;
			q.push(next);
		}
		
	}
	return -1;
}

int main(){
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	dr[0] = U;	dr[1] = -1 * D;
	
	INFO start;
	start.track = S;	start.cnt = 0;
	q.push(start);
	visited[start.track] = true;
	int ans = bfs();
	if(ans == -1)	printf("use the stairs");
	else printf("%d", ans);
	
	return 0;
}
