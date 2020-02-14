// OUTPUT : 게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램을 작성하시오.
// 스도쿠 판을 채우는 방법이 여럿인 경우는 그 중 하나만을 출력한다.

#include <stdio.h> 
#include <string.h> 
#include <algorithm>
#include <vector>

using namespace std;

int map[9][9];
bool sero[9][10];  // []번째 세로줄에 이미 []값이 이미 있느냐! 
bool garo[9][10];  // []번째 가로줄에 이미 []값이 이미 있느냐! 
bool square[9][10];  // []번째 논리적 사각형안에 이미 []값이 이미 있느냐! 

vector<pair<int ,int> > empties;
vector<int> picked;

bool flag = false;

void dfs(){
	if(flag)	return;
	
	if(picked.size() == empties.size()){
		for(int i = 0 ; i < picked.size() ; ++i){
			map[empties[i].first][empties[i].second] = picked[i];
		}
		
		for(int i = 0 ; i < 9 ; ++i){
			for(int j = 0 ; j < 9 ; ++j){
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}				
		flag = true;
		return;			
	}
	
	for(int i = 1 ; i <= 9 ; ++i){
		int cur_r = empties[picked.size()].first;	int cur_c = empties[picked.size()].second;
		if(!garo[cur_r][i] && !sero[cur_c][i] && !square[((cur_r/3) * 3) + (cur_c/3)][i]){
			picked.push_back(i);
			garo[cur_r][i] = true;
			sero[cur_c][i] = true;
			square[((cur_r/3) * 3) + (cur_c/3)][i] = true;
			dfs();
			picked.pop_back();
			garo[cur_r][i] = false;
			sero[cur_c][i] = false;
			square[((cur_r/3) * 3) + (cur_c/3)][i] = false;
		}
	}
}

int main(){
	for(int i = 0 ; i < 9 ; ++i){
		for(int j = 0 ; j < 9 ; ++j){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 0){
				empties.push_back(make_pair(i,j));
			}
			else{
				garo[i][map[i][j]] = true;
				sero[j][map[i][j]] = true;
				int a = i/3;	int b = j/3;
				int tmp = (a * 3) + b;
				square[tmp][map[i][j]] = true;
			}
		} 
	}
	
	// 중복 순열 이용...? 
	dfs();
	
	return 0;
}
