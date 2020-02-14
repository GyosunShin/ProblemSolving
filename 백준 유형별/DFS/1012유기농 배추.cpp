// ���߹��� ���α��� M(1 �� M �� 50)�� ���α��� N(1 �� N �� 50), �׸��� ���߰� �ɾ��� �ִ� ��ġ�� ���� K(1 �� K �� 2500)

// OUTPUT : �� �׽�Ʈ ���̽��� ���� �ʿ��� �ּ��� ������������ ���� ���� ����Ѵ�.

#include <stdio.h> 
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct INFO{
	int r, c;
};

int T;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

int M, N, K;
int map[50][50];
int visited[50][50];

void dfs(int r, int c){
	
	for(int dir = 0 ; dir < 4 ; ++dir){
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		if(0> next_r || next_r >= N || 0> next_c || next_c >= M || visited[next_r][next_c] != 0 || map[next_r][next_c] != 1){
			continue;
		}
		visited[next_r][next_c] = 1;
		dfs(next_r, next_c);
	}
	
}

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		scanf("%d %d %d", &M, &N, &K);  // ����(column), ����(row), ���� ����  
		
		vector<INFO> v;
		for(int i = 0 ; i < K ; ++i){
			int tmp_r, tmp_c;
			scanf("%d %d", &tmp_c, &tmp_r);  // ����(column), ����(row)
			map[tmp_r][tmp_c] = 1;
			INFO tmp;
			tmp.r = tmp_r;	tmp.c = tmp_c;
			v.push_back(tmp);
		}
		
		int ans = 0;
		
		for(int i = 0 ; i < v.size() ; ++i){
			INFO cur = v[i];
//			printf("CUR_R : %d / CUR_C : %d\n", cur.r, cur.c);
			
			if(visited[cur.r][cur.c] == 1){
//				printf("VISITED!\n");
				continue;
			}
			
			dfs(cur.r, cur.c);
//			printf("++ANS!! : %d\n", ans);
			++ans;
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}
