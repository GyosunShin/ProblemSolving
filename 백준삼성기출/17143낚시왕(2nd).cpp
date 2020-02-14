// R, C와 상어의 수 M이 주어진다. (2 ≤ R, C ≤ 100, 0 ≤ M ≤ R×C)
//  r, c, s, d, z (1 ≤ r ≤ R, 1 ≤ c ≤ C, 0 ≤ s ≤ 1000, 1 ≤ d ≤ 4, 1 ≤ z ≤ 10000)
//  (r, c) : 상어 위치
//  s : 속력
//  d : 이동 방향   --> (1 : 위) (2 : 아래) (3 : 오른쪽) (4 : 왼쪽)
//  z : 크기 
//  
//  OUTPUT : 낚시왕이 잡은 상어 크기의 합을 출력한다.

#include <stdio.h>
#include <queue>

using namespace std;

struct SHARK{
	int speed, dir, size;
};
 
int R, C, M;
int visited[100][100];
SHARK sharks[100][100];

queue<pair<int, int> > q;

int ans;

int main(){
	scanf("%d %d %d", &R, &C, &M);
	for(int i = 0 ; i < M ; ++i){
		int r, c, s, d, z;
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		q.push(pair<int, int>((r-1), (c-1)));
		SHARK tmp;
		tmp.speed = s;	tmp.dir = d;	tmp.size = z;
		sharks[r-1][c-1] = tmp;
		visited[r-1][c-1] = 1;
	}
	
	// 시뮬레이션 시작!
	for(int i = 0 ; i < C ; ++i){
		
		for(int j = 0 ; j < R ; ++j){   // 가까운거 먼저 먹는다.
			if(visited[j][i] == 1){
				ans += sharks[j][i].size;
				visited[j][i] = 0;
			}
		}
		
		int visited_new[100][100] = { 0, };
		// 이제 상어 이동 차례
		// queue에서 하나씩 빼면서 visited를 통해 이전에 잡아먹혔는지 확인한다.
		// 그리고 안 잡아먹혔으면 다음 위치를 계산한다
		// 근데 다음위치에 누가 이미 있으면 size 비교 후 잡어먹는다.
		while(!q.empty()){
	}
	
	
}
