// � ��� = K * K + (K - 1) * (K - 1)

// OUTPUT : ���ظ� ���� �����鼭 Ȩ��� ���񽺸� ���� ���� ���鿡 �����ϴ� ���� ������ ã��,
// �� ���� Ȩ��� ���񽺸� ���� �޴� ������ ���� ����ϴ� ���α׷��� �ۼ��϶�.

// ������ ũ��  (5 �� N �� 20)
// (1 �� M �� 10) 
// 1 : ��  || 0 : ������ 

#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

struct INFO{
	int r, c, len;
};

int N, M;

int map[20][20];
int visited[20][20];

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

queue<INFO> q;
vector<INFO> v;

int ans = -1 * 0x7fffffff;

void check(){
	int tmp;
	for(int i = 0 ; i <= (N*2) + 1 ; ++i){
		int opex = ((i+1) * (i+1)) + (i*i);
		int total = 0;
		int cnt = 0;
		for(int z = 0 ; z < v.size() ; ++z){
			printf("V_SIZE : %d\n", v.size());
			INFO cur = v[z];
			if(cur.len > i)	break;
			if(0 > cur.r || cur.r >= N || 0 > cur.c || cur.c >= N)	continue;
			if(map[cur.r][cur.c] == 1){
				++cnt;
				total += M;
			}	
		}
		if(total - opex >= 0){
			tmp = (total / M);
			printf("START_R : %d / START_C : %d / TMP : %d / I : %d / CNT : %d\n", v[0].r, v[0].c, tmp, i, cnt);
			if(ans < tmp){
//				printf("START_R : %d / START_C : %d / TMP : %d / I : %d\n", v[0].r, v[0].c, tmp, i);
				ans = tmp;
			}
		}	
	}
	
}

void bfs(int start_r, int start_c){   
	memset(visited, -1, sizeof(visited));

	v.clear();
	while(!q.empty())	q.pop();

	INFO start;	start.r = start_r;	start.c = start_c;	start.len = 0;
	visited[start_r][start_c] = 1;
	q.push(start);

	while(!q.empty()){
		INFO cur = q.front();	q.pop();
		if(cur.len > (N*2) + 1)	break;
		v.push_back(cur);
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int next_r = cur.r + dr[dir];	int next_c = cur.c + dc[dir];
			if(0 <= next_r && next_r < N && 0 <= next_c && next_c < N){
				if(visited[next_r][next_c] != -1)	continue;	
				visited[next_r][next_c] = 1;
				INFO next;	next.r = next_r;	next.c = next_c;	next.len = cur.len + 1;
				q.push(next);
			}
			else if(0 > next_r || next_r >= N || 0 > next_c || next_c >= N){
				INFO next;	next.r = next_r;	next.c = next_c;	next.len = cur.len + 1;
				q.push(next);	
			}
		}	
	}
	
//	int tmp_ans = check();
//	return check();
	check();
}

int main(){ 
	int T;
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		scanf("%d %d", &N, &M);
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &map[i][j]);
			}
		}
		//#################################
		ans = -1 * 0x7fffffff;
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
//				int tmp_ans = bfs(i, j);	
				bfs(i, j);
//				if(ans < tmp_ans)	ans = tmp_ans;
			}
		}		
		printf("#%d %d\n", z, ans);   // �� ���� ���񽺸� ���� �޴� ������ '�ִ�' ���̴�.
	}
	return 0;
}

