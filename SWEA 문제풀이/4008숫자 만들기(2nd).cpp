// ( 3 ¡Â N ¡Â 12 )

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;
int opers[4];
int pan[12];
int mmin = 0x7fffffff;
int mmax = -1 * 0x7fffffff;

vector<int> picked;

void dfs(){
	
	if(picked.size() == (N-1)){
		int tmp_ret = pan[0];
		for(int i = 0 ; i < picked.size() ; ++i){
			if(picked[i] == 0){
				tmp_ret += pan[i+1];
			}
			else if(picked[i] == 1){
				tmp_ret -= pan[i+1];
			}
			else if(picked[i] == 2){
				tmp_ret *= pan[i+1];
			}
			else if(picked[i] == 3){
				tmp_ret /= pan[i+1];
			}
		}
		
		mmin = min(mmin, tmp_ret);
		mmax = max(mmax, tmp_ret);
	}
	
	for(int i = 0 ; i < 4 ; ++i){
		
		if(opers[i] > 0){
			opers[i]--;
			picked.push_back(i);
			dfs();
			picked.pop_back();
			opers[i]++;
		}
		
	}
	
}

int solve(){
	
	dfs();
	
	return (mmax - mmin);
}

int main(){
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		mmin = 0x7fffffff;
		mmax = -1 * 0x7fffffff;
		
		scanf("%d", &N);	
		
		for(int i = 0 ; i < 4 ; ++i)	scanf("%d", &opers[i]);
		for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
		
		int ans = solve();
		printf("#%d %d\n", z, ans);
		
	}
	return 0;
}
