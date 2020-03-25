
// 1 <= n <= 16

// º®(1) : OR
// ºóÄ­(0) : AND

#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int pan[2][16][16];

vector<string> answer;

int N;

void check(vector<int>& board, int idx){
	
	for(int i = 0 ; i < board.size() ; ++i){
		for(int j = 0 ; j < N ; ++j){
			
			if(((1 << j) & board[i]) == (1 << j)){	// º®ÀÎ °æ¿ì 
				pan[idx][i][(N-1)-j] = 1;
			}
			else{									// °ø¹éÀÎ °æ¿ì 
				pan[idx][i][(N-1)-j] = 0;
			}
			
		}
	}
	
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	
	N = n;
	
	check(arr1, 0);
	check(arr2, 1);
	
//	for(int z = 0 ; z < 2 ; ++z){
//		for(int i = 0 ; i < N ; ++i){
//			for(int j = 0 ; j < N ; ++j){	
//			
//				printf("%d ", pan[z][i][j]);
//			
//			}
//			printf("\n");
//		}
//		printf("\n");
//		printf("\n");
//	}
	
	// º®(1) : OR
	// ºóÄ­(0) : AND
	for(int i = 0 ; i < N ; ++i){
		string tmp;
		for(int j = 0 ; j < N ; ++j){	
			if(pan[0][i][j] == 1 || pan[1][i][j] == 1){
				tmp += "#";
			}
			else if(pan[0][i][j] == 0 && pan[1][i][j] == 0){
				tmp += " ";
			}
		}
		answer.push_back(tmp);
	}
    
    return answer;
}
