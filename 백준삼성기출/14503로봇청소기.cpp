/* BFS�� �̿��ؼ� �κ�û�ұ��� �������� �����ؾ� �� �� */

//(3 �� N, M �� 50)
//�θ�û�ұ� (r, c)  | 0:�� 1:�� 2:�� 3:��
//0:��ĭ 1:��
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int r, c, dir;
int map[50][50];
int cleaned[50][50] = { 0, };
int ans = 0;

int check = 0;

// �� �� �� �� 
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

queue<pair<int, int> > q;

void bfs(){
	// �ϴ� �̹� start���� queue.push()�� ���� 
	
	while(!q.empty()){
		printf("ONCE!!  %d\n", ans);
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		printf("r : %d , c : %d\n", cur_r, cur_c);
		printf("check : %d\n", check);
		q.pop();		
		int next_dir = -1;
		int next_r, next_c; 
		int back_r, back_c; 
		
		// 0:�� 1:�� 2:�� 3:��
		if(dir == 0){ // �� -> ��=��(2) 
			next_r = cur_r + dr[2]; 
			next_c = cur_c + dc[2];
			back_r = cur_r + dr[1];  // �� -> ��=��(1) 
			back_c = cur_c + dc[1];
			next_dir = 3;
		}
		else if(dir == 1){ // �� -> ��=��(0) 
			next_r = cur_r + dr[0]; 
			next_c = cur_c + dc[0];
			back_r = cur_r + dr[2];  // �� -> ��=��(2) 
			back_c = cur_c + dc[2];
			next_dir = 0;
		}
		else if(dir == 2){ // �� -> ��=��(3) 
			next_r = cur_r + dr[3]; 
			next_c = cur_c + dc[3];
			back_r = cur_r + dr[0];  // �� -> ��=��(0) 
 			back_c = cur_c + dc[0];
			next_dir = 1;
		}		
		else if(dir == 3){ // �� -> ��=��(1) 
			next_r = cur_r + dr[1]; 
			next_c = cur_c + dc[1];
			back_r = cur_r + dr[3];   // �� -> ��=��(3) 
			back_c = cur_c + dc[3];
			next_dir = 2;
		}		
		printf("next_r : %d , next_c : %d\n", next_r, next_c);
		
		// �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ '����'�� �ϰ� 2������ ���ư���.
		if(check == 4 && map[back_r][back_c] != 1){
			printf("BACK!!\n");
			q.push(pair<int, int>(back_r, back_c));
			check = 0;
		}
		// �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
		else if(check == 4 && map[back_r][back_c] == 1){
			printf("END   : %d\n", ans);
			check = 0;
			return;
		}		
		// ���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
		else if(map[next_r][next_c] == 0 && cleaned[next_r][next_c] != 1) {
			cleaned[cur_r][cur_c] = 1;
			printf("CLEAN!!\n");
			++ans;
			dir = next_dir;
			q.push(pair<int, int>(next_r, next_c));
			check = 0;
		}
		// ���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
		else if(map[next_r][next_c] == 1 || cleaned[next_r][next_c] == 1){
			printf("ROTATE!!!!\n");
			dir = next_dir;
			q.push(pair<int, int>(cur_r, cur_c));
			++check; // �̰� 4�� ���� 4���� ���� �� 
			
			
		}
		printf("\n");
	}
}
 
int main(){
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &dir);   // dir --> 0:�� 1:�� 2:�� 3:��
	cleaned[r][c] = 1;
	++ans;
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < M ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	// ------------ ������� �Է� �� -------------
	q.push(pair<int, int>(r,c));
	bfs();
	printf("%d", ans);
}
 
