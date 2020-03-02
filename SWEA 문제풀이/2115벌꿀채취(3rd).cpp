// (3 ≤ N ≤ 10)
// (1 ≤ M ≤ 5)
// (10 ≤ C ≤ 30)

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M, C;
int pan[10][10];

//vector<vector<int> > picked;
vector<int> picked;

int ar, ac, br, bc;

int ad = -1 * 0x7fffffff;
int bd = -1 * 0x7fffffff;

int ans = -1 * 0x7fffffff;

void dfs(int start){
	
	int asum = 0;	int bsum = 0;
	int adouble = 0;	int bdouble = 0;
	
	for(int i = 0 ; i < picked.size() ; ++i){
		int offset = picked[i];
		asum += pan[ar][ac + offset];
		bsum += pan[br][bc + offset];
		adouble += pow(pan[ar][ac + offset], 2);
		bdouble += pow(pan[br][bc + offset], 2);
	}
	
	if(asum <= C){
		ad = max(ad, adouble);
	}
	if(bsum <= C){
		bd = max(bd, bdouble);
	}	
	
	if(picked.size() == M)	return;
	
	for(int i = start ; i < M ; ++i){
		picked.push_back(i);
		dfs(i+1);
		picked.pop_back();
	}
	
}

void solve(int i, int j, int k, int l){
	
//	printf("(%d, %d) / (%d, %d)\n", i, j, k, l);
		
	// (i,j) ~~  / (k,l) ~~
	ar = i;	ac = j;
	br = k;	bc = l;
	
	ad = -1 * 0x7fffffff;
	bd = -1 * 0x7fffffff;
	
	dfs(0);
//	printf("AD : %d / BD : %d\n", ad, bd);
	ans = max(ans, ad+bd);
	
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		ans = -1 * 0x7fffffff;		
		scanf("%d %d %d", &N, &M, &C);	
		
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &pan[i][j]);		
			}
		}		
		
//		dfs(0);
		
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j <= N-M ; ++j){
				
				for(int k = i ; k < N ; ++k){
					if(i == k){
						for(int l = j+M ; l <= N-M ; ++l){
							solve(i,j,k,l);
						}
					}
					else{
						for(int l = 0 ; l <= N-M ; ++l){
							solve(i,j,k,l);
						}
					}
				}
				
			}
		}		
		
		// OUTPUT : 두 일꾼이 꿀을 채취하여 얻을 수 있는 최대 수익
		printf("#%d %d\n", z, ans);
	}
	
	return 0;
}
