
// ���� ����Ǵ� �߿� ���� 4�� �̻� ���̴� ���� ������ ����ȴ�.

// �� ���� �̵��� �� ���� �÷��� �ִ� ���� �Բ� �̵��Ѵ�

// ���� Target ĭ�� ��
// ���(0) : �׳� ����ϰ� �̵��Ͽ� ���� �״´�.
// ������(1) : ����� �����ϰ� �̵��Ͽ� ���� ������ ���� �����´�.
// �Ķ���(2) (or) ��� ��� ��� : �̵����� ������Ű�� ��ĭ �̵��ϱ�

//4 �� N(ü���� ũ��) �� 12
//4 �� K(�� ����) �� 10 

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct INFO{
	int r, c, dir;
};

// ��, ��, ��, �� 
const int dr[] = {0,0,-1,1};
const int dc[] = {1,-1,0,0};
const int dd[] = {1,0,3,2};

int N, K;
int pan[12][12];	// For) ���� 
vector<int> track[12][12];

vector<INFO> horses;

bool check(){
		
	for(int i = 0 ; i < horses.size() ; ++i){
		
		int cur_r = horses[i].r;	int cur_c = horses[i].c;	int cur_dir = horses[i].dir;
		int next_r = cur_r + dr[cur_dir];	int next_c = cur_c + dc[cur_dir];	int next_dir = cur_dir;
		
		if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N 
		|| pan[next_r][next_c] == 2){	// �Ķ��� (or) ���� ��� ��� 
			next_dir = dd[next_dir];
			next_r = cur_r + dr[next_dir];	next_c = cur_c + dc[next_dir];
			horses[i].dir = next_dir;
			if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N || pan[next_r][next_c] == 2){
				continue;
			}
		}
		
		if(pan[next_r][next_c] == 0){	// ���
			int idx = 0;
			for(int j = 0 ; j < (int)track[cur_r][cur_c].size() ; ++j){
				if(track[cur_r][cur_c][j] == i){
					idx = j;
					break;
				}
			}
			for(int j = idx ; j < (int)track[cur_r][cur_c].size() ; ++j){
				track[next_r][next_c].push_back(track[cur_r][cur_c][j]);
				horses[track[cur_r][cur_c][j]].r = next_r;	horses[track[cur_r][cur_c][j]].c = next_c;
			}
			int tmp = (int)track[cur_r][cur_c].size() - idx;
			for(int j = 0 ; j < tmp ; ++j){
				track[cur_r][cur_c].pop_back();
			}
		}
		else if(pan[next_r][next_c] == 1){	// ������
			int idx = 0;
			for(int j = 0 ; j < (int)track[cur_r][cur_c].size() ; ++j){
				if(track[cur_r][cur_c][j] == i){
					idx = j;
					break;
				}
			}			
			for(int j = (int)track[cur_r][cur_c].size()-1 ; j >= idx ; --j){
				track[next_r][next_c].push_back(track[cur_r][cur_c][j]);
				horses[track[cur_r][cur_c][j]].r = next_r;	horses[track[cur_r][cur_c][j]].c = next_c;
			}
			int tmp = (int)track[cur_r][cur_c].size() - idx;
			for(int j = 0 ; j < tmp ; ++j){
				track[cur_r][cur_c].pop_back();
			}
		}	
		
		if(track[next_r][next_c].size() >= 4)	return true;	
	}
	
	return false;
}

int solve(){
	int turn = 1;
	
	while(true){
		if(turn > 1000){
			turn = -1;
			break;
		}
		
		if(check()){
			break;
		}
		turn++;
	}
	
	// ������ ����Ǵ� ���� ��ȣ�� ����Ѵ�. 
	// �� ���� 1,000���� ũ�ų� ����� ������ ������� �ʴ� ��쿡�� -1�� ����Ѵ�.
	return turn;
}

int main(){
	scanf("%d %d", &N, &K);
	
	//  (0 : ���)  (1 : ������)  (2 : �Ķ���) 
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	
	int r, c, dir;
	for(int i = 0 ; i < K ; ++i){
		scanf("%d %d %d", &r, &c, &dir);
		r--;	c--;	dir--;
		INFO tmp = {r, c, dir};
		horses.push_back(tmp);
		track[r][c].push_back(i);
	}
	
	printf("%d", solve());
	
	return 0;
}
