
// ======== GREEDY형 문제 ========== 

// 4 <= N <= 50

// (0=빈칸) <= 각 행의 원소 <= 200

// OUTPUT : 검은 블록을 떨어뜨려 없앨 수 있는 블록 개수의 최댓값을 구하라

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

vector<pair<int, int>> bs[201];
bool visited[201];

int N, answer;

int sero[6][3][2] = {
	{
		{0,1},
		{0,1},
		{1,1}
	},		
	{
		{1,0},
		{1,0},
		{1,1}
	},	
	{
		{1,1},
		{1,0},
		{1,0}
	},
	{
		{1,1},
		{0,1},
		{0,1}
	},
	{
		{1,0},
		{1,1},
		{1,0}
	},
	{
		{0,1},
		{1,1},
		{0,1}
	}
};

int garo[6][2][3] = {
	{
		{1,0,0},
		{1,1,1}
	},		
	{
		{0,0,1},
		{1,1,1}
	},
	{
		{0,1,0},
		{1,1,1}
	},	
	{
		{1,1,1},
		{0,0,1}
	},
	{
		{1,1,1},
		{1,0,0}
	},
	{
		{1,1,1},
		{0,1,0}
	}
};

	
bool check(int idx, vector<vector<int>>& board){
	
	sort(bs[idx].begin(), bs[idx].end());
	vector<pair<int, int>> backup;
	backup.resize(bs[idx].size());
	copy(bs[idx].begin(), bs[idx].end(), backup.begin());
	
	int mmin_c= 0x7fffffff; int mmin_r = 0x7fffffff; 
	for(int i = 0 ; i < bs[idx].size() ; ++i){
		mmin_c = min(mmin_c, bs[idx][i].second);
		mmin_r = min(mmin_r, bs[idx][i].first);
	}
	
	for(int i = 0 ; i < backup.size() ; ++i){
		backup[i].first -= mmin_r;	backup[i].second -= mmin_c;
	}
	
	// 일단 자기 혼자 가능한 모양인지 확인
	// (최소 C , 최대 C값을 확인하여 그 차이를 통해 어떤 모양인지 확인)
	int min_c = 0x7fffffff; 	int max_c = -1;
	for(int i = 0 ; i < bs[idx].size() ; ++i){
		if(bs[idx][i].second < min_c) min_c = bs[idx][i].second;
		if(bs[idx][i].second > max_c) max_c = bs[idx][i].second;
	}
	
	
	if(abs(max_c - min_c) == 1){	// 세로모양
		int ret_idx = 0;
		// 불가능한거 2,3,4,5
		for(int i = 0 ; i < 6 ; ++i){
			bool flag = true;	
			for(int j = 0 ; j < 3 ; ++j){	
				for(int k = 0 ; k < 2 ; ++k){
					if(sero[i][j][k] == 1){
						bool tmp_flag = false;
						for(int l = 0 ; l < backup.size() ; ++l){
							if(backup[l].first == j && backup[l].second == k){
								tmp_flag = true;
								break;
							}
						}
						if(!tmp_flag){
							flag = false;
							break;
						}
					}
				}
				if(!flag)	break;
			}
			if(flag){
				ret_idx = i;
				break;
			}
		}
		printf("세로 : %d\n", ret_idx);
		
		if(ret_idx >= 2){
			return false;
		}
		
		int tr = -1, tc = -1;
	
		// 빈칸 찾기
		for(int i = 0 ; i < 3 ; ++i){
			if(tr != -1 && tc != -1)	break;
			for(int j = 0 ; j < 2 ; ++j){
				if(board[i+mmin_r][j+mmin_c] == 0){
					tr = i + mmin_r;	tc = j + mmin_c;
					break;
				}
			}
		}			
		
		if(tr == -1 && tc == -1)	return false;
		
		for(int i = 0 ; i < tr ; ++i){
			if(board[i][tc] != 0){
				return false;
			}
		}
		
		board[tr][tc] = idx;
		bs[idx].push_back({tr, tc});		
		

		if(bs[idx].size() == 6){
			for(int i = 0 ; i < bs[idx].size() ; ++i){
				board[bs[idx][i].first][bs[idx][i].second] = 0;
			}
			bs[idx].clear();
			answer++;
		}			

	}
	else{	// 가로모양 
		
		// 불가능한거 3,4,5
		int ret_idx = 0;
		for(int i = 0 ; i < 6 ; ++i){
			bool flag = true;	
			for(int j = 0 ; j < 2 ; ++j){	
				for(int k = 0 ; k < 3 ; ++k){
					if(garo[i][j][k] == 1){
						bool tmp_flag = false;
						for(int l = 0 ; l < backup.size() ; ++l){
							if(backup[l].first == j && backup[l].second == k){
								tmp_flag = true;
								break;
							}
						}
						if(!tmp_flag){
							flag = false;
							break;
						}
					}
				}
				if(!flag)	break;
			}
			if(flag){
				ret_idx = i;
				break;
			}
		}
		printf("가로 : %d\n", ret_idx);
		if(ret_idx >= 3){
			return false;
		}
		
		// 그 후 위에 혹시 누가 가리고 있는지 확인 
		int tr = -1, tc = -1;
	
		// 빈칸 찾기
		for(int i = 0 ; i < 2 ; ++i){
			if(tr != -1 && tc != -1)	break;
			for(int j = 0 ; j < 3 ; ++j){
				
				if(board[i+mmin_r][j+mmin_c] == 0){
					tr = i + mmin_r;	tc = j + mmin_c;
					break;
				}
				
			}
		}					
		
		printf("TR : %d / TC: %d\n", tr, tc);
		if(tr == -1 && tc == -1)	return false;
	
		for(int i = 0 ; i < tr ; ++i){
			if(board[i][tc] != 0){
				return false;
			}
		}
		
		board[tr][tc] = idx;
		bs[idx].push_back({tr, tc});
			
		if(bs[idx].size() == 6){
			for(int i = 0 ; i < bs[idx].size() ; ++i){
				board[bs[idx][i].first][bs[idx][i].second] = 0;
			}
			bs[idx].clear();
			printf("ANW!\n");
			answer++;
		}
		
	}
	
	return true;
}
 
