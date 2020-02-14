// 그렇게 하기 위해서 추가해야 하는 가로선 개수의 최솟값을 구하는 프로그램을 작성하시오.

//  (2 ≤ N(세로선) ≤ 10, 1 ≤ H(세로선마다 가로선을 놓을 수 있는 위치의 개수) ≤ 30, 0 ≤ M(가로선) ≤ (N-1)×H)


// 만약, 정답이 3보다 큰 값이면 -1을 출력한다. 또, 불가능한 경우에도 -1을 출력한다.

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

bool check(){   // 하나라도 자신의 도착점에 도착 못하면 return false; 
	for(int i = 1 ; i <= N ; ++i){
		int start_r = 0;   // +1씩	
		int start_c = i;   // 변경해야 하는 값 
		
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
//		printf("시작점 : %d / 끝 점 : %d\n", i, start_c);
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
		scanf("%d %d", &a, &b);  // b ~ b+1 세로선 사이에 a 높이에서...
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
	
	// 가로선을 1개부터 3개까지만 늘려본다.
	for(int i = 1 ; i <= 3 ; ++i){
		dfs(1, 1, i);
		if(global_break){
			printf("%d", i);
			return 0;
		}
	}	
	
	// 가로선이 4개이상 늘려야 하면 -1출력 
	printf("-1");
	
	return 0;
}

