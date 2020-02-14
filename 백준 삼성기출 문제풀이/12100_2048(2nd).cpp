//  N (1 �� N �� 20)�� �־����� 
//  0 : ��ĭ 

// OUTPUT --> �ִ� 5�� �̵����Ѽ� ���� �� �ִ� ���� ū ����� ����Ѵ�.

#include <stdio.h>
#include <vector>

using namespace std;

int dir[] = {1,2,3,4}; // ���ʴ�� (��, ��, ��, ��)
vector<int> picked;

int dr[] = {-1, 1, 0, 0};   // �� �� �� �� 
int dc[] = {0, 0, -1, 1};

int N;
int map[20][20];

int ans = (-1 * (0x7fffffff));  // �ְ� ã�ƾ� �ϴϱ� �ּҰ����� ����  

void rotate(int cnt, int (&back)[][]){
	int tmp[N][N];
	if(cnt == 1){  // ���� ���	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				tmp[i][j] = back[(N-1)-j][i]; 
			}
		}
	}
	else if(cnt == 3){  // ���� ���	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				tmp[i][j] = back[j][(N-1)-i];
			}
		}
	}
	else if(cnt == 2){  // ���� ���	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				tmp[i][j] =back[i][(N-1)-j];
			}
		}
	}	
	else if(cnt == 0){ // ���� ���� ��� �� �״�� 
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				tmp[i][j] = back[i][j];
			}
		}		
	}
	
	// ���� �����ϼ� ���������� �и鼭  (�翬�� tmp������ �ؾ���)
	// ���������� �о�鼭 �ϴϱ� �ϴ� ���� ������Ų��. �� i���� ���� j���� ����
	for(int i= 0 ; i < N ; ++i) {
		for(int j = 0 ; j <N ; ++j){
			if(tmp[i][j] == 0)	continue;
		}
	}
	
	
	
	// ������ �ٽ� ������ ���󺹱� ����� �� ��(�״ϱ� tmp --> back) 
	if(cnt == 1){  // ���� ���	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				back[i][j] = tmp[j][(N-1)-i];
			}
		}
	}
	else if(cnt == 3){  // ���� ���	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				back[i][j] = tmp[(N-1)-j][i]; 
			}
		}
	}
	else if(cnt == 2){  // ���� ���	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				back[i][j] = tmp[i][(N-1)-j];
			}
		}
	}	
	else if(cnt == 0){ // ���� ���� ��� �� �״�� 
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				back[i][j] = tmp[i][j];
			}
		}		
	}	
	
}


// �� �Լ����� picked�� ���� ���������� ���� rotate�ϰ� ������� ����Ѵ�.  
// �׸��� picked�� ������ ������������ �̿���ؼ� ���� ������, �ְ� ã�� �������� ans�� ���Ѵ�. 
void update(){  
	// �ϴ� backup
	int backup[N][N];
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			backup[i][j] = map[i][j];
		}
	}
	
	// {1,2,3,4} --> ���ʴ�� (��, ��, ��, ��)
	for(int i = 0 ; i < picked.size() ; ++i){
		if(picked[i] == 1){  // ���� ��� 
			rotate(1, backup);
		} 
		else if(picked[i] == 2){  // ���� ��� 
			rotate(3, backup);
		}
		else if(picked[i] == 3){  // ���� ��� 
			rotate(2, backup);
		}
		else if(picked[i] == 4){  // ���� ��� 
			rotate(0, backup);
		}						
	}
	
	
	// ���� ���� ��� �Ϸ�� backup���� �ְ� ã�´�
	int tmp_max = (-1 * (0x7fffffff));
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(tmp_max < backup[i][j]){
				tmp_max = backup[i][j];
			}
		}
	}	
	
	if(tmp_max > ans){
		ans = tmp_max;
	}
}

void dfs(int count){
	if(count == 5){
		// �� ���� ���⼭ ������ �����ؾ��� 
		update();
		return;
	}

	for(int i = 0 ; i < 4 ; ++i){
		picked.push_back(dir[i]);
		dfs(picked.size());
		picked.pop_back();
	}
	
}

int main(){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	//###################################
	
	// Ǯ�̹�� : DFS�� 5����(��,��,��,��) �� ����� ���� ����� ����!
	// �״ϱ� 4 * 4 * 4 * 4* 4 �� case���� backup[][] �������� �� ��
	dfs(0);
	printf("%d\n", ans);
}
