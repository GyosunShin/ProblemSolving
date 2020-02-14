// ���μ��� ���� N / ���μ��� ���� M / ���μ����� ���μ��� ���� �� �ִ� ��ġ�� ���� H
// (2 �� N �� 10, 1 �� H �� 30, 0 �� M �� (N-1)��H)
// (1 �� a �� H, 1 �� b �� N-1) 
// 
// i�� ���μ��� ����� i���� �������� ��ٸ� ������ �����Ϸ���, �߰��ؾ� �ϴ� ���μ� ������ �ּڰ��� ����Ѵ�. 
// ����, ������ 3���� ū ���̸� -1�� ����Ѵ�. ��, �Ұ����� ��쿡�� -1�� ����Ѵ�.
#include <stdio.h>
#include <stdlib.h>



int N, M, H;
int map[30][19] = { 0, };

// ��, ��, �� 
int dr[] = {-1, 0, 0}; 
int dc[] = {0, 1, -1};

void map_copy(int dsc[30][19], int src[30][19]){
	for(int i = 0 ; i < 30 ; ++i){
		for(int j = 0 ; j < 19 ; ++j){
			dsc[i][j] = src[i][j];
		}
	}
}

// �ϴ� map[][] ���󳻷����� �Լ� ����
// ������ ����� ����� column���� ���� ��� �����Ͽ����� Ȯ��! 
bool track() {
	printf("<TRACK>\n");
	for(int i = 0 ; i < 30 ; ++i){
		printf("[");
		for(int j = 0 ; j < 19 ; ++j){
			printf("%d ", map[i][j]);
		}
		printf("]\n");
	}	
	bool ret = true; // �ϳ��� �ڽŰ� ������ ��ġ���� ������ ������ 0���� �ٲ�� ������ �ƴ��� �ǹ�. 
	for(int i = 0 ; i <= ((2 * N) - 2) ; i = i+2){  // 0 -> 2 -> 4 -> 6 -> 8
		int r = 0;
		int c = i;
		int flag = 0;	
		while(0 <= r && r <= H-1){
			printf("r : %d / c : %d\n", r, c);
			
			// ������ġ ���� ���� �� Ȯ��
			int dir = 0; // 0 : �ٷ� ������ | 1 : ��� | 2 : �·� 
			int r_r = r;
			int r_c = c+1; 
			int l_r = r;
			int l_c = c-1;
			printf("r_r : %d / r_c : %d\n", r_r, r_c);
			printf("l_r : %d / l_c : %d\n", l_r, l_c);
			if(1 <= r_c && r_c <= (2*N - 3) && map[r_r][r_c] == 1 && flag == 0){
				printf("RIGHT\n");
				dir = 1;
			}
			if(1 <= l_c && l_c <= (2*N - 3) && map[l_r][l_c] == 1 && flag == 0){
				printf("LEFT\n");
				dir = 2;
			}
			
			if(dir == 0){
				printf("DOWN\n\n");
				flag = 0;
				++r;
			}
			else if(dir == 1){
				flag = 1;
				c = c+2;
			}
			else if(dir == 2){
				flag = 1;
				c = c-2;
			}			
		}  // The End of While Loop
		printf("i : %d / c : %d\n", i, c);
		// ���� ���κп� r == H�� �Ǿ���� �׷��� ������ c���� �̿��Ͽ� i�� �������� �Ǵ��ؾ� ��
		if(c != i) {
			printf("RETURN FALSE\n");
			return false;
		}
	} // the End of ��� ��ٸ� Ÿ�� �� �ڽŰ� ������ ��ġ�� ����
	printf("RETURN TRUE\n");
	return true; 
}


// �� dfs�Ἥ (0,1,2,3)���� ���μ��� �߰��Ͽ��� ��� �� ��� case���� track()�Լ� �̿��ؼ� true��ȯ�Ǹ� �����ô�.
// 4�� �̻��� �� ��� '-1' ����ϼ�~~~ 
int dfs(int count){
	printf("COUNT : %d\n", count);
	if(count == 4){
		printf("-1");
		return 0;
	}
	// �������� �޸� 'count == 4' �� �ƴѰ�쿡�� �߰��Ҷ�����  'bool track()' �� �Լ� Ȯ! ����������!
	if(count != 0 && track()) {
		printf("%d", count);
		exit(0);
//		return 0;
	}
	
	int backup[30][19];
	// 1��->2��->3��(���ÿ� �����鼭) �߰����� ����
	for(int i = 1 ; i < (2*N - 2) ; i = i+2){
		for(int j = 0 ; j < H ; ++j){
			map_copy(backup, map);  // �� ���ϱ� ���� �������� ����! �س��´�. 
			int r_c = i+2;
			int l_c = i-2;
			if(map[j][i] == 1){
				continue;
			}
			if(1 <= r_c && r_c <= (2*N - 3) && map[j][r_c] == 1){
				continue;
			}
			if(1 <= l_c && l_c <= (2*N - 3) && map[j][l_c] == 1){
				continue;
			}			
			map[j][i] = 1;
			printf("ADD 1 (j : %d / i : %d )\n", j, i);
			dfs(count+1);
			map_copy(map, backup);
		}
	}
	 
}


int main() {
	scanf("%d %d %d", &N, &M, &H);
	for(int i = 0 ; i < M ; ++i){
		int a, b;
		scanf("%d %d", &a, &b);	  // (a,b) b�� ���μ��� b+1�� ���μ��� a�� ���� ��ġ���� ����
		map[a-1][2*b-1] = 1;
	}
	
	for(int i = 0 ; i < 30 ; ++i){
		printf("[");
		for(int j = 0 ; j < 19 ; ++j){
			printf("%d ", map[i][j]);
		}
		printf("]\n");
	}
	
	// �ƹ��͵� �� �߰��ص� �Ǵ°��
	if(track()){
		printf("0");
		return 0;
	}
	// �������ʹ� �ּ��� 1���� ��ٸ� �߰��ϴ� ��� 
	dfs(0);
	return 0;
}
