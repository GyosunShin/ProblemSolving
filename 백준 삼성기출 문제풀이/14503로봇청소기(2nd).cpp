//  (3 �� N, M �� 50)


// 0�� ��쿡�� ������, 1�� ��쿡�� ������, 2�� ��쿡�� ������, 3�� ��쿡�� ����
// (0 : ��) (1 : �� ) (2 : ��) (3 : ��)
// (0 : ��ĭ) (1 : ��)

#include <cstdio>

int map[50][50];
bool cleaned[50][50];
int R, C, start_r, start_c, start_dir;

// ��  ��  ��  �� 
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int dir_change[] = {3, 0, 1, 2};
const int back_r[] = {1, 0, -1, 0};
const int back_c[] = {0, -1, 0, 1};
const int left[4][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};

int ans;

	// OUTPUT : �κ� û�ұⰡ û���ϴ� ĭ�� ������ ����Ѵ�.
	//���� ��ġ�� û���Ѵ�.
	//���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
		//���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
		//���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
		//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
		//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
void dfs(int r, int c, int dir){
	
//	printf("R : %d / C : %d\n", r, c);
	
	int cur_dir = dir;
	
	bool tmp_flag = true;
	for(int i = 0 ; i < 4 ; ++i){
		dir = dir_change[dir];
		int next_r = r + dr[dir];	int next_c = c + dc[dir];
		if(map[next_r][next_c] == 0 && !cleaned[next_r][next_c] && tmp_flag){
			++ans;
			cleaned[next_r][next_c] = true;
			dfs(next_r, next_c, dir);
			tmp_flag = false;
			break;
		}
	}
	
	if(tmp_flag){
		int b_r = r + back_r[dir];	int b_c = c + back_c[dir];
		if(map[b_r][b_c] == 1){
			// �۵��� �����.
			return;
		}
		else{
			// �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
			dfs(b_r, b_c, dir);
		}
	}
}

int main(){
	scanf("%d %d", &R, &C);
	scanf("%d %d %d", &start_r, &start_c, &start_dir);
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%d", &map[i][j]);
		}
	}

	++ans;
	cleaned[start_r][start_c] = true;
	dfs(start_r, start_c, start_dir);
	
	printf("%d", ans);
	return 0;
}

