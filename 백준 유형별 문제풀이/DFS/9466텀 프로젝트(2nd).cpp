// 학생의 수가 정수 n (2 ≤ n ≤ 100,000)
// 모든 학생들은 1부터 n까지 번호가 부여된다 

// OUTPUT : 프로젝트 팀에 속하지 못한 학생들의 수를 나타내면 된다.

#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std; 

int T, N;
int map[100001];
int cache[100001];   // (1 : 그룹할당) (0 : 미정) (-1 : 그룹 안됨)
int visited[100001];

vector<int> picked;

void dfs(int next){
	
	if(cache[next] != 0){  // 진행하다가 다음거가 이미 그룹에 해당되는지 결정난 경우 
		for(int i = 0 ; i < picked.size() ; ++i)	cache[picked[i]] = -1;
		return;
	}
	
	if(visited[next] != 0){
		bool tmp_flag = false;
		for(int i= 0 ; i < picked.size() ; ++i){
			if(tmp_flag){
				cache[picked[i]] = 1;
				continue;
			}
			if(picked[i] == next){
				tmp_flag = true;
				cache[picked[i]] = 1;
				continue;
			}
			cache[picked[i]] = -1;
		}
		return;
	}
	visited[next] = 1;
	picked.push_back(next);
	dfs(map[next]);
}

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		memset(cache, 0, sizeof(cache));
		memset(visited, 0, sizeof(visited));
		picked.clear();
		
		scanf("%d", &N);
		for(int i = 1 ; i <= N ; ++i){
			scanf("%d", &map[i]);	
		}
		
		for(int i = 1 ; i <= N ; ++i){
			if(cache[i] != 0)	continue;
			visited[i] = 1;
			picked.clear();
			picked.push_back(i);
			dfs(map[i]);
		}
		
		int ans = N;
		for(int i = 1 ; i <= N ; ++i){
			if(cache[i] == 1)	--ans;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
