// N (2 ≤ N ≤ 100)과 L (1 ≤ L ≤ N)
// 각 칸의 높이 <= 10 

// OUTPUT : 첫째 줄에 지나갈 수 있는 길의 개수를 출력한다.

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;
int map[100][100];

int ans;

bool garo(int r){
	// (r, 0)  ~  (r, N-1)
	
	// 전부 똑같은지
	bool flag = true;
	for(int i = 0 ; i < N-1 ; ++i){
		if(map[r][i] != map[r][i+1]){
			flag = false;
			break;
		}
	}
	if(flag){
		return true;
	}	
	
	if(map[r][0] == map[r][N-1]){
		for(int i = 1 ; i < N-1 ; ++i){
			if(map[r][i] < map[r][0])	return false;
		}
		
		int cnt = 0;
		
		
		for()
		
	}
	
	
	
	// 계곡이 있는지
	int tmp = map[r][0] > map[r][N-1] ? 1 : -1;
	if(tmp == 1){  // 왼쪽이 더 큰 경우 
		for(int i = 0 ; i < N-1 ; ++i){
			if(map[r][i] < map[r][i+1]){
				return false;
			}
		}
	}
	else if(tmp == -1){  // 오른쪽이 더 큰 경우 
		for(int i = 0 ; i < N-1 ; ++i){
			if(map[r][i] > map[r][i+1]){
				return false;
			}
		}		
	}
	 
	
	// 계곡이 없고 일렬로 오름차순이거나 내림차순일 경우
	if(tmp == -1){  // 오른쪽이 더 큰 경우 
		vector<int> diff;
		int start = map[r][N-1];
		int cnt = 0;
		for(int i = N-2 ; i >= 0 ; --i){
			if(map[r][i] == map[r][N-1]){
				continue;
			}
			else{
				if(map[r][i] != start && start == map[r][N-1]){
					if(abs(map[r][i] - start) > 1)	return false;
					start = map[r][i];
					cnt++;
				}
				else if(map[r][i] != start && start != map[r][N-1]){
					if(abs(map[r][i] - start) > 1)	return false;
					diff.push_back(cnt);
					start = map[r][i];
					cnt = 1;
				}
				else if(map[r][i] == start && start != map[r][N-1]){
					cnt++;
				}
			}
			if(i == 0)	diff.push_back(cnt);
		}
		
		for(int i = 0 ; i < diff.size() ; ++i){
			if(diff[i] < L)	return false;
		}
		return true;
	}
	else if(tmp == 1){  // 왼쪽이 더 큰 경우 
		vector<int> diff;
		int start = map[r][0];
		int cnt = 0;
		for(int i = 1 ; i < N ; ++i){
			if(map[r][i] == map[r][0]){
				continue;
			}
			else{
				if(map[r][i] != start && start == map[r][0]){
					if(abs(map[r][i] - start) > 1)	return false;
					start = map[r][i];
					cnt++;
				}
				else if(map[r][i] != start && start != map[r][0]){
					if(abs(map[r][i] - start) > 1)	return false;
					diff.push_back(cnt);
					start = map[r][i];
					cnt = 1;
				}
				else if(map[r][i] == start && start != map[r][0]){
					cnt++;
				}
			}
			if(i == N-1)	diff.push_back(cnt);
		}
		for(int i = 0 ; i < diff.size() ; ++i){
			if(diff[i] < L)	return false;
		}
		return true;
	}	 
}

bool sero(int c){
	// (0, c)  ~  (N-1, c)
	
	// 전부 똑같은지
	bool flag = true;
	for(int i = 0 ; i < N-1 ; ++i){
		if(map[i][c] != map[i+1][c]){
			flag = false;
			break;
		}
	}
	if(flag){
		return true;
	}	
	
	// 계곡이 있는지
	int tmp = map[0][c] > map[N-1][c] ? 1 : -1;
	if(tmp == 1){  // 위쪽이 더 큰 경우 
		for(int i = 0 ; i < N-1 ; ++i){
			if(map[i][c] < map[i+1][c]){
				return false;
			}
		}
	}
	else if(tmp == -1){  // 아래쪽이 더 큰 경우 
		for(int i = 0 ; i < N-1 ; ++i){
			if(map[i][c] > map[i+1][c]){
				return false;
			}
		}		
	}
	 
	
	// 계곡이 없고 일렬로 오름차순이거나 내림차순일 경우
	if(tmp == -1){  // 아래쪽이 더 큰 경우 
		vector<int> diff;
		int start = map[N-1][c];
		int cnt = 0;
		for(int i = N-2 ; i >= 0 ; --i){
			if(map[i][c] == map[N-1][c]){
				continue;
			}
			else{
				if(map[i][c] != start && start == map[N-1][c]){
					if(abs(map[i][c] - start) > 1)	return false;
					start = map[i][c];
					cnt++;
				}
				else if(map[i][c] != start && start != map[N-1][c]){
					if(abs(map[i][c] - start) > 1)	return false;
					diff.push_back(cnt);
					start = map[i][c];
					cnt = 1;
				}
				else if(map[i][c] == start && start != map[N-1][c]){
					cnt++;
				}
			}
			if(i == 0)	diff.push_back(cnt);
		}
		for(int i = 0 ; i < diff.size() ; ++i){
			if(diff[i] < L)	return false;
		}
		return true;
	}
	else if(tmp == 1){  // 위쪽이 더 큰 경우 
		vector<int> diff;
		int start = map[0][c];
		int cnt = 0;
		for(int i = 1 ; i < N ; ++i){
			if(map[i][c] == map[0][c]){
				continue;
			}
			else{
				if(map[i][c] != start && start == map[0][c]){
					if(abs(map[i][c] - start) > 1)	return false;
					start = map[i][c];
					cnt++;
				}
				else if(map[i][c] != start && start != map[0][c]){
					if(abs(map[i][c] - start) > 1)	return false;
					diff.push_back(cnt);
					start = map[i][c];
					cnt = 1;
				}
				else if(map[i][c] == start && start != map[0][c]){
					cnt++;
				}
			}
			if(i == N-1)	diff.push_back(cnt);
		}
		for(int i = 0 ; i < diff.size() ; ++i){
			if(diff[i] < L)	return false;
		}
		return true;
	}	 
}

int main(){
	scanf("%d %d", &N, &L);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	
	for(int i = 0 ; i < N ; ++i){
		if(garo(i)){
			printf("%d번째 ROW 가능1\n", i);
			++ans;
			continue;
		}	
		printf("%d번째 ROW 안됭ㅁ!!!1\n", i);
	}
	for(int i = 0 ; i < N ; ++i){
		if(sero(i)){
			printf("%d번째 COL 가능1\n", i);
			++ans;
			continue;
		}	
		printf("%d번째 COL 안됭ㅁ!!!1\n", i);
	}	
	
	printf("%d", ans);
	
	return 0;
}
