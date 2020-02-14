// N 개의 원자들의 [x, y] 위치, 이동 방향, 보유 에너지가 주어질 때 원자들이 소멸되면서 방출하는 에너지의 총합을 구하는 프로그램을 작성하라.

// 원자의 수 (1≤N≤1,000) 
// 각 원자의 보유 에너지 (1≤K≤100) 
// 처음 위치 (-1,000≤x,y≤1,000)
// 좌표의 범위에 제한은 없다.
// 상(0), 하(1), 좌(2), 우(3)

#include <cstdio>
#include <vector>

using namespace std;

struct INFO{
	int x, y, dir, energy;
	bool live;
};

int T, N;

int pan[4001][4001];

//  상 하 좌 우 
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

vector<INFO> atoms;

int main(){
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		int ans = 0;
		atoms.clear();
		scanf("%d", &N);
		for(int i = 0 ; i < N ; ++i){
			int x, y, dir, k;
			scanf("%d %d %d %d", &x, &y, &dir, &k);		// 상(0), 하(1), 좌(2), 우(3)
			x += 1000;	y += 1000;
			x *= 2;	y *= 2;
			INFO tmp;
			tmp.x= x;	tmp.y = y;	tmp.dir = dir;	tmp.energy = k;	tmp.live = true;
			atoms.push_back(tmp);
		}
		
		while(true){
			bool ret = true;
			for(int i = 0 ; i < N ; ++i){
				if(atoms[i].live){
					ret = false;
					break;
				}
			}
			if(ret){
				break;
			}
			
			for(int i = 0 ; i < N ; ++i){
				if(!atoms[i].live)	continue;
				
				int next_x = atoms[i].x + dx[atoms[i].dir];	int next_y = atoms[i].y + dy[atoms[i].dir];
				if(0 > next_x || next_x >= 4001 || 0 > next_y || next_y >= 4001){
					atoms[i].live = false;
					continue;
				}
				pan[next_x][next_y] += 1;
				atoms[i].x = next_x;	atoms[i].y = next_y;
			}
			
			for(int i = 0 ; i < N ; ++i){
				if(!atoms[i].live)	false;
				int cur_x = atoms[i].x;	int cur_y = atoms[i].y;
				
				if(pan[cur_x][cur_y] > 1){
					for(int j = 0 ; j < N ; ++j){		
						if(atoms[j].x == cur_x && atoms[j].y == cur_y){
							ans += atoms[j].energy;
							atoms[j].live = false;
						}
					}
				}
				pan[cur_x][cur_y] = 0;
			}
			
		}		
		printf("#%d %d\n", z, ans);
	}
	return 0;
}



