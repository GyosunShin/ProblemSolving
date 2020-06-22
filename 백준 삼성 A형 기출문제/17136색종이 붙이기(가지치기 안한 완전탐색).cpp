// 1이 적힌 칸은 모두 색종이로 덮여져야 한다

// (1 X 1) ~~ (5 X 5) 각각 5개씩!! 보유 

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int pan[10][10];
bool done[10][10];

int hold[6] = {5,5,5,5,5,5};

const int dr[] = {1,1,0};
const int dc[] = {0,1,1};

bool rangeCheck(int r, int c){
	if(0 > r || r >= 10 || 0 > c || c >= 10)	return false;
	return true;
}

//int sizeCheck(int r, int c){
//	int ret = -1;
//	for(int z = 1 ; z <= 5 ; ++z){
//		bool flag = true;
//
//		for(int i = 0 ; i < z ; ++i){
//			if(!flag)	break;
//			for(int j = 0 ; j < z ; ++j){
//				if(pan[r+i][c+j] != 1 || done[r+i][c+j]
//				|| !rangeCheck(r+i, c+j)){
//					flag = false;
//					break;
//				}
//			}
//		}
//		
//		if(!flag){
//			ret = z;
//			break;
//		}
//	}
//	if(ret == -1)	return 5;
//	return ret - 1;
//}

int sizeCheck(int r, int c){
	
	bool visited[10][10];
	memset(visited, false, sizeof(visited));
	int cnt[6];
	memset(cnt, 0, sizeof(cnt));
	
	queue<pair<int, pair<int, int>>> q;
	
	visited[r][c] = true;
	q.push(make_pair(1, make_pair(r, c)));
	
	while(!q.empty()){
		int cur_r = q.front().second.first;	int cur_c = q.front().second.second;
		int sofar = q.front().first;
		if(sofar > 5)	break;
		if(sofar > 1 && cnt[sofar-1] < ((sofar-1)*2 - 1))	break;
		cnt[sofar]++;
		q.pop();
		
		for(int dir = 0 ; dir < 3 ; ++dir){
			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
			if(!rangeCheck(next_r, next_c))	continue;
			if(visited[next_r][next_c] || pan[next_r][next_c] != 1 || done[next_r][next_c])	continue;
			visited[next_r][next_c] = true;
			int next_sofar = sofar + 1;
			q.push(make_pair(next_sofar, make_pair(next_r, next_c)));
		}
	}
	
	int ret = 6;
	
	for(int i = 1 ; i <= 5 ; ++i){
		if(cnt[i] < (i*2 - 1)){
			ret = i;
			break;
		}
	}
	
	return ret-1;
}

void overlap(int r, int c, int size){
	for(int i = 0 ; i < size ; ++i){
		for(int j = 0 ; j < size ; ++j){
			done[r+i][c+j] = true;
		}
	}
}

void overlapUndo(int r, int c, int size){
	for(int i = 0 ; i < size ; ++i){
		for(int j = 0 ; j < size ; ++j){
			done[r+i][c+j] = false;
		}
	}
}

bool allDone(){
	for(int i = 0 ; i < 10 ; ++i){
		for(int j = 0 ; j < 10 ; ++j){
			if(pan[i][j] == 1 && !done[i][j])	return false;
		}
	}
	return true;
}


int dfs(int r, int c){
	
	if(allDone()){
		return 0;
	}
	
	int mmin = 0x7fffffff / 2;
	
	bool flag = false;
	
	for(int i = r ; i < 10 ; ++i){
		if(flag)	break;
		for(int j = c ; j < 10 ; ++j){
			
			if(pan[i][j] == 1 && !done[i][j]){
				int size = sizeCheck(i, j);
				size = size > 5 ? 5 : size;
				
				for(int k = size ; k >= 1 ; --k){
					if(hold[k] < 1)	continue;
					hold[k]--;
					overlap(i, j, k);
					int next_r = i;	int next_c = (j+k) % 10;
					mmin = min(mmin, dfs(next_r, next_c) + 1);
					hold[k]++;
					overlapUndo(i, j, k);
				}	
				flag = true;
				break;
			}	
		}
		c = 0;
	}
	
	return mmin;
}

int solve(){
	if(allDone())	return 0;
	
	int mmin = 0x7fffffff / 2;	
	
	bool flag = false;
	
	for(int i = 0 ; i < 10 ; ++i){
		if(flag)	break;
		for(int j = 0 ; j < 10 ; ++j){
			if(pan[i][j] == 1 && !done[i][j]){
				int size = sizeCheck(i, j);
				size = size > 5 ? 5 : size;
				
				for(int k = size ; k >= 1 ; --k){
					if(hold[k] < 1)	continue;
					hold[k]--;
					overlap(i, j, k);
					depth++;
					int next_r = i;	int next_c = (j+k) % 10;
					mmin = min(mmin, dfs(next_r, next_c) + 1);
					hold[k]++; 	
					depth--;
					overlapUndo(i, j, k);
				}
				flag = true;
				break;
			}
		}
	}
	
	if(mmin == (0x7fffffff / 2))	return -1;
	return mmin;
}

int main(){
	
	for(int i = 0 ; i < 10 ; ++i){
		for(int j = 0 ; j < 10 ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	
	int ret = solve();
	
	// OUTPUT
	// 모든 1을 덮는데 필요한 색종이의 최소 개수를 출력한다. 
	// 1을 모두 덮는 것이 불가능한 경우에는 -1을 출력
	printf("%d", ret);
	
	return 0;
}
