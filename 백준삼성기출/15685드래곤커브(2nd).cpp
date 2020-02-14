// �巡�� Ŀ���� ���� N(1 �� N �� 20)

// x�� y�� �巡�� Ŀ���� ���� ��, d�� ���� ����, g�� �����̴�. (0 �� x, y �� 100, 0 �� d �� 3, 0 �� g �� 10)

// 0: x��ǥ�� �����ϴ� ���� (��)  �� 
// 1: y��ǥ�� �����ϴ� ���� (��)  �� 
// 2: x��ǥ�� �����ϴ� ���� (��)  �� 
// 3: y��ǥ�� �����ϴ� ���� (��)  �� 

// OUTPUT : ù° �ٿ� ũ�Ⱑ 1��1�� ���簢���� �� �������� ��� �巡�� Ŀ���� �Ϻ��� ���� ������ ����Ѵ�.

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// �� �� �� �� 
const int dr[] = {0, -1, 0, 1};
const int dc[] = {1, 0, -1, 0};
const int dir_change[] = {1, 2, 3, 0} ;

int N;
int start_x, start_y, dir, gen;

bool map[101][101];

vector<int> track;

pair<int, int> change_idx(int r, int c){
	return make_pair(c+100, r);
}

void solve(int start_r, int start_c, int cnt){
//	printf("TEST : %d / start_R : %d  || strat_c : %d\n", cnt, start_r, start_c);
	
//	for(int i = 0 ; i < track.size() ; ++i)	printf("(%d) ", track[i]);
//	printf("\n");
	
	if(cnt > gen){
		return;
	}
	map[start_r][start_c] = true;
//	printf("[%d][%d] -> TRUE\n", start_r, start_c);
	int divv = track.size() / 2;
	for(int i = divv ; i < track.size() ; ++i){
		start_r += dr[track[i]];	start_c += dc[track[i]];	
		map[start_r][start_c] = true;
//		printf("[%d][%d] -> TRUE\n", start_r, start_c);
	}
	for(int i = track.size()-1 ; i >= 0 ; --i){
		track.push_back(dir_change[track[i]]);
	}
	
	solve(start_r, start_c, cnt+1);
}


int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		scanf("%d %d %d %d", &start_x, &start_y, &dir, &gen);
//		pair<int, int> tmp = change_idx(start_x, start_y);
		track.push_back(dir);
		solve(start_y, start_x, 0);
		track.clear();
	}
	
	int ans = 0;
	
	for(int i = 0 ; i < 100 ; ++i){
		for(int j = 0 ; j < 100 ; ++j){
			if(map[i][j] == true && map[i][j+1] == true && map[i+1][j] == true && map[i+1][j+1] == true)	++ans;
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
