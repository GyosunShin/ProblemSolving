// ���� ó���� ����� ��� ĭ�� 5��ŭ ����ִ�.

// �� : �ڽ��� ���̸�ŭ ��и԰� / ���� 1 ����
// ������ ���� ������ ��������� 
// �ڽ��� ���̸�ŭ �� ���� ���ϸ� ��� ����

// ���� : ���� ���� ������ ������� ����
// (���� ���� ���� / 2) ��ŭ �߰�

// ���� : ���̰� 5�� ����� ���  ������ 8�� ĭ�� ����
// ������ ������ ���̰� 1 

// �ܿ� : S2D2�� ���� ����߰���
//=========================================================
// 1 �� N �� 10

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
	// ù° �ٿ� K���� ���� �� ��Ƴ��� ������ ���� ����Ѵ�.
	int answer = 0;
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			answer += pq[i][j].size();
		}
	}
	printf("%d", answer);
	
	return 0;
}





