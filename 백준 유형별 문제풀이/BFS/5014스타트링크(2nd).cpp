// S --> G

// OUTPUT 
// 강호가 G층에 도착하려면, 버튼을 적어도 몇 번 눌러야 하는지 구하는 프로그램을 작성하시오. 
// 만약, 엘리베이터를 이용해서 G층에 갈 수 없다면, "use the stairs"를 출력한다.

//  (1 ≤ S, G ≤ F ≤ 1,000,000, 0 ≤ U, D ≤ 1000000) 

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int F,S,G,U,D;
bool visited[1000001];
queue<pair<int, int>> q;
int dr[2];

int main(){
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	q.push({S, 0});
	visited[S] = true;
	dr[0] = U;	dr[1] = D * -1;
	
	while(!q.empty()){
		int cur = q.front().first;	int time = q.front().second;
		q.pop();
		
		if(cur == G){
			printf("%d", time);
			return 0;
		}
		
		for(int i = 0 ; i < 2 ; ++i){
			int next = cur + dr[i];
			if(0 >= next || next > F || visited[next])	continue;
			visited[next] = true;
			q.push({next, time + 1});
		}
		
	}
	
	printf("use the stairs");
	
	return 0;
}


