// 사무실의 크기와 상태, 그리고 CCTV의 정보가 주어졌을 때,
// CCTV의 방향을 적절히 정해서, 사각 지대의 최소 크기를 구하는 프로그램을 작성하시오.

// INPUT :  (1 ≤ N, M ≤ 8)


#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO{
	int r, c, kind;
};

int map[8][8];
int R, C;

int ans = 0x7fffffff;

vector<INFO> cctvs;
vector<int> picked;
vector<int> drdc[5][4];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

void bfs(int start_r, int start_c, int dir, int (&arr)[8][8]){
	queue<pair<int, int> > q;
	q.push(make_pair(start_r, start_c));
	
	while(!q.empty()){
		int cur_r = q.front().first;	int cur_c = q.front().second;	q.pop();
		arr[cur_r][cur_c] = -1;
		
		int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
		if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C)	continue;
		if(arr[next_r][next_c] == 6)	continue;
				
		q.push(make_pair(next_r, next_c));
	}
	
}

void dfs(int idx){
	
	if(picked.size() == cctvs.size()){
		int backup[8][8];
		copy(&map[0][0], &map[0][0] + 8 * 8, &backup[0][0]);
		
//		for(int i = 0 ; i < picked.size() ; ++i)	printf("%d  ", picked[i]);
//		printf("\n");
		
		for(int i = 0 ; i < picked.size() ; ++i){
			int which = cctvs[i].kind;
			int dir = picked[i];
			for(int j = 0 ; j < drdc[which][dir].size() ; ++j){
				int cur_dir = drdc[which][dir][j];
				bfs(cctvs[i].r, cctvs[i].c, cur_dir, backup);
			}
		}
		
		int tmp_sum = 0;
		for(int i = 0 ; i < R ; ++i){
			for(int j = 0 ; j < C ; ++j){
				if(backup[i][j] == 0)	++tmp_sum;
			}
		}
		ans = min(ans, tmp_sum);
		return;
	}
	
	if(cctvs[idx].kind == 0){
		for(int i = 0 ; i < 4 ; ++i){
			picked.push_back(i);
			dfs(idx + 1);
			picked.pop_back();
		}
	}
	else if(cctvs[idx].kind == 1){
		for(int i = 0 ; i < 2 ; ++i){
			picked.push_back(i);
			dfs(idx + 1);
			picked.pop_back();
		}			
	}
	else if(cctvs[idx].kind == 2){
		for(int i = 0 ; i < 4 ; ++i){
			picked.push_back(i);
			dfs(idx + 1);
			picked.pop_back();
		}		
	}
	else if(cctvs[idx].kind == 3){
		for(int i = 0 ; i < 4 ; ++i){
			picked.push_back(i);
			dfs(idx + 1);
			picked.pop_back();
		}		
	}
	else if(cctvs[idx].kind == 4){
		for(int i = 0 ; i < 1 ; ++i){
			picked.push_back(i);
			dfs(idx + 1);
			picked.pop_back();
		}		
	}
	
}

int main(){
	
	// (0 : 상) (1 : 하) (2 : 좌) (3 : 우)
	drdc[0][0].push_back(0);
	drdc[0][1].push_back(1);
	drdc[0][2].push_back(2);
	drdc[0][3].push_back(3);
	
	drdc[1][0].push_back(2);	drdc[1][0].push_back(3);
	drdc[1][1].push_back(0);	drdc[1][1].push_back(1);
	
	drdc[2][0].push_back(0);	drdc[2][0].push_back(3);
	drdc[2][1].push_back(1);	drdc[2][1].push_back(3);
	drdc[2][2].push_back(1);	drdc[2][2].push_back(2);
	drdc[2][3].push_back(0);	drdc[2][3].push_back(2);
	
	drdc[3][0].push_back(0);	drdc[3][0].push_back(2);	drdc[3][0].push_back(3);
	drdc[3][1].push_back(0);	drdc[3][1].push_back(1);	drdc[3][1].push_back(3);
	drdc[3][2].push_back(1);	drdc[3][2].push_back(2);	drdc[3][2].push_back(3);
	drdc[3][3].push_back(0);	drdc[3][3].push_back(1);	drdc[3][3].push_back(2);
	
	drdc[4][0].push_back(0);	drdc[4][0].push_back(1);	drdc[4][0].push_back(2);	drdc[4][0].push_back(3);
	
	
	scanf("%d %d", &R, &C);
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%d", &map[i][j]);
			if(1 <= map[i][j] && map[i][j] <= 5){
				INFO tmp;	tmp.r = i;	tmp.c = j;	tmp.kind = map[i][j]-1;
				cctvs.push_back(tmp);
			}
		}
	}
	
	dfs(0);
	
	printf("%d", ans);
	
	return 0;
}
