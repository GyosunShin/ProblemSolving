//  �������� ũ�� N(4 �� N �� 50), ���� �� �ִ� ���̷����� ���� M(1 �� M �� 10) 
//  0�� �� ĭ, 1�� ��, 2(M<=  &&  <= 10)�� ���̷���
//  
//  OUTPUT : �������� ��� �� ĭ�� ���̷����� �ְ� �Ǵ� �ּ� �ð��� ����Ѵ�. 
//  ���̷����� ��� ���Ƶ� ��� �� ĭ�� ���̷����� �۶߸� �� ���� ��쿡�� -1�� ����Ѵ�.

#include <stdio.h>
#include <vector>
#include <queue> 

using namespace std;

struct INFO{
	int r, c, len;
};

int N, M;
int map[50][50];

int ans = 0x7fffffff;

vector<pair<int, int> > virus;
vector<pair<int, int> > virus_picked;

int dr[] = {-1, 1, 0, 0};  // �� �� �� �� 
int dc[] = {0, 0, -1, 1};
int blank;

int flag = 0;

void bfs(){
	int max_time = -1 * 0x7fffffff;
	int tmp_cnt = 0; 
	int visited[50][50] = { 0, };
	// �ϴ� ť �����ϰ� ť�� virus_picked�� ��ǥ���� �־��ش�.
	queue<INFO> q;
	for(int i = 0 ; i < virus_picked.size() ; ++i){
		INFO tmp;
		tmp.r = virus_picked[i].first;	tmp.c = virus_picked[i].second;	tmp.len = 0;
		q.push(tmp);
		visited[tmp.r][tmp.c] = 1;
		if(max_time < tmp.len)	max_time = tmp.len;
	}
	
	while(!q.empty()){
		INFO cur = q.front();	q.pop();
//		printf("CUR_R : %d / CUR_C : %d\n", cur.r, cur.c);
		if(map[cur.r][cur.c] != 2)	++tmp_cnt;
		if(max_time < cur.len)	max_time = cur.len;
		if(tmp_cnt == blank){  // �� ä���ٸ�! 
//			printf("HIT! --> tmp_cnt : %d\n", tmp_cnt);
//			printf("FILL COMPLETE! : %d\n", max_time);
			flag = 1;
			if(ans > max_time){
				ans = max_time;
			}
			break; 
		}
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			INFO next;
			next.r = cur.r + dr[dir];	next.c = cur.c + dc[dir];	next.len = cur.len + 1;
//			printf("NEXT_R : %d / NEXT_C : %d\n", next.r, next.c);
			
			// ���� ����ų� (or) �̹� �ٸ� ���κ��� üũ�Ǿ��ٴ��� (or) ���̶�� --> �Ѿ��. 
			if(0 > next.r || next.r >= N || 0 > next.c || next.c >= N || visited[next.r][next.c] != 0 || map[next.r][next.c] == 1){
				continue;
			}
			
			// ��ĭ�� ���! 
			visited[next.r][next.c] = 1;
			q.push(next);	
		}
		
	} // The End of 'while(!q.empty())'
//	printf("\n\n");
	
}

void dfs(int cnt){
	if(virus_picked.size() == M){
		// TODO : BFS������ �ð� �����ϰ� ans���� ������ ans�� �������ش�.
//		for(int i = 0 ; i < virus_picked.size() ; ++i){
//			printf("(%d, %d) ", virus_picked[i].first, virus_picked[i].second);
//		}
//		printf("\n");
		bfs();
		
		return;
	}
	
	for(int i = cnt ; i < virus.size() ; ++i){
		virus_picked.push_back(virus[i]);
		dfs(i + 1);
		virus_picked.pop_back();
	}
	
}


int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 2)	virus.push_back(pair<int, int>(i, j));
			if(map[i][j] == 0)	++blank;
		}
	}
//	printf("BLANK : %d\n\n", blank);
	//#################################
	
	
	// 1st) DFS�� ���� virus vector�� �����ϴ� ���� m���� �̴´�. 
	dfs(0);
	
	if(!flag)	ans = -1;
	printf("%d", ans);
	return 0;	
}
