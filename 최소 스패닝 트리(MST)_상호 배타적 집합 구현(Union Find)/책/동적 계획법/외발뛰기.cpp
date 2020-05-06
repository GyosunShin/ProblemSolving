#inclue <stdio.h>
#include <iostream>

using namespace std;

int n;
int board[100][100];
int cache[100][100];

int jump2(int r, int c){
	// 기저사례 : 게임판 밖을 벗어난 경우 
	if((!(0 <= r && r <= n-1)) || (!(0 <= c && c <= n-1))
		return 0;
	// 정답에 도달하였을 경우 
	if((r == n-1) && (c == n-1) )
		return 1;
	
	int& ref = cache[r][c]; 
	// 이미 써져 있을 경우 
	if(ref != -1){
		return ref;
	}
	int jmpSize = board[r][c];
	return ref = (jump2(r + jmpSize, c) || jump2(r, c + jmpSize));	
	
}



// 이거는 그냥 완전탐색용 
//bool jump(int r, int c){
//	// 기저사례 : 게임판 밖을 벗어난 경우 
//	if((!(0 <= r && r <= n-1)) || (!(0 <= c && c <= n-1))
//		return false;
//	if((r == n-1) && (c == n-1) )
//		return true;
//	
//	int jmpSize = board[r][c];
//	return isExist(r + jmpSize, c) || isExist(r, c + jmpSize);
//}
