// 원자 수  (1≤N≤1,000)
// (-1,000≤x,y≤1,000)
// 상(0), 하(1), 좌(2), 우(3)

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct INFO{
	int r, c, dir, energy;
	bool alive;
};

vector<INFO> atoms;
//vector<int> pan[(2001*2)-1][(2001*2)-1];
int pan[(2001*2)-1][(2001*2)-1];

int T, N;

const int dr[] = {1, -1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int ans;

bool endcheck(){
	
	bool tmp_flag = true;
	
	for(int i = 0 ; i < atoms.size() ; ++i){
		if(atoms[i].alive){
			tmp_flag = false;
			break;
		}
	}
	
	return tmp_flag;
	
}

void solve(){
	
	while(true){
			
		for(int i = 0 ; i < atoms.size() ; ++i){
			if(atoms[i].alive){
				int next_r = atoms[i].r + dr[atoms[i].dir];	int next_c = atoms[i].c + dc[atoms[i].dir];
				if(0 > next_r || next_r >= 4001 || 0 > next_c || next_c >= 4001){
					atoms[i].alive = false;		
					continue;
				}
//				pan[next_r][next_c].push_back(i);
				pan[next_r][next_c]++;
				
//				pan[atoms[i].r][atoms[i].c].clear();
//				pan[atoms[i].r][atoms[i].c] = 0;

				atoms[i].r = next_r;	atoms[i].c = next_c;
			}
		}
		
		for(int i = 0 ; i < atoms.size() ; ++i){
			if(pan[atoms[i].r][atoms[i].c] > 1 && atoms[i].alive){
				
				atoms[i].alive = false;
				ans += atoms[i].energy;
				for(int j = i + 1 ; j < atoms.size() ; ++j){
					if(atoms[i].r == atoms[j].r && atoms[i].c == atoms[j].c	&& atoms[j].alive){
						atoms[j].alive = false;
						ans += atoms[j].energy;		
					}
				}
			}
			pan[atoms[i].r][atoms[i].c] = 0;
		}
		
		if(endcheck())	return;
	}
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		
//		for(int i = 0 ; i < 4001 ; ++i){
//			for(int j = 0 ; j < 4001 ; ++j){
//				pan[i][j].clear();
//			}
//		}
		memset(pan, 0, sizeof(pan));
		ans = 0;
		atoms.clear();
		
		scanf("%d", &N);	
		for(int i = 0 ; i < N ; ++i){
			// x 위치, y 위치, 이동 방향, 보유 에너지 K
			int c, r, dir, k;	// (-1,000≤x,y≤1,000)
			scanf("%d %d %d %d", &c, &r, &dir, &k);	
			INFO tmp = {(r+1000)*2, (c+1000)*2, dir, k, true};
			atoms.push_back(tmp);
		}
		
		solve();
		
		// OUTPUT : 방출되는 에너지의 총합을 출력
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}
