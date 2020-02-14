#include <stdio.h>
#include <iostream> 

using namespace std;

int n;
int ret;  // 정답! 

struct BOARD{
	int map[20][20];
	
	void rotate(){
		int temp[20][20];
		
		// 90도 회전! 
		for(int y = 0 ; y < n ; ++y){
			for(int x = 0 ; x < n ; ++x){
				temp[y][x] = map[n-x-1][y];
			}
		}
		
		// 다시 map으로 옮기는 작업  
		for(int y = 0 ; y < n ; ++y){
			for(int x = 0 ; x < n ; ++x){
				map[y][x] = temp[y][x];
			}
		}
	}
	
	// 걍 map중에서 가장 큰 블록 값 return! 
	int get_max(){
		int ret = 0;
		for(int y = 0; y < n ; ++y){
			for(int x = 0 ; x < n ; ++x){
				if(ret < map[y][x]){
					ret = map[y][x];
				}
			}
		}
		return ret;
	}
	
	
	void up(){
		int temp[20][20];
		
		for(int x = 0 ; x < n ; ++x){ // UP이므로 x를 고정시키고 y를 훑어야 하므로 x관련 for문 먼저! 
			int flag = 0, target = -1;
			for(int y = 0 ; y < n ; ++y){
				if(map[y][x] == 0){  // 아무것도 없으면 걍 넘어가고... 
					continue;
				}
				if(flag == 1 && map[y][x] == temp[target][x]){
					temp[target][x] *= 2, flag = 0;
				}
				else{
					temp[++target][x] = map[y][x], flag = 1;
				}
			}
			for(++target ; target < n ; ++target){
				temp[target][x] = 0;
			}
		}
		
		// map에 다시 복사해준다 
		for(int y = 0 ; y < n ; ++y){
			for(int x = 0 ; x < n ; ++x){
				map[y][x] = temp[y][x];
			}
		}
	}
};

void dfs(BOARD cur, int count) {
	// 밑의 if문이 바로 재귀적인 호출을 탈출하는 조건! 
	if(count == 5){
		int candi = cur.get_max();  // 일단 현재에서  가장 큰 블록의 값을 candi에 저장 
		if(ret < candi){
			ret = candi;  // 지금까지 한것중에 가장 큰 블록에 대한 값을 ret에 저장한다. 
		}
		return;
	}
	
	for(int dir = 0 ; dir < 4 ; ++dir){
		BOARD next = cur;
		next.up();
		// ######################		
		dfs(next, count + 1);
		// ######################
		cur.rotate();
		// ######################		
	}
}

int main(){
	BOARD board;
	scanf("%d", &n);
	for(int y = 0 ; y < n ; ++y){
		for(int x = 0 ; x < n ; ++x){
			scanf("%d", &board.map[y][x]);
		}
	}
	
	ret = 0;
	dfs(board, 0);
	printf("%d\n", ret);
}
