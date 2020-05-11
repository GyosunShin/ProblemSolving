// 가장 처음에 양분은 모든 칸에 5만큼 들어있다.

// 봄 : 자신의 나이만큼 양분먹고 / 나이 1 증가
// 여러개 나무 있으면 어린나무부터 
// 자신의 나이만큼 다 먹지 못하면 즉시 죽음

// 여름 : 봄에 죽은 나무가 양분으로 변함
// (죽은 나무 나이 / 2) 만큼 추가

// 가을 : 나이가 5의 배수인 놈들  인접한 8개 칸에 번식
// 번식한 나무는 나이가 1 

// 겨울 : S2D2에 의해 양분추가됨
//=========================================================
// 1 ≤ N ≤ 10

#include <cstdio> 
#include <queue> 
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;

int A[10][10];
priority_queue<int, vector<int>, greater<int>> pq[10][10];
queue<int> q[10][10];
int pan[10][10];
vector<int> dead[10][10];

const int dr[] = {-1,1,0,0,1,1,-1,-1};
const int dc[] = {0,0,-1,1,1,-1,1,-1};

void spring(){
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			
			if(pq[i][j].size() > 0){
				while(!pq[i][j].empty()){
					int cur_age = pq[i][j].top();	pq[i][j].pop();
					
					if(cur_age > pan[i][j]){
						dead[i][j].push_back((int)(cur_age / 2));
						break;
					}
				
					q[i][j].push(cur_age + 1);
					pan[i][j] -= cur_age;
				}
				while(!pq[i][j].empty()){
					int cur_age = pq[i][j].top();	pq[i][j].pop();
					dead[i][j].push_back((int)(cur_age / 2));
				}
			}
			
		}
	}
	
}

void summer(){
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(dead[i][j].size() > 0){
				
				for(int k = 0 ; k < dead[i][j].size() ; ++k){				
					pan[i][j] += dead[i][j][k];
				}
				dead[i][j].clear();
			
			}
		}
	}
	
}

void fall(){
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			
			if(q[i][j].size() > 0){
				
				while(!q[i][j].empty()){
					int cur_age = q[i][j].front();	q[i][j].pop();
					
					pq[i][j].push(cur_age);
					
					if(cur_age % 5 == 0){
						for(int dir = 0 ; dir < 8 ; ++dir){
							int next_r = i + dr[dir];	int next_c = j + dc[dir];
							if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N)	continue;
							pq[next_r][next_c].push(1);
						}
					}
					
				}
				
			}
			
		}
	}
	
}

void winter(){
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			pan[i][j] += A[i][j];
		}
	}
	
}

void solve(){	
	spring(); 
	
	summer();
	
	fall();
	
	winter();
}

int main(){
	scanf("%d %d %d", &N, &M, &K);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			pan[i][j] = 5;
		}
	}
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &A[i][j]);
		}
	}
	
	int r, c, age;
	for(int i = 0 ; i < M ; ++i){
		scanf("%d %d %d", &r, &c, &age);
		r--;	c--;
		pq[r][c].push(age);
	}
	
	for(int i = 0 ; i < K ; ++i)	solve();
	
	// OUTPUT
	// 첫째 줄에 K년이 지난 후 살아남은 나무의 수를 출력한다.
	int answer = 0;
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			answer += pq[i][j].size();
		}
	}
	printf("%d", answer);
	
	return 0;
}





