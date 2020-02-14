// M 시간 동안 이 미생물 군집들을 격리하였다. M시간 후 남아 있는 미생물 수의 총합을 구하여라.

// (상: 1, 하: 2, 좌: 3, 우: 4)

#include <cstdio>
#include <vector>
#include <map>

using namespace std;

struct GUNZIP{
	int r, c, num, dir;
};

map<int, GUNZIP> m;

vector<int> pan[100][100];

int T, N, M, K;

const int dr[] = {-1 ,1 ,0 ,0};
const int dc[] = {0, 0, -1, 1};

const int change_dir[] = {1, 0, 3, 2};

int main(){
	
	scanf("%d", &T);
	
	for(int z = 1; z <= T ; ++z){
		
		m.clear();
		for(int i = 0 ; i < 100 ; ++i){
			for(int j = 0 ; j < 100 ; ++j){
				pan[i][j].clear();
			}
		}
		
		scanf("%d %d %d", &N, &M, &K);	
		for(int i = 0 ; i < K ; ++i){  //  (5 ≤ K ≤ 1,000)
			int r, c, n, dir;
			scanf("%d %d %d %d", &r, &c, &n, &dir);
			GUNZIP tmp;
			tmp.r = r;	tmp.c = c;	tmp.num = n;	tmp.dir = dir - 1;
			m[i] = tmp;
		}
		
		for(int q = 0 ; q < M ; ++q){  // (1 ≤ M ≤ 1,000)
		
			map<int, GUNZIP>::iterator it;
			for(it = m.begin() ; it != m.end() ; ++it){
				int key = it->first;
				int cur_r = it->second.r;	int cur_c = it->second.c;	int cur_dir = it->second.dir;
				int next_r = cur_r + dr[cur_dir];	int next_c = cur_c + dc[cur_dir];
				
				if(next_r == 0 || next_r == N-1 || next_c == 0 || next_c == N-1){
					m[key].num /= 2;
					m[key].dir = change_dir[m[key].dir];
				}
				m[key].r = next_r;	m[key].c = next_c;
				
				pan[next_r][next_c].push_back(key);
			}
			
			for(int i = 0 ; i < N ; ++i){
				for(int j = 0 ; j < N ; ++j){
					if(pan[i][j].size() > 1){
						int tmp_sum = 0;
						int big_key = pan[i][j][0];
						int big_num = m[pan[i][j][0]].num;
						for(int k = 0 ; k < pan[i][j].size() ; ++k){
							int cur_key = pan[i][j][k];
							tmp_sum += m[cur_key].num;
							if(big_num < m[pan[i][j][k]].num){
								big_key = pan[i][j][k];
								big_num = m[pan[i][j][k]].num;
							}
						}
						for(int k = 0 ; k < pan[i][j].size() ; ++k){
							if(pan[i][j][k] != big_key){
								m.erase(pan[i][j][k]);
							}
						}
						m[big_key].num = tmp_sum;
					}
					if(q != M-1)	pan[i][j].clear();
				}
			}
		}
		
		int ans = 0;
		for(int i = 0 ; i < 100 ; ++i){
			for(int j = 0 ; j < 100 ; ++j){
				if(pan[i][j].size() > 0){
					for(int k = 0 ; k < pan[i][j].size() ; ++k){
						int key = pan[i][j][k];
						ans += m[key].num;
					}
				}
			}
		}
		
		printf("#%d %d\n", z, ans);
	}
	return 0;
}
