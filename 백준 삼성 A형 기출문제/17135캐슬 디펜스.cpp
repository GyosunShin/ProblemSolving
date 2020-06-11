// 3 ≤ N, M ≤ 15		1 ≤ D ≤ 10
	
// 거리가 D이하인 && 가장 왼쪽에 있는 적 공격 

// (0 : 빈칸) (1 : 적)

// OUTPUT
// 궁수의 공격으로 제거할 수 있는 적의 최대 수

#include <cstdio> 
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int R, C, D;
int pan[15][15];
int backup[15][15];

int answer = 0;

vector<int> picked;

bool comp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b){
	if(a.first == b.first && a.second.second == b.second.second)	return a.second.first < b.second.first;
	if(a.first == b.first)	return a.second.second < b.second.second;
	return a.first < b.first;	
}

void backupBuild(){
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			backup[i][j] = pan[i][j];
		}
	}
	
}

void go(){
	
	for(int i = 0 ; i < C ; ++i){
		for(int j = R-2 ; j >= 0 ; --j){
			backup[j+1][i] = backup[j][i];
		}
	}
	for(int i = 0 ; i < C ; ++i)	backup[0][i] = 0;
	
}

int dist(int archerR, int archerC, int targetR, int targetC){
	return abs(archerR - targetR) + abs(archerC - targetC);
}

int kill(){
	bool tmp[15][15];
	memset(tmp, false, sizeof(tmp));
	
	for(int z = 0 ; z < picked.size() ; ++z){
		int archerIdx = picked[z];
		
		vector<pair<int, pair<int, int>>> v;	// <거리, Column>

		for(int i = 0 ; i < R ; ++i){
			for(int j = 0 ; j < C ; ++j){	
				if(backup[i][j] == 1){
					int d = dist(R, archerIdx, i, j);
					if(d <= D)	v.push_back(make_pair(d, make_pair(i, j)));
				}
			}
		}
		if((int)v.size() == 0)	continue;
		sort(v.begin(), v.end(), comp);
		tmp[v[0].second.first][v[0].second.second] = true;
	}
	
	int sum = 0;
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){	
			if(tmp[i][j]){
				backup[i][j] = 0;
				++sum;
			}
		}
	}
	return sum;
}

int check(){
	
	int sum = 0;
	
	backupBuild();
	
	// |r1-r2| + |c1-c2| <= D
	for(int z = 0 ; z < R ; ++z){
		sum += kill();
		go();
	}
	
	return sum;
}

void comb(int start){
	
	if(picked.size() == 3){
		answer = max(answer, check());
		return;
	}
	
	for(int i = start ; i < C ; ++i){
		picked.push_back(i);
		comb(i+1);
		picked.pop_back();
	}	
	
}

void solve(){
	
	// 0 ~ (C-1)
	comb(0);
}

int main(){
	scanf("%d %d %d", &R, &C, &D);
	
	for(int i = 0 ; i < R ; ++i){
		for(int j = 0 ; j < C ; ++j){
			scanf("%d", &pan[i][j]);
		}
	}
	
	solve();
	
	printf("%d", answer);
	
	return 0;
}
