	// (1 ≤ N, M ≤ 8)
	// 0은 빈 칸, 6은 벽, 1~5는 CCTV
	// CCTV의 최대 개수는 8개를 넘지 않는다
	#include <stdio.h> 
	#include <algorithm>
	#include <vector>
	
	using namespace std;
	
	int N,M;
	int map[8][8];
	int ans = 0x7fffffff;
	
	int total = 0;
	
	vector<pair<int, pair<int, int> > > order;
	
	vector<pair<int, pair<int, int> > > picked;
	
	int kind[5] = {4,2,4,4,1};  // 각각 kind[i]개의 방향종류 보유 
	int nums[5] = { 0, };
	
	int cnt = 0;
	
	void minret(const int (&back)[8][8]){     // 사각지역 몇개인지 int cnt에 SAVE! 
		cnt = 0;
		for(int i = 0 ; i < N ; ++i){
	//		printf("[");
			for(int j = 0 ; j < M ; ++j){
	//			printf("%d ", back[i][j]);
				if(back[i][j] == 0){
					++cnt;
				}
			}
	//		printf("]\n\n");
		}
	//	printf("SHI : %d\n", cnt);
		if(ans > cnt) {
			ans = cnt;
		}
	}
	
	void work(){
		int backup[8][8];
		for(int i = 0 ; i < N ; ++i){
	//		printf("<");
			for(int j = 0 ; j < M ; ++j){
				backup[i][j] = map[i][j];
	//			printf("%d ", backup[i][j]);
			}
	//		printf(">\n");
		}
		
		//picked<11, i, j> 가지고 작업 시작!
		for(int i = 0 ; i < picked.size() ; ++i) {
			int type = picked[i].first;
			int r = picked[i].second.first;
			int c = picked[i].second.second;
			
			if(type == 11){   // 윗방향 
				int tmp = r-1;
				while(backup[tmp][c] != 6 && 0<=tmp && tmp < N) {
					if(1<= backup[tmp][c] && backup[tmp][c] <= 5) {
						break;
					}
					backup[tmp][c] = -1;
					--tmp;
				}
			}
			else if(type == 12){  // 오른쪽 
				int tmp = c+1;
				while(backup[r][tmp] != 6 && 0<=tmp && tmp < M) {
					if(1<= backup[r][tmp] && backup[r][tmp] <= 5) {
						break;
					}				
					backup[r][tmp] = -1;
					++tmp;
				}			 
			}
			else if(type == 13){  // 아래로 
				int tmp = r+1;			
				while(backup[tmp][c] != 6 && 0<=tmp && tmp < N) {
					if(1<= backup[tmp][c] && backup[tmp][c] <= 5) {
						break;
					}				
					backup[tmp][c] = -1;
					++tmp;
				}			 			
			}
			else if(type == 14){  // 왼쪽으로 
				int tmp = c-1;
				while(backup[r][tmp] != 6 && 0<=tmp && tmp < M) {
					if(1<= backup[r][tmp] && backup[r][tmp] <= 5) {
						break;
					}				
					backup[r][tmp] = -1;
					--tmp;
				}	
			}		
			
			
			else if(type == 21){  // 좌우로 
				int tmp = c-1;   // 좌  
				while(backup[r][tmp] != 6 && 0<=tmp && tmp < M) {
					if(1<= backup[r][tmp] && backup[r][tmp] <= 5) {
						break;
					}				
					backup[r][tmp] = -1;
					--tmp;
				}			
				int tmp2 = c+1; // 우  
				while(backup[r][tmp2] != 6 && 0<=tmp2 && tmp2 < M) {
					if(1<= backup[r][tmp2] && backup[r][tmp2] <= 5) {
						break;
					}				
					backup[r][tmp2] = -1;
					++tmp2;
				}				
			}		
			else if(type == 22){  // 위아래로 
				int tmp = r+1;   // 아래 
				while(backup[tmp][c] != 6 && 0<=tmp && tmp < N) {
					if(1<= backup[tmp][c] && backup[tmp][c] <= 5) {
						break;
					}				
					backup[tmp][c] = -1;
					++tmp;
				}				
				int tmp2 = r-1;  /// 위  
				while(backup[tmp2][c] != 6 && 0<=tmp2 && tmp2 < N) {
					if(1<= backup[tmp2][c] && backup[tmp2][c] <= 5) {
						break;
					}
					backup[tmp2][c] = -1;
					--tmp2;
				}			
			}				
			
			
			else if(type == 31){  // 위 & 오른쪽 
				int tmp2 = r-1;  /// 위  
				while(backup[tmp2][c] != 6 && 0<=tmp2 && tmp2 < N) {
					if(1<= backup[tmp2][c] && backup[tmp2][c] <= 5) {
						break;
					}
					backup[tmp2][c] = -1;
					--tmp2;
				}			
				int tmp = c+1; // 우  
				while(backup[r][tmp] != 6 && 0<=tmp && tmp < M) {
					if(1<= backup[r][tmp] && backup[r][tmp] <= 5) {
						break;
					}				
					backup[r][tmp] = -1;
					++tmp;
				}			
				
			}						
			else if(type == 32){  // 오른쪽 & 아래 
				int tmp = c+1; // 우  
				while(backup[r][tmp] != 6 && 0<=tmp && tmp < M) {
					if(1<= backup[r][tmp] && backup[r][tmp] <= 5) {
						break;
					}				
					backup[r][tmp] = -1;
					++tmp;
				}	
				int tmp2 = r+1;   // 아래 
				while(backup[tmp2][c] != 6 && 0<=tmp2 && tmp2 < N) {
					if(1<= backup[tmp2][c] && backup[tmp2][c] <= 5) {
						break;
					}				
					backup[tmp2][c] = -1;
					++tmp2;
				}			
				
			}				
			else if(type == 33){  // 아래 & 왼쪽 
				int tmp2 = r+1;   // 아래 
				while(backup[tmp2][c] != 6 && 0<=tmp2 && tmp2 < N) {
					if(1<= backup[tmp2][c] && backup[tmp2][c] <= 5) {
						break;
					}				
					backup[tmp2][c] = -1;
					++tmp2;
				}			
				int tmp = c-1;   // 좌  
				while(backup[r][tmp] != 6 && 0<=tmp && tmp < M) {
					if(1<= backup[r][tmp] && backup[r][tmp] <= 5) {
						break;
					}				
					backup[r][tmp] = -1;
					--tmp;
				}				
			}				
			else if(type == 34){  // 왼쪽 & 위
				int tmp = c-1;   // 좌  
				while(backup[r][tmp] != 6 && 0<=tmp && tmp < M) {
					if(1<= backup[r][tmp] && backup[r][tmp] <= 5) {
						break;
					}				
					backup[r][tmp] = -1;
					--tmp;
				}			 
				int tmp2 = r-1;  /// 위  
				while(backup[tmp2][c] != 6 && 0<=tmp2 && tmp2 < N) {
					if(1<= backup[tmp2][c] && backup[tmp2][c] <= 5) {
						break;
					}
					backup[tmp2][c] = -1;
					--tmp2;
				}			
			}					
			
								
			else if(type == 41){  // ㅗ (좌, 위, 우)
				int tmp = c-1;   // 좌  
				while(backup[r][tmp] != 6 && 0<=tmp && tmp < M) {
					if(1<= backup[r][tmp] && backup[r][tmp] <= 5) {
						break;
					}				
					backup[r][tmp] = -1;
					--tmp;
				}			 
				int tmp2 = r-1;  /// 위  
				while(backup[tmp2][c] != 6 && 0<=tmp2 && tmp2 < N) {
					if(1<= backup[tmp2][c] && backup[tmp2][c] <= 5) {
						break;
					}
					backup[tmp2][c] = -1;
					--tmp2;
				}			
				int tmp3 = c+1; // 우  
				while(backup[r][tmp3] != 6 && 0<=tmp3 && tmp3 < M) {
					if(1<= backup[r][tmp3] && backup[r][tmp3] <= 5) {
						break;
					}				
					backup[r][tmp3] = -1;
					++tmp3;
				}			
				
			}						
			else if(type == 42){  // ㅏ (위, 우, 아래)
				int tmp3 = c+1; // 우  
				while(backup[r][tmp3] != 6 && 0<=tmp3 && tmp3 < M) {
					if(1<= backup[r][tmp3] && backup[r][tmp3] <= 5) {
						break;
					}				
					backup[r][tmp3] = -1;
					++tmp3;
				}			
				int tmp2 = r-1;  /// 위  
				while(backup[tmp2][c] != 6 && 0<=tmp2 && tmp2 < N) {
					if(1<= backup[tmp2][c] && backup[tmp2][c] <= 5) {
						break;
					}
					backup[tmp2][c] = -1;
					--tmp2;
				}			
				int tmp = r+1;   // 아래 
				while(backup[tmp][c] != 6 && 0<=tmp && tmp < N) {
					if(1<= backup[tmp][c] && backup[tmp][c] <= 5) {
						break;
					}				
					backup[tmp][c] = -1;
					++tmp;
				}			
				
			}				
			else if(type == 43){  // ㅜ (좌, 아래, 우)
				int tmp = r+1;   // 아래 
				while(backup[tmp][c] != 6 && 0<=tmp && tmp < N) {
					if(1<= backup[tmp][c] && backup[tmp][c] <= 5) {
						break;
					}				
					backup[tmp][c] = -1;
					++tmp;
				}			
				int tmp3 = c+1; // 우  
				while(backup[r][tmp3] != 6 && 0<=tmp3 && tmp3 < M) {
					if(1<= backup[r][tmp3] && backup[r][tmp3] <= 5) {
						break;
					}				
					backup[r][tmp3] = -1;
					++tmp3;
				}			
				int tmp2 = c-1;   // 좌  
				while(backup[r][tmp2] != 6 && 0<=tmp2 && tmp2 < M) {
					if(1<= backup[r][tmp2] && backup[r][tmp2] <= 5) {
						break;
					}				
					backup[r][tmp2] = -1;
					--tmp2;
				}			
			}				
			else if(type == 44){  // ㅓ (위, 좌, 아래)
				int tmp2 = c-1;   // 좌  
				while(backup[r][tmp2] != 6 && 0<=tmp2 && tmp2 < M) {
					if(1<= backup[r][tmp2] && backup[r][tmp2] <= 5) {
						break;
					}				
					backup[r][tmp2] = -1;
					--tmp2;
				}		
				int tmp = r+1;   // 아래 
				while(backup[tmp][c] != 6 && 0<=tmp && tmp < N) {
					if(1<= backup[tmp][c] && backup[tmp][c] <= 5) {
						break;
					}				
					backup[tmp][c] = -1;
					++tmp;
				}					
				int tmp3 = r-1;  /// 위  
				while(backup[tmp3][c] != 6 && 0<=tmp3 && tmp3 < N) {
					if(1<= backup[tmp3][c] && backup[tmp3][c] <= 5) {
						break;
					}
					backup[tmp3][c] = -1;
					--tmp3;
				}				
			}						
			
			
			else if(type == 51){ // + (상 화 좌 우 전부다!)
				int tmp2 = c-1;   // 좌  
				while(backup[r][tmp2] != 6 && 0<=tmp2 && tmp2 < M) {
					if(1<= backup[r][tmp2] && backup[r][tmp2] <= 5) {
						break;
					}				
					backup[r][tmp2] = -1;
					--tmp2;
				}		
				int tmp = r+1;   // 아래 
				while(backup[tmp][c] != 6 && 0<=tmp && tmp < N) {
					if(1<= backup[tmp][c] && backup[tmp][c] <= 5) {
						break;
					}				
					backup[tmp][c] = -1;
					++tmp;
				}					
				int tmp3 = r-1;  /// 위  
				while(backup[tmp3][c] != 6 && 0<=tmp3 && tmp3 < N) {
					if(1<= backup[tmp3][c] && backup[tmp3][c] <= 5) {
						break;
					}
					backup[tmp3][c] = -1;
					--tmp3;
				}
				int tmp4 = c+1; // 우  
				while(backup[r][tmp4] != 6 && 0<=tmp4 && tmp4 < M) {
					if(1<= backup[r][tmp4] && backup[r][tmp4] <= 5) {
						break;
					}				
					backup[r][tmp4] = -1;
					++tmp4;
				}							
			}						
			
		}
		minret(backup);
	}
	
	void dfs(int count, int ii){
	//	printf("[");
	//	for(int i = 0 ; i < picked.size() ; ++i){
	//		printf("%d  ", picked[i]);
	//	}
	//	printf("]\n");	
		if(count == total){
	//		printf("[SATISFIED]");
	//		printf("[");
	//		for(int i = 0 ; i < picked.size() ; ++i){
	//			printf("(%d, i:%d, j:%d)", picked[i].first, picked[i].second.first, picked[i].second.second);
	//		}
	//		printf("]\n\n");
			work();
			return;	
		}
		
		for(int i = ii ; i < order.size() ; ++i){
			int tmp = order[i].first - 1;
			for(int j = 0 ;  j < kind[tmp] ; ++j){
				int ttmp = order[i].first * 10 + (j+1);  // 11, 12, 13, 14, 21, 22 뭐.. 이런 형식으로.... 
				picked.push_back(pair<int, pair<int, int> >(ttmp, make_pair(order[i].second.first, order[i].second.second)));
				dfs(picked.size(), i+1);
				picked.pop_back();
			}
		}
	}
	
	
	int main(){
		scanf("%d %d", &N, &M);
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < M ; ++j){
				int tmp;
				
				scanf("%d", &tmp);
				map[i][j] = tmp;
				
				if(1<= tmp && tmp <= 5){
					order.push_back(pair<int, pair<int, int> >(tmp, make_pair(i,j)));
					++nums[tmp-1];
					++total;
				}			
				
			}
		}
		//##################################
	//	for(int i = 0 ; i < N ; ++i){
	//		printf("(");
	//		for(int j = 0 ; j < M ; ++j){
	//			printf("%d ", map[i][j]);
	//		}
	//		printf(")\n");
	//	}	
		
	//	printf("TOTAL : %d\n", total);
	//	printf("ORDER SIZE : %d\n", order.size());
		dfs(0, 0);
		
		printf("%d", ans);
		
	}
