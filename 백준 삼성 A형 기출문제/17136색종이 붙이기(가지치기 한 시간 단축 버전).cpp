// 1�� ���� ĭ�� ��� �����̷� �������� �Ѵ�

// (1 X 1) ~~ (5 X 5) ���� 5����!! ���� 

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

#include <vector>

using namespace std;

int pan[10][10];
bool done[10][10];

int hold[6] = {5,5,5,5,5,5};

int answer = 0x7fffffff;

vector<pair<int, pair<int, int>>> v;

const int dr[] = {1,1,0};
const int dc[] = {0,1,1};

bool rangeCheck(int r, int c){
	if(0 > r || r >= 10 || 0 > c || c >= 10)	return false;
	return true;
}

int sizeCheck(int r, int c){
	int ret = -1;
	for(int z = 1 ; z <= 5 ; ++z){
		bool flag = true;

		for(int i = 0 ; i < z ; ++i){
			if(!flag)	break;
			for(int j = 0 ; j < z ; ++j){
				if(pan[r+i][c+j] != 1 || done[r+i][c+j]
				|| !rangeCheck(r+i, c+j)){
					flag = false;
					break;
				}
			}
		}
		
		if(!flag){
			ret = z;
			break;
		}
	}
	if(ret == -1)	return 5;
	return ret - 1;
}


// <BFS QUEUE �̿����>
//int sizeCheck(int r, int c){
//	
//	bool visited[10][10];
//	memset(visited, false, sizeof(visited));
//	int cnt[6];
//	memset(cnt, 0, sizeof(cnt));
//	
//	queue<pair<int, pair<int, int>>> q;
//	
//	visited[r][c] = true;
//	q.push(make_pair(1, make_pair(r, c)));
//	
//	while(!q.empty()){
//		int cur_r = q.front().second.first;	int cur_c = q.front().second.second;
//		int sofar = q.front().first;
//		if(sofar > 5)	break;
//		if(sofar > 1 && cnt[sofar-1] < ((sofar-1)*2 - 1))	break;
//		cnt[sofar]++;
//		q.pop();
//		
//		for(int dir = 0 ; dir < 3 ; ++dir){
//			int next_r = cur_r + dr[dir];	int next_c = cur_c + dc[dir];
//			if(!rangeCheck(next_r, next_c))	continue;
//			if(visited[next_r][next_c] || pan[next_r][next_c] != 1 || done[next_r][next_c])	continue;
//			visited[next_r][next_c] = true;
//			int next_sofar = sofar + 1;
//			q.push(make_pair(next_sofar, make_pair(next_r, next_c)));
//		}
//	}
//	
//	int ret = 6;
//	
//	for(int i = 1 ; i <= 5 ; ++i){
//		if(cnt[i] < (i*2 - 1)){
//			ret = i;
//			break;
//		}
//	}
//	
//	return ret-1;
//}

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

void dfs(int r, int c, int sofar){
	
	if(allDone()){
		answer = min(answer, sofar);
		return;
	}
	
	if(sofar > answer){
		return;
	}
	
	bool flag = false;
	
	for(int i = r ; i < 10 ; ++i){
		if(flag)	break;
		for(int j = c ; j < 10 ; ++j){			
			if(pan[i][j] == 1 && !done[i][j]){
				int size = sizeCheck(i, j);
				
				for(int k = size ; k >= 1 ; --k){
					if(hold[k] < 1)	continue;
					hold[k]--;
					overlap(i, j, k);
					int next_r = i;	int next_c = (j+k) % 10;
					v.push_back(make_pair(k, make_pair(i, j)));
					dfs(next_r, next_c, sofar + 1);
					v.pop_back();
					hold[k]++;
					overlapUndo(i, j, k);
				}
				flag = true;
				break;
			}
		}
		c = 0;
	}
	
}

void solve(){
	if(allDone()){
		answer = 0;
		return;
	}
	
	bool flag = false;
	
	for(int i = 0 ; i < 10 ; ++i){
		if(flag)	break;
		for(int j = 0 ; j < 10 ; ++j){
			if(pan[i][j] == 1 && !done[i][j]){
				int size = sizeCheck(i, j);

				for(int k = size ; k >= 1 ; --k){
					if(hold[k] < 1)	continue;
					hold[k]--;
					overlap(i, j, k);
					int next_r = i;	int next_c = (j+k) % 10;
					v.push_back(make_pair(k, make_pair(i, j)));
					dfs(next_r, next_c, 1);
					v.pop_back();
					hold[k]++;
					overlapUndo(i, j, k);
				}
				flag = true;
				break;
			}
		}
	}
	
}

int main(){
	
	for(int i = 0 ; i < 10 ; ++i){
		for(int j = 0 ; j < 10 ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	
	solve();
	
	// OUTPUT
	// ��� 1�� ���µ� �ʿ��� �������� �ּ� ������ ����Ѵ�. 
	// 1�� ��� ���� ���� �Ұ����� ��쿡�� -1�� ���
	if(answer == 0x7fffffff)	answer = -1;
	printf("%d", answer);
	
	return 0;
}
