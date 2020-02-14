// ������ ����Ǵ� ���� ��ȣ�� ���غ���.

// 4 �� N �� 12  /  4 �� K �� 10
// (0 ���) (1 ������) (2 �Ķ���)
// ��, ���� ��ȣ(1 <=)  , �̵� ����   (1 ��) (2 ��) (3 ��) (4  ��)

// OUTPUT : ������ ����Ǵ� ���� ��ȣ�� ����Ѵ�. �� ���� 1,000���� ũ�ų� ����� ������ ������� �ʴ� ��쿡�� -1�� ����Ѵ�.

#include <stdio.h> 
#include <queue>
#include <vector>

using namespace std;

int map[12][12];
vector<int> v[12][12];

// �� �� �� �� 
const int dr[] = {0, 0, -1, 1};
const int dc[] = {1, -1, 0, 0};
// �� �� �� �� 
const int rev_dr[] = {0, 0, 1, -1};
const int rev_dc[] = {-1, 1, 0, 0};

int N, K;
int loc[11][3];

int dir_change(int input){
	if(input == 0)	return 1;
	if(input == 1)	return 0;
	if(input == 2)	return 3;
	if(input == 3)	return 2;
}

int solve(){
	
	int ret = 1;
	
	while(true){
		if(ret > 1000)	return -1;
		
		for(int i = 1 ; i <= K ; ++i){
			int cur_r = loc[i][0];
			int cur_c = loc[i][1];
			int cur_dir = loc[i][2];
			
//			printf("HORSE : %d / CUR_R : %d / CUR_C : %d / CUR_DIR : %d / RET : %d\n",i , cur_r, cur_c, cur_dir, ret);						
			
			// map : (0 ���) (1 ������) (2 �Ķ���)
			int stack_size = v[cur_r][cur_c].size();
			int where;
			for(int j = 0 ; j < stack_size ; ++j){
				if(v[cur_r][cur_c][j] == i){
					where = j;
					break;
				}
			}
			
			int next_r = cur_r + dr[cur_dir];	int next_c = cur_c + dc[cur_dir];
			
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N){   // ���� ������ ���ǿ��� ��� ��� 
				int rev_r = cur_r + rev_dr[cur_dir];	int rev_c = cur_c + rev_dc[cur_dir];
				if(map[rev_r][rev_c] == 2){
					loc[i][2] = dir_change(cur_dir);
					continue;
				}
				else{
					next_r = rev_r;	next_c = rev_c; cur_dir = dir_change(cur_dir);
					loc[i][2] = cur_dir;
				}
			}
			
			if(map[next_r][next_c] == 2) {  // �� �ڸ��� �Ķ� ���� ��� 
				int rev_r = cur_r + rev_dr[cur_dir];	int rev_c = cur_c + rev_dc[cur_dir];
				if(0 > rev_r || rev_r >= N || 0 > rev_c || rev_c >= N){
					loc[i][2] = dir_change(cur_dir);								
					continue;
				}
				if(map[rev_r][rev_c] == 2){
					loc[i][2] = dir_change(cur_dir);							
					continue;
				}
				else{
					next_r = rev_r;	next_c = rev_c; cur_dir = dir_change(cur_dir);
					loc[i][2] = cur_dir;
				}				
			}			
			
			if(map[next_r][next_c] == 0) {  // �� �ڸ��� �� ���� ��� 
				loc[i][0] = next_r;
				loc[i][1] = next_c;
				for(int k = where ; k < stack_size ; ++k){  // ���ο� ������ �Ű��ְ� 
					v[next_r][next_c].push_back(v[cur_r][cur_c][k]);
					loc[v[cur_r][cur_c][k]][0] = next_r;	loc[v[cur_r][cur_c][k]][1] = next_c;
				}
				for(int k = where ; k < stack_size ; ++k){  // ������ �ڸ����� ���ش�. 
					v[cur_r][cur_c].pop_back();
				}	
			}
			
			if(map[next_r][next_c] == 1) {  // �� �ڸ��� ���� ���� ��� 
				loc[i][0] = next_r;
				loc[i][1] = next_c;
				for(int k = stack_size-1 ; k >= where ; --k){  // ���ο� ������ �Ű��ְ� 
					v[next_r][next_c].push_back(v[cur_r][cur_c][k]);
					loc[v[cur_r][cur_c][k]][0] = next_r;	loc[v[cur_r][cur_c][k]][1] = next_c;
				}
				for(int k = where ; k < stack_size ; ++k){  // ������ �ڸ����� ���ش�. 
					v[cur_r][cur_c].pop_back();
				}					
			}
			
			
			for(int q = 0 ; q < N ; ++q){
				for(int j = 0 ; j < N ; ++j){
					if(v[q][j].size() >= 4)	return ret;
				}
			}
			
			
		}  // �� ������� 
		ret++;
	}
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);		
		}
	}
	for(int i = 1 ; i <= K ; ++i){
		// ��, ���� ��ȣ(1 <=)  , �̵� ����   (1 ��) (2 ��) (3 ��) (4  ��)
		int r, c, dir;
		scanf("%d %d %d", &r, &c, &dir);
		r--;
		c--;
		dir--;
		loc[i][0] = r;
		loc[i][1] = c;
		loc[i][2] = dir;
		v[r][c].push_back(i);
	}
	
	printf("%d", solve());
	
	return 0;
}

