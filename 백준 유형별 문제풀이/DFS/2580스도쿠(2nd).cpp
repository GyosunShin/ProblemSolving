#include <cstdio> 
#include <vector>
#include <algorithm>

using namespace std;

int pan[9][9];

bool sero[9][10];
bool garo[9][10];
bool nemo[9][10];

vector<pair<int, int>> v;

bool flag;

void check(int i, int j){
	int tgt = 0;
	
	int a = i / 3;	int b = j / 3;
	tgt = (a*3) + (b);
	
	nemo[tgt][pan[i][j]] = true;
}

void dfs(int deep){
	if(flag)	return;
	
	if(deep == v.size()){
		
		for(int i = 0 ; i < 9 ; ++i){
			for(int j = 0 ; j < 9 ; ++j){
				printf("%d ", pan[i][j]);
			}
			printf("\n");
		}
		
		flag = true;
		
		return;
	}
	
	int r = v[deep].first;	int c = v[deep].second;
	int n = ((r / 3) * 3) + (c / 3);
	
	for(int i = 1 ; i <= 9 ; ++i){
		if(!garo[r][i] && !sero[c][i] && !nemo[n][i]){
			garo[r][i] = true;
			sero[c][i] = true;
			nemo[n][i] = true;
			pan[r][c] = i;
			dfs(deep + 1);
			pan[r][c] = 0;
			garo[r][i] = false;
			sero[c][i] = false;
			nemo[n][i] = false;
		}
	}
	
}

int main(){
	for(int i = 0 ; i < 9 ; ++i){
		for(int j = 0 ; j < 9 ; ++j){
			scanf("%d", &pan[i][j]);
			
			if(pan[i][j] == 0){
				v.push_back({i, j});
			}
			else{
				// (i : garo) (j : sero)
				garo[i][pan[i][j]] = true;
				sero[j][pan[i][j]] = true;
				check(i,j);
			}
		}
	}
	
	dfs(0);
	
	
	return 0;
}
