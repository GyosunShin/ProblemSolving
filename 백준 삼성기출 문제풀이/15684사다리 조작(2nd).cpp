// ���μ��� ���� N, ���μ��� ���� M, ���μ����� ���μ��� ���� �� �ִ� ��ġ�� ���� H�� �־�����. 
// (2 �� N �� 10  /  1 �� H �� 30  /  0 �� M �� (N-1)��H)
// M���� �ٿ��� ���μ��� ������ �� �ٿ� �ϳ��� 
// a�� b�� ��Ÿ����. (1 �� a �� H, 1 �� b �� N-1) b�� ���μ��� b+1�� ���μ��� a�� ���� ��ġ���� �����ߴٴ� �ǹ�


// OUTPUT : ������ 3���� ū ���̸� -1�� ����Ѵ�. ��, �Ұ����� ��쿡�� -1�� ����Ѵ�.

#include <stdio.h> 

int N, M, H;
int ladder[30][9];

int ans = 4;

bool check(){	// i��° src --> i��° dst�� ������ check!
	bool tmp_ans = true;
	
	for(int i = 0 ; i < N ; ++i){	// Column
		int tmp_i = i;
		for(int j = 0 ; j < H ; ++j){	// Row
			if(ladder[j][tmp_i] == 1 && 0 <= tmp_i && tmp_i < N - 1){	// �����ʿ� ��ٸ� ���� ��� 
				++tmp_i;		
			}
			else if(ladder[j][tmp_i - 1] == 1 && 0 <= tmp_i - 1 && tmp_i - 1 < N - 1){	// ���ʿ� ��ٸ� ���� ��� 
				--tmp_i;
			}
		}
		if(tmp_i != i){
			tmp_ans = false;
			break;
		}
	}
	
	return tmp_ans;
}

void dfs(int cnt, int r, int c){
	if(cnt > ans)	return;	// �̹� ���� �� ���� ��  �־����� ����ġ��!
	 
	if(check()){	// i���簡 ��� i��° ���ٸ� 
		ans = cnt;
		return;
	}
	
	if(cnt == 3)	return;	//������ ���� �ڵ忡�� cnt+1�� �ش��ϴ°� �� ���̹Ƿ� ���⼭ �׸��Ѵ�. 
	
	for(int i = r ; i < H ; ++i){
		for(int j = c ; j < N-1 ; ++j){
			if(ladder[i][j] != 1){
				ladder[i][j] = 1;
				dfs(cnt + 1, i, j);
				ladder[i][j] = 0;
			}
		}
		c = 0;
	}
	
}

int main(){
	scanf("%d %d %d", &N, &M, &H);
	for(int i = 0 ; i < M ; ++i){
		int a,b;  // b�� ���μ��� b+1�� ���μ��� a�� ���� ��ġ���� �����ߴٴ� �ǹ�
		scanf("%d %d", &a, &b);
		ladder[a-1][b-1] = 1;
	}
	//############################
	
	// 1st) DFS�� �̿��Ͽ� ��ٸ��߰��� 1������ 3������ �Ѵ� �׸��� 4�� �̻���ʹ� ������ -1�� ��½�Ų��. 
	dfs(0, 0, 0);
	if(ans == 4)	ans = -1;	
	printf("%d", ans);
	return 0;	
}


