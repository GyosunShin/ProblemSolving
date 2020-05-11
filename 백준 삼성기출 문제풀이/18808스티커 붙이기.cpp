// 없으면 시계방향으로 90도씩 4번 도전

// (1 ≤ N(R) ≤ 40)  M(1 ≤ M(C) ≤ 40)	(1 ≤ K(스티커 개수) ≤ 100)

#include <cstdio> 
#include <cstring>
#include <vector>

using namespace std;

struct INFO{
	int r, c;
	int sticker[10][10];
};
vector<INFO> stickers;

int R, C, K;

int pan[40][40];
int backup[10][10];

void pt(int idx){
	
	int r = stickers[idx].r;
	int c = stickers[idx].c;
	
	for(int i = 0 ; i < r ; ++i){
		for(int j = 0 ; j < c ; ++j){
			printf("%d ", stickers[idx].sticker[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	
}

bool check(int idx, int sr, int sc){
	int ret = true;
	
	for(int i = 0 ; i < stickers[idx].r ; ++i){
		for(int j = 0 ; j < stickers[idx].c ; ++j){
			if(stickers[idx].sticker[i][j] == 1){
				if(pan[sr+i][sc+j] != 0){
					ret = false;
					break;
				}
			}
		}
		if(!ret)	break;
	}
	
	if(ret){
		for(int i = 0 ; i < stickers[idx].r ; ++i){
			for(int j = 0 ; j < stickers[idx].c ; ++j){
				if(stickers[idx].sticker[i][j] == 1){
					pan[sr+i][sc+j]	= idx+1;
				}
			}
		}
	}
	
	return ret;	
}

void rotate(int idx, int dir){
	// dir : (0 : 90도)	(1 : 180도)	(2 : 270도)
	
	memset(backup, 0, sizeof(backup));
	
	int r = stickers[idx].r;
	int c = stickers[idx].c;
	 
	if(dir == 0 || dir == 2){
		for(int i = r-1 ; i >= 0 ; --i){
			for(int j = 0 ; j < c ; ++j){
				backup[j][r-i-1] = stickers[idx].sticker[i][j];
			}
		}
	}
	else if(dir == 1){
		for(int i = 0 ; i < c ; ++i){
			for(int j = r-1 ; j >= 0 ; --j){
				backup[i][r-j-1] = stickers[idx].sticker[j][i];
			}
		}
	}
	
	
	for(int i = 0 ; i < 10 ; ++i){
		for(int j = 0 ; j < 10 ; ++j){
			stickers[idx].sticker[i][j] = backup[i][j];
		}
	}
	int tmp = stickers[idx].r;
	stickers[idx].r = stickers[idx].c;
	stickers[idx].c = tmp;
}

void solve(){
	
	for(int z = 0 ; z < stickers.size() ; ++z){
		bool tmp_ret = false;
		
		for(int dir = 0 ; dir < 4 ; ++dir){
			int sr = stickers[z].r;	int sc = stickers[z].c;
			for(int i = 0 ; i <= R - sr ; ++i){
				for(int j = 0 ; j <= C - sc ; ++j){
					if(check(z, i, j)){
						tmp_ret = true;
						break;
					}
				}
				if(tmp_ret)	break;
			}
			
			if(tmp_ret)	break;
			if(dir < 3) {
				rotate(z, dir);
			}
		}
		
	}
	
}

int main(){
	
	scanf("%d %d %d", &R, &C, &K);
	
	int r, c;
	
	for(int z = 0 ; z < K ; ++z){
		INFO sticker;
		scanf("%d %d", &r, &c);
		sticker.r = r;	sticker.c = c;
		int tmp;
		for(int i = 0 ; i < r ; ++i){
			for(int j = 0 ; j < c ; ++j){
				// (0 : 빈칸)	(1 : 스티커)
				scanf("%d", &tmp);
				sticker.sticker[i][j] = tmp;
			}
		}
		stickers.push_back(sticker);
	}
	
	solve();
	
	// OUTPUT
	// 첫째 줄에 주어진 스티커들을 차례대로 붙였을 때 노트북에서 스티커가 붙은 칸의 수를 출력한다.
	int answer = 0;
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
//			printf("%d ", pan[i][j]);
			if(pan[i][j] != 0)	++answer;
		}
//		printf("\n");
	}
//	printf("\n");
	printf("%d", answer);
	
	return 0;
}
