// (2 �� R, C �� 100, 0 �� M �� R��C)
// r, c, s, d, z (1 �� r �� R, 1 �� c �� C, 0 �� s(�ӷ�) �� 1000, 1 �� d(�̵�����) �� 4, 1 �� z(ũ��) �� 10000)
// d: 1�� / 2�Ʒ� / 3������ / 4���� 
// 
// OUTPUT : ���ÿ��� ���� ��� ũ���� ���� ����Ѵ�. 

#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

struct INFO{
	int s, d, z;   // �ӵ�, ����, ũ�� 
};

int R, C, M;

INFO map[2][100][100];

const int dr[] = {-1, 1, 0, 0};  // �� �� �� �� 
const int dc[] = {0, 0, 1, -1};

int seq = 0; 

int ans; 

queue<pair<int, int> > loc[2];

int main(){
	scanf("%d %d %d", &R, &C, &M);
	for(int m = 0 ; m < M ; ++m){
		int r, c, s, d, z;
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		INFO tmp;	tmp.s = s;	tmp.d = d-1;	tmp.z = z;
		map[seq][r-1][c-1] = tmp;
		loc[seq].push(pair<int, int>(r-1, c-1));
	}
	
	//#################################################
	
	for(int i = 0 ; i < C ; ++i){
		// �ϴ� ���� �Դ´�.
		for(int j = 0 ; j < R ; ++j) {
			if(map[seq][j][i].z > 0){  // �� ������ ���  �԰� ��� �����ش�. 
				ans += map[seq][j][i].z;
				map[seq][j][i].s = 0;	map[seq][j][i].d = 0;	map[seq][j][i].z = 0;   // ����! 
				break;	
			}	
		}
		
		if(i == C-1)	break;
		
		// ����  ��� �������ش�.
		int next_seq;
		if(seq == 0)	next_seq = 1;
		else if(seq == 1)	next_seq = 0;
		
		memset(map[next_seq], 0, sizeof(map[next_seq]));
		
		// ���� ��ġ ã��...
		while(!loc[seq].empty()){
			int cur_r = loc[seq].front().first;	int cur_c = loc[seq].front().second;	loc[seq].pop();
			int cur_dir = map[seq][cur_r][cur_c].d;   // 0 : ��  | 1 : �� | 2 : �� | 3 : �� 
			int cur_speed = map[seq][cur_r][cur_c].s;
			int cur_size = map[seq][cur_r][cur_c].z;
			
			
			for(int z = 0 ; z < cur_speed ; ++z){
				cur_r += dr[cur_dir];	cur_c += dc[cur_dir];
				if(0 > cur_r || cur_r >= R || 0 > cur_c || cur_c >= C){
					cur_r -= dr[cur_dir];	cur_c -= dc[cur_dir];	
					if(cur_dir == 0)	cur_dir = 1;
					else if(cur_dir == 1)	cur_dir = 0;
					else if(cur_dir == 2)	cur_dir = 3;
					else if(cur_dir == 3)	cur_dir = 2;
					cur_r += dr[cur_dir];	cur_c += dc[cur_dir];	
				}
			}
			
			if(map[next_seq][cur_r][cur_c].z > 0){  // �̹� ���� ������ ũ�� ���ؼ� 
				if(cur_size > map[next_seq][cur_r][cur_c].z){  // ���ο�� �� Ŭ��� 
					map[next_seq][cur_r][cur_c].z = cur_size;
					map[next_seq][cur_r][cur_c].s = cur_speed;
					map[next_seq][cur_r][cur_c].d = cur_dir;	
				}
			}
			else{
				loc[next_seq].push(pair<int,int>(cur_r, cur_c));
				map[next_seq][cur_r][cur_c].z = cur_size;
				map[next_seq][cur_r][cur_c].s = cur_speed;
				map[next_seq][cur_r][cur_c].d = cur_dir;					
			}
			
			
		}
		
		
		seq = next_seq;	 
	}
	
	printf("%d", ans);
	return 0;
}





