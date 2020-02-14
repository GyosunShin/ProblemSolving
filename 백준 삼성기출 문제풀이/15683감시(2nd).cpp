// OUTPUT : 첫째 줄에 사각 지대의 '최소' 크기를 출력한다.

#include <stdio.h>
#include <vector>

using namespace std;

struct INFO{
	int r, c, type, dir;
};

int R, C;

int map[8][8];
int cctvs;

vector<INFO> cctv_list;
vector<INFO> picked;

int ans = 0x7fffffff;
int backup[8][8];

void up(int cur_r, int cur_c){
	for(int j = cur_r - 1 ; j >= 0 ; --j){
		if(backup[j][cur_c] == 6){
			break;
		}
		else if(1 <= backup[j][cur_c] && backup[j][cur_c] <= 5){
			continue;
		}
		else{
			backup[j][cur_c] = -1;
		}
	}	
}

void down(int cur_r, int cur_c){
	for(int j = cur_r + 1 ; j < R ; ++j){
		if(backup[j][cur_c] == 6){
			break;
		}
		else if(1 <= backup[j][cur_c] && backup[j][cur_c] <= 5){
			continue;
		}
		else{
			backup[j][cur_c] = -1;
		}				
	}	
}

void left(int cur_r, int cur_c){
	for(int j = cur_c - 1 ; j >= 0 ; --j){
		if(backup[cur_r][j] == 6){
			break;
		}
		else if(1 <= backup[cur_r][j] && backup[cur_r][j] <= 5){
			continue;
		}
		else{
			backup[cur_r][j] = -1;
		}							
	}	
}

void right(int cur_r, int cur_c){
	for(int j = cur_c + 1 ; j < C ; ++j){
		if(backup[cur_r][j] == 6){
			break;
		}
		else if(1 <= backup[cur_r][j] && backup[cur_r][j] <= 5){
			continue;
		}
		else{
			backup[cur_r][j] = -1;
		}						
	}	
}

int check(){
	int tmp_ans = 0;
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			backup[i][j] = map[i][j];
		}
	}
	
	for(int i = 0 ; i < picked.size() ; ++i){
		INFO cur = picked[i];
		if(cur.type == 1){
			if(cur.dir == 1){  // 위로 
				up(cur.r, cur.c);
			}
			else if(cur.dir == 2){  // 아래로 
				down(cur.r, cur.c);
			}
			else if(cur.dir == 3){  // 왼쪽으로 
				left(cur.r, cur.c);
			}
			else if(cur.dir == 4){ // 오른쪽으로 
				right(cur.r, cur.c);				
			}						
		}
		else if(cur.type == 2){
			if(cur.dir == 1){
				left(cur.r, cur.c);
				right(cur.r, cur.c);				
			}
			else if(cur.dir == 2){
				up(cur.r, cur.c);
				down(cur.r, cur.c);
			}			
		}
		else if(cur.type == 3){
			if(cur.dir == 1){
				up(cur.r, cur.c);
				right(cur.r, cur.c);
			}
			else if(cur.dir == 2){
				right(cur.r, cur.c);
				down(cur.r, cur.c);
			}
			else if(cur.dir == 3){
				down(cur.r, cur.c);
				left(cur.r, cur.c);
			}
			else if(cur.dir == 4){
				left(cur.r, cur.c);
				up(cur.r, cur.c);
			}				
		}
		else if(cur.type == 4){
			if(cur.dir == 1){
				left(cur.r, cur.c);
				up(cur.r, cur.c);
				right(cur.r, cur.c);
			}
			else if(cur.dir == 2){
				up(cur.r, cur.c);
				right(cur.r, cur.c);
				down(cur.r, cur.c);
			}
			else if(cur.dir == 3){
				right(cur.r, cur.c);
				down(cur.r, cur.c);
				left(cur.r, cur.c);
			}
			else if(cur.dir == 4){
				down(cur.r, cur.c);
				left(cur.r, cur.c);
				up(cur.r, cur.c);
			}				
		}
		else if(cur.type == 5){
			up(cur.r, cur.c);
			down(cur.r, cur.c);
			left(cur.r, cur.c);
			right(cur.r, cur.c);
		}						
	}
	
	// 사각지역 개수 check
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){	
			if(backup[i][j] == 0)	++tmp_ans;
		}
	}
	
	return tmp_ans;
}

void dfs(int index){
	if(picked.size() == cctvs){	
//		for(int i = 0 ; i < picked.size() ; ++i){
//			printf("%d ", picked[i].dir);
//		}
//		printf("\n");
		int tmp_ans = check();
		if(ans > tmp_ans)	ans = tmp_ans;
		
		return;
	}
	
	INFO cur = cctv_list[index];
	INFO next;
	next.r = cur.r;	next.c = cur.c;	next.type = cur.type;
	
	if(cur.type  == 1){   // 4가지 존재 
		for(int i = 1 ; i <= 4 ; ++i) {
			next.dir = i;
			picked.push_back(next);
			dfs(index + 1);
			picked.pop_back();
		}
	}
	else if(cur.type  == 2){  // 2가지 존재 
		for(int i = 1 ; i <= 2 ; ++i) {
			next.dir = i;
			picked.push_back(next);
			dfs(index + 1);
			picked.pop_back();
		}		
	}	
	else if(cur.type  == 3){  // 4가지 존재 
		for(int i = 1 ; i <= 4 ; ++i) {
			next.dir = i;
			picked.push_back(next);
			dfs(index + 1);
			picked.pop_back();
		}		
	}	
	else if(cur.type  == 4){  // 4가지 존재 
		for(int i = 1 ; i <= 4 ; ++i) {
			next.dir = i;
			picked.push_back(next);
			dfs(index + 1);
			picked.pop_back();
		}		
	}	
	else if(cur.type  == 5){  // 1가지 존재 
		for(int i = 1 ; i <= 1 ; ++i) {
			next.dir = i;
			picked.push_back(next);
			dfs(index + 1);
			picked.pop_back();
		}		
	}				
	
	
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i = 0 ; i < R; ++i){
		for(int j = 0 ; j < C; ++j){
			scanf("%d", &map[i][j]);
			if(1 <= map[i][j] && map[i][j] <= 5){
				++cctvs;
				INFO tmp;
				tmp.r = i;	tmp.c=  j; tmp.type = map[i][j];	tmp.dir = -1;
				cctv_list.push_back(tmp);
			}
		}
	}
	//########################################################################
	
	dfs(0);
	
	printf("%d", ans);
	
	return 0;
}
