// (5 ≤ N ≤ 100)
// 미생물 군집 수 (5 ≤ K ≤ 1,000)
// 격리시간 (1 ≤ M ≤ 1,000)
//  각 군집 내 미생물 수는 1 이상 10,000 이하
//  (상: 1, 하: 2, 좌: 3, 우: 4)
// 세로 위치, 가로 위치, 미생물 수, 이동 방향 순

#include <stdio.h>
#include <string.h>

struct INFO{
	int r, c, num, dir;
};

int T, N, M, K;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};
const int conv[] = {1, 0, 3, 2};

INFO infos[1000];

int map[100][100][2];  // [0] : 미생물 수 | [1] : 배열 INDEX 

bool outCheck(int r, int c){
	return (r == 0 || r == N-1 || c == 0 || c == N-1);
}

int main(){
	scanf("%d", &T);
	for(int t = 1; t <= T ; ++t){
		scanf("%d %d %d", &N, &M, &K);
		for(int i = 0 ; i < K ; ++i){
			int r,c,n,d;
			scanf("%d %d %d %d", &r, &c, &n, &d);
			INFO tmp;
			tmp.r = r;	tmp.c = c;	tmp.num = n;	tmp.dir = (d-1);
			infos[i] = tmp;
		}
		
		for(int z = 0 ; z < M ; ++z){
			memset(map, -1, sizeof(map));
			for(int i = 0 ; i < K ; ++i){
				INFO& tmp = infos[i];
				
				if(tmp.num == 0)	continue;
				
				tmp.r += dr[tmp.dir];	tmp.c += dc[tmp.dir];
				
				if(outCheck(tmp.r, tmp.c)){
					tmp.dir = conv[tmp.dir];
					tmp.num /= 2;
				}
				
				if(map[tmp.r][tmp.c][1] == -1){   // 아직 아무도 위치하지 않았을 경우 
					map[tmp.r][tmp.c][1] = i;   // [1] Tartget_INDEX
					map[tmp.r][tmp.c][0] = tmp.num; // [0] # of 미생물 
				}
				else{	// 이미 다른 군집이 위치해 있을 경우 
					int idx = map[tmp.r][tmp.c][1];
					if(map[tmp.r][tmp.c][0] < tmp.num){ // 새로들어올 놈이 더 큰 경우  
						map[tmp.r][tmp.c][0] = tmp.num;
						infos[idx].dir = tmp.dir;
					}
					infos[idx].num += tmp.num;
					tmp.num = 0;
				}
			}
		}
		
		
		int tmp_ans = 0;
		for(int i = 0 ; i < K ; ++i){
			tmp_ans += infos[i].num;
		}
		printf("#%d %d\n", t, tmp_ans);
	}
	return 0;
}
