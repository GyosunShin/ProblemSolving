// 첫째 줄에 드래곤 커브의 개수 N(1 ≤ N ≤ 20)이 주어진다
// 둘째 줄부터 N개의 줄에는 드래곤 커브의 정보가 주어진다(x, y, d, g)
// x와 y는 드래곤 커브의 시작 점, d는 시작 방향, g는 세대이다. (0 ≤ x, y ≤ 100, 0 ≤ d ≤ 3, 0 ≤ g ≤ 10)
// 0: x좌표가 증가하는 방향 (→)
// 1: y좌표가 감소하는 방향 (↑)
// 2: x좌표가 감소하는 방향 (←)
// 3: y좌표가 증가하는 방향 (↓)
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int map[101][101];  // 이유: 0 ≤ x ≤ 100, 0 ≤ y ≤ 100만 유효한 좌표
int input[20][4];  // [column, row, direction, generation]

int ans;

void check(){
//	for(int i = 0 ; i < 8 ; ++i) {
//		printf("[");
//		for(int j = 0 ; j < 8 ; ++j){
//			printf("%d ", map[i][j]);
//		}
//		printf("]\n");
//	}
	
	// map에서 사각형 다 1값 갖는거 몇개인지 CHECK!
	for(int i = 0 ; i < 100 ; ++i) {
		for(int j = 0 ; j < 100 ; ++j){
			if(map[i][j] == 1 && map[i][j+1] == 1 && map[i+1][j] == 1 && map[i+1][j+1] == 1){
				++ans;
			}
		}
	}
}

int main(){
	scanf("%d", &N);  // 드래곤커브의 개수 
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < 4 ; ++j){  // x(=c), y(=r), d, g
			scanf("%d", &input[i][j]);
		}
	}
	//###################### 입력 끝 ##################################
	
	
	for(int i = 0 ; i < N ; ++i){
		vector<int> tmp;
		tmp.push_back(input[i][2]);  // 일단 처음 방향을 집어넣는다. 
		for(int j = 0 ; j < input[i][3] ; ++j) {  // 세대만큼  (g == 0이면 더 이상 안하죠)
			int len = tmp.size();  // 현재까지 몇개가 들어 있는지.
			for(int k = len-1 ; k >= 0 ; --k){  // 현재까지 있는 만큼 집어넣는다. 
//				printf("#### tmp[k] : %d\n", tmp[k]);
				if(tmp[k] == 0){
					tmp.push_back(1);
				}
				else if(tmp[k] == 1){
					tmp.push_back(2);
				}
				else if(tmp[k] == 2){
					tmp.push_back(3);
				}
				else if(tmp[k] == 3){
					tmp.push_back(0);
				}								
			}	 
		}
		//  다 쳐 집어넣었으면, 이제 vector에 들어있는 dir값을 기반으로 하여 좌표를 1로 바꿔준다야! 
		
		int len = tmp.size();
//		for(int j = 0 ; j < len ; ++j){
//			printf("%d ", tmp[j]);
//		}
		int start_r = input[i][1];
		int start_c = input[i][0];
//		printf("start_r : %d / start_c : %d\n", start_r, start_c);
		map[start_r][start_c] = 1;  // 일단 처음 시작점은 미리 1로 바꿔준다. 
		for(int j = 0 ; j < len ; ++j){  //방향에 맞춰 전진 후 map[][]의 값을 1로 바꿔준다. 
			int dir = tmp[j];
			if(dir == 0){  // 오른 
//				printf("right!\n");
				map[start_r][start_c+1] = 1;
				++start_c;
			}
			else if(dir == 1){  // 위 
//				printf("up!\n");
				map[start_r-1][start_c] = 1;
				--start_r;
			}
			else if(dir == 2){  // 왼 
//				printf("left!\n");
				map[start_r][start_c-1] = 1;
				--start_c;
			}	
			else if(dir == 3){  // 아래 
//				printf("down!\n");
				map[start_r+1][start_c] = 1;
				++start_r;
			}			
//			printf("next_r : %d / next_c : %d\n", start_r, start_c);
		}
//		printf("EACH!!!\n");
	}
	check(); 
	
	printf("%d", ans);
}

