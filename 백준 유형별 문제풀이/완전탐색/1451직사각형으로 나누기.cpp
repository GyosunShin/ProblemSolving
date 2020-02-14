// 세로 크기 N과 가로 크기 M

// OUTPUT : 세 개의 작은 직사각형의 합의 곱의 최댓값을 출력한다.

#include <stdio.h>
#include <vector>

using namespace std;

int R, C;
int map[100][100];

vector<int> picked;
int visited[100];

long long ans = -1 * 0x7fffffff;

void sero(int start){
	
	if(picked.size() == 2){
		
		long long ret = 1;
		long long suma = 0;
		long long sumb = 0;
		long long sumc = 0;
		
		for(int j = 0 ; j <= picked[0] ; ++j){
			for(int i = 0 ; i < R ; ++i){
				suma += map[i][j];
			}
		}
		
		for(int j = picked[0] + 1 ; j <= picked[1] ; ++j){
			for(int i = 0 ; i < R ; ++i){
				sumb += map[i][j];
			}
		}
		
		for(int j = picked[1] + 1 ; j < C ; ++j){
			for(int i = 0 ; i < R ; ++i){
				sumc += map[i][j];
			}
		}
		
		ret *= suma;
		ret *= sumb;
		ret *= sumc;
		if(ans < ret)	ans = ret;
		return;
	}
	
	for(int i = start ; i < C-1 ; ++i){
		picked.push_back(i);
		sero(i+1);
		picked.pop_back();
	}
}


void garo(int start){
	
	if(picked.size() == 2){
//		for(int i = 0 ; i < picked.size() ; ++i){
//			printf("%d ", picked[i]);
//		}
//		printf("\n");
		
		long long ret = 1;
		long long suma = 0;
		long long sumb = 0;
		long long sumc = 0;
		
		for(int i = 0 ; i <= picked[0] ; ++i){
			for(int j = 0 ; j < C ; ++j){
				suma += map[i][j];
			}
		}
		
		for(int i = picked[0] + 1 ; i <= picked[1] ; ++i){
			for(int j = 0 ; j < C ; ++j){
				sumb += map[i][j];
			}
		}
		
		for(int i = picked[1] + 1 ; i < R ; ++i){
			for(int j = 0 ; j < C ; ++j){
				sumc += map[i][j];
			}
		}
		
		ret *= suma;
		ret *= sumb;
		ret *= sumc;
		if(ans < ret)	ans = ret;
		return;
	}
	
	for(int i = start ; i < R-1 ; ++i){
		picked.push_back(i);
		garo(i+1);
		picked.pop_back();
	}
}

void mix(int r ,int c){
	long long suma = 0;
	long long sumb = 0;
	long long sumc = 0;
	long long ret = 1;
	
	// |=
	suma = 0;
	sumb = 0;
	sumc = 0;
	ret = 1;
	for(int j = 0 ; j <= c ; ++j){
		for(int i = 0 ; i < R ; ++i){
			suma += map[i][j];
		}
	}
	for(int i = 0 ; i <= r ; ++i){
		for(int j = c+1 ; j < C ; ++j){
			sumb += map[i][j];
		}
	}	
	for(int i = r+1 ; i < R ; ++i){
		for(int j = c+1 ; j < C ; ++j){
			sumc += map[i][j];
		}
	}		
	ret *= suma;
	ret *= sumb;
	ret *= sumc;
	if(ans < ret)	ans = ret;
	
	// =|
	suma = 0;
	sumb = 0;
	sumc = 0;
	ret = 1;
	for(int i = 0 ; i <= r ; ++i){
		for(int j = 0 ; j <= c ; ++j){
			suma += map[i][j];
		}
	}	
	for(int i = r+1 ; i < R ; ++i){
		for(int j = 0 ; j <= c ; ++j){
			sumb += map[i][j];
		}
	}			
	for(int j = c+1 ; j < C ; ++j){
		for(int i = 0 ; i < R ; ++i){
			sumc += map[i][j];
		}
	}	
	ret *= suma;
	ret *= sumb;
	ret *= sumc;
	if(ans < ret)	ans = ret;
	
	
	// ㅜ
	suma = 0;
	sumb = 0;
	sumc = 0;
	ret = 1;
	for(int i = 0 ; i <= r ; ++i){
		for(int j = 0 ; j < C ; ++j){
			suma += map[i][j];
		}
	}	
	for(int j = 0 ; j <= c ; ++j){
		for(int i = r + 1 ; i < R ; ++i){
			sumb += map[i][j];
		}
	}	
	for(int j = c+1 ; j < C ; ++j){
		for(int i = r + 1 ; i < R ; ++i){
			sumc += map[i][j];
		}
	}		
	ret *= suma;
	ret *= sumb;
	ret *= sumc;
	if(ans < ret)	ans = ret;
	
	// ㅗ 
	suma = 0;
	sumb = 0;
	sumc = 0;
	ret = 1;
	
	for(int j = 0 ; j <= c ; ++j){
		for(int i = 0 ; i <= r ; ++i){
			suma += map[i][j];
		}
	}	
	for(int j = c+1 ; j < C ; ++j){
		for(int i = 0 ; i <= r ; ++i){
			sumb += map[i][j];
		}
	}	
	for(int i = r+1 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			sumc += map[i][j];
		}
	}		
	ret *= suma;
	ret *= sumb;
	ret *= sumc;
	if(ans < ret)	ans = ret;
	
}

int main(){
	scanf("%d %d", &R, &C);
	
	for(int i = 0 ; i < R; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%1d", &map[i][j]);
		}
	}
	
	// (c-1)C2
	sero(0);
	
	// (r-1)C2
	garo(0);
	
	// 가로에서 하나 & 세로에서 하나 뽑아야 함 
	for(int i = 0 ; i < R-1; ++i){
		for(int j = 0 ; j < C-1 ; ++j){
			mix(i,j);
		}
	}
	
	printf("%lld", ans);
	
	return 0;
}

 
