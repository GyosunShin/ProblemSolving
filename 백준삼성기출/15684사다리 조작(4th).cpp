// �׷��� �ϱ� ���ؼ� �߰��ؾ� �ϴ� ���μ� ������ �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

//  (2 �� N(���μ�) �� 10, 1 �� H(���μ����� ���μ��� ���� �� �ִ� ��ġ�� ����) �� 30, 0 �� M(���μ�) �� (N-1)��H)


// ����, ������ 3���� ū ���̸� -1�� ����Ѵ�. ��, �Ұ����� ��쿡�� -1�� ����Ѵ�.

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, H;

bool ladder[31][11];
bool backup[31][11];

vector<pair<int, int> > picked;

bool global_break = false;

bool check(){   // �ϳ��� �ڽ��� �������� ���� ���ϸ� return false; 
	for(int i = 1 ; i <= N ; ++i){
		int start_r = 0;   // +1��	
		int start_c = i;   // �����ؾ� �ϴ� �� 
		
		for(int j = 0 ; j < H ; ++j){
			start_r++;
			if(start_c == 1){
				if(backup[start_r][start_c]){
					start_c++;
				}
			}
			else if(start_c == N){
				if(backup[start_r][start_c - 1]){
					start_c--;
				}
			}
			else{
				if(backup[start_r][start_c]){
					start_c++;
				}
				else if(backup[start_r][start_c - 1]){
					start_c--;
				}
			}	
		}
//		printf("������ : %d / �� �� : %d\n", i, start_c);
		if(start_c != i)	return false;
	}
	return true;
}

void dfs(int start_r, int start_c, int howmany){
	if(global_break)	return;
	
	if(picked.size() == howmany){
		copy(&ladder[0][0], &ladder[0][0] + 11 * 31, &backup[0][0]);
		
		for(int i = 0 ; i < picked.size() ; ++i){
			backup[picked[i].first][picked[i].second] = true;
		}
		
//		printf("[%d]\n", howmany);
//		for(int i = 1 ; i <= H ; ++i){
//			for(int j = 1 ; j <= N ; ++j){
//				if(backup[i][j])	printf("1 ");
//				else	printf("0 ");
//			}
//			printf("\n");
//		}
//		printf("\n");
		
		if(check()){
			global_break = true;
			return;
		}
		
		return;
	}
	
	for(int i = start_r ; i <= H ; ++i){
		for(int j = start_c ; j <= N ; ++j){
			
			if(j == 1){
				if(ladder[i][j+1])	continue;
			}
			else if(j == H){
				if(ladder[i][j-1])	continue;
			}
			else{
				if(ladder[i][j+1] || ladder[i][j-1])	continue;
			}
			if(ladder[i][j])	continue;
			picked.push_back(make_pair(i, j));
			if(j == H)	dfs(i+1, 0, howmany);
			else	dfs(i, j+1, howmany);
			picked.pop_back();
			
		}
		start_c = 1;	
	}
	
}

int main(){
	scanf("%d %d %d", &N, &M, &H);
	for(int i = 0 ; i < M ; ++i){
		int a, b;
		scanf("%d %d", &a, &b);  // b ~ b+1 ���μ� ���̿� a ���̿���...
		ladder[a][b] = true;
	}
	copy(&ladder[0][0], &ladder[0][0] + 11 * 31, &backup[0][0]);	
	
//	printf("[0]\n");
//	for(int i = 1 ; i <= H ; ++i){
//		for(int j = 1 ; j <= N ; ++j){
//			if(backup[i][j])	printf("1 ");
//			else	printf("0 ");
//		}
//		printf("\n");
//	}
//	printf("\n");	
		
	if(check()){
		printf("%d", 0);
		return 0;
	}
	
	// ���μ��� 1������ 3�������� �÷�����.
	for(int i = 1 ; i <= 3 ; ++i){
		dfs(1, 1, i);
		if(global_break){
			printf("%d", i);
			return 0;
		}
	}	
	
	// ���μ��� 4���̻� �÷��� �ϸ� -1��� 
	printf("-1");
	
	return 0;
}

