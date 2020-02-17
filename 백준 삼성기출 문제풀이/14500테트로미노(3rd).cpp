// 테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.a

// (4 ≤ N(R), M(C) ≤ 500)

#include <cstdio>
#include <algorithm>

using namespace std;

int R, C;
int map[500][500];

int global_max = -1 * 0x7fffffff;

// ****
void one(){   
	int tmp_max = -1 * 0x7fffffff;
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C-3 ; ++j){
			int tmp_sum = 0;
			tmp_sum += (map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3]);
			tmp_max = max(tmp_sum, tmp_max);	
		}
	}	
	global_max = max(global_max, tmp_max);
}

// *
// *
// *
// *
void two(){
	int tmp_max = -1 * 0x7fffffff;
	for(int i = 0 ; i < R-3 ; ++i){
		for(int j = 0 ; j < C ; ++j){
			int tmp_sum = 0;
			tmp_sum += (map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j]);
			tmp_max = max(tmp_sum, tmp_max);
		}
	}	
	global_max = max(global_max, tmp_max);	
}

//**
//**
void three(){
	int tmp_max = -1 * 0x7fffffff;
	for(int i = 0 ; i < R-1 ; ++i){
		for(int j = 0 ; j < C-1 ; ++j){
			int tmp_sum = 0;
			tmp_sum += (map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i][j+1]);
			tmp_max = max(tmp_sum, tmp_max);
		}
	}	
	global_max = max(global_max, tmp_max);		
}

//**
//**
//**
void four(){  // 동일한 틀 안에 8가지 CASE 존재

	int flag[8][3][2] = {
		{
			{1,0},
			{1,0},
			{1,1}
		},
		{
			{0,1},
			{0,1},
			{1,1}
		},
		{
			{1,1},
			{0,1},
			{0,1}
		},
		{
			{1,1},
			{1,0},
			{1,0}
		},
		{
			{1,0},
			{1,1},
			{0,1}
		},
		{
			{0,1},
			{1,1},
			{1,0}
		},
		{
			{0,1},
			{1,1},
			{0,1}
		},
		{
			{1,0},
			{1,1},
			{1,0}
		}
	};
	
	int tmp_max = -1 * 0x7fffffff;
	
	for(int z = 0 ; z < 8 ; ++z){
		for(int i = 0 ; i < R-2 ; ++i){
			for(int j = 0 ; j < C-1 ; ++j){
				int tmp_sum = 0;
				// l, m
				for(int l = 0 ; l < 3 ; ++l){
					for(int m = 0 ; m < 2 ; ++m){
						if(flag[z][l][m]){
							tmp_sum += map[i+l][j+m];
						}
					}
				}
				tmp_max = max(tmp_sum, tmp_max);
			}
		}
	}
	
	global_max = max(global_max, tmp_max);		
	
}

//***
//***
void five(){
	
	int flag[8][2][3] = {
		{
			{1, 1, 1},
			{1, 0, 0}
		},
		{
			{1, 1, 1},
			{0, 0, 1}
		},
		{
			{0, 0, 1},
			{1, 1, 1}
		},
		{
			{1, 0, 0},
			{1, 1, 1}
		},
		{
			{0, 1, 1},
			{1, 1, 0}
		},
		{
			{1, 1, 0},
			{0, 1, 1}
		},
		{
			{1, 1, 1},
			{0, 1, 0}
		},
		{
			{0, 1, 0},
			{1, 1, 1}
		}
	};
	
	int tmp_max = -1 * 0x7fffffff;
	
	for(int z = 0 ; z < 8 ; ++z){
		for(int i = 0 ; i < R-1 ; ++i){
			for(int j = 0 ; j < C-2 ; ++j){
				int tmp_sum = 0;
				// l, m
				for(int l = 0 ; l < 2 ; ++l){
					for(int m = 0 ; m < 3 ; ++m){
						if(flag[z][l][m]){
							tmp_sum += map[i+l][j+m];
						}
					}
				}
				tmp_max = max(tmp_sum, tmp_max);
			}
		}
	}
	
	global_max = max(global_max, tmp_max);		
	
}


int main(){
	scanf("%d %d", &R, &C);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	
	one();
	two();
	three();
	four();
	five();
	
	// 첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.
	printf("%d", global_max);
	
	return 0;
}


