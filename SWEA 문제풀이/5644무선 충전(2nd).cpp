// 총 이동 시간  (20 ≤ M ≤ 100)
// BC개수  (1 ≤ A ≤ 8)

#include <cstdio> 
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, M, A;

const int dr[] = {0, -1, 0, 1, 0};
const int dc[] = {0, 0, 1, 0, -1};

const int ddr[] = {-1, 1, 0, 0};
const int ddc[] = {0 ,0, -1, 1};

int amove[100];
int bmove[100];

vector<int> pan[10][10];
bool visited[10][10];

vector<int> bcs;

int ans; 

void spread(int r, int c, int range, int idx){
	
	memset(visited, false, sizeof(visited));
	
	queue<pair<int, pair<int, int> > > q;
	q.push(make_pair(0, make_pair(r, c)));
	visited[r][c] = true;
	
	while(!q.empty()){
		int cur_r = q.front().second.first;	int cur_c = q.front().second.second; int cur_dis = q.front().first;
		q.pop();
		if(cur_dis > range)	return;
		pan[cur_r][cur_c].push_back(idx);
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur_r + ddr[dir];	int next_c = cur_c + ddc[dir];
			if(0 > next_r || next_r >= 10 || 0 > next_c || next_c >= 10 || visited[next_r][next_c])	continue;
			visited[next_r][next_c] = true;
			q.push(make_pair(cur_dis + 1, make_pair(next_r, next_c)));
		}
	}	
	
}

int check(int aidx, int bidx){
	
	if(aidx == bidx){
		return bcs[aidx];
	}
	return bcs[aidx] + bcs[bidx];
	
}

void solve(){
	// 각 턴마다 최대의 값을 구한다. 
	int tmp_ret = -1 * 0x7fffffff;
	
	int a_r = 0;	int a_c = 0;	int b_r = 9;	int b_c = 9;
	
	for(int z = 0 ; z <= M ; ++z){
		tmp_ret = 0;
		int a_size = pan[a_r][a_c].size();	int b_size = pan[b_r][b_c].size();
		
		if(a_size == 0){
			for(int j = 0 ; j < b_size ; ++j){
				tmp_ret = max(tmp_ret, bcs[pan[b_r][b_c][j]]);
			}
		}
		else if(b_size == 0){
			for(int j = 0 ; j < a_size ; ++j){
				tmp_ret = max(tmp_ret, bcs[pan[a_r][a_c][j]]);
			}
		}
		else{
			for(int i = 0 ; i < a_size ; ++i){
				for(int j = 0 ; j < b_size ; ++j){
					tmp_ret = max(tmp_ret, check(pan[a_r][a_c][i], pan[b_r][b_c][j]));
				}
			}
		}
		
		ans += tmp_ret;
		
		if(z == M)	break;
		a_r += dr[amove[z]];	a_c += dc[amove[z]];	b_r += dr[bmove[z]];	b_c += dc[bmove[z]];
	}
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		
		for(int i = 0 ; i < 10 ; ++i){
			for(int j = 0 ; j < 10 ; ++j){		
				pan[i][j].clear();
			}
		}
		bcs.clear();
		
		ans = 0;
		memset(pan, 0, sizeof(pan));
		scanf("%d %d", &M, &A);	//  총 이동 시간(M), BC의 개수(A)
		
		// (0 : 이동안함) (1 : 상) (2 : 우) (3 : 하) (4 : 좌)
		for(int i = 0 ; i < M ; ++i){
			scanf("%d", &amove[i]);
		}
		for(int i = 0 ; i < M ; ++i){
			scanf("%d", &bmove[i]);
		}
				
		// 그 다음 줄에는 A개의 줄에 걸쳐 BC의 정보가 주어진다.
		// 하나의 BC 정보는 좌표(X, Y), 충전 범위(C), 처리량(P)로 구성된다.
		int c, r, range, p;
		for(int i = 0 ; i < A ; ++i){
			scanf("%d %d %d %d", &c, &r, &range, &p);
			bcs.push_back(p);
			--c;	--r;
			spread(r, c, range, i);
		}
		
//		for(int i = 0 ; i < 10 ; ++i){
//			for(int j = 0 ; j < 10 ; ++j){
//				printf("%d  ", pan[i][j].size());
//			}
//			printf("\n");
//		}
//		printf("\n");
		
		solve();
		
		// OUTPUT : BC의 정보와 사용자의 이동 궤적이 주어졌을 때, 모든 사용자가 충전한 양의 합의 최댓값
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}
