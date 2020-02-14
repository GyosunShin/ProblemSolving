//  (만약, U층 위, 또는 D층 아래에 해당하는 층이 없을 때는, 엘리베이터는 움직이지 않는다)
// S --> G

// INPUT  : F, S, G, U, D  (1 ≤ S, G ≤ F ≤ 1000000, 0 ≤ U, D ≤ 1000000)

// OUTPUT : 버튼을 적어도 몇 번 눌러야 하는지 구하는 프로그램을 작성하시오. 
// 만약, 엘리베이터를 이용해서 G층에 갈 수 없다면, "use the stairs"를 출력한다.

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
