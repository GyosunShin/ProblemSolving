// (2 ≤ N ≤ 100) : 보드크기 
// (0 ≤ K ≤ 100) : 사과 개수 
// 
// 뱀의 방향 변환 횟수 L 이 주어진다. (1 ≤ L ≤ 100)
// 정수 X와 문자 C
// X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전

// INPUT
//6
//3
//3 4
//2 5
//5 3
//3
//3 D
//15 L
//17 D
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <deque> 
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};  // ㅗ(상=0) ㅏ(우=1) ㅜ(하=2) ㅓ (좌=3)  
int dc[] = {0, 1, 0, -1};

int N, K, L;

vector<pair<int, int> > apple;   // 사과의 (r,c)
queue<pair<int, char> > change;   // 뱀의 방향 변환 (sec,dir)

int ans;  // 시각 (초)

int dir = 1; // 일단 처음에는 오른쪽으로 이동 

int main(){
	scanf("%d", &N);
	scanf("%d", &K);
	for(int i = 0 ; i < K ; ++i){
		int tmp_r, tmp_c;
		scanf("%d %d", &tmp_r, &tmp_c);
		apple.push_back(pair<int, int>((tmp_r-1), (tmp_c-1)));
	}
	
	scanf("%d", &L);
	for(int i = 0 ; i < L ; ++i){
		int sec;
		char dir;
		scanf("%d %c", &sec, &dir);
		change.push(pair<int, char>(sec, dir));  // FIFO 
	}	
	//####################################################
	
	deque<pair<int, int> > snake;
	snake.push_back(pair<int, int>(0,0));
	 
	while(1){
		// 종료 기저조건 1 : head가 map의 범위에서 벗아났을때 
		int flag = 1;
		int collide = 0;
		pair<int, int> next_head = snake.back();
//		printf("CUR_R : %d / CUR_C : %d\n", next_head.first, next_head.second);
		if(0 > next_head.first || next_head.first >= N || 0 > next_head.second || next_head.second >= N){
//			printf("RANGE OUT!!\n");
			break;
		}
		// 종료 기저조건 2 : 자신의 몸뚱아리에 부닺혔을때   !! 대가리먼저 일단 들이밀고 본다 !!
//		printf("&&&&& : %d\n", snake.size());
		for(int i = 0 ; i < snake.size()-1 ; ++i){
//			printf("snake[%d]_r : %d / snake[%d]_c : %d\n", i, snake[i].first, i, snake[i].second);
			if(snake[i].first == next_head.first && snake[i].second == next_head.second){
				collide = 1;
			}
		}
		if(collide){
//			printf("COLLIDE!!\n");
			break;
		}
		
		
		// 사과 위치에 갔는지 확인먼저!
		int apple_chk = 0;
		for(int i = 0 ; i < apple.size() ; ++i){
			if(next_head.first == apple[i].first && next_head.second == apple[i].second) {
				apple[i].first = -1;
				apple[i].second = -1;
				apple_chk = 1;
				break;
			}
		}
		if(!apple_chk){
//			printf("APPLE NO EXIST!\n");
			flag = 0;
		}
		
		if(!flag && ans != 0){  // 이전 전진에서 사과 못 먹었다면 꼬리 없애줘야 함 
//			printf("DELETE!\n");
			snake.pop_front();
		}		
		
		
		
		// 자! 이제 방향설정하고 전진시작!
		int tick = change.front().first;	
		char l_r = change.front().second;
		int next_r, next_c;
//		printf("ANS : %d / tick : %d\n", ans, tick);
//		printf("PREV DIR : %d\n", dir);
		if(ans == tick){  // 방향 바꿔줄 필요 됨 
//			printf("CHANGE TIMING!! \n");
//			printf("ANS : %d / tick : %d\n", ans, tick);
			if(l_r == 'L'){  // 왼쪽으로 
				if(dir == 0)	dir = 3;
				else{
					dir -= 1;
				}	
			}
			else if(l_r == 'D'){  // 오른쪽으로 90도... 
				dir = (dir + 1) % 4;
			}
			change.pop();
//			printf("AFTER DIR : %d\n", dir);
		}
		next_r = next_head.first + dr[dir];
		next_c = next_head.second + dc[dir];
//		printf("NEXT_R : %d / NEXT_C : %d\n\n", next_r, next_c);
		snake.push_back(pair<int, int>(next_r, next_c));
		 
		++ans;  // 초 증가는 마지막에 해줘야 다음턴에서 전진 전에 방향 변화 확인가능하다 
	}
	
	printf("%d", ans);
	return 0;
}
 
