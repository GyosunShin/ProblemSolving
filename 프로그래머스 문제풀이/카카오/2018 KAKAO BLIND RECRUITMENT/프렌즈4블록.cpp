// 2  <=  ���� m(R), �� n(C)  <=  30

// OUTPUT : �Է����� �־��� �� ������ ������ �� ���� ����� �������� ����϶�.

#include <string>
#include <cstring>
#include <vector>

using namespace std;

int R, C;

bool blank[30][30];
char pan[2][30][30];

int ans;
int year;

vector<char> vs[30];

bool charc(char input){
	// ���̾�(R), ����(M), ����ġ(A), ���ε�(F), �׿�(N), Ʃ��(T), ������(J), ��(C)
//	if(input == 'R' || input == 'M' || input == 'A' || input == 'F' || input == 'N' || input == 'T' || 
//	input == 'J' || input == 'C')	return true;
	if('A' <= input && input <= 'Z')	return true;
	
	return false;
}

bool check(vector<string>& board){	// �ϳ��� ���������� true��ȯ 
	int next = (year+1) % 2;

	memset(blank, false, sizeof(blank));

	bool flag = false;

	for(int i = 0 ; i < R-1 ; ++i){
		for(int j = 0 ; j < C-1 ; ++j){
//			printf("<%d / %d> : %c\n", i, j, pan[year][i][j]);
			if(charc(pan[year][i][j])){
//				printf("%c / %c\n%c / %c\n", 
//				pan[year][i][j], pan[year][i][j+1], pan[year][i+1][j], pan[year][i+1][j+1]);
				char cur = pan[year][i][j];
				if(pan[year][i][j+1] == cur && pan[year][i+1][j] == cur && pan[year][i+1][j+1] == cur){
//					printf("%c / %c\n%c / %c\n", 
//					pan[year][i][j], pan[year][i][j+1], pan[year][i+1][j], pan[year][i+1][j+1]);
//					printf("(%d, %d)\n\n", i, j);
					blank[i][j] = true;	blank[i][j+1] = true;	blank[i+1][j] = true;	blank[i+1][j+1] = true;
					flag = true;
				}
			}
		}
	}
	
	for(int i = 0 ; i < C ; ++i){
		for(int j = R-1 ; j >= 0 ; --j){
			
			if(!blank[j][i]){
				vs[i].push_back(pan[year][j][i]);
			}
			else{
				++ans;
			}
			
		}
	}
	
	for(int i = 0 ; i < C ; ++i){
		for(int j = 0 ; j < vs[i].size() ; ++j){
			pan[next][R-1-j][i] = vs[i][j];
//			printf("���� : (%d / %d) %c\n", R-1-j, i, vs[i][j]);
		}		
	}
	
	for(int i = 0 ; i < C ; ++i)	vs[i].clear();
	
	memset(pan[year], 0, sizeof(pan[year]));
	
	year = next;
	return flag; 
}

int solution(int m, int n, vector<string> board) {
	memset(pan, 0, sizeof(pan));
	
    R = board.size();
    C = board[0].size();
    
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){    
			pan[0][i][j] = board[i][j];
		}
	}	
    
    while(true){
//    	printf("HOWMANY!\n");
    	if(!check(board)){
    		break;
    	}
    }
    
    return ans;
}

//int main(){
//	
//	vector<string> tmp({"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"});
//	printf("%d\n", solution(4, 5, tmp));
//	
//}
