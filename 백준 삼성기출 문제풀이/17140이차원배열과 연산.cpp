// r, c, k가 주어진다. (1 ≤ r, c, k ≤ 100)
// 1 <= A[i][j] <= 100

// OUTPUT : A[r][c]에 들어있는 값이 k가 되기 위한 연산의 최소 시간을 출력한다. 이 값이 100을 넘어가는 경우에는 -1을 출력한다.

//  (수, 수의 등장 횟수)

#include <stdio.h> 
#include <algorithm>
#include <vector>

using namespace std;

int r, c, k;
int map[100][100];
int size_r = 3;
int size_c = 3;

int ans;

int main(){
	int tmp_r, tmp_c; 
	scanf("%d %d %d", &tmp_r, &tmp_c, &k);
	r = --tmp_r;
	c = --tmp_c;
	for(int i = 0 ; i < 3 ; ++i){
		for(int j = 0 ; j < 3 ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	//##############################
	
	while(1){
		
//		printf("size_r : %d / size_c : %d\n", size_r, size_c);
//		
//		for(int i = 0 ; i < size_r ; ++i) {
//			printf("[");
//			for(int j = 0 ; j < size_c ; ++j){
//				printf("%d ", map[i][j]);
//			}
//			printf("]\n");
//		}
//		printf("\n");
		
		
		// 종료 조건! 
		if(map[r][c] == k){
			break;
		}
		
		if(ans > 100){
			ans = -1;
			break;
		}
		
		// 일단 R ? C 누가 큰지 결정한다
		int r_c = (size_r >= size_c) ? (1) : (-1);  // 1 : R연산, -1 : C연산 
		
		if(r_c == 1){  // R연산 
			int tmp_max = -1 * 0x7fffffff;
			for(int i = 0 ; i < size_r ; ++i){ // 각 행마다 수행 
				int cnt[101] = { 0, };  // 각 행마다 알아서 초기화 되어.. 각 행마다 존재하는 100이하 자연수의 개수 측정 
				vector<pair<int, int> > v; // <개수, 숫자>
				int tmp_cnt = 0;
				for(int j = 0 ; j < size_c ; ++j){  // 열마다 숫자 개수 count! 
					++cnt[map[i][j]];
				}
				tmp_cnt = 0;
				for(int k = 1 ; k <= 100 ; ++k){
					if(cnt[k] != 0){
						v.push_back(pair<int, int>(cnt[k], k));
						tmp_cnt += 2;
					}	
				}
//				printf("TMP_CNT : %d\n", tmp_cnt);
				sort(v.begin(), v.end());
				if(tmp_max < tmp_cnt)	tmp_max = tmp_cnt;
				
				// 자! 이제 map 바꿔주자 
				// 일단 해당 행을 전부 0으로 초기화
				for(int j = 0 ; j < size_c ; ++j)	map[i][j] = 0;
				for(int j = 0 ; j < v.size() ; ++j){
					map[i][j*2] = v[j].second;	map[i][(j*2) + 1] = v[j].first;
				}
			}
			size_c = tmp_max;
		}
		else if(r_c == -1){  // C연산 
			int tmp_max = -1 * 0x7fffffff;
			for(int i = 0 ; i < size_c ; ++i){ // 각 행마다 수행 
				int cnt[101] = { 0, };  // 각 행마다 알아서 초기화 되어.. 각 행마다 존재하는 100이하 자연수의 개수 측정 
				vector<pair<int, int> > v; // <개수, 숫자>
				int tmp_cnt = 0;
				for(int j = 0 ; j < size_r ; ++j){  // 열마다 숫자 개수 count! 
					++cnt[map[j][i]];
				}
				tmp_cnt = 0;
				for(int k = 1 ; k <= 100 ; ++k){
					if(cnt[k] != 0){
						v.push_back(pair<int, int>(cnt[k], k));
						tmp_cnt += 2;
					}	
				}
				sort(v.begin(), v.end());
				if(tmp_max < tmp_cnt)	tmp_max = tmp_cnt;
				
				// 자! 이제 map 바꿔주자 
				// 일단 해당 열을 전부 0으로 초기화
				for(int j = 0 ; j < size_r ; ++j)	map[j][i] = 0;
				for(int j = 0 ; j < v.size() ; ++j){
					map[j*2][i] = v[j].second;	map[(j*2) + 1][i] = v[j].first;
				}
			}
			size_r = tmp_max;			
		}
		++ans;
	}
	
	printf("%d", ans);
	return 0;
}

