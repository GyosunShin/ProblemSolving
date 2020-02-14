//  (N극 : 0)  (S극 : 1)
// (시계방향 : 1)   (반시계방향 : -1)


#include <cstdio> 
#include <cmath>

using namespace std;

int T, N;

int map[4][8];

void rotate(int who, int dir){
	if(dir == 1){  // 시계방향 
		int tmp = map[who][7];
		for(int i = 6 ; i >= 0 ; --i){
			map[who][i+1] = map[who][i];
		}
		map[who][0] = tmp;
	}
	else if(dir == -1){	 //반시계 방향 
		int tmp = map[who][0];
		for(int i = 1 ; i <= 7 ; ++i){
			map[who][i-1] = map[who][i];
		}
		map[who][7] = tmp;
	}
}

void solve(int who, int dir){  // (시계방향 : 1)   (반시계방향 : -1)
	who--;
	
	bool flags[4] = { false, };
	int dirs[4] = { 0, };
	
	if(who == 0){
		flags[who] = true;
		dirs[who] = dir;
		
		if(map[0][2] != map[1][6]){
			flags[1] = true;			
			dir *= -1;
			dirs[1] = dir;
			
			if(map[1][2] != map[2][6]){
				flags[2] = true;			
				dir *= -1;
				dirs[2] = dir;
				
				if(map[2][2] != map[3][6]){
					flags[3] = true;			
					dir *= -1;
					dirs[3] = dir;	
				}
			}
			
		}
		
	}
	else if(who == 1){
		flags[who] = true;
		dirs[who] = dir;
		
		if(map[1][6] != map[0][2]){
			flags[0] = true;			
			dirs[0] = dir * -1;
		}
		
		if(map[1][2] != map[2][6]){
			flags[2] = true;		
			dir *= -1;
			dirs[2] = dir;
			if(map[2][2] != map[3][6]){
				flags[3] = true;		
				dir *= -1;
				dirs[3] = dir;	
			}
		}		
		
	}
	else if(who == 2){
		flags[who] = true;
		dirs[who] = dir;
		
		if(map[2][2] != map[3][6]){
			flags[3] = true;			
			dirs[3] = dir * -1;
		}
		
		if(map[2][6] != map[1][2]){
			flags[1] = true;		
			dir *= -1;
			dirs[1] = dir;
			if(map[1][6] != map[0][2]){
				flags[0] = true;		
				dir *= -1;
				dirs[0] = dir;	
			}
		}			
		
	}
	else if(who == 3){
		flags[who] = true;
		dirs[who] = dir;
		
		if(map[3][6] != map[2][2]){
			flags[2] = true;			
			dir *= -1;
			dirs[2] = dir;
			
			if(map[2][6] != map[1][2]){
				flags[1] = true;			
				dir *= -1;
				dirs[1] = dir;
				
				if(map[1][6] != map[0][2]){
					flags[0] = true;			
					dir *= -1;
					dirs[0] = dir;	
				}
			}
			
		}		
		
	}
	
	for(int i = 0 ; i < 4 ; ++i){
		if(flags[i]){
			rotate(i, dirs[i]);
		}
	}
	
}

int main(){
	
	scanf("%d", &T);
	for(int z = 1 ; z <= T ; ++z){
		scanf("%d", &N);
		for(int i = 0 ; i < 4; ++i){
			for(int j = 0 ; j < 8 ; ++j){
				scanf("%d", &map[i][j]);
			}
		}
		for(int i = 0 ; i < N ; ++i){
			int who, dir;
			scanf("%d %d", &who, &dir);
			solve(who, dir);
			
//			for(int j = 0 ; j < 4 ; ++j){
//				for(int k = 0 ; k < 8 ; ++k)	printf("%d  ", map[j][k]);
//				printf("\n");
//			}
			
			
		}
		
		int ans = 0;
		for(int i = 0 ; i < 4 ; ++i){
			if(map[i][0] == 1){
				int tmp = pow(2, i);
//				printf("TMP : %d\n", tmp);
				ans += tmp;
			}
		}
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}

	
