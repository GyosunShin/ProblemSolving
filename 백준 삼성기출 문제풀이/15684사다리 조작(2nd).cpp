// 세로선의 개수 N, 가로선의 개수 M, 세로선마다 가로선을 놓을 수 있는 위치의 개수 H가 주어진다. 
// (2 ≤ N ≤ 10  /  1 ≤ H ≤ 30  /  0 ≤ M ≤ (N-1)×H)
// M개의 줄에는 가로선의 정보가 한 줄에 하나씩 
// a과 b로 나타낸다. (1 ≤ a ≤ H, 1 ≤ b ≤ N-1) b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결했다는 의미


// OUTPUT : 정답이 3보다 큰 값이면 -1을 출력한다. 또, 불가능한 경우에도 -1을 출력한다.

#include <stdio.h> 

int N, M, H;
int ladder[30][9];

int ans = 4;

bool check(){	// i번째 src --> i번째 dst로 가는지 check!
	bool tmp_ans = true;
	
	for(int i = 0 ; i < N ; ++i){	// Column
		int tmp_i = i;
		for(int j = 0 ; j < H ; ++j){	// Row
			if(ladder[j][tmp_i] == 1 && 0 <= tmp_i && tmp_i < N - 1){	// 오른쪽에 사다리 있을 경우 
				++tmp_i;		
			}
			else if(ladder[j][tmp_i - 1] == 1 && 0 <= tmp_i - 1 && tmp_i - 1 < N - 1){	// 왼쪽에 사다리 있을 경우 
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
	if(cnt > ans)	return;	// 이미 전에 더 좋은 게  있었으면 가지치기!
	 
	if(check()){	// i번재가 모두 i번째 갔다면 
		ans = cnt;
		return;
	}
	
	if(cnt == 3)	return;	//어차피 다음 코드에서 cnt+1에 해당하는거 할 것이므로 여기서 그만한다. 
	
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
		int a,b;  // b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결했다는 의미
		scanf("%d %d", &a, &b);
		ladder[a-1][b-1] = 1;
	}
	//############################
	
	// 1st) DFS를 이용하여 사다리추가를 1개에서 3개까지 한다 그리고 4개 이상부터는 무조건 -1을 출력시킨다. 
	dfs(0, 0, 0);
	if(ans == 4)	ans = -1;	
	printf("%d", ans);
	return 0;	
}


