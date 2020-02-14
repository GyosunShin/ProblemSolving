// OUTPUT :  우리는 게임 캐릭터가 지나간 길 중 캐릭터가 처음 걸어본 길의 길이를 구하려고 합니다.

#include <string>
#include <iostream>
using namespace std;

int visited[11][11][11][11];

int cur_r, cur_c;

const int dr[] = {1, -1, 0, 0};	// U D R L
const int dc[] = {0, 0, 1, -1};

int ans;

int solution(string dirs) {
	
	for(int i = 0 ; i < dirs.size() ; ++i){
		int dir;
		if(dirs[i] == 'U')	dir = 0;
		if(dirs[i] == 'D')	dir = 1;
		if(dirs[i] == 'R')	dir = 2;
		if(dirs[i] == 'L')	dir = 3;
	
//		cout << "cur_r : " << cur_r << " / cur_c : " << cur_c << endl;
		int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
//		cout << "next_r : " << next_r << " / next_c : " << next_c << endl;
		
		if(-5 > next_r || next_r > 5 || -5 > next_c || next_c > 5){
//			cout << "COTINUE " << endl;
			continue;
		}
		
		int tmp_cur_r = cur_r;
		int tmp_cur_c = cur_c;
		int tmp_next_r = next_r;
		int tmp_next_c = next_c;
		if(cur_r < 0)	tmp_cur_r = cur_r + 11;
		if(cur_c < 0)	tmp_cur_c = cur_c + 11;
		if(next_r < 0)	tmp_next_r = next_r + 11;
		if(next_c < 0)	tmp_next_c = next_c + 11;
		
		if(visited[tmp_cur_r][tmp_cur_c][tmp_next_r][tmp_next_c] == 0 && visited[tmp_next_r][tmp_next_c][tmp_cur_r][tmp_cur_c] == 0){
			++ans;
			visited[tmp_cur_r][tmp_cur_c][tmp_next_r][tmp_next_c] = 1;
			visited[tmp_next_r][tmp_next_c][tmp_cur_r][tmp_cur_c] = 1;
		}
		cur_r = next_r;	cur_c = next_c;	
	}
	
	return ans;
}
