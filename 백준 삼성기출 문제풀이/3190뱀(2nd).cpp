// (2 �� N �� 100) : ����ũ�� 
// (0 �� K �� 100) : ��� ���� 
// 
// ���� ���� ��ȯ Ƚ�� L �� �־�����. (1 �� L �� 100)
// ���� X�� ���� C
// X�ʰ� ���� �ڿ� ����(C�� 'L') �Ǵ� ������(C�� 'D')�� 90�� ������ ȸ��

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

int dr[] = {-1, 0, 1, 0};  // ��(��=0) ��(��=1) ��(��=2) �� (��=3)  
int dc[] = {0, 1, 0, -1};

int N, K, L;

vector<pair<int, int> > apple;   // ����� (r,c)
queue<pair<int, char> > change;   // ���� ���� ��ȯ (sec,dir)

int ans;  // �ð� (��)

int dir = 1; // �ϴ� ó������ ���������� �̵� 

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
		// ���� �������� 1 : head�� map�� �������� ���Ƴ����� 
		int flag = 1;
		int collide = 0;
		pair<int, int> next_head = snake.back();
//		printf("CUR_R : %d / CUR_C : %d\n", next_head.first, next_head.second);
		if(0 > next_head.first || next_head.first >= N || 0 > next_head.second || next_head.second >= N){
//			printf("RANGE OUT!!\n");
			break;
		}
		// ���� �������� 2 : �ڽ��� ���׾Ƹ��� �δ�������   !! �밡������ �ϴ� ���̹а� ���� !!
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
		
		
		// ��� ��ġ�� ������ Ȯ�θ���!
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
		
		if(!flag && ans != 0){  // ���� �������� ��� �� �Ծ��ٸ� ���� ������� �� 
//			printf("DELETE!\n");
			snake.pop_front();
		}		
		
		
		
		// ��! ���� ���⼳���ϰ� ��������!
		int tick = change.front().first;	
		char l_r = change.front().second;
		int next_r, next_c;
//		printf("ANS : %d / tick : %d\n", ans, tick);
//		printf("PREV DIR : %d\n", dir);
		if(ans == tick){  // ���� �ٲ��� �ʿ� �� 
//			printf("CHANGE TIMING!! \n");
//			printf("ANS : %d / tick : %d\n", ans, tick);
			if(l_r == 'L'){  // �������� 
				if(dir == 0)	dir = 3;
				else{
					dir -= 1;
				}	
			}
			else if(l_r == 'D'){  // ���������� 90��... 
				dir = (dir + 1) % 4;
			}
			change.pop();
//			printf("AFTER DIR : %d\n", dir);
		}
		next_r = next_head.first + dr[dir];
		next_c = next_head.second + dc[dir];
//		printf("NEXT_R : %d / NEXT_C : %d\n\n", next_r, next_c);
		snake.push_back(pair<int, int>(next_r, next_c));
		 
		++ans;  // �� ������ �������� ����� �����Ͽ��� ���� ���� ���� ��ȭ Ȯ�ΰ����ϴ� 
	}
	
	printf("%d", ans);
	return 0;
}
 
