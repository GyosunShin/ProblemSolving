// �̵� �ð�(��) = | PR - SR | + | PC - SC |

// OUTPUT : �̶�, ��� ������� ����� ������ �̵��� �Ϸ�Ǵ� �ð��� �ּҰ� �Ǵ� ��츦 ã��,
// �� ���� �ҿ�ð��� ����ϴ� ���α׷��� �ۼ��϶�.

// (4 �� N �� 10)
// (1 �� ����� �� �� 10)
// (2 �� ����� ���� �� 10)
// ����� ���� ������ 2�� 

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T, N;

int map[10][10];

vector<pair<int, int> > people;
vector<pair<int, int> > stair;
vector<int> picked;

int peoples, stairs;

vector<int> pq[2];

int mmin = 0x7fffffff;

void solve(){
	
	int alphas[2];
	alphas[0] = map[stair[0].first][stair[0].second];
	alphas[1] = map[stair[1].first][stair[1].second];
	
	pq[0].clear();	pq[1].clear();
	
	for(int i = 0 ; i < picked.size() ; ++i){
		int person_r = people[i].first;	int person_c = people[i].second;
		int stair_r = stair[picked[i]].first;	int stair_c = stair[picked[i]].second;
		int dis = abs(person_r - stair_r) + abs(person_c - stair_c);
		pq[picked[i]].push_back(dis);
	}
	
	int final_max = -1 * 0x7fffffff;
	sort(pq[0].begin(), pq[0].end());	sort(pq[1].begin(), pq[1].end());
	
	for(int i = 0 ; i < 2 ; ++i){
		int plus_alpha = alphas[i];
		int remain[3] = { 0, };
		int ret;
		
		int tick = 0; 
		
		for(int q = 0 ; q < pq[i].size() ; ++q){
			int now = pq[i][q];
			ret = now;
			
			if(q > 0){
				int tmp_dif = pq[i][q] - pq[i][q-1];
				if(tick > tmp_dif){
					tick -= tmp_dif;
					ret += tick;
				}
				else{
					tick = 0;
					for(int j = 0 ; j < 3 ; ++j){
						if(remain[j] > 0)	remain[j] -= tmp_dif;
						if(remain[j] < 0)	remain[j] = 0;
					}					
				}
			}
			
			while(true){
				bool tmp_flag = true;
				for(int j = 0 ; j < 3 ; ++j){
					if(remain[j] == 0){
						tmp_flag = false;
						if(tick == 0){
							remain[j] = plus_alpha + 1;
							ret++;
						}	
						else	remain[j] = plus_alpha;
						break;
					}
				}
				if(!tmp_flag){   // ���ڸ��� �� �ڸ��� �־
					break;
				}	
				else{	// �� �ڸ��� ���� ��� �ϳ��� ���ش�. 
					remain[0] -= 1;	remain[1] -= 1;	remain[2] -= 1;
				}
				ret++;
				tick++;
			}
			ret += plus_alpha;			
			final_max = max(final_max, ret);		
		}
	}
	mmin = min(mmin, final_max);
}

void dfs(){
	
	if(picked.size() == peoples){
		solve();
		return;
	}
	
	for(int i = 0 ; i < stairs ; ++i){
		picked.push_back(i);
		dfs();
		picked.pop_back();
	}
	
}

int main(){
	
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		people.clear();	stair.clear();
		mmin = 0x7fffffff;
		scanf("%d", &N);	
		// (1 : ���) (2 ~ 10 : ���)
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &map[i][j]);
				if(map[i][j] == 1)	people.push_back(make_pair(i, j));
				else if(2 <= map[i][j] && map[i][j] <= 10)	stair.push_back(make_pair(i, j));
			}
		}
		
		peoples = people.size();	stairs = stair.size();
		
		// �ߺ����� �̿��ؼ� ��� <-> ��� Mapping 
		dfs();
		
		printf("#%d %d\n", z, mmin);
	}
	return 0;
}


