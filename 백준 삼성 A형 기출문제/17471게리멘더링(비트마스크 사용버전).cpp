// OUTPUT
// 첫째 줄에 백준시를 두 선거구로 나누었을 때, 
// 두 선거구의 인구 차이의 최솟값을 출력한다. 두 선거구로 나눌 수 없는 경우에는 -1을 출력한다.

// 2 ≤ N ≤ 10
// 1 ≤ 구역의 인구 수 ≤ 100 

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, tmp, ttmp;
int pan[10];
int group[10];

bool visited[10];

vector<int> con[10];
vector<int> picked, unpicked;

int ans = 0x7fffffff;

void dfs(int start, int flag){
	
	for(int i = 0 ; i < con[start].size() ; ++i){
		int next = con[start][i];
		if(!visited[next] && group[next] == flag){
			visited[next] = true;
			dfs(next, flag);
		}
	}
	
}

bool check(vector<int> &arr, int flag){
	memset(visited, false, sizeof(visited));
	
	int start = arr[0];
	
	visited[start] = true;
	dfs(start, flag);
	
	for(int i = 0 ; i < arr.size() ; ++i){
		if(!visited[arr[i]])	return false;
	}
	
	return true;
}

void solve(){
	
	// 1 <=   <= 2^N-1-1
	int start = 1;
	int end = (int)pow(2, N) - 2;
	
	for(int i = start ; i <= end ; ++i){
		// (1 : picked)	(0 : unpicked)
		picked.clear();
		unpicked.clear();
		memset(group, 0, sizeof(group));
		
		int picked_sum = 0, unpicked_sum = 0;
		
		for(int j = 0 ; j < N ; ++j){
			int target = (int)pow(2, j);
			if((i & target) > 0){	// (1 : picked)
				picked.push_back(j);
				picked_sum += pan[j];
				group[j] = 1;
			}
			else{	// (0 : unpicked)
				unpicked.push_back(j);
				unpicked_sum += pan[j];
			}
		}
		
//		for(int i = 0 ; i < picked.size() ; ++i)	printf("%d ", picked[i]);
//		printf("\n");		
//		for(int i = 0 ; i < unpicked.size() ; ++i)	printf("%d ", unpicked[i]);
//		printf("\n");				
		
		if(!check(picked, 1) || !check(unpicked, 0))	continue;
		
		ans = min(ans, abs(picked_sum - unpicked_sum));
		
	}
	
}

int main(){
	scanf("%d", &N);
	
	for(int i = 0 ; i < N ; ++i)	scanf("%d", &pan[i]);
	
	for(int i = 0 ; i < N ; ++i){
		scanf("%d", &tmp);
		for(int j = 0 ; j < tmp ; ++j){
			scanf("%d", &ttmp);
			con[i].push_back(ttmp-1);
		}
	}
	
	solve(); 
	
	if(ans == 0x7fffffff)	ans = -1;
	printf("%d", ans);
	
	return 0;
}

