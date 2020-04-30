// 낚시왕 오른쪽 한칸 이동
// 가장 가까운 상어먹기
// 상어 이동

// 상어가 이동을 마친 후에 한 칸에 상어가 두 마리 이상 있을 수 있다. 이때는 크기가 가장 큰 상어가 나머지 상어를 모두 잡아먹는다.

// INPUT
// (2 ≤ R, C ≤ 100, 0 ≤ M(상어 수) ≤ R×C) 
// (1 ≤ r ≤ R, 1 ≤ c ≤ C, 0 ≤ s ≤ 1000, 1 ≤ d ≤ 4, 1 ≤ z ≤ 10000)

#include <cstdio> 
#include <vector>

using namespace std;

int R, C, M;
int r,c,s,d,z;

const int dr[] = {-1,1,0,0}; 
const int dc[] = {0,0,1,-1};
const int dd[] = {1,0,3,2};

struct INFO{
	int r,c,s,d,z;
	bool alive;
};

vector<INFO> sharks;

vector<int>  pan[100][100];

int ans;

void clear(){
	for(int i = 0 ; i < 100 ; ++i){
		for(int j = 0 ; j < 100 ; ++j){
			pan[i][j].clear();
		}
	}
}

pair<int, pair<int, int>> fast(int start_r, int start_c, int jmp, int dir){
	pair<int, pair<int, int>> ret;
	ret.first = dir;	
	int det_r = start_r;	int det_c = start_c;
	
	if(dir == 0){		// 상 
		int bnd = start_r;
		if(jmp <= bnd){
			det_r += dr[dir] * jmp;
		}
		else{
			jmp -= (bnd + 1);
			int moc = jmp / (R-1);
			int na = jmp % (R-1);
			if(moc % 2 == 0){	
				ret.first = dd[dir];
				det_r = na+1;
			}
			else{
				det_r = R-1-na-1;
			}
		}		
	}
	else if(dir == 1){	// 하 
		int bnd = R - 1 - start_r;
		if(jmp <= bnd){
			det_r += dr[dir] * jmp;
		}
		else{
			jmp -= (bnd + 1);
			int moc = jmp / (R-1);
			int na = jmp % (R-1);
			if(moc % 2 == 0){	// 방향 바꿔야 함 
				ret.first = dd[dir];
				det_r = R-1-na-1;
			}
			else{
				det_r = na+1;
			}
		}
	}
	else if(dir == 2){	// 우 
		int bnd = C - 1 - start_c;
		if(jmp <= bnd){
			det_c += dc[dir] * jmp;
		}
		else{
			jmp -= (bnd+1);
			int moc = jmp / (C-1);
			int na = jmp % (C-1);			
			if(moc % 2 != 0){
				det_c = na + 1;
			}
			else{
				ret.first = dd[dir];
				det_c = C - 1 - na - 1;
			}
		}
	}
	else if(dir == 3){	// 좌 
		int bnd = start_c;
		if(jmp <= bnd){
			det_c += dc[dir] * jmp;
		}
		else{
			jmp -= (bnd+1);
			int moc = jmp / (C-1);
			int na = jmp % (C-1);
			if(moc % 2 == 0){	
				ret.first = dd[dir];
				det_c = na + 1;
			}
			else{
				det_c = C-1-na-1;
			}
		}		
	}
	
	ret.second.first = det_r;	ret.second.second = det_c;
	return ret;
}

void move(){
	
	for(int i = 0 ; i < sharks.size() ; ++i){
		if(!sharks[i].alive)	continue;
		int start_r = sharks[i].r;	int start_c = sharks[i].c;	int speed = sharks[i].s;
		int dir = sharks[i].d;
		
		pair<int, pair<int, int>> ret = fast(start_r, start_c, speed, dir);
		
		sharks[i].r = ret.second.first;	sharks[i].c = ret.second.second;	
		sharks[i].d = ret.first;
		
		if(pan[ret.second.first][ret.second.second].size() > 0){
			if(sharks[pan[ret.second.first][ret.second.second][0]].z > sharks[i].z){
				sharks[i].alive = false;
			}
			else{
				sharks[pan[ret.second.first][ret.second.second][0]].alive = false;
				pan[ret.second.first][ret.second.second][0] = i;
			}
		}
		else{
			pan[ret.second.first][ret.second.second].push_back(i);	
		}		
	}
	
}

void solve(){
	
	// 낚시왕 오른쪽 한칸 이동
	// 가장 가까운 상어먹기
	// 상어 이동	
	
	for(int i = 0 ; i < C ; ++i){
		
		for(int j = 0 ; j < R ; ++j){
			if(pan[j][i].size() > 0){
				int idx = pan[j][i][0];
				sharks[idx].alive = false;
				ans += sharks[idx].z;
				break;
			}
		}
		// 상어 이동 시작
		clear();
		move();
	}
	
}

int main(){
	scanf("%d %d %d", &R, &C, &M);
	
	for(int i = 0 ; i < M ; ++i){
		// r, c, s(속력), d(이동방향), z(크기)
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);	
		r--;	c--;	d--;
		INFO cur;
		cur.r = r;	cur.c = c;	cur.s = s;	cur.d = d;	cur.z = z;
		cur.alive = true;
		sharks.push_back(cur);
		
		pan[r][c].push_back(i);
	}
	
	solve();
	
	// OUTPUT
	// 낚시왕이 잡은 상어 크기의 합을 출력한다.
	printf("%d", ans);
	
	return 0;
}
