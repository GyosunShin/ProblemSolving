// 0은 빈 칸 / 6은 벽 /  1~5는 CCTV의 번호
// (1 ≤ N(R), M(C) ≤ 8)

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct INFO{
	int r, c, kind;
};

int R, C;
int pan[8][8];
int backup[8][8];

vector<INFO> cctvs;
vector<int>	picked;
vector<int>	ref[6][5];

int howmany[] = {0, 4, 2, 4, 4, 1};

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

void paint(){
	for(int i = 0 ; i < cctvs.size() ; ++i){
		int shape = cctvs[i].kind;
		int start_r = cctvs[i].r;	int start_c = cctvs[i].c;
		int how = picked[i];
		
		for(int j = 0 ; j < ref[shape][how].size() ; ++j){
			int dir = ref[shape][how][j];
			int next_r = start_r;	int next_c= start_c;
			while(true){
				next_r += dr[dir];	next_c += dc[dir];
				if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C || backup[next_r][next_c] == 6)	break;
				backup[next_r][next_c] = -2;
			}
		}
		
	}
	
}

int solve(){
	
	paint();
	
	int tmp_sum = 0;
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			if(backup[i][j] == 0)	++tmp_sum;
		}
	}
	
	return tmp_sum;
}

int ans = 0x7fffffff;

void dfs(int idx){
	
	if(picked.size() == cctvs.size()){
		
		copy(&pan[0][0], &pan[0][0] + (8 * 8), &backup[0][0]);
		int ret = solve();
		
		ans = min(ans, ret);
		
		return;
	}
	
	for(int i = 1 ; i <= howmany[cctvs[idx].kind] ; ++i){
		picked.push_back(i);
		dfs(idx+1);
		picked.pop_back();
	}
	
}

int main(){
	
	ref[1][1].push_back(3);	ref[1][2].push_back(0);	ref[1][3].push_back(2);	ref[1][4].push_back(1);
	ref[2][1].push_back(2);	ref[2][1].push_back(3);
	ref[2][2].push_back(0);	ref[2][2].push_back(1);
	ref[3][1].push_back(0);	ref[3][1].push_back(3);
	ref[3][2].push_back(1);	ref[3][2].push_back(3);
	ref[3][3].push_back(1);	ref[3][3].push_back(2);
	ref[3][4].push_back(0);	ref[3][4].push_back(2);
	ref[4][1].push_back(0);	ref[4][1].push_back(3);	ref[4][1].push_back(2);
	ref[4][2].push_back(1);	ref[4][2].push_back(0);	ref[4][2].push_back(3);
	ref[4][3].push_back(1);	ref[4][3].push_back(2);	ref[4][3].push_back(3);
	ref[4][4].push_back(0);	ref[4][4].push_back(2);	ref[4][4].push_back(1);
	ref[5][1].push_back(0);	ref[5][1].push_back(1);	ref[5][1].push_back(2);	ref[5][1].push_back(3);
	
	
	scanf("%d %d", &R, &C);
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%d", &pan[i][j]);
			if(1 <= pan[i][j] && pan[i][j] <=5){
				INFO tmp;
				tmp.r = i;	tmp.c = j;	tmp.kind = pan[i][j];
				cctvs.push_back(tmp);
			}
		}
	}
	
	dfs(0);
	
	// 사각 지대의 최소 크기를 출력
	printf("%d", ans);
	
	return 0;
}


