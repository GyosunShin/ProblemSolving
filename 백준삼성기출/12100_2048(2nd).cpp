//  N (1 ≤ N ≤ 20)이 주어진다 
//  0 : 빈칸 

// OUTPUT --> 최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록을 출력한다.

#include <stdio.h>
#include <vector>

using namespace std;

int dir[] = {1,2,3,4}; // 차례대로 (상, 하, 좌, 우)
vector<int> picked;

int dr[] = {-1, 1, 0, 0};   // 상 하 좌 우 
int dc[] = {0, 0, -1, 1};

int N;
int map[20][20];

int ans = (-1 * (0x7fffffff));  // 최고값 찾아야 하니까 최소값으로 시작  

void rotate(int cnt, int (&back)[][]){
	int tmp[N][N];
	if(cnt == 1){  // 상인 경우	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				tmp[i][j] = back[(N-1)-j][i]; 
			}
		}
	}
	else if(cnt == 3){  // 하인 경우	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				tmp[i][j] = back[j][(N-1)-i];
			}
		}
	}
	else if(cnt == 2){  // 좌인 경우	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				tmp[i][j] =back[i][(N-1)-j];
			}
		}
	}	
	else if(cnt == 0){ // 원래 우인 경우 걍 그대로 
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				tmp[i][j] = back[i][j];
			}
		}		
	}
	
	// 이제 연산하셈 오른쪽으로 밀면서  (당연히 tmp가지고 해야함)
	// 오른쪽으로 밀어내면서 하니까 일단 행을 고정시킨다. 걍 i순서 다음 j순서 동일
	for(int i= 0 ; i < N ; ++i) {
		for(int j = 0 ; j <N ; ++j){
			if(tmp[i][j] == 0)	continue;
		}
	}
	
	
	
	// 이제는 다시 돌려서 원상복구 해줘야 할 듯(그니까 tmp --> back) 
	if(cnt == 1){  // 상인 경우	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				back[i][j] = tmp[j][(N-1)-i];
			}
		}
	}
	else if(cnt == 3){  // 하인 경우	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				back[i][j] = tmp[(N-1)-j][i]; 
			}
		}
	}
	else if(cnt == 2){  // 좌인 경우	
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				back[i][j] = tmp[i][(N-1)-j];
			}
		}
	}	
	else if(cnt == 0){ // 원래 우인 경우 걍 그대로 
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				back[i][j] = tmp[i][j];
			}
		}		
	}	
	
}


// 이 함수에서 picked에 담은 방향정보를 토대로 rotate하고 연산까지 계속한다.  
// 그리고 picked의 마지막 방향정보까지 이용다해서 연산 했으면, 최고값 찾고 전역변수 ans와 비교한다. 
void update(){  
	// 일단 backup
	int backup[N][N];
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			backup[i][j] = map[i][j];
		}
	}
	
	// {1,2,3,4} --> 차례대로 (상, 하, 좌, 우)
	for(int i = 0 ; i < picked.size() ; ++i){
		if(picked[i] == 1){  // 상인 경우 
			rotate(1, backup);
		} 
		else if(picked[i] == 2){  // 하인 경우 
			rotate(3, backup);
		}
		else if(picked[i] == 3){  // 좌인 경우 
			rotate(2, backup);
		}
		else if(picked[i] == 4){  // 상인 경우 
			rotate(0, backup);
		}						
	}
	
	
	// 이젠 연산 모두 완료된 backup에서 최고값 찾는다
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
		// 자 이제 여기서 연산을 수행해야함 
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
	
	// 풀이방법 : DFS로 5가지(상,하,좌,우) 의 경우의 수를 만들고 구현!
	// 그니까 4 * 4 * 4 * 4* 4 각 case마다 backup[][] 만들어놔야 할 듯
	dfs(0);
	printf("%d\n", ans);
}
