//(3 �� N, M �� 8)  N : ���� / M : ����
//0 : ��ĭ(3�̻�) / 1 : ��(2�̻� 10����) / 2 : ���̷���
//
//��� : ���� �� �ִ� ���� ������ �ִ� ũ�� 
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int map[8][8];

int ans; // ���� ū ���������� �ִ� ũ�� 

// �� �� �� �� 
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs(){
	queue<int> q;
	int backup[8][8]; // �ʿ��� ���� : BFS�� ���� ���̷����� �÷��� ���̹Ƿ�! 
	int visited[8][8] = { 0, };
	
	// �ϴ� ���̷������� �۶߷��� �Ѵ�.  BY) BFS!!!
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			backup[i][j] = map[i][j];
			if(backup[i][j] == 2){  // �̹� 'Virus'�� �ִٸ� visited�� ǥ���ص���! 
				visited[i][j] = 1;
				q.push(i*10 + j);
			}
		}
	}
	// �׷��� ��������� ���� map�� �����Ͽ��� Virus�� queue�� ������� ���̴�.
	// ���� ������ ������ �ʿ���� �������� ���̷����� �÷����⸸ �ϸ� �Ǵ� ���̹Ƿ� �̸� ä�� �־ No���
	
	while(!q.empty()){
		int cur = q.front(); q.pop();
		int cur_r = cur / 10;
		int cur_c = cur % 10;
		backup[cur_r][cur_c] = 2;
		for(int i = 0 ; i < 4 ; ++i){
			int next_r = cur_r + dr[i];		
			int next_c = cur_c + dc[i];
			// �������� ��� ��� ���
			if(next_r < 0 || next_r >= N || next_c < 0 || next_c >= M)	continue;
			
			if(backup[next_r][next_c] == 0 && visited[next_r][next_c] != 1){  // ����ִٸ� ���̷��� ����! 
				visited[next_r][next_c] = 1;
				int next = next_r * 10 + next_c;
				q.push(next);	 
			}
		}
	}
	// ��! �׷��� ������� ����  Virus ���� �Ϸ�! 
	
	// ����... �������� ũ�� ��� ����!
	int tmp = 0;
	for(int i = 0 ; i < N ; ++i) {
		for(int j = 0 ; j < M ; ++j){
			if(backup[i][j] == 0) tmp++;
		}
	}
	
	if(tmp > ans){
		ans = tmp;
	}
	
	 
	
}

void dfs(int count, int r, int c){  // �ϴ� map�� ��� ������ �����鼭 ��ĭ�̶��, �� ���� '0'�� ������ 3���� �������� �����Ѵ�. 
	if(count == 3){
		bfs();
		return; 
	}
	
	for(int i = r ; i < N ; ++i){
		for(int j = c ; j < M ; ++j){
			if(map[i][j] == 0){  // ��ĭ�̶��!!
				map[i][j] = 1;
				dfs(count + 1, i, j);
				map[i][j] = 0;
			}
		}
		// !!!!!!!!!!!
		c = 0;
		// !!!!!!!!!!!		
	}
}


int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0, 0, 0);
	printf("%d", ans);
}
 
