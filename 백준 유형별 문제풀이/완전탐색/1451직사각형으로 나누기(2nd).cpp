// ������ ���� ���簢���� ���� ���� �ִ�� �ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 1 <= N(R), M(C) <= 100

// OUTPUT : �� ���� ���� ���簢���� ���� ���� �ִ��� ����Ѵ�.

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
int pan[100][100];

vector<int> picked_sero;
vector<int> picked_garo;

long long ans = -1;

void garo(int start){
	
	if(picked_garo.size() == 2){
		long long a = 0;	long long b = 0;	long long c = 0;
		
		for(int i = 0 ; i < R ; ++i){
			for(int j = 0 ; j < C ; ++j){
				
				if(0 <= i && i < picked_garo[0]){
					a += pan[i][j];
				}
				else if(picked_garo[0] <= i && i < picked_garo[1]){
					b += pan[i][j];
				}
				else if(picked_garo[1] <= i){
					c += pan[i][j];
				}
				
			}
		}
		
		ans = max(ans, (a*b*c));		
		
		return;
	}
	 
	for(int i = start ; i < R ; ++i){
		picked_garo.push_back(i);
		garo(i+1);
		picked_garo.pop_back();
	}
	
}

void sero(int start){
	
	if(picked_sero.size() == 2){
		long long a = 0;	long long b = 0;	long long c = 0;
		
		for(int i = 0 ; i < R ; ++i){
			for(int j = 0 ; j < C ; ++j){
				
				if(0 <= j && j < picked_sero[0]){
					a += pan[i][j];
				}
				else if(picked_sero[0] <= j && j < picked_sero[1]){
					b += pan[i][j];
				}
				else if(picked_sero[1] <= j){
					c += pan[i][j];
				}
				
			}
		}
		
		ans = max(ans, (a*b*c));
		
		return;
	}
	 
	for(int i = start ; i < C ; ++i){
		picked_sero.push_back(i);
		sero(i+1);
		picked_sero.pop_back();
	}
	
}

void solve_a(int first, int second){
	
	long long a = 0;	long long b = 0;	long long c = 0;
	long long aa = 0;	long long bb = 0;	long long cc = 0;
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j <= first ; ++j){	// ���θ���� 0<= <=first������
			a += pan[i][j];
		}
		for(int j = first+1 ; j < C ; ++j){	// (first+1) <=  <= C
			aa += pan[i][j];
		}
	}	
	
	// 0<= <second  --> b�� �� 
	// second<= <R  --> b�� ��
	for(int i = 0 ; i < R ; ++i){
		
		for(int j = first+1 ; j < C ; ++j){
			if(0 <= i && i < second){
				b += pan[i][j];
			}
			else if(second <= i){
				c += pan[i][j];
			}
		}
		
		for(int j = 0 ; j <= first ; ++j){	// 0 <=  <= first
			if(0 <= i && i < second){
				bb += pan[i][j];
			}
			else if(second <= i){
				cc += pan[i][j];
			}
		}			
	}
	ans = max(ans, (a*b*c));
	ans = max(ans, (aa*bb*cc));	
}

//for(int i = 0 ; i < R-1 ; ++i){
//for(int j = 1 ; j < C ; ++j){
void solve_b(int r, int c){
	long long a = 0;	long long b = 0;	long long ccc = 0;
	long long aa = 0;	long long bb = 0;	long long cc = 0;	
	
	for(int j = 0 ; j < C ; ++j){
		for(int i = 0 ; i <= r ; ++i){
			a += pan[i][j];
		}
		for(int i = r+1 ; i < R ; ++i){
			aa += pan[i][j];
		}
	}
	
	for(int j = 0 ; j < C ; ++j){
		
		for(int i = r+1 ; i <= R ; ++i){
			if(0 <= j && j < c){
				b += pan[i][j];
			}
			else if(c <= j){
				ccc += pan[i][j];
			}
		}
		
		for(int i = 0 ; i <= r ; ++i){
			if(0 <= j && j < c){
				bb += pan[i][j];
			}
			else if(c <= j){
				cc += pan[i][j];
			}
		}		
		
	}
	
	ans = max(ans, (a*b*ccc));
	ans = max(ans, (aa*bb*cc));	
	
}


int main(){
	scanf("%d %d", &R, &C);
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%1d", &pan[i][j]);
		}
	}
	
	sero(1);
	
	garo(1);
	
	for(int i = 0 ; i < C-1 ; ++i){
		for(int j = 1 ; j < R ; ++j){
			solve_a(i,j);
		}
	}
	
	for(int i = 0 ; i < R-1 ; ++i){
		for(int j = 1 ; j < C ; ++j){
			solve_b(i,j);
		}
	}	
	
	printf("%lld", ans);
	
	return 0;
}
