// 주어진 선택의 결과를 보고 어느 프로젝트 팀에도 속하지 않는 학생들의 수를 계산하는 프로그램을 작성하라.

// 학생의 수가 정수 n (2 ≤ n ≤ 100,000)
// (모든 학생들은 1부터 n까지 번호가 부여된다.)

#include <stdio.h> 
#include <string.h> 
#include <vector>

using namespace std;

int T, N;
int map[100001];
int visited[100001];
int cache[100001];	// (-1 : 외톨이)  (0 : 미정)  (1 : 친구)
vector<int> track;

void dfs(int start){
	int next = map[start];
	
	if(cache[next] != 0){
		for(int i = 0 ; i < track.size() ; ++i)	cache[track[i]] = -1;
		return;
	}
	
	if(visited[next] != 0){
		bool tmp_flag = false;
		for(int i = 0 ; i < track.size() ; ++i){
			if(track[i] == next)	tmp_flag = true;
			if(tmp_flag){
				cache[track[i]] = 1;
			}
			else{
				cache[track[i]] = -1;
			}
		}
		return;
	}
	
	visited[next] = 1;
	track.push_back(next);
	dfs(next);
}

int main(){
	scanf("%d", &T);
	for(int z = 0 ; z < T ; ++z){
		memset(visited, 0, sizeof(visited));
		memset(cache, 0, sizeof(cache));
		scanf("%d", &N);	
		for(int i = 1 ; i <= N ; ++i){
			scanf("%d", &map[i]);	
		}
		
		for(int i = 1 ; i <= N ; ++i){
			if(cache[i] == 0){
				track.clear();
				visited[i] = 1;
				track.push_back(i);
				dfs(i);
			}
		}
		
		int ans = 0;
		for(int i = 1 ; i <= N ; ++i){
			if(cache[i] == -1)	++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}


