// (1≤N(R)≤50, 1≤M(C)≤50)
// (1≤K≤300)
// 생명력 (1≤X≤10) 

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO{
	int r, c, power, left;
//	INFO(int R, int C, int P, int LE) : r(R), c(C), power(P), left(LE)	{};
};

struct cmp{
	bool operator()(const INFO& a, const INFO& b){
		return a.power < b.power;
	}
};

int pan[651][651];	// (0 : 빈칸 / 1 : death / 2 : baby / 3 : active)

const int dr[] = {-1, 1, 0 ,0};
const int dc[] = {0 ,0, -1, 1};

int T, R, C, K;

priority_queue<INFO, vector<INFO>, cmp> active[2];
queue<INFO> baby[2];

int now, next_year;

void solve(){
	
	next_year = (now + 1) % 2;
	
	// active -> 번식 (or) death
	while(!active[now].empty()){
		INFO cur = active[now].top();	active[now].pop();
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
			if(pan[next_r][next_c] != 0)	continue;
			pan[next_r][next_c] = cur.power;
			INFO tmp = {next_r, next_c, cur.power, cur.power};
			baby[next_year].push(tmp);
//			printf("번식\n");
		}
		
		if(cur.left > 1){
			INFO tmp = {cur.r, cur.c, cur.power, cur.left - 1};
			active[next_year].push(tmp);
//			printf("활성 -> 활성\n");
		}
		else{
			pan[cur.r][cur.c] = -1;
//			printf("활성 -> 주금 \n");
		}
		
	}
	
	
	// baby -> baby[next] (or) active
	while(!baby[now].empty()){
		INFO cur = baby[now].front();	baby[now].pop();
		
		if(cur.left == 1){
			INFO next = {cur.r, cur.c, cur.power, cur.power};
			active[next_year].push(next);
//			printf("비활 -> 활성\n");
		}
		else{
			INFO next = {cur.r, cur.c, cur.power, cur.left - 1};
			baby[next_year].push(next);
//			printf("비활성 -> 비활성\n");
		}
	}
	
	
	now = next_year;
}

void init(){
	while(!baby[0].empty())	baby[0].pop();
	while(!baby[1].empty())	baby[1].pop();
	while(!active[0].empty())	active[0].pop();
	while(!active[1].empty())	active[1].pop();
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		init();
		now = 0;
		next_year = 0;
		memset(pan, 0, sizeof(pan));
		scanf("%d %d %d", &R, &C, &K);	
		for(int i = 0 ; i < R ; ++i){
			for(int j = 0 ; j < C ; ++j){
				// 1~10까지의 숫자는 해당 그리드 셀에 위치한 줄기 세포의 생명력을 의미하며,
				// 0인 경우 줄기 세포가 존재하지 않는 그리드이다.
				scanf("%d", &pan[i+300][j+300]);
				if(pan[i+300][j+300] != 0){
					INFO tmp = {i+300, j+300, pan[i+300][j+300], pan[i+300][j+300]};
					baby[now].push(tmp);
				}
			}
		}
		
		for(int i = 0 ; i < K ; ++i){
			solve();
//			printf("[%d년 후]\n", i+1);
//			printf("비활성 : %d   /  활성 : %d\n", baby[now].size(), active[now].size());
		}	
		
		int ans = baby[now].size() + active[now].size();
		
		// OUTPUT : K시간 후 살아있는 줄기 세포(비활성 상태 + 활성 상태)의 총 개수
		printf("#%d %d\n", z, ans);
	}
	return 0;
}
