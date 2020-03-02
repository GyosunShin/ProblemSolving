// (0 ºóÄ­) (1 Áý) (2 Ä¡Å²Áý)

// (2 ¡Â N ¡Â 50)	(1 ¡Â M ¡Â 13)

#include <cstdio> 
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int pan[50][50];

vector<pair<int, int> > cs;
vector<pair<int, int> > hs;

vector<int> picked;

int ans = 0x7fffffff;

void dfs(int start){
	
	if(picked.size() == M){
		int tmp_sum = 0;
		
		for(int i = 0 ; i < hs.size() ; ++i){
			int mmin = 0x7fffffff;
			for(int j = 0 ; j < picked.size() ; ++j){
				mmin = min(mmin, abs(hs[i].first - cs[picked[j]].first) + abs(hs[i].second - cs[picked[j]].second));
			}
			tmp_sum += mmin;
		}
		
		ans = min(ans, tmp_sum);
		
		return;
	}
	
	for(int i = start ; i < cs.size() ; ++i){
		picked.push_back(i);
		dfs(i+1);
		picked.pop_back();
	}
	
}

int main(){
	scanf("%d %d", &N, &M);
	
	for(int i= 0 ; i < N ; ++i){
		for(int j= 0 ; j < N ; ++j){
			scanf("%d", &pan[i][j]);	// (0 ºóÄ­) (1 Áý) (2 Ä¡Å²Áý)
			if(pan[i][j] == 2)	cs.push_back(make_pair(i, j));
			else if(pan[i][j] == 1)	hs.push_back(make_pair(i, j));
		}
	}
	
	dfs(0);
	
	printf("%d", ans);
	
	
	return 0;
}
