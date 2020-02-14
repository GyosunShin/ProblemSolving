// ������ ũ�� N(2 �� N �� 20)
// 0: �� ĭ
// 1, 2, 3, 4, 5, 6: ĭ�� �ִ� ������� ũ��
// 9: �Ʊ� ����� ��ġ

#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int map[20][20];

int size = 2; // �ʱ� �Ʊ����� ũ�� 
int eat_cnt = 0;   // �� �ڸ� �Ű����� ����� ���� Ƚ�� ó������ �ٽý���! 	

int ans;

// �� �� �� ��
int dr[] = {-1, 0, 0, 1}; 
int dc[] = {0, -1, 1, 0};

struct INFO{
	int r;
	int c;	
	int len;	 
};

INFO start; 

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 9){  // ���� ����� ��ġ ��� 
				start.r = i;
				start.c = j;
				start.len = 0;
				map[i][j] = 0;
			}
		}
	}
	// ##############################
	

	
	while(1){  // ���̻� ���� ����� ������������ 
		queue<INFO> q;
		q.push(start);
		int flag = 0; 
		int visited[20][20] = { 0, };
		
		INFO tmp;
		tmp.len = -1;
		// �ֻ�� �������� �ִ°� ������ ������ �ʱⰪ �̷��� �����! 
		tmp.r = 20;
		tmp.c = 20;
		
		while(!q.empty()) {
			INFO cur = q.front();
			q.pop();
			visited[cur.r][cur.c] = 1;
			
			if(tmp.len != -1 && cur.len > tmp.len){  // �̹� �̾Ƴ� ����. 				
				break;
			}
			
			if(map[cur.r][cur.c] < size && map[cur.r][cur.c] != 0){  // ���� �� �ִ°�� 
				// ������ ���õ� ���̶� �Ÿ��� ���������� ��ġ�� �� ����, ���ʿ� ��ġ�� ��� tmp����! 
				flag = 1 ;
				if(tmp.r > cur.r || (tmp.r == cur.r && tmp.c > cur.c)) {
					tmp = cur;
				}
			}
			
			for(int i = 0 ; i < 4 ; ++i){
				INFO next;
				next.r =  cur.r + dr[i];
				next.c =  cur.c + dc[i];
				next.len = cur.len + 1;
				// �̹� �ٸ� ���κ����� BFSŽ���� ���� ��ģ�����̶��... (or) �������� ����ٸ�... 
				if(visited[next.r][next.c] != 0 || 0 > next.r || next.r >= N || 0 > next.c || next.c >= N){  
					continue; 
				}
				if(map[next.r][next.c] <= size){
					visited[next.r][next.c] = 1;
					q.push(next);
				}
				
			}
		} // queue empty�Ǵ� ����
		
		if(!flag){
			break;
		}
		else{
			start = tmp;
			ans += tmp.len; 
			++eat_cnt;
			if(eat_cnt == size){  // ����� ũ�� ++! 
				++size;
				eat_cnt = 0;
			}
			map[tmp.r][tmp.c] = 0;  // �Ծ����ϱ� ��ĭ���� �ٲ��ش�.				
		}
	}
	
	printf("%d", start.len);
}





