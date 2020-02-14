// (5 �� N �� 100)
// �̻��� ���� �� (5 �� K �� 1,000)
// �ݸ��ð� (1 �� M �� 1,000)
//  �� ���� �� �̻��� ���� 1 �̻� 10,000 ����
//  (��: 1, ��: 2, ��: 3, ��: 4)
// ���� ��ġ, ���� ��ġ, �̻��� ��, �̵� ���� ��

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

int map[100][100][2];  // [0] : �̻��� �� | [1] : �迭 INDEX 

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
				
				if(map[tmp.r][tmp.c][1] == -1){   // ���� �ƹ��� ��ġ���� �ʾ��� ��� 
					map[tmp.r][tmp.c][1] = i;   // [1] Tartget_INDEX
					map[tmp.r][tmp.c][0] = tmp.num; // [0] # of �̻��� 
				}
				else{	// �̹� �ٸ� ������ ��ġ�� ���� ��� 
					int idx = map[tmp.r][tmp.c][1];
					if(map[tmp.r][tmp.c][0] < tmp.num){ // ���ε��� ���� �� ū ���  
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
