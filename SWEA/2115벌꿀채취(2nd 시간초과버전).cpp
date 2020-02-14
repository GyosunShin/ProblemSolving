// 서로 겹치면 안 된다. 

// 이때 두 일꾼이 꿀을 채취하여 얻을 수 있는 수익의 합이 최대가 되는 경우를 찾고, 그 때의 최대 수익을 출력하는 프로그램을 작성하라.

// (3 ≤ N ≤ 10)

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, M, C;
int map[10][10];

int ans; 
int amax, bmax;

vector<pair<int, int> > dong;
vector<int> picked;

vector<int> aidx, bidx;
vector<int> a, b;

void dfsb(int start){
	int tmp_sum = 0;
	for(int i = 0 ; i < bidx.size() ; ++i){
		tmp_sum += b[bidx[i]];
	}
	
	if(tmp_sum > C)	return;	
	
	int ret_max = 0;
	for(int i = 0 ; i < bidx.size() ; ++i){
		ret_max += b[bidx[i]] * b[bidx[i]];
	}
	bmax = max(bmax, ret_max);
	
	if(bidx.size() == M)	return;
	
	for(int i = start ; i < M ; ++i){
		bidx.push_back(i);
		dfsb(i+1);
		bidx.pop_back();
	}	
}

void dfsa(int start){
	int tmp_sum = 0;	
	for(int i = 0 ; i < aidx.size() ; ++i){
		tmp_sum += a[aidx[i]];
	}
	if(tmp_sum > C)	return;
		
	int ret_max = 0;
	for(int i = 0 ; i < aidx.size() ; ++i){
		ret_max += a[aidx[i]] * a[aidx[i]];
	}
	amax = max(amax, ret_max);	
	
	if(aidx.size() == M)	return;
	
	for(int i = start ; i < M ; ++i){
		aidx.push_back(i);
		dfsa(i+1);
		aidx.pop_back();
	}	
}

void solve(int ar, int ac, int br, int bc){	
	a.clear();	b.clear();
	// 최대 수익 출력이 답 
	for(int i = 0 ; i < M ; ++i){
		int tmpa = map[ar][ac+i];	int tmpb = map[br][bc+i];
		a.push_back(tmpa);
		b.push_back(tmpb);
	}
	// 조합 이용?
	
	amax = -1 * 0x7fffffff;	bmax = -1 * 0x7fffffff;
	dfsa(0);	dfsb(0);
	ans = max(ans, amax + bmax);
}

void dfs(int start){	// For) nCr 조합
 
	if(picked.size() == 2){
		// 서로 부딪히는지 확인
		int ar = dong[picked[0]].first;	int ac = dong[picked[0]].second;
		int br = dong[picked[1]].first;	int bc = dong[picked[1]].second;
		
		if(ar == br){
			if(abs(ac - bc) < M)	return;
		}
		
		solve(ar, ac, br, bc);
		
		return;
	}
	
	for(int i = start ; i < dong.size() ; ++i){
		picked.push_back(i);
		dfs(i + 1);
		picked.pop_back();
	}
	
}

int main(){
	
	scanf("%d", &T);
	
	for(int z = 1 ; z <= T ; ++z){
		ans = -1 * 0x7fffffff;
		scanf("%d %d %d", &N, &M, &C);
		for(int i = 0 ; i < N ; ++i){
			for(int j = 0 ; j < N ; ++j){
				scanf("%d", &map[i][j]);			
				if(j <= N - M){
					dong.push_back(make_pair(i,j));
				}
			}
		}
		
		dfs(0);
		
		printf("#%d %d\n", z, ans);
	}
	return 0;
}
