// 5 ≤ N ≤ 20
// 1 ≤ A[r][c] ≤ 100

// OUTPUT
// 첫째 줄에 인구가 가장 많은 선거구와 가장 적은 선거구의 인구 차이의 최솟값을 출력한다.

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int pan[20][20];
int backup[20][20];
int nums[5];

int ans = 0x7fffffff;

const int dr[] = {1,1,-1,-1};
const int dc[] = {-1,1,1,-1};

bool check(int r, int c, int d1, int d2){
	
	if(r+d1 >= N)	return false;
	if(c-d1 < 0)	return false;
	if(r+d2 >= N)	return false;
	if(c+d2 >= N)	return false;
	if(r+d1+d2 >= N)	return false;
	if(0 > c-d1+d2 || c-d1+d2 >= N)	return false;
		
	return true;
}

void paint(int r, int c, int d1, int d2){
	
	int start_r = r;	int start_c = c;
	
	for(int i = 0 ; i < d1 ; ++i){
		start_r += dr[0];	start_c += dc[0];
		backup[start_r][start_c] = 5;
	}
	for(int i = 0 ; i < d2 ; ++i){
		start_r += dr[1];	start_c += dc[1];
		backup[start_r][start_c] = 5;
	}
	for(int i = 0 ; i < d1 ; ++i){
		start_r += dr[2];	start_c += dc[2];
		backup[start_r][start_c] = 5;
	}
	for(int i = 0 ; i < d2 ; ++i){
		start_r += dr[3];	start_c += dc[3];
		backup[start_r][start_c] = 5;
	}
	
	
	for(int i = r+1 ; i < r+d1+d2 ; ++i){
		int flag = false;
		for(int j = 0 ; j < N ; ++j){	
			if(backup[i][j] == 5 && flag)	break;
			if(backup[i][j] == 5 && !flag)	flag = true;
			if(flag){
				backup[i][j] = 5;
			}
		}
	}	
	
//	for(int i = 0 ; i < N ; ++i){
//		for(int j = 0 ; j < N ; ++j){	
//			printf("%d ", backup[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
	
}

void paintAll(int r, int c, int d1, int d2){
	
	for(int i = 0 ; i < r ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(j <= c)	backup[i][j] = 1;
			else	backup[i][j] = 2;
		}
	}
	
	
	for(int i = r+d1+d2+1 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(j < (c-d1+d2))	backup[i][j] = 3;
			else	backup[i][j] = 4;
		}
	}	
	
	
	for(int i = r ; i < r+d1 ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(backup[i][j] == 5)	break;
			backup[i][j] = 1;
		}
	}
	
	for(int i = r+d1 ; i <= r+d1+d2 ; ++i){
		for(int j = 0 ; j < N ; ++j){
			if(backup[i][j] == 5)	break;
			backup[i][j] = 3;
		}
	}	
	
	
	for(int i = r ; i <= r+d2 ; ++i){
		for(int j = N-1 ; j >= 0 ; --j){
			if(backup[i][j] == 5)	break;
			backup[i][j] = 2;
		}
	}	
	
	for(int i = r+d2+1 ; i <= r+d1+d2 ; ++i){
		for(int j = N-1 ; j >= 0 ; --j){
			if(backup[i][j] == 5)	break;
			backup[i][j] = 4;
		}
	}		
	
//	for(int i = 0 ; i < N ; ++i){
//		for(int j = 0 ; j < N ; ++j){	
//			printf("%d ", backup[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");	
	
}


void count(){
	for(int r = 0 ; r < N ; ++r){
		for(int c = 0 ; c < N ; ++c){	
			nums[backup[r][c] - 1] += pan[r][c];
		}
	}
	
	
//	for(int i = 0 ; i < 5 ;++i)	printf("%d  / ", nums[i]);
//	printf("\n");
}


void solve(){
	
	for(int r = 0 ; r < N ; ++r){
		for(int c = 0 ; c < N ; ++c){	
			
			for(int d1 = 1 ; d1 < N ; ++d1){
				for(int d2 = 1 ; d2 < N ; ++d2){	
				
					if(!check(r,c,d1,d2))	continue;
					
					memset(backup, 0, sizeof(backup));
					paint(r,c,d1,d2);
					
					paintAll(r,c,d1,d2);
					
					memset(nums, 0, sizeof(nums));
					
					count();
					sort(nums, nums+5);
					ans = min(ans, nums[4] - nums[0]);
				}
			}
		
		
		}
	}
	
	
}

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){	
			scanf("%d", &pan[i][j]);	
		}
	}
	
	solve();	
	
	printf("%d", ans);
	
	return 0;
}