void solve(vector<vector<int>>& board){
	
	while(true){
		printf("\ntry!\n");
	
		memset(visited, false, sizeof(visited));
		
		bool flag = false;
		
		for(int i = 0 ; i < board.size() ; ++i){
			for(int j = 0 ; j < board[i].size() ; ++j){
				int cur = board[i][j];
				if(cur > 0 && !visited[cur]){
					if(check(cur, board)){
						printf("성공!\n") ;
						flag = true;
					}
					
					visited[board[i][j]] = true;
				}
				
			}
		}
		
		if(!flag)	return;
	
	}
	
}

int solution(vector<vector<int>> board) {
    N = board.size();
    
	for(int i = 0 ; i < board.size() ; ++i){
		for(int j = 0 ; j < board[i].size() ; ++j){
			if(board[i][j] > 0){
				bs[board[i][j]].push_back({i, j});
			}
		}
	}
	
	solve(board);
    
    return answer;
}

//int main(){
//	vector<vector<int>> board({
//		vector<int>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
//		vector<int>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
//		vector<int>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
//		vector<int>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
//		vector<int>({0, 0, 0, 0, 0, 0, 4, 0, 0, 0}),
//		vector<int>({0, 0, 0, 0, 0, 4, 4, 0, 0, 0}),
//		vector<int>({0, 0, 0, 0, 3, 0, 4, 0, 0, 0}),
//		vector<int>({0, 0, 0, 2, 3, 0, 0, 0, 5, 5}),
//		vector<int>({1, 2, 2, 2, 3, 3, 0, 0, 0, 5}),
//		vector<int>({1, 1, 1, 0, 0, 0, 0, 0, 0, 5}),
//	});
//	
//	cout << "ANS : " << solution(board) << endl;
//	
//}
