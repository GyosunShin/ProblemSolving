// 추가해야 하는 가로선 개수의 최솟값을 구하는 프로그램을 작성하시오.
// 만약, 정답이 3보다 큰 값이면 -1을 출력한다. 또, 불가능한 경우에도 -1을 출력한다.

// (2 ≤ N ≤ 10, 1 ≤ H ≤ 30, 0 ≤ M ≤ (N-1)×H)

#include <stdio.h>
#include <vector>

//int map[H][N-1];
int map[30][9];

using namespace std;

int N, M, H;

vector<pair<int, int> > picked;

int ans = 0x7fffffff;

bool check(){
//	for(int i = 0 ; i < H ; ++i){
//		for(int j = 0 ; j < N-1 ; ++j){
//			printf("%d ", map[i][j]);
//		}
//		printf("\n");
//	}
	bool tmp_ans = true;
	
	for(int i = 0 ; i < N-1 ; ++i){
//		printf("ORDER : %d\n", i);
		int cur = i;
		int cur_r = -1;
		for(int z = 1 ; z <= H ; ++z){
			if(0 <= cur && cur < N-1){
				if(map[cur_r + z][cur] == 1){
//					printf("right\n");
					++cur;
					continue;
				}
			}
			if(0 <= (cur-1) && (cur-1) < N-1){
				if(map[cur_r + z][cur-1] == 1){
//					printf("left\n");
					--cur;
					continue;
				}
			}			
		}
		if(cur != i){
			tmp_ans = false;
			break;
		}
	}
//	printf("\n");
	return tmp_ans;
}

void dfs(int r, int c){
	if(picked.size() > ans)	return;	   // 이미 전에 더 좋은 게  있었으면 가지치기!
	if(picked.size() > 3){
		return;
	}
	
	if(check()){
		if(ans > picked.size())	ans = picked.size();
		return;
	}
	
	for(int i = r ; i < H ; ++i){
		for(int j = c ; j < N-1 ; ++j){
			if(map[i][j] == 0){
				if(0 <= j - 1 && j - 1 < N-1){
					if(map[i][j-1] == 1)	continue;
				}
				if(0 <= j + 1 && j + 1 < N-1){
					if(map[i][j+1] == 1)	continue;
				}				
				map[i][j] = 1;
				picked.push_back(pair<int, int>(i, j));
				dfs(i, j);
				map[i][j] = 0;
				picked.pop_back();
			}
		}
		c = 0;
	}
	
	
}

int main(){
	scanf("%d %d %d", &N, &M, &H);
	for(int i = 0 ; i < M ; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		map[a-1][b-1] = 1;
	}
	//##################################
	
	dfs(0,0);
	
	if(ans > 3)	printf("-1");
	else	printf("%d", ans);
	
	return 0;
}
