// 1 <= �� ��ȣ <= 16
// 8���� (�����¿�, �밢��)

// �ϴ� [0,0]�� �ִ� ����� �԰� �ش� ������� ������ ���Ե�

// ����� �̵�����(��ȣ���� ��������!) 
//     �̵�����ĭ(�ٸ� ����� (or) ��ĭ) 	
//		�̵� �Ұ���ĭ(����ִ� ĭ (or) ���Ѵ°�) 
//		�ݽð� 45���� �̵������Ҷ����� ����ٲٰ� �׷��� ������ �������� �ʴ´�.
//		�̵������ϰ� �Ǹ� �ش� �ڸ��� �ִ� ������ �ڸ��� Switch!!

// ���� ����̵� ���� 

#include <cstdio>
#include <algorithm>

using namespace std;

struct FISH{
	int r, c;
	int dir;
	bool alive;
};

FISH fishes[17];	// 1 <= Idx <= 16

int num[4][4];

// ��(0), ��, ��, ��, ��, ��, ��, ��(7) 
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, -1, -1, -1, 0, 1, 1, 1};

int answer;

void pt(){
	for(int i = 0 ; i < 4 ; ++i){
		for(int j = 0 ; j < 4 ; ++j){
			printf("%d ", num[i][j]);
		}
		printf("\n");
	}
}

bool rangeCheck(int r, int c){
	if(0 > r || r >= 4 || 0 > c || c >= 4)	return false;
	return true;
}

void fishMove(int (&arr)[4][4], FISH (&fishes)[17]){
	
	for(int i = 1 ; i <= 16 ; ++i){
		if(fishes[i].alive){
			int cur_r = fishes[i].r;	int cur_c = fishes[i].c;
			int cur_dir = fishes[i].dir;
			
			for(int n = 0 ; n < 8 ; ++n){
				int next_dir = (cur_dir + n) % 8;
				int next_r = cur_r + dr[next_dir];
				int next_c = cur_c + dc[next_dir];
				if(!rangeCheck(next_r, next_c) || arr[next_r][next_c] == -1)	continue;
				
				fishes[i].r = next_r;	fishes[i].c = next_c;
				fishes[i].dir = next_dir;
				
				int nextIdx = arr[next_r][next_c];
				fishes[nextIdx].r = cur_r;	fishes[nextIdx].c = cur_c;
				
				int tmp = arr[next_r][next_c];
				arr[next_r][next_c] = arr[cur_r][cur_c];
				arr[cur_r][cur_c] = tmp;
				
				break;
			}	
		}
	}
	
}

void dfs(int r, int c, int dir, int sofar, int (&arr)[4][4], FISH (&fish)[17]){
	
	int backup[4][4];
	for(int i = 0 ; i < 4 ; ++i){
		for(int j = 0 ; j < 4 ; ++j){
			backup[i][j] = arr[i][j];
		}
	}
	
	FISH fishesBackUp[17];
	for(int i = 1 ; i <= 16 ; ++i){
		fishesBackUp[i].alive = fish[i].alive;
		fishesBackUp[i].r = fish[i].r;	fishesBackUp[i].c = fish[i].c;
		fishesBackUp[i].dir = fish[i].dir;
	}
		
	// ����� �̵����� 
	fishMove(backup, fishesBackUp);
	
	// ���� ����̵����� 
	// �� ĭ�� �ִ� ����⸦ �԰�, �� ������� ������ ������ �ȴ� 
	// ����Ⱑ ���� ĭ���δ� �̵��� �� ���� 
	// �� �̵��� �� �ִ� ĭ�� ������ �������� ��� ������ ���� 
	int trycnt = 0;
	for(int k = 1 ; k <= 3; ++k){
		int next_r = r + (k * dr[dir]);	int next_c = c + (k * dc[dir]);
		if(!rangeCheck(next_r, next_c))	break;
				
		int target = backup[next_r][next_c];
		if(target == 0)	continue;
		
		int next_dir = fishesBackUp[target].dir;
		
		trycnt++;
		backup[r][c] = 0;
		backup[next_r][next_c] = -1;
		fishesBackUp[target].alive = false;
		dfs(next_r, next_c, next_dir, sofar + target, backup, fishesBackUp);
		fishesBackUp[target].alive = true;
		backup[next_r][next_c] = target;
		backup[r][c] = -1;
	}
	
	if(trycnt == 0)	answer = max(answer, sofar);
}

void solve(){
	// �ϴ� [0,0]���� ���� 
	int initialTarget = num[0][0];
	fishes[initialTarget].alive = false;
	int initialDir = fishes[initialTarget].dir;
	num[0][0] = -1;	// ��� �ִ� ĭ�̶�� ǥ�� 
	
	dfs(0, 0, initialDir, initialTarget, num, fishes);
}

int main(){
	
	for(int i = 0 ; i < 4 ; ++i){
		for(int j = 0 ; j < 4 ; ++j){
			int tmp_dir;
			scanf("%d %d", &num[i][j], &tmp_dir);
			tmp_dir--;
			fishes[num[i][j]].r = i;	fishes[num[i][j]].c = j;
			fishes[num[i][j]].dir = tmp_dir;
			fishes[num[i][j]].alive = true;
		}
	}

	solve(); 
	
	// OUTPUT
	// �� ���� �� �ִ� ����� ��ȣ�� ���� �ִ�
	printf("%d", answer);
	
	return 0;
}
