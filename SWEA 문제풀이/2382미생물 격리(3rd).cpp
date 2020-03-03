// OUTPUT : M시간 후 남아 있는 미생물 수의 총합을 구하여라.

// (5 ≤ N ≤ 100)
// (1 ≤ M ≤ 1,000)
// (5 ≤ K ≤ 1,000)
// (상: 1, 하: 2, 좌: 3, 우: 4)

// INPUT
// 셀의 개수 N, 격리 시간 M, 미생물 군집의 개수 K
// 세로 위치, 가로 위치, 미생물 수, 이동 방향

#include <cstdio>
#include <vector>
#include <queue> 

using namespace std;

struct INFO{
	int r, c, num, dir;
};

queue<INFO> q;

int T, N, M, K;

vector<INFO> pan[100][100];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};
const int change_dir[] = {1, 0, 3, 2};

void move(){
	
	while(!q.empty()){
		INFO now = q.front();	q.pop();
		INFO next;
		
		int next_r = now.r + dr[now.dir];	int next_c = now.c + dc[now.dir];
		next.r = next_r;	next.c = next_c;	next.dir = now.dir;	next.num = now.num;
		if(1 > next_r || next_r >= N-1 || 1 > next_c || next_c >= N-1){
			if(now.num / 2 == 0)	continue;
			next.num = now.num / 2;
			next.dir = change_dir[now.dir];
		}
		
		pan[next_r][next_c].push_back(next);
	}
	
}

void fold(){
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			
			if(pan[i][j].size() >= 2){
				int num_sum = 0;
				int max_idx;
				int max_num = -1;
				for(int k = 0 ; k < pan[i][j].size() ; ++k){
					num_sum += pan[i][j][k].num;
					if(max_num < pan[i][j][k].num){
						max_num = pan[i][j][k].num;
						max_idx = k;
					}
				}
				pan[i][j][max_idx].num = num_sum;
				q.push(pan[i][j][max_idx]);
			}
			else if(pan[i][j].size() == 1){
				q.push(pan[i][j][0]);
			}
			
		}
	}
	
}


int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T; ++z){
		scanf("%d %d %d", &N, &M, &K);
		int y, x, n, d;
		for(int i = 0 ; i < K ; ++i){
			scanf("%d %d %d %d", &y, &x, &n, &d);
			INFO tmp;
			tmp.r = y;	tmp.c = x;	tmp.num = n;	tmp.dir = d-1;
			q.push(tmp);
		}
		
		for(int m = 0 ; m < M ; ++m){
			
			// 다음 셀로 이동 
			// queue --> pan
			move();
			// 겹치는 거 확인후 queue에 push 
			// pan --> queue
			fold();
			
			for(int i = 0 ; i < N ; ++i){
				for(int j = 0 ; j < N ; ++j){
					pan[i][j].clear();
				}
			}
			
		}
		
		int ans = 0;
		
		while(!q.empty()){
			ans += q.front().num;	q.pop();
		}
		
		printf("#%d %d\n", z, ans);
		
		
	}
	return 0;
}

