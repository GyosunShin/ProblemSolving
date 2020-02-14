//N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > chicken;
vector<pair<int, int> > home;
vector<pair<int, int> > picked;

int N, M, ans;

int map[50][50];


void dfs(int count){
	if(picked.size() == M){  // chicken집 m개 다 뽑았으면.. 이제...
		int sum = 0;
		
		for(int i = 0 ; i < home.size() ; ++i){  // 각 집마다의 최소 치킨거리 찾는다.
			int tmpMin = 0x7fffffff;
			for(int j = 0 ; j < picked.size() ; ++j){
				int tmptmpMin = abs(home[i].first - picked[j].first) + abs(home[i].second - picked[j].second);
				if(tmpMin > tmptmpMin){
					tmpMin = tmptmpMin;
				}
			}
			sum += tmpMin;
		}
		if(ans > sum){
			ans = sum;
		}	
		return;
	}
	
	for(int i = count ; i < chicken.size() ; ++i){
		picked.push_back(pair<int, int>(chicken[i].first, chicken[i].second));
		dfs(i + 1);
		picked.pop_back();
	}
}


int main(){
	ans = 0x7fffffff;
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; ++i){
		for(int j = 0 ; j < N ; ++j){
			int tmp;
			scanf("%d", &tmp);
			if(tmp == 2){  // CHICKEN
				chicken.push_back(pair<int, int>(i,j));
			} 
			else if(tmp == 1){  // HOME
				home.push_back(pair<int, int>(i,j));
			}
		}
	}
	//-------------- 여기까지 INPUT받는거! --------------------
	
	//이제 DFS이용해서 chicken.size()에서 M개의 치킨집을 골라내야 함! 
	dfs(0);
	printf("%d", ans);
	
}
