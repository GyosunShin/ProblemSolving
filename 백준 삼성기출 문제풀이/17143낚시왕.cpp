// �������� ũ�� R, C�� ����� �� M�� �־�����. (2 �� R, C �� 100, 0 �� M �� R��C) 
// r, c, s, d, z (1 �� r �� R, 1 �� c �� C, 0 �� s �� 1000, 1 �� d �� 4, 1 �� z �� 10000) 
// (r, c)�� ����� ��ġ, s�� �ӷ�, d�� �̵� ����, z�� ũ��
// d = 1 --> �� 
// d = 2 --> �Ʒ� 
// d = 3 --> ������ 
// d = 4 --> ����

// OUTPUT : ���ÿ��� ���� ��� ũ���� ���� ����Ѵ�.

#include <stdio.h> 
#include <queue> 

using namespace std;

struct SHARK{
	int s, d, z;
};  // s : ũ��   d : �̵�����   z : ũ�� 

struct FOR_QUEUE{
	int r, c, size, speed, dir;
};

SHARK sharks[100][100];
int map[100][100];  // �������ϴ��� ���θ��̿�����

queue<FOR_QUEUE> q;
 
int R, C, M;
int ans;

int dr[] = {-1, 1, 0, 0};  // 0 : ��    1 : �Ʒ�   2 : ������   3 : ���� 
int dc[] = {0, 0, 1, -1};

int main(){
	scanf("%d %d %d", &R, &C, &M);
	for(int i = 0 ; i < M ; ++i){
		int r,c; 
		SHARK tmp;
		FOR_QUEUE tmp2;
		scanf("%d %d %d %d %d", &r, &c, &tmp.s, &tmp.d, &tmp.z);
		--r;	--c;	--tmp.d;
		tmp2.r = r;
		tmp2.c = c;
		tmp2.dir = tmp.d;
		tmp2.size = tmp.z;
		tmp2.speed = tmp.s;
		sharks[r][c] = tmp;
		map[r][c] = 1;
		q.push(tmp2);
	}
	//#################################################################################################
	
	
	for(int e = 0 ; e < R ; ++e){
		printf("<");
		for(int m = 0 ; m < C ; ++m){
			printf("%d ", sharks[e][m].s);
		}
		printf(">\n");
	}
	printf("\n");	
	
	// �� : 0 ~ C-1
	for(int i = 0 ; i < C ; ++i) {  // �� 
		// ������ ������ �ȴ´�
		for(int j = 0 ; j < R ; ++j){  // �� 
			if(map[j][i] != 0){  // ��� ��� �ܰ� 
				ans += sharks[j][i].z;
				printf("###ANS += %d\n", sharks[j][i].z);
				map[j][i] = 0;
				break;
			}
		}
		
		// ��� �̵� ó���ϴ� �ܰ�
		// d = 1 --> ��   d = 2 --> �Ʒ�   d = 3 --> ������   d = 4 --> ����
		int map2[100][100] = { 0, };
		printf("QUEUE SIZE  : %d\n", q.size());
		while(!q.empty()){
			FOR_QUEUE cur = q.front();	q.pop();
			int cur_r = cur.r;	int cur_c = cur.c;	
			printf("CUR_R : %d / CUR_C : %d / CUR_SPEED : %d / CUR_SIZE : %d / CUR_DIR : %d\n", cur_r, cur_c, cur.speed, cur.size, cur.dir);
			if(map[cur_r][cur_c] == 0){
				printf("EATEN!!\n");
				continue;  // ���� �ܰ迡�� ���ò����� ��Ƹ����� ������ ��� 
			}	
			int dir = cur.dir;
			int next_r = cur_r;
			int next_c = cur_c;
			for(int k = 0 ; k < cur.speed ; ++k){
				next_r += dr[dir];	next_c += dc[dir];
				if(0 > next_r || next_r >= R || 0 > next_c || next_c >= C){
					next_r -= dr[dir];	next_c -= dc[dir];	
					if(dir == 0)	dir = 1;
					else if(dir == 1)	dir = 0;
					else if(dir == 2)	dir = 3;
					else if(dir == 3)	dir = 2;
					sharks[cur_r][cur_c].d = dir;
					next_r += dr[dir];	next_c += dc[dir];	
				}
			}  // ��� �����ڸ��� ���� �Ϸ� 
			
			if(map2[next_r][next_c] == 1){  // ���� �̹� �ڸ� �����ߴٸ�..! 
				if(sharks[next_r][next_c].z > cur.size){  // ������ �ִ³��� �� ũ�ٸ� 
					map[cur_r][cur_c] = 0;
					continue;
				}
			}
			printf("NEXT_R : %d / NEXT_C : %d\n", next_r, next_c);
			map2[next_r][next_c] = 1;
			sharks[next_r][next_c] = sharks[cur_r][cur_c];
		}  // ��� �̵� �Ϸ�   The End of 'while(!q.empty())'
		
		for(int e = 0 ; e < R ; ++e){
			printf("[");
			for(int m = 0 ; m < C ; ++m){
				map[e][m] = map2[e][m];
				if(map2[e][m] == 1){
					FOR_QUEUE ttmp;
					ttmp.r = e;	ttmp.c = m;	ttmp.dir = sharks[e][m].d;	ttmp.size = sharks[e][m].z;	ttmp.speed = sharks[e][m].s;
					q.push(ttmp);
				}
				printf("%d ", map[e][m]);
			}
			printf("]\n");
		}
		printf("\n\n");
		 
	}
	
	printf("%d", ans);
	return 0;
	
}
 
 
  
 
