// OUTPUT
// 첫째 줄에 백준시를 두 선거구로 나누었을 때, 
// 두 선거구의 인구 차이의 최솟값을 출력한다. 두 선거구로 나눌 수 없는 경우에는 -1을 출력한다.

// 2 ≤ N ≤ 10
// 1 ≤ 구역의 인구 수 ≤ 100 

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, tmp, ttmp;
int pan[10];

vector<int> con[10];
vector<int> picked;
int howmany;

bool used[10];
bool visited[10];
int mark[10];

int ans = 0x7fffffff;

void search(int start, int flag){
	
	for(int i = 0 ; i < con[start].size() ; ++i){
		int next = con[start][i];
		if(!visited[next] && mark[next] == flag){
			visited[next] = true;
			search(next, flag);
		}
	}
	
}

bool check(vector<int>& input, int flag){
	memset(visited, false, sizeof(visited));
	
	int start = input[0];
	
	visited[start] = true;
	search(start, flag);
	
	for(int i = 0 ; i < input.size() ; ++i){
		if(!visited[input[i]])	return false;
	}
	
	return true;
}

void dfs(int start){
	
	if((int)picked.size() == howmany){
		
		memset(mark, 0, sizeof(mark));
		
		int picked_sum = 0;	int unpicked_sum = 0;
		
		vector<int> unpicked;
		for(int i = 0 ; i < N ; ++i){
			if(!used[i]){
				mark[i] = 1;
				unpicked.push_back(i);
				unpicked_sum += pan[i];
			}
		}		
		
		
//		for(int i = 0 ; i < picked.size() ; ++i)	printf("%d ", picked[i]);
//		printf("\n");
//		for(int i = 0 ; i < N ; ++i){
//			if(!used[i])	printf("%d ", i);
//		}
//		printf("\n");

		if(!check(picked, 0) || !check(unpicked, 1))	return;

		for(int i = 0 ; i < picked.size() ; ++i)	picked_sum += pan[picked[i]];
		
		ans = min(ans, abs(picked_sum - unpicked_sum));
//		printf("RET : %d\n\n", abs(picked_sum - unpicked_sum));
		
		return;
	}
	
	for(int i = start ; i < N ; ++i){
		used[i] = true;
		picked.push_back(i);
		dfs(i+1);
		picked.pop_back();	
		used[i] = false;
	}
		
}

void solve(){
	
	for(int i = 1 ; i < N ; ++i){
		howmany = i;
		dfs(0);
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

