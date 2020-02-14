// (4 �� N(���� ROW), M(���� COLUMN) �� 500)
// 
// OUTPUT : ù° �ٿ� ��Ʈ�ι̳밡 ���� ĭ�� ���� ������ ���� �ִ��� ����Ѵ�.

#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

struct INFO{
	int r, c;
};

int N, M;
int map[500][500];
int visited[500][500];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

vector<INFO> picked;

int ans = (-1 * 0x7fffffff);

int fuckyou(int r, int c){
	int tmp_ans = 0;
	if(r+2 < N && c+1 < M) {
		// �����
		tmp_ans = max(tmp_ans, (map[r][c] + map[r+1][c] + map[r+2][c] + map[r+1][c+1]));
		// �ø��
		tmp_ans = max(tmp_ans, (map[r+1][c] + map[r][c+1] + map[r+1][c+1] + map[r+2][c+1]));
	}
	if(r+1 < N && c+2 < M) {
		// �Ǹ��
		tmp_ans = max(tmp_ans, (map[r][c+1] + map[r+1][c] + map[r+1][c+1] + map[r+1][c+2]));
		// �̸��
		tmp_ans = max(tmp_ans, (map[r][c] + map[r][c+1] + map[r][c+2] + map[r+1][c+1]));
	}	
	return tmp_ans;	 
}

void dfs(int r, int c, int len){  // (r, c) : ������ 

	if(picked.size() == 4){
//		for(int i = 0 ; i < picked.size() ; ++i){
//			printf("[EVERY](R : %d / C : %d)  ", picked[i].r, picked[i].c);
//		}		
//		printf("\n");
		int tmp_sum = 0;
		for(int i = 0 ; i < picked.size() ; ++i){
			tmp_sum += map[picked[i].r][picked[i].c];
		}
		if(tmp_sum > ans){
//			for(int i = 0 ; i < picked.size() ; ++i){
//				printf("(R : %d / C : %d)  ", picked[i].r, picked[i].c);
//			}
//			printf("\n");
			ans = tmp_sum;
//			printf("ans : %d\n", ans);
		}
		
		return;
	}
	
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
//		if(0 > next_r || next_r >= N || 0 > next_c || next_c >= M || visited[next_r][next_c] != 0){
//			continue;
//		}
		
		
		if(0 <= next_r && next_r < N && 0 <= next_c && next_c < M && visited[next_r][next_c] == 0){
			INFO next;	next.r = next_r;	next.c = next_c;
			picked.push_back(next);
			visited[next_r][next_c] = 1;
			dfs(next_r, next_c, len+1);
			visited[next_r][next_c] = 0;
			picked.pop_back();
		}
	}
	
}

int main(){
	memset(visited, 0, sizeof(visited));
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	//#################################
	
	// DFS�� �̿��ؼ� 4���� �̾��� ��� ���� �غ��ڴ�! 
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			
			picked.clear();
			INFO start;	start.r = i;	start.c = j;
			visited[i][j] = 1;
			picked.push_back(start);
			dfs(i, j, 1);
			visited[i][j] = 0;
			picked.pop_back();
		}
	}
	
	
	// ����! �� �� �� �� ��翡�� �ִ� �� ã�� DFS�� ã�� �ִ� ���̶� ���Ѵ�. 
	int ttmp_ans = 0;
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			ttmp_ans = max(ttmp_ans, fuckyou(i, j));
		}
	}
	
	int real = max(ans, ttmp_ans);
	
	printf("%d",real);
	return 0;
	
}
